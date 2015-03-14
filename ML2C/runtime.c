#include "runtime.h"

/******************************************************************************/
/******************* Debut implementation des fonctions ***********************/
/******************************************************************************/

/******************************************************************************/
/********** Les methodes pour les deux pointeurs de fonction invoke ***********/
/******************************************************************************/

MLvalue* MLFun_invoke(MLvalue *x)
{
  return NULL;
}


MLvalue* MLPrimitive_invoke_hd(MLvalue *x)
{
  return MLhd_real(x);
}

MLvalue* MLPrimitive_invoke_tl(MLvalue *x)
{
  return MLtl_real(x);
}

MLvalue* MLPrimitive_invoke_fst(MLvalue *x)
{
  return MLfst_real(x);
}

MLvalue* MLPrimitive_invoke_snd(MLvalue *x)
{
  return MLsnd_real(x);
}

/******************************************************************************/
/************************* Instancier les objets ******************************/
/******************************************************************************/

MLvalue* new_MLunit()
{
  MLvalue *m;
  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLUNIT;
  m->content.MLunit = 0;
  return m;
}


MLvalue* new_MLint(int x)
{
  MLvalue *m;
  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLINT;
  m->content.MLint = x;
  return m;
}


MLvalue* new_MLbool(int a)
{
  if((a!=TRUE) && (a!=FALSE)){
    fprintf(stderr, "Erreur new_MLbool\n");
    fflush(stderr);
  }

  MLvalue *m;
  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLBOOL;
  m->content.MLbool = a;
  return m;
}


MLvalue* new_MLdouble(double a)
{
  MLvalue *m;
  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLDOUBLE;
  m->content.MLdouble = a;
  return m;
}


MLvalue* new_MLstring(char *s)
{
  MLvalue *m;
  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLSTRING;
  m->content.MLstring = strdup(s);
  return m;
}


MLvalue* new_MLpair(MLvalue *a, MLvalue *b)
{
  MLvalue *m;
  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLPAIR;
  m->content.MLpair = (MLPair*) malloc(sizeof(MLPair));
  m->content.MLpair->MLfst = a;
  m->content.MLpair->MLsnd = b;
  return m;
}


MLvalue* new_MLlist(MLvalue *a, MLvalue *b)
{
  MLvalue *m;
  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLLIST;
  m->content.MLlist = (MLList*) malloc(sizeof(MLList));

  if(a)
    m->content.MLlist->MLcar = a;
  else
    m->content.MLlist->MLcar = NULL;

  if(b && (b->type == MLLIST)  && b->content.MLlist)
    m->content.MLlist->MLcdr = b->content.MLlist;
  else
    m->content.MLlist->MLcdr = NULL;

  return m;
}


MLvalue* new_MLfun(int n)
{
  MLvalue *m;
  MLvalue **env = (MLvalue**) malloc(n*sizeof(MLvalue*));

  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLFUN;
  m->content.MLfun = (MLFun*) malloc(sizeof(MLFun));
  m->content.MLfun->name = NULL;
  m->content.MLfun->MLcounter = 0;
  m->content.MLfun->MLenv = env;
  m->content.MLfun->invoke = NULL;
  return m;
}


MLvalue* new_MLprimitive(char *n)
{
  MLvalue *m;

  m = (MLvalue*) malloc(sizeof(MLvalue));
  m->type = MLPRIMITIVE;
  m->content.MLfun = (MLFun*) malloc(sizeof(MLFun));
  m->content.MLfun->name = n;
  m->content.MLfun->MLenv = NULL;
  m->content.MLfun->invoke = NULL;
  return m;
}


MLvalue* MLaddenv(MLvalue *f, MLvalue **O_env, MLvalue *a)
{
  int i;

  for (i=0; i< f->content.MLfun->MLcounter; i++) {
    f->content.MLfun->MLenv[i] = O_env[i];
  }

  f->content.MLfun->MLenv[f->content.MLfun->MLcounter] =
    (MLvalue*) malloc(sizeof(MLvalue));
  f->content.MLfun->MLenv[f->content.MLfun->MLcounter]=a;
  (f->content.MLfun->MLcounter)++;

  return f;
}

/******************************************************************************/
/************************* arithmetique sur les entiers ***********************/
/******************************************************************************/

MLvalue* MLaddint(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLINT || y->type != MLINT)){
    fprintf(stderr, "MLaddint ERREUR\n");
    fflush(stderr);
  }

  MLvalue *ml;
  ml = (MLvalue*) malloc(sizeof(MLvalue));
  ml->type = MLINT;
  ml->content.MLint = x->content.MLint + y->content.MLint;
  return ml;
}


