#include "runtime.h"

/**
 *  ftest.c engendre par ml2c 
 */

  MLvalue* null___1;
  MLvalue* g___8;
  MLvalue* h___12;
  MLvalue* q___17;
  MLvalue* v___25;
  MLvalue* w___27;
  MLvalue* map___37;
  MLvalue* iter___57;
  MLvalue* inter___71;
  MLvalue* mult___87;
  MLvalue* i___92;
  MLvalue* l___98;
  MLvalue* fd___106;
  MLvalue* ig___108;
  MLvalue* bi___114;
  MLvalue* ik___118;
  MLvalue* b___122;
  MLvalue* umap___126;
  MLvalue* value___146;


  MLvalue* f_null___1();
  MLvalue* f_g___8();
  MLvalue* f_h___12();
  MLvalue* f_q___17();
  MLvalue* f_v___25();
  MLvalue* f_w___27();
  MLvalue* f_map___37();
  MLvalue* f_iter___57();
  MLvalue* f_inter___71();
  MLvalue* f_mult___87();
  MLvalue* f_umap___126();



/**
 *  de'claration de la fonction null___1
 *    vue comme la structure : MLfun_null___1
 */ 


typedef struct null___1 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* );
} _null___1;

_null___1* MLfun_null___1;


  MLvalue* null___1_invoke_real(MLvalue* l___2) {

    { 
      MLvalue* T___3;
      { 
        MLvalue* T___4;
        MLvalue* T___5;
        T___4=l___2;
        T___5=MLnil;
        T___3=MLequal(T___4,T___5);
      }
      if (T___3->content.MLbool)
        { 
          MLvalue* T___6;
          T___6=MLtrue;
          return T___6;
        }
      else
        { 
          MLvalue* T___7;
          T___7=MLfalse;
          return T___7;
        }
    }
  }

