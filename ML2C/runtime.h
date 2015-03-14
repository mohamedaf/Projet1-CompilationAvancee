#ifndef __RUNTIME_H__
#define __RUNTIME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* pour le type boolean */

#define FALSE 0
#define TRUE 1

/* les differents types pour un MLvalue */

#define MLUNIT 2
#define MLBOOL 3
#define MLINT 4
#define MLDOUBLE 5
#define MLSTRING 6
#define MLPAIR 7
#define MLLIST 8
#define MLFUN 9
#define MLPRIMITIVE 10

/******************************************************************************/
/********************** Declaration de la strcuture de base *******************/
/******************************************************************************/

typedef struct _MLPair MLPair;
typedef struct _MLList MLList;
typedef struct _MLFun  MLFun;
typedef struct _Mlvalue MLvalue;

struct _MLPair {
  MLvalue *MLfst;
  MLvalue *MLsnd;
};

struct _MLList {
  MLvalue *MLcar;
  MLList *MLcdr;
};

/* peut etre MLprimitive si name donnee et invoke */
struct _MLFun {
  char* name;
  int MLcounter;
  MLvalue **MLenv;
  MLvalue* (*invoke)(MLvalue*);
};

struct _Mlvalue
{
  int type;

  union {
    int MLunit;
    int MLbool;
    int MLint;
    double MLdouble;
    char* MLstring;
    MLPair* MLpair;
    MLList* MLlist;
    MLFun* MLfun;
  } content;
};

/******************************************************************************/
/*************** Declaration des variables globales publiques *****************/
/******************************************************************************/

/* booleens */
MLvalue *MLtrue, *MLfalse;

/* unit */
MLvalue *MLlrp;

/* nil */
MLvalue *MLnil;

/* acces aux champs des paires */
MLvalue *MLfst, *MLsnd;

/* acces aux champs des listes */
MLvalue *MLhd, *MLtl;

/******************************************************************************/
/***************************** Declaration des fonctions **********************/
/******************************************************************************/

/* Les methodes pour les deux pointeurs de fonction invoke */

MLvalue* MLFun_invoke(MLvalue *x);
MLvalue* MLPrimitive_invoke_hd(MLvalue *x);
MLvalue* MLPrimitive_invoke_tl(MLvalue *x);
MLvalue* MLPrimitive_invoke_fst(MLvalue *x);
MLvalue* MLPrimitive_invoke_snd(MLvalue *x);

/* Instancier les objets */
MLvalue* new_MLunit();
MLvalue* new_MLint(int x);
MLvalue* new_MLbool(int a);
MLvalue* new_MLdouble(double a);
MLvalue* new_MLstring(char *s);
MLvalue* new_MLpair(MLvalue *a, MLvalue *b);
MLvalue* new_MLlist(MLvalue *a, MLvalue *b);
MLvalue* new_MLfun(int n);
MLvalue* new_MLprimitive(char *n);

MLvalue* MLaddenv(MLvalue *f, MLvalue **O_env, MLvalue *a);

/* arithmetique sur les entiers */
MLvalue* MLaddint(MLvalue *x, MLvalue *y);
MLvalue* MLsubint(MLvalue *x, MLvalue *y);
MLvalue* MLmulint(MLvalue *x, MLvalue *y);
MLvalue* MLdivint(MLvalue *x, MLvalue *y);

/*fonction equal*/
MLvalue* MLequal(MLvalue *x, MLvalue *y);

/* inegalites sur les entiers */
MLvalue* MLltint(MLvalue *x, MLvalue *y);
MLvalue* MLleint(MLvalue *x, MLvalue *y);
MLvalue* MLgtint(MLvalue *x, MLvalue *y);
MLvalue* MLgeint(MLvalue *x, MLvalue *y);

/* paire */
MLvalue* MLpair(MLvalue *x, MLvalue *y);

/* liste */
MLvalue* MLlist(MLvalue *x, MLvalue *y);
MLvalue* MLconcat(MLvalue *x, MLvalue *y);

/* acces aux champs des paires */
MLvalue* MLfst_real(MLvalue *p);
MLvalue* MLsnd_real(MLvalue *p);

/* acces aux champs des listes */
MLvalue* MLhd_real(MLvalue *l);
MLvalue* MLtl_real(MLvalue *l);

/* la fonction d'affichage */
MLvalue* MLprint(MLvalue *x);

/* fonction ou on initialise les variables globales */
void init_runtime();

#endif