MLvalue* MLsubint(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLINT || y->type != MLINT)){
    fprintf(stderr, "MLsubint ERREUR\n");
    fflush(stderr);
  }

  MLvalue *ml;
  ml = (MLvalue*) malloc(sizeof(MLvalue));
  ml->type = MLINT;
  ml->content.MLint = x->content.MLint - y->content.MLint;
  return ml;
}


MLvalue* MLmulint(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLINT || y->type != MLINT)){
    fprintf(stderr, "MLmulint ERREUR\n");
    fflush(stderr);
  }

  MLvalue *ml;
  ml = (MLvalue*) malloc(sizeof(MLvalue));
  ml->type = MLINT;
  ml->content.MLint = x->content.MLint * y->content.MLint;
  return ml;
}


MLvalue* MLdivint(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLINT || y->type != MLINT)){
    fprintf(stderr, "MLdivint ERREUR\n");
    fflush(stderr);
  }

  MLvalue *ml;
  ml = (MLvalue*) malloc(sizeof(MLvalue));
  ml->type = MLINT;
  ml->content.MLint = x->content.MLint / y->content.MLint;
  return ml;
}

/******************************************************************************/
/**********************************fonction equal******************************/
/******************************************************************************/

MLvalue* MLequal(MLvalue *x, MLvalue *y)
{
  int i;
  MLvalue *m = new_MLbool(FALSE);
  MLvalue *a, *b, *c, *d;
  MLList *xtmp = NULL, *ytmp = NULL;

  if((!x) && (!y))
    return new_MLbool(TRUE);

  if((!x) || (!y))
    return new_MLbool(FALSE);

  if(x->type != y->type)
    return new_MLbool(FALSE);

  switch(x->type){
  case MLUNIT:
    return new_MLbool(TRUE);
  case MLBOOL:
    if((x->content.MLbool==TRUE && y->content.MLbool==TRUE) ||
       (x->content.MLbool==FALSE && y->content.MLbool==FALSE))
      return new_MLbool(TRUE);
    else
      return new_MLbool(FALSE);
  case MLINT:
    if(x->content.MLint == y->content.MLint)
      return new_MLbool(TRUE);
    else
      return new_MLbool(FALSE);
  case MLDOUBLE:
    if(x->content.MLdouble == y->content.MLdouble)
      return new_MLbool(TRUE);
    else
      return new_MLbool(FALSE);
  case MLSTRING:
    if(!strcmp(x->content.MLstring, y->content.MLstring))
      return new_MLbool(TRUE);
    else
      return new_MLbool(FALSE);
  case MLPAIR:
    if((!x->content.MLpair) || (!y->content.MLpair)){
      fprintf(stderr, "MLequal MLPAIR ERREUR\n");
      fflush(stderr);
    }

    a = MLequal(x->content.MLpair->MLfst, y->content.MLpair->MLfst);
    b = MLequal(x->content.MLpair->MLsnd, y->content.MLpair->MLsnd);
    return MLequal(a, b);
  case MLLIST:
    if((!x->content.MLlist) || (!y->content.MLlist)){
      fprintf(stderr, "MLequal MLLIST ERREUR\n");
      fflush(stderr);
    }

    a = MLequal(x->content.MLlist->MLcar, y->content.MLlist->MLcar);

    if(a->content.MLbool == FALSE)
      return new_MLbool(FALSE);

    /* On appel recursivement sur les elements suivants de la liste */
    xtmp = x->content.MLlist->MLcdr;
    ytmp = y->content.MLlist->MLcdr;

    if((!xtmp) && (!ytmp))
      return new_MLbool(TRUE);

    if((!xtmp) || (!ytmp))
      return new_MLbool(FALSE);

    c = (MLvalue*) malloc(sizeof(MLvalue));
    d = (MLvalue*) malloc(sizeof(MLvalue));

    c->type = MLLIST;
    d->type = MLLIST;

    c->content.MLlist = (MLList*) malloc(sizeof(MLList));
    d->content.MLlist = (MLList*) malloc(sizeof(MLList));

    while(xtmp && ytmp){
      c->content.MLlist->MLcar = xtmp->MLcar;
      d->content.MLlist->MLcar = ytmp->MLcar;
      c->content.MLlist->MLcdr = NULL;
      d->content.MLlist->MLcdr = NULL;

      /* appel recursif sur l'element suivant de la liste */
      b = MLequal(c, d);

      if(b->content.MLbool == FALSE)
	return new_MLbool(FALSE);

      xtmp = xtmp->MLcdr;
      ytmp = ytmp->MLcdr;
    }

    /* ici les deux doivent etre null sinon pas egaux */
    if(xtmp || ytmp)
      return new_MLbool(FALSE);

    return new_MLbool(TRUE);
  case MLFUN:
    if((!x->content.MLfun) || (!y->content.MLfun)){
      fprintf(stderr, "MLequal MLFUN ERREUR\n");
      fflush(stderr);
    }

    if(x->content.MLfun->MLcounter != y->content.MLfun->MLcounter)
      return new_MLbool(FALSE);

    /* on aurait pu prendre comme taille le MLcounter de y meme taille */
    for(i=0; i<x->content.MLfun->MLcounter; i++){
      a = x->content.MLfun->MLenv[i];
      b = y->content.MLfun->MLenv[i];

      c = MLequal(a, b);

      if(c->content.MLbool == FALSE)
	return new_MLbool(FALSE);
    }

    if(x->content.MLfun->invoke && y->content.MLfun->invoke
       && (x->content.MLfun->invoke == y->content.MLfun->invoke))
      return new_MLbool(TRUE);
    else
      return new_MLbool(FALSE);
  case MLPRIMITIVE:
    if((!x->content.MLfun) || (!y->content.MLfun)){
      fprintf(stderr, "MLequal MLPRIMITIVE ERREUR\n");
      fflush(stderr);
    }

    if(strcmp(x->content.MLfun->name, y->content.MLfun->name))
      return new_MLbool(FALSE);

    if(x->content.MLfun->invoke != y->content.MLfun->invoke)
      return new_MLbool(FALSE);

    return new_MLbool(TRUE);
  default:
    fprintf(stderr, "MLequal Type non reconnu\n");
    fflush(stderr);
    break;
  }

  return m;
}