MLvalue* null___1_invoke(MLvalue* MLparam){
  if (MLfun_null___1->f->MLcounter == (MLfun_null___1->MAX-1)) {
    return null___1_invoke_real(MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_null___1->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(null___1_invoke);
    MLfun_null___1->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_null___1(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_null___1 = (_null___1*) malloc(sizeof(_null___1));
  MLfun_null___1->MAX = 1;
  MLfun_null___1->f = m->content.MLfun;
  MLfun_null___1->f->invoke = &(null___1_invoke);
  MLfun_null___1->invoke_real = &(null___1_invoke_real);
  m->content.MLfun = MLfun_null___1->f;

  return m;
}

MLvalue* f_null___1() {
  return new_MLfun_null___1(1);
}


// fin de la classe MLfun_null___1


/**
 *  de'claration de la fonction g___8
 *    vue comme la structure : MLfun_g___8
 */ 


typedef struct g___8 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* );
} _g___8;

_g___8* MLfun_g___8;


  MLvalue* g___8_invoke_real(MLvalue* x___9) {

    { 
      MLvalue* T___10;
      MLvalue* T___11;
      T___10=x___9;
      T___11=MLnil;
      return MLequal(T___10,T___11);
    }
  }

MLvalue* g___8_invoke(MLvalue* MLparam){
  if (MLfun_g___8->f->MLcounter == (MLfun_g___8->MAX-1)) {
    return g___8_invoke_real(MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_g___8->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(g___8_invoke);
    MLfun_g___8->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_g___8(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_g___8 = (_g___8*) malloc(sizeof(_g___8));
  MLfun_g___8->MAX = 1;
  MLfun_g___8->f = m->content.MLfun;
  MLfun_g___8->f->invoke = &(g___8_invoke);
  MLfun_g___8->invoke_real = &(g___8_invoke_real);
  m->content.MLfun = MLfun_g___8->f;

  return m;
}

MLvalue* f_g___8() {
  return new_MLfun_g___8(1);
}


// fin de la classe MLfun_g___8


/**
 *  de'claration de la fonction h___12
 *    vue comme la structure : MLfun_h___12
 */ 


typedef struct h___12 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* , MLvalue*);
} _h___12;

_h___12* MLfun_h___12;


  MLvalue* h___12_invoke_real(MLvalue* x___13, MLvalue* y___14) {

    { 
      MLvalue* T___15;
      MLvalue* T___16;
      T___15=x___13;
      T___16=y___14;
      return MLlist(T___15,T___16);
    }
  }

MLvalue* h___12_invoke(MLvalue* MLparam){
  if (MLfun_h___12->f->MLcounter == (MLfun_h___12->MAX-1)) {
    return h___12_invoke_real(MLfun_h___12->f->MLenv[0], MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_h___12->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(h___12_invoke);
    MLfun_h___12->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_h___12(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_h___12 = (_h___12*) malloc(sizeof(_h___12));
  MLfun_h___12->MAX = 2;
  MLfun_h___12->f = m->content.MLfun;
  MLfun_h___12->f->invoke = &(h___12_invoke);
  MLfun_h___12->invoke_real = &(h___12_invoke_real);
  m->content.MLfun = MLfun_h___12->f;

  return m;
}

MLvalue* f_h___12() {
  return new_MLfun_h___12(2);
}


// fin de la classe MLfun_h___12


/**
 *  de'claration de la fonction q___17
 *    vue comme la structure : MLfun_q___17
 */ 


typedef struct q___17 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* );
} _q___17;

_q___17* MLfun_q___17;


  MLvalue* q___17_invoke_real(MLvalue* x___18) {

    { 
      MLvalue* T___19;
      MLvalue* T___22;
      { 
        MLvalue* T___20;
        MLvalue* T___21;
        T___20=MLhd;
        T___21=x___18;
        T___19=T___20->content.MLfun->invoke(T___21);
      }
      { 
        MLvalue* T___23;
        MLvalue* T___24;
        T___23=MLtl;
        T___24=x___18;
        T___22=T___23->content.MLfun->invoke(T___24);
      }
      return MLpair(T___19,T___22);
    }
  }

MLvalue* q___17_invoke(MLvalue* MLparam){
  if (MLfun_q___17->f->MLcounter == (MLfun_q___17->MAX-1)) {
    return q___17_invoke_real(MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_q___17->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(q___17_invoke);
    MLfun_q___17->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_q___17(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_q___17 = (_q___17*) malloc(sizeof(_q___17));
  MLfun_q___17->MAX = 1;
  MLfun_q___17->f = m->content.MLfun;
  MLfun_q___17->f->invoke = &(q___17_invoke);
  MLfun_q___17->invoke_real = &(q___17_invoke_real);
  m->content.MLfun = MLfun_q___17->f;

  return m;
}

MLvalue* f_q___17() {
  return new_MLfun_q___17(1);
}


// fin de la classe MLfun_q___17


/**
 *  de'claration de la fonction v___25
 *    vue comme la structure : MLfun_v___25
 */ 


typedef struct v___25 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* );
} _v___25;

_v___25* MLfun_v___25;


  MLvalue* v___25_invoke_real(MLvalue* x___26) {

    return MLnil;
  }

MLvalue* v___25_invoke(MLvalue* MLparam){
  if (MLfun_v___25->f->MLcounter == (MLfun_v___25->MAX-1)) {
    return v___25_invoke_real(MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_v___25->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(v___25_invoke);
    MLfun_v___25->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_v___25(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_v___25 = (_v___25*) malloc(sizeof(_v___25));
  MLfun_v___25->MAX = 1;
  MLfun_v___25->f = m->content.MLfun;
  MLfun_v___25->f->invoke = &(v___25_invoke);
  MLfun_v___25->invoke_real = &(v___25_invoke_real);
  m->content.MLfun = MLfun_v___25->f;

  return m;
}

MLvalue* f_v___25() {
  return new_MLfun_v___25(1);
}


// fin de la classe MLfun_v___25


/**
 *  de'claration de la fonction w___27
 *    vue comme la structure : MLfun_w___27
 */ 


typedef struct w___27 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* , MLvalue*);
} _w___27;

_w___27* MLfun_w___27;


  MLvalue* w___27_invoke_real(MLvalue* l___28, MLvalue* x___29) {

    { 
      MLvalue* T___30;
      { 
        MLvalue* T___31;
        MLvalue* T___32;
        T___31=l___28;
        T___32=MLnil;
        T___30=MLequal(T___31,T___32);
      }
      if (T___30->content.MLbool)
        { 
          MLvalue* T___33;
          T___33=MLnil;
          return T___33;
        }
      else
        { 
          MLvalue* T___34;
          { 
            MLvalue* T___35;
            MLvalue* T___36;
            T___35=x___29;
            T___36=MLnil;
            T___34=MLlist(T___35,T___36);
          }
          return T___34;
        }
    }
  }

MLvalue* w___27_invoke(MLvalue* MLparam){
  if (MLfun_w___27->f->MLcounter == (MLfun_w___27->MAX-1)) {
    return w___27_invoke_real(MLfun_w___27->f->MLenv[0], MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_w___27->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(w___27_invoke);
    MLfun_w___27->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_w___27(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_w___27 = (_w___27*) malloc(sizeof(_w___27));
  MLfun_w___27->MAX = 2;
  MLfun_w___27->f = m->content.MLfun;
  MLfun_w___27->f->invoke = &(w___27_invoke);
  MLfun_w___27->invoke_real = &(w___27_invoke_real);
  m->content.MLfun = MLfun_w___27->f;

  return m;
}

MLvalue* f_w___27() {
  return new_MLfun_w___27(2);
}


// fin de la classe MLfun_w___27


/**
 *  de'claration de la fonction map___37
 *    vue comme la structure : MLfun_map___37
 */ 


typedef struct map___37 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* , MLvalue*);
} _map___37;

_map___37* MLfun_map___37;


  MLvalue* map___37_invoke_real(MLvalue* f___38, MLvalue* l___39) {

    { 
      MLvalue* T___40;
      { 
        MLvalue* T___41;
        MLvalue* T___42;
        T___41=f_null___1();
        T___42=l___39;
        T___40=T___41->content.MLfun->invoke(T___42);
      }
      if (T___40->content.MLbool)
        { 
          MLvalue* T___43;
          T___43=MLnil;
          return T___43;
        }
      else
        { 
          MLvalue* T___44;
          { 
            MLvalue* T___45;
            MLvalue* T___50;
            { 
              MLvalue* T___46;
              MLvalue* T___47;
              T___46=f___38;
              { 
                MLvalue* T___48;
                MLvalue* T___49;
                T___48=MLhd;
                T___49=l___39;
                T___47=T___48->content.MLfun->invoke(T___49);
              }
              T___45=T___46->content.MLfun->invoke(T___47);
            }
            { 
              MLvalue* T___51;
              MLvalue* T___54;
              { 
                MLvalue* T___52;
                MLvalue* T___53;
                T___52=f_map___37();
                T___53=f___38;
                T___51=T___52->content.MLfun->invoke(T___53);
              }
              { 
                MLvalue* T___55;
                MLvalue* T___56;
                T___55=MLtl;
                T___56=l___39;
                T___54=T___55->content.MLfun->invoke(T___56);
              }
              T___50=T___51->content.MLfun->invoke(T___54);
            }
            T___44=MLlist(T___45,T___50);
          }
          return T___44;
        }
    }
  }

MLvalue* map___37_invoke(MLvalue* MLparam){
  if (MLfun_map___37->f->MLcounter == (MLfun_map___37->MAX-1)) {
    return map___37_invoke_real(MLfun_map___37->f->MLenv[0], MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_map___37->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(map___37_invoke);
    MLfun_map___37->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_map___37(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_map___37 = (_map___37*) malloc(sizeof(_map___37));
  MLfun_map___37->MAX = 2;
  MLfun_map___37->f = m->content.MLfun;
  MLfun_map___37->f->invoke = &(map___37_invoke);
  MLfun_map___37->invoke_real = &(map___37_invoke_real);
  m->content.MLfun = MLfun_map___37->f;

  return m;
}

MLvalue* f_map___37() {
  return new_MLfun_map___37(2);
}


// fin de la classe MLfun_map___37


/**
 *  de'claration de la fonction iter___57
 *    vue comme la structure : MLfun_iter___57
 */ 


typedef struct iter___57 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* , MLvalue*);
} _iter___57;

_iter___57* MLfun_iter___57;


  MLvalue* iter___57_invoke_real(MLvalue* f___58, MLvalue* l___59) {

    { 
      MLvalue* T___60;
      { 
        MLvalue* T___61;
        MLvalue* T___62;
        T___61=f_null___1();
        T___62=l___59;
        T___60=T___61->content.MLfun->invoke(T___62);
      }
      if (T___60->content.MLbool)
        { 
          MLvalue* T___63;
          T___63=MLnil;
          return T___63;
        }
      else
        { 
          MLvalue* T___64;
          { 
            MLvalue* T___65;
            MLvalue* T___66;
            T___65=f_iter___57();
            { 
              MLvalue* T___67;
              MLvalue* T___68;
              T___67=f___58;
              { 
                MLvalue* T___69;
                MLvalue* T___70;
                T___69=MLtl;
                T___70=l___59;
                T___68=T___69->content.MLfun->invoke(T___70);
              }
              T___66=T___67->content.MLfun->invoke(T___68);
            }
            T___64=T___65->content.MLfun->invoke(T___66);
          }
          return T___64;
        }
    }
  }

MLvalue* iter___57_invoke(MLvalue* MLparam){
  if (MLfun_iter___57->f->MLcounter == (MLfun_iter___57->MAX-1)) {
    return iter___57_invoke_real(MLfun_iter___57->f->MLenv[0], MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_iter___57->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(iter___57_invoke);
    MLfun_iter___57->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_iter___57(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_iter___57 = (_iter___57*) malloc(sizeof(_iter___57));
  MLfun_iter___57->MAX = 2;
  MLfun_iter___57->f = m->content.MLfun;
  MLfun_iter___57->f->invoke = &(iter___57_invoke);
  MLfun_iter___57->invoke_real = &(iter___57_invoke_real);
  m->content.MLfun = MLfun_iter___57->f;

  return m;
}

MLvalue* f_iter___57() {
  return new_MLfun_iter___57(2);
}


// fin de la classe MLfun_iter___57


/**
 *  de'claration de la fonction inter___71
 *    vue comme la structure : MLfun_inter___71
 */ 


typedef struct inter___71 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* , MLvalue*);
} _inter___71;

_inter___71* MLfun_inter___71;


  MLvalue* inter___71_invoke_real(MLvalue* a___72, MLvalue* b___73) {

    { 
      MLvalue* T___74;
      { 
        MLvalue* T___75;
        MLvalue* T___76;
        T___75=a___72;
        T___76=b___73;
        T___74=MLgtint(T___75,T___76);
      }
      if (T___74->content.MLbool)
        { 
          MLvalue* T___77;
          T___77=MLnil;
          return T___77;
        }
      else
        { 
          MLvalue* T___78;
          { 
            MLvalue* T___79;
            MLvalue* T___80;
            T___79=a___72;
            { 
              MLvalue* T___81;
              MLvalue* T___86;
              { 
                MLvalue* T___82;
                MLvalue* T___83;
                T___82=f_inter___71();
                { 
                  MLvalue* T___84;
                  MLvalue* T___85;
                  T___84=a___72;
                  T___85=new_MLint(1);
                  T___83=MLaddint(T___84,T___85);
                }
                T___81=T___82->content.MLfun->invoke(T___83);
              }
              T___86=b___73;
              T___80=T___81->content.MLfun->invoke(T___86);
            }
            T___78=MLlist(T___79,T___80);
          }
          return T___78;
        }
    }
  }

MLvalue* inter___71_invoke(MLvalue* MLparam){
  if (MLfun_inter___71->f->MLcounter == (MLfun_inter___71->MAX-1)) {
    return inter___71_invoke_real(MLfun_inter___71->f->MLenv[0], MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_inter___71->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(inter___71_invoke);
    MLfun_inter___71->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_inter___71(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_inter___71 = (_inter___71*) malloc(sizeof(_inter___71));
  MLfun_inter___71->MAX = 2;
  MLfun_inter___71->f = m->content.MLfun;
  MLfun_inter___71->f->invoke = &(inter___71_invoke);
  MLfun_inter___71->invoke_real = &(inter___71_invoke_real);
  m->content.MLfun = MLfun_inter___71->f;

  return m;
}

MLvalue* f_inter___71() {
  return new_MLfun_inter___71(2);
}


// fin de la classe MLfun_inter___71


/**
 *  de'claration de la fonction mult___87
 *    vue comme la structure : MLfun_mult___87
 */ 


typedef struct mult___87 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* , MLvalue*);
} _mult___87;

_mult___87* MLfun_mult___87;


  MLvalue* mult___87_invoke_real(MLvalue* x___88, MLvalue* y___89) {

    { 
      MLvalue* T___90;
      MLvalue* T___91;
      T___90=x___88;
      T___91=y___89;
      return MLmulint(T___90,T___91);
    }
  }

MLvalue* mult___87_invoke(MLvalue* MLparam){
  if (MLfun_mult___87->f->MLcounter == (MLfun_mult___87->MAX-1)) {
    return mult___87_invoke_real(MLfun_mult___87->f->MLenv[0], MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_mult___87->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(mult___87_invoke);
    MLfun_mult___87->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_mult___87(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_mult___87 = (_mult___87*) malloc(sizeof(_mult___87));
  MLfun_mult___87->MAX = 2;
  MLfun_mult___87->f = m->content.MLfun;
  MLfun_mult___87->f->invoke = &(mult___87_invoke);
  MLfun_mult___87->invoke_real = &(mult___87_invoke_real);
  m->content.MLfun = MLfun_mult___87->f;

  return m;
}

MLvalue* f_mult___87() {
  return new_MLfun_mult___87(2);
}


// fin de la classe MLfun_mult___87


/**
 *  de'claration de la fonction umap___126
 *    vue comme la structure : MLfun_umap___126
 */ 


typedef struct umap___126 {
  MLFun *f;
  int MAX;

  MLvalue* (*invoke_real)(MLvalue* , MLvalue*);
} _umap___126;

_umap___126* MLfun_umap___126;


  MLvalue* umap___126_invoke_real(MLvalue* l___127, MLvalue* x___128) {

    { 
      MLvalue* T___129;
      { 
        MLvalue* T___130;
        MLvalue* T___131;
        T___130=f_null___1();
        T___131=l___127;
        T___129=T___130->content.MLfun->invoke(T___131);
      }
      if (T___129->content.MLbool)
        { 
          MLvalue* T___132;
          T___132=MLnil;
          return T___132;
        }
      else
        { 
          MLvalue* T___133;
          { 
            MLvalue* T___134;
            MLvalue* T___139;
            { 
              MLvalue* T___135;
              MLvalue* T___138;
              { 
                MLvalue* T___136;
                MLvalue* T___137;
                T___136=MLhd;
                T___137=l___127;
                T___135=T___136->content.MLfun->invoke(T___137);
              }
              T___138=x___128;
              T___134=T___135->content.MLfun->invoke(T___138);
            }
            { 
              MLvalue* T___140;
              MLvalue* T___145;
              { 
                MLvalue* T___141;
                MLvalue* T___142;
                T___141=f_umap___126();
                { 
                  MLvalue* T___143;
                  MLvalue* T___144;
                  T___143=MLtl;
                  T___144=l___127;
                  T___142=T___143->content.MLfun->invoke(T___144);
                }
                T___140=T___141->content.MLfun->invoke(T___142);
              }
              T___145=x___128;
              T___139=T___140->content.MLfun->invoke(T___145);
            }
            T___133=MLlist(T___134,T___139);
          }
          return T___133;
        }
    }
  }

MLvalue* umap___126_invoke(MLvalue* MLparam){
  if (MLfun_umap___126->f->MLcounter == (MLfun_umap___126->MAX-1)) {
    return umap___126_invoke_real(MLfun_umap___126->f->MLenv[0], MLparam);
  }
  else {
    MLvalue *m;
    m = new_MLfun(MLfun_umap___126->f->MLcounter+1);
    m = MLaddenv(m, m->content.MLfun->MLenv, MLparam);
    m->content.MLfun->invoke = &(umap___126_invoke);
    MLfun_umap___126->f = m->content.MLfun;
    return m;
  }
}

MLvalue* new_MLfun_umap___126(int n) {
  MLvalue *m = new_MLfun(n);

MLfun_umap___126 = (_umap___126*) malloc(sizeof(_umap___126));
  MLfun_umap___126->MAX = 2;
  MLfun_umap___126->f = m->content.MLfun;
  MLfun_umap___126->f->invoke = &(umap___126_invoke);
  MLfun_umap___126->invoke_real = &(umap___126_invoke_real);
  m->content.MLfun = MLfun_umap___126->f;

  return m;
}

MLvalue* f_umap___126() {
  return new_MLfun_umap___126(2);
}


// fin de la classe MLfun_umap___126
void init(){

  null___1= new_MLfun_null___1(1);
  g___8= new_MLfun_g___8(1);
  h___12= new_MLfun_h___12(2);
  q___17= new_MLfun_q___17(1);
  v___25= new_MLfun_v___25(1);
  w___27= new_MLfun_w___27(2);
  map___37= new_MLfun_map___37(2);
  iter___57= new_MLfun_iter___57(2);
  inter___71= new_MLfun_inter___71(2);
  mult___87= new_MLfun_mult___87(2);
  umap___126= new_MLfun_umap___126(2);
}


int main(int argc, char* argv[]) {

init_runtime();

init();

{ 
  MLvalue* T___93;
  MLvalue* T___96;
  { 
    MLvalue* T___94;
    MLvalue* T___95;
    T___94=f_inter___71();
    T___95=new_MLint(1);
    T___93=T___94->content.MLfun->invoke(T___95);
  }
  T___96=new_MLint(10);
  i___92=T___93->content.MLfun->invoke(T___96);
}
{ 
  MLvalue* bidon___97;
  bidon___97=MLlrp;
  bidon___97=MLprint(i___92);
}
{ 
  MLvalue* T___99;
  MLvalue* T___104;
  { 
    MLvalue* T___100;
    MLvalue* T___101;
    T___100=f_map___37();
    { 
      MLvalue* T___102;
      MLvalue* T___103;
      T___102=f_mult___87();
      T___103=new_MLint(5);
      T___101=T___102->content.MLfun->invoke(T___103);
    }
    T___99=T___100->content.MLfun->invoke(T___101);
  }
  T___104=i___92;
  l___98=T___99->content.MLfun->invoke(T___104);
}
{ 
  MLvalue* bidon___105;
  bidon___105=MLlrp;
  bidon___105=MLprint(l___98);
}
fd___106=f_map___37();
{ 
  MLvalue* bidon___107;
  bidon___107=MLlrp;
  bidon___107=MLprint(fd___106);
}
{ 
  MLvalue* T___109;
  MLvalue* T___110;
  T___109=f_map___37();
  { 
    MLvalue* T___111;
    MLvalue* T___112;
    T___111=f_mult___87();
    T___112=new_MLint(5);
    T___110=T___111->content.MLfun->invoke(T___112);
  }
  ig___108=T___109->content.MLfun->invoke(T___110);
}
{ 
  MLvalue* bidon___113;
  bidon___113=MLlrp;
  bidon___113=MLprint(ig___108);
}
{ 
  MLvalue* T___115;
  MLvalue* T___116;
  T___115=ig___108;
  T___116=l___98;
  bi___114=T___115->content.MLfun->invoke(T___116);
}
{ 
  MLvalue* bidon___117;
  bidon___117=MLlrp;
  bidon___117=MLprint(bi___114);
}
{ 
  MLvalue* T___119;
  MLvalue* T___120;
  T___119=f_map___37();
  T___120=f_mult___87();
  ik___118=T___119->content.MLfun->invoke(T___120);
}
{ 
  MLvalue* bidon___121;
  bidon___121=MLlrp;
  bidon___121=MLprint(ik___118);
}
{ 
  MLvalue* T___123;
  MLvalue* T___124;
  T___123=ik___118;
  T___124=i___92;
  b___122=T___123->content.MLfun->invoke(T___124);
}
{ 
  MLvalue* bidon___125;
  bidon___125=MLlrp;
  bidon___125=MLprint(b___122);
}
{ 
  MLvalue* T___147;
  MLvalue* T___150;
  { 
    MLvalue* T___148;
    MLvalue* T___149;
    T___148=f_umap___126();
    T___149=b___122;
    T___147=T___148->content.MLfun->invoke(T___149);
  }
  T___150=new_MLint(10);
  value___146=T___147->content.MLfun->invoke(T___150);
}
{ 
  MLvalue* bidon___151;
  bidon___151=MLlrp;
  bidon___151=MLprint(value___146);
}

return 0;
}

// fin du fichier ftest.c
