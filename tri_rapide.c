#include "tri_rapide.h"
int sommet(const pile_t *p){

  if (p->tete != -1)
       return p->elts[p->tete];
  return 0;
}

void empiler(pile_t *p, int e){
 if(p->tete != PILE_TAILLE)
 {
  p->tete+=1;
  p->elts[p->tete]=e;
 }
}

/**
 * Dépile l'élément en tête de pile.
 * La pile ne doit pas être vide !
 * @param p	Pile à dépiler.
 */
void depiler(pile_t *p){
  if(p->tete  != -1)
       p->tete-=1;
}
bool pile_vide(const pile_t *p){
  if (p->tete==-1)
       return true;
  return false;
}

 void init_pile(pile_t *p){
  p->tete=-1;
}
void afficher_pile(const pile_t *p){
  int i;
  if (p->tete==-1);
  else
  {
    for (i=p->tete;i>=0;i--)
         printf("\n%d", p->elts[i]);
  }
  
}
int partitionner(int* T, int ind_premier, int ind_dernier){
  int ind_pivot = ind_premier ;
  int valPivot = T [ ind_pivot ];
  int j = ind_dernier ;
  while(ind_pivot<j){
       if (T[ind_pivot]>=T[ind_pivot+1]){
            T[ind_pivot]=T[ind_pivot+1];
            T[ind_pivot+1]=valPivot;
            ind_pivot++;}
      else{
        int val=T[j];
        T[j]=T[ind_pivot+1];
        T[ind_pivot+1]=val;
        j--;
      }
  }

  return ind_pivot;
}


void tri_rapide(int* T, int ind_premier, int ind_dernier){
  int ind_pivot;
  if(ind_premier < ind_dernier){
    ind_pivot = partitionner(T, ind_premier, ind_dernier);
    tri_rapide(T, ind_premier, ind_pivot-1);
    tri_rapide(T, ind_pivot+1, ind_dernier);
  }
}

void tri_rapide_iteratif(int* T, int taille){
  
   pile_t p;
   int ind_debut=0, ind_fin=taille-1, ind_pivot=0;
   init_pile(&p);
   empiler(&p,ind_debut); empiler(&p,ind_fin);
   while(!pile_vide(&p)){
        ind_fin=sommet(&p); depiler(&p);ind_debut=sommet(&p);
        depiler(&p); 
        ind_pivot=partitionner(T,ind_debut,ind_fin);
        printf("\npivot=%d\n",ind_pivot);
        if (ind_pivot-1-ind_debut>0){
          empiler(&p,ind_debut); empiler(&p,ind_pivot-1);
        }
        if(ind_fin-ind_pivot+1>0){
           empiler(&p,ind_pivot+1); empiler(&p,ind_fin);
        }  
      for(int k=0;k<15;k++)
          printf("%d ",T[k]);
   }
}


/*
int __attribute__((weak)) main(){
  A completer pour tester 
 return 0;
}
*/

int main(void)
{
  int T[] = {1,-9,5,4,3,2,-1,1,6,3,-6,-4,3,2,0};

  tri_rapide_iteratif(T,15);
  return 0;
}