/******************************************************************************/
/**************************** inegalites sur les entiers **********************/
/******************************************************************************/

MLvalue* MLltint(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLINT || y->type != MLINT)){
    fprintf(stderr, "MLltint ERREUR\n");
    fflush(stderr);
  }

  return (x->content.MLint < y->content.MLint) ? new_MLbool(TRUE) : new_MLbool(FALSE);
}


MLvalue* MLleint(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLINT || y->type != MLINT)){
    fprintf(stderr, "MLleint ERREUR\n");
    fflush(stderr);
  }

  return (x->content.MLint <= y->content.MLint) ? new_MLbool(TRUE) : new_MLbool(FALSE);
}


MLvalue* MLgtint(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLINT || y->type != MLINT)){
    fprintf(stderr, "MLgtint ERREUR\n");
    fflush(stderr);
  }

  return (x->content.MLint > y->content.MLint) ? new_MLbool(TRUE) : new_MLbool(FALSE);
}


MLvalue* MLgeint(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLINT || y->type != MLINT)){
    fprintf(stderr, "MLgeint ERREUR\n");
    fflush(stderr);
  }

  return (x->content.MLint >= y->content.MLint) ? new_MLbool(TRUE) : new_MLbool(FALSE);
}


/* paire */
MLvalue* MLpair(MLvalue *x, MLvalue *y)
{
  return new_MLpair(x,y);
}


/* liste */
MLvalue* MLlist(MLvalue *x, MLvalue *y)
{
  return new_MLlist(x,y);
}


MLvalue* MLconcat(MLvalue *x, MLvalue *y)
{
  if((!x && !y) || (x->type != MLSTRING || y->type != MLSTRING)){
    fprintf(stderr, "MLconcat ERREUR\n");
    fflush(stderr);
  }

  MLvalue *s;
  char string[strlen(x->content.MLstring)+strlen(y->content.MLstring)];

  strcat(string,x->content.MLstring);
  strcat(string,y->content.MLstring);
  s = new_MLstring(string);
  return s;
}


/* acces aux champs des paires */
MLvalue* MLfst_real(MLvalue *p)
{
  return p->content.MLpair->MLfst;
}


MLvalue* MLsnd_real(MLvalue *p)
{
  return p->content.MLpair->MLsnd;
}

/******************************************************************************/
/***************************** acces aux champs des listes ********************/
/******************************************************************************/

MLvalue* MLhd_real(MLvalue *l)
{
  return l->content.MLlist->MLcar;
}


MLvalue* MLtl_real(MLvalue *l)
{
  MLvalue *m;
  m = (MLvalue*)malloc(sizeof(MLvalue));
  m->type = MLLIST;
  m->content.MLlist = l->content.MLlist->MLcdr;
  return m;
}

/******************************************************************************/
/*************************** la fonction d'affichage **************************/
/******************************************************************************/

