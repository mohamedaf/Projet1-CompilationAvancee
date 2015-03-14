(************************************************************************
 *                                                                      *
 *                       MASTER STL M1 anne'e 2014/15                   *
 *                                                                      *
 *                     Cours Compilation Avanceels                      *
 *                                                                      *
 *                       Compilation -> Langage intermediaire           *
 *                                                                      *
 *                         partie de ml2c                               *
 *                                                                      *
 ************************************************************************
 *                                                                      *
 *   prodc.ml  : traducteur LI_instr -> texte C                         *
 *                                                                      *
 *   version : 0.1           01/03/15                                   *
 *                                                                      *
 *   auteur : AFFES Mohamed Amin                                        *
 *            (modification faite sur le code prod.ml                   *
 *	       servant pour ml2Java fait par Emmanuel CHAILLOUX         *
 *	       pour qu'il corresponde au nouveau runtime)               *
 *                                                                      *
 ************************************************************************)

open Types;;
open Typeur;;
open Env_typeur;;
open Env_trans;;
open Langinter;;
open Str;;


(* des symboles globaux bien utiles par la suite *)

let compiler_name = ref "ml2c";;
let object_suffix = ref ".c";;

(* des valeurs pour certains symboles de env_trans *)

pair_symbol:=",";;
cons_symbol:="::";;
ref_symbol:="ref";;

(* l'environnement initial du traducteur en liaison avec la Runtime *)

let build (s,equiv)  = 
  let t = 
      try List.assoc s !initial_typing_env  
      with Not_found -> 
        failwith ("building initial_trans_env : for symbol : "^s)
  in (s,(equiv,type_instance t));;

(*
let get_param_type fun_t =  match fun_t with 
  Fun_type (Pair_type (t1,t2),tr) -> [t1;t2],tr
| Fun_type ( t1,tr) -> [t1],tr
| _ -> failwith "get_param_type"
;;
*)

initial_special_env := 
 List.map build [
      "hd","MLhd";
      "tl","MLtl";
      "fst","MLfst";
      "snd","MLsnd"
];;


initial_trans_env:= 

let alpha = max_unknown () in
[",",("MLpair", Fun_type (Pair_type (alpha,alpha),
                                    Pair_type (alpha,alpha)))]@
["::",("MLlist", Fun_type (Pair_type (alpha,alpha),
ie                                    List_type (alpha)))]@

(
List.map build 
     ["true" ,"MLtrue";
      "false","MLfalse";
      "+","MLaddint";
      "-","MLsubint";
      "*","MLmulint";
      "/","MLdivint";
      "=","MLequal";
      "<","MLltint";
      "<=","MLleint";
      ">","MLgtint";
      ">=","MLgeint";
      "^", "MLconcat"
      
]
)
;;

(* des fonctions d'I/O *)

let output_channel = ref stdout;;
let change_output_channel oc = output_channel := oc;;

let shift_string = String.make 256 ' ';;
let out s = output_string !output_channel s;;
let out_start s nb = out ("\n"^(String.sub shift_string 0 (2*nb))^s);;
let out_end s nb = out ("\n"^(String.sub shift_string 0 nb)^"}\n");;
let out_line s = out (s^"\n");;

let out_before (fr,sd,nb) = 
  if sd<>"" then out_start (sd^"=") nb
  else if fr then out_start ("return ") nb;;


let out_after  (fr,sd,nb) = 
  if sd<>"" then 
  begin
      out ";";
      if fr then out (("return "^sd^";"))
  end
  else if fr then out ";";;


(* des fonctions utilitaires pour commenter un peu la production *)

let header_main  s = 
  List.iter out 
   ["#include \"runtime.h\"\n\n";
    "/**\n";
    " *  "^ s ^ ".c" ^ " engendre par ml2c \n";
    " */\n"]
;;

let footer_main  s = 
  List.iter out
   ["// fin du fichier " ^ s ^ ".c\n"]
;;

let header_one  s = 
   List.iter out
     [];;


let footer_one  s = ();;

let header_two  s = 
  List.iter out
  [ ""
  ]
;;

let footer_two  s = ();;

let header_three  s = 
  List.iter out
  [  "\n\n";
     "int main(int argc, char* argv[]) {\n";
     "\ninit_runtime();\n";
     "\ninit();\n"]
;;

let footer_three  s = 
  List.iter out
  [ "\n\nreturn 0;";
    "\n}\n\n"]
;;

(* on recuoere le  type pour une declaration precise *)
(* Tout est MLvalue donc pas besoin de cast *)
  
let string_of_const_type ct = match ct with   
  INTTYPE    -> ""
| FLOATTYPE  -> ""
| STRINGTYPE -> ""
| BOOLTYPE   -> ""
| UNITTYPE   -> ""
;;
(*  INTTYPE    -> "MLint "
| FLOATTYPE  -> "MLdouble "
| STRINGTYPE -> "MLstring "
| BOOLTYPE   -> "MLbool "
| UNITTYPE   -> "MLunit "
;;*)
 
let rec string_of_type typ = match typ with 
  CONSTTYPE t -> string_of_const_type t
| ALPHA    ->  ""
| PAIRTYPE -> ""
| LISTTYPE -> ""
| FUNTYPE  -> ""
| REFTYPE  -> ""
;;
(*| PAIRTYPE -> "MLpair "
| LISTTYPE -> "MLlist "
| FUNTYPE  -> "MLfun "
| REFTYPE  -> "MLref "
  ;;*)


let prod_global_var instr = match instr with
  VAR (v,t) -> out_start ("MLvalue* "^(*(string_of_type t)*)v^";") 1 
| FUNCTION (ns,t1,ar,(p,t2), instr) ->
    out_start ("MLvalue* "(*"fun_"^ns^" "*)^ns^";") 1
| _ -> ()
;;

let prod_init instr = match instr with
  FUNCTION (ns,t1,ar,(p,t2), instr) ->
    out_start (""(*"fun_"^ns^" "*)^ns^"= new_MLfun_"^ns^"("^(string_of_int ar)^");") 1
| _ -> () ;
;;

let prod_bis ast_li = 
  out_line "void init(){";
  List.iter prod_init ast_li ;
  out_line "";
  out_line "}";
;;

let prod_proto instr = match instr with
   FUNCTION (ns,t1,ar,(p,t2), instr) ->
    out_start ("MLvalue* f_"(*"fun_"^ns^" "*)^ns^"();") 1
| _ -> ()
;;
  
let prod_two  ast_li = 
  List.iter prod_global_var ast_li ;
  out_line "";
  out_line "";
  List.iter prod_proto ast_li ;
  out_line "";
  out_line "";
;;

let get_param_type lv = 
  List.map (function (VAR(name,typ)) -> typ 
        | _ -> failwith "get_param_type" ) lv;;


let prod_const c = match c with 
  INT i -> out ("new_MLint("^(string_of_int i)^")")
| FLOAT f -> out ("new_MLdouble("^(string_of_float f)^")")
| BOOL b  -> out ("new_MLbool("^(if b then "true" else "false")^")")
| STRING s -> out ("new_MLstring("^"\""^s^"\""^")")
| EMPTYLIST -> out ("MLnil")
| UNIT ->      out ("MLlrp")
;;

let rec prod_local_var (fr,sd,nb) (v,t) = 
  out_start ("MLvalue* "(*(string_of_type t)*)^v^";") nb;;

let rec prod_instr (fr,sd,nb) instr  = match instr with 
  CONST c -> out_before (fr,sd,nb);
             prod_const c;
             out_after (fr,sd,nb)
| VAR (v,t)
          -> if (nb = 0) && ( sd = "") then ()
             else 
             begin 
               out_before (fr,sd,nb);
	       (*out (Str.global_replace (Str.regexp "ftest.") "" v);*)
               out v;
               out_after (fr,sd,nb)           
             end
| IF(i1,i2,i3) -> 
              out_start "if (" nb;
              prod_instr (false,"",nb) i1 ;
              out"->content.MLbool";
              out ")";
              prod_instr (fr,sd,nb+1) i2 ;
              out_start "else" (nb);
              prod_instr (fr,sd,nb+1) i3
| RETURN i -> prod_instr (true,"",nb) i
| AFFECT (v,i) -> prod_instr (false,v,nb) i
| BLOCK(l,i) -> out_start "{ " nb;
                  List.iter (fun (v,t,i) -> prod_local_var (false,"",nb+1) 
                                           (v,t)) l;
                  List.iter (fun (v,t,i) -> prod_instr (false,v,nb+1) i) l;
                  prod_instr (fr,sd,nb+1) i;
                out_start "}" nb
             
| APPLY(i1,i2) -> 
   out_before(fr,sd,nb);
     prod_instr (false,"",nb) i1;
     out "->content.MLfun->invoke(";
     prod_instr (false,"",nb) i2;     
     out")";
   out_after(fr,sd,nb)
| PRIM ((name,typ),instrl) ->
   let ltp = get_param_type instrl in 
   out_before (fr,sd,nb);
   (*if (name = "MLequal") || (name = "MLpair") || (name = "MLlist") || (name = "MLprint") then
     begin
       out (name^"(&"^(string_of_type (List.hd ltp))^"");
       prod_instr (false,"",nb+1) (List.hd instrl);
       List.iter2 (fun x y -> out (",&"^(string_of_type y)^"");
         prod_instr (false,"",nb+1) x) 
         (List.tl instrl) (List.tl ltp);
       out ")" ;
       out_after(fr,sd,nb)
     end
   else *)
   (*begin*)
   out (name^"("^(string_of_type (List.hd ltp))^"");
   prod_instr (false,"",nb+1) (List.hd instrl);
   List.iter2 (fun x y -> out (","^(string_of_type y)^"");
			  prod_instr (false,"",nb+1) x) 
	      (List.tl instrl) (List.tl ltp);
   out ")" ;
   out_after(fr,sd,nb)
(*end*)                     

| FUNCTION _ -> ()
;;

let fun_header fn cn  = 
  List.iter out 
    ["\n\n";
     "/**\n";
     " *  de'claration de la fonction "^fn^"\n";
     " *    vue comme la structure : "^cn^"\n";
     " */ \n";
     "\n\n"]
;;

let prod_invoke cn  ar  ns = 
  List.iter out_line 
     ["MLvalue* "^ns^"_invoke(MLvalue* MLparam){";
      "  if ("^cn^"->f->MLcounter == ("^cn^"->MAX-1)) {"
     ];

  out ("    return "^ns^"_invoke_real(");
  for i=0 to ar-2 do 
    out (""^cn^"->f->MLenv["^(string_of_int i)^"], ")
  done;
  out_line "MLparam);";     

  List.iter out_line 
     ["  }";
      "  else {";
      "    MLvalue *m;";
      "    m = new_MLfun("^cn^"->f->MLcounter+1);";
      "    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);";
      "    m->content.MLfun->invoke = &("^ns^"_invoke);";
      "    "^cn^"->f = m->content.MLfun;";
      "    return m;";
      "  }";
      "}"
      ]
;;

let prod_invoke_fun cn ar t lp instr ns =
  out_start ("MLvalue* "^ns^"_invoke_real(") 1;
  out ("MLvalue* "^(List.hd lp));
  List.iter (fun x -> out (", MLvalue* "^x)) (List.tl lp);
  out_line ") {";
  prod_instr (true,"",2) instr;
  
  out_start "}" 1;
  out_line ""
;;

let prod_init cn ns lp ar =
  out_line ("MLvalue* new_MLfun_"^ns^"(int n) {");
  out_line "  MLvalue *m = new_MLfun(n);";
  out_line "";
  out_line (""^cn^" = (_"^ns^"*) malloc(sizeof(_"^ns^"));");
  out_line ("  "^cn^"->MAX = "^string_of_int (List.length lp)^";");
  out_line ("  "^cn^"->f = m->content.MLfun;");
  out_line ("  "^cn^"->f->invoke = &("^ns^"_invoke);");
  out_line ("  "^cn^"->invoke_real = &("^ns^"_invoke_real);");
  out_line ("  m->content.MLfun = "^cn^"->f;");
  out_line "";
  out_line "  return m;";
  out_line "}";
  out_line "";

(*definir la fonction pour donner une nouvelle instance*)
  out_line ("MLvalue* f_"^ns^"() {");
  out_line ("  return new_MLfun_"^ns^"("^(string_of_int ar)^");");
  out_line "}";
  out_line "";
;;

let prod_fun instr = match instr with 
  FUNCTION (ns,t1,ar,(lp,t2),instr) -> 
      let class_name = "MLfun_"^ns in
      fun_header ns class_name ;
      out_line ("typedef struct "^ns^" {");
      out_line ("  MLFun *f;");
      out_line ("  int MAX;");
      out_start ("MLvalue* (*invoke_real)(MLvalue* ") 1;
      List.iter (fun x -> out (", MLvalue*")) (List.tl lp);
      out_line ");";
      out_line ("} _"^ns^";");
      out_line "";
      out_line ("_"^ns^"* "^class_name^";");
      out_line "";
      prod_invoke_fun class_name ar t1 lp instr ns;
      out_line "";
      prod_invoke class_name ar ns;
      out_line "";
      prod_init class_name ns lp ar;
      out_line "";
      out_line ("// fin de la classe "^class_name)
      
      
|  _ -> ()
;;


let prod_one  ast_li =
  (* applique la fonction prod_fun aux elements de la liste ast_li *)
  List.iter prod_fun ast_li
;;


let prod_three  ast_li = 
 List.iter (prod_instr  (false,"",0) ) ast_li
;;



let prod_file filename ast_li = 
  let obj_name = filename ^ !object_suffix in 
  let oc = open_out obj_name in 
  change_output_channel oc;  
  module_name:=filename;
  try 
    header_main  filename;
    header_two  filename;
    prod_two  ast_li;
    footer_two  filename;
    header_one  filename;
    prod_one  ast_li;
    footer_one  filename;
    prod_bis ast_li;
    header_three  filename;
    prod_three  ast_li;
    footer_three  filename;
    footer_main  filename;
    close_out oc
  with x -> close_out oc; raise x;;



