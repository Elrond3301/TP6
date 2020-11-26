#include "pile.h"
#include <stdio.h>
#include <assert.h>

typedef struct pile_t {
    int elts[PILE_TAILLE];
    int tete;
} pile_t;
/**
 * Crée une pile vide.
 * @param p	Pile à initializer.
 */
 void init_pile(pile_t *p){
  p->tete=-1;
}

/**
 * Empile un élément dans la pile.
 * La pile ne doit pas être pleine.
 * @param p		Pile où empiler.
 * @param e		Elément à empiler.
 */
void empiler(pile_t *p, int e){
 if(p->tete  != PILE_TAILLE)
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

/* ----------------------------------
            Accesseurs
   --------------------------------*/

/**
 * Récupère le sommet de pile.
 * La pile ne doit pas être vide !
 * @param p		Pile à accéder.
 * @return		Elément en tête de pile.
 */

int sommet(const pile_t *p){

  if (p->tete != -1)
       return p->elts[p->tete];
  return 0;
}
/**
 * Teste si la pile est vide.
 * @param p		Pile à tester.
 * @return		TRUE si la pile est vide, FALSE sinon.
 */
bool pile_vide(const pile_t *p){
  if (p->tete==-1)
       return true;
  return false;
}
 
/**
 * Test si la pile est elle pleine.
 * @param p		Pile à etster.
 * @return		TRUE si la pile est pleine, FALSE sinon.
 */
bool pile_pleine(const pile_t *p){
  if (p->tete==PILE_TAILLE-1)
       return true;
  return false;
}

/**
 *  Affiche le contenu de la pile sur la stortie standard.
 * @param p		Pile à afficher.
 */
void afficher_pile(const pile_t *p){
  int i;
  if (p->tete==-1)
       printf("\nLa pile est vide !");
  else
  {
    for (i=p->tete;i>=0;i--)
         printf("\n%d", p->elts[i]);
  }
  
}