MLvalue* MLprint(MLvalue *x)
{
  int i;
  MLvalue *a;
  MLList *tmp = NULL;

  if(!x){
    fprintf(stderr, "MLprint ERREUR\n");
    fflush(stderr);
  }

  switch(x->type){
  case MLUNIT:
    printf("()\n");
    break;
  case MLBOOL:
    if(x->content.MLbool)
      printf("true\n");
    else
      printf("false\n");

    break;
  case MLINT:
    printf("%d", x->content.MLint);
    break;
  case MLDOUBLE:
    printf("%f", x->content.MLdouble);
    break;
  case MLSTRING:
    printf("\\%s\\\n", x->content.MLstring);
    break;
  case MLPAIR:
    if(!x->content.MLpair){
      fprintf(stderr, "MLprint MLPAIR ERREUR\n");
      fflush(stderr);
    }

    printf("(");
    MLprint(x->content.MLpair->MLfst);
    printf(",");
    MLprint(x->content.MLpair->MLsnd);
    printf(")\n");

    break;
  case MLLIST:
    if(!x->content.MLlist){
      fprintf(stderr, "MLprint MLLIST ERREUR\n");
      fflush(stderr);
    }

    if(!x->content.MLlist->MLcar)
      printf("[]\n");
    else{
     MLprint(x->content.MLlist->MLcar);
     printf("::");
     fflush(stdout);

     /* On appel recursivement sur les elements suivants de la liste */
     tmp = x->content.MLlist->MLcdr;
     a = (MLvalue*) malloc(sizeof(MLvalue));
     a->type = MLLIST;
     a->content.MLlist = (MLList*) malloc(sizeof(MLList));

     while(tmp){
       a->content.MLlist->MLcar = tmp->MLcar;
       a->content.MLlist->MLcdr = NULL;
       MLprint(a);
       tmp = tmp->MLcdr;
     }
    }

    break;
  case MLFUN:
    if(!x->content.MLfun){
      fprintf(stderr, "MLprint MLFUN ERREUR\n");
      fflush(stderr);
    }

    printf("<fun> [");

    a = (MLvalue*) malloc(sizeof(MLvalue));

    for(i=0; i<x->content.MLfun->MLcounter; i++){
      a = x->content.MLfun->MLenv[i];
      MLprint(a);
    }

    printf("]\n");

    break;
  case MLPRIMITIVE:
    if(!x->content.MLfun){
      fprintf(stderr, "MLprint MLPRIMITIVE ERREUR\n");
      fflush(stderr);
    }

    printf("MLprimitive:\n");
    printf("name = %s\n", x->content.MLfun->name);
    break;
  default:
    fprintf(stderr, "Type non reconnu !!\n");
    fflush(stderr);
    break;
  }

  fflush(stdout);
  return MLlrp;
}


void init_runtime(){
  MLList *list;
  MLvalue *m;
  MLFun *fstprimitive, *sndprimitive, *hdprimitive, *tlprimitive;

  m = new_MLlist(NULL, NULL);
  list = m->content.MLlist;
  m = new_MLprimitive("fst");
  fstprimitive = m->content.MLfun;
  m = new_MLprimitive("snd");
  sndprimitive = m->content.MLfun;
  m = new_MLprimitive("hd");
  hdprimitive = m->content.MLfun;
  m = new_MLprimitive("tl");
  tlprimitive = m->content.MLfun;

  MLtrue = new_MLbool(TRUE);
  MLfalse = new_MLbool(FALSE);
  MLlrp = new_MLunit();

  MLnil = (MLvalue*) malloc(sizeof(MLvalue));
  MLfst = (MLvalue*) malloc(sizeof(MLvalue));
  MLsnd = (MLvalue*) malloc(sizeof(MLvalue));
  MLhd = (MLvalue*) malloc(sizeof(MLvalue));
  MLtl = (MLvalue*) malloc(sizeof(MLvalue));


  MLnil->type   = MLLIST;
  MLfst->type   = MLPRIMITIVE;
  MLsnd->type   = MLPRIMITIVE;
  MLhd->type    = MLPRIMITIVE;
  MLtl->type    = MLPRIMITIVE;

  fstprimitive->invoke = &MLPrimitive_invoke_fst;
  sndprimitive->invoke = &MLPrimitive_invoke_snd;
  hdprimitive->invoke = &MLPrimitive_invoke_hd;
  tlprimitive->invoke = &MLPrimitive_invoke_tl;

  MLnil->content.MLlist = list;

  fflush(stdout);

  MLfst->content.MLfun = fstprimitive;
  MLsnd->content.MLfun = sndprimitive;
  MLhd->content.MLfun = hdprimitive;
  MLtl->content.MLfun = tlprimitive;
}
