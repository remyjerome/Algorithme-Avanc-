//
//  main.c
//  TP1
//
//  Created by remy on 09/02/2016.
//  Copyright © 2016 remy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


void afficheTableau(int * tab, int taille);
void triFusion(int * tab,int p,int q);
void fusionTableau(int * tab,int p,int q,int r);
void quickSort(int * tableau, int debut, int fin);
void echanger(int tableau[], int a, int b);

int main(int argc, const char * argv[]) {

    int tab[] = {7,2,1,8,4,9,0,3,5,6};
    //afficheTableau(tab, 10);
    //triFusion(tab, 0, 9);
    quickSort(tab, 0, 9);
    afficheTableau(tab, 10);
    return 0;
}

void afficheTableau(int * tab, int taille)
{
    int i;
    for(i=0;i<taille;i++)
    {
        printf("tab[%d]=%d\n",i,tab[i]);
    }
}

void triFusion(int * tab,int p,int q)
{
    
    if (p<q)
    {
        int r = (p+q)/2;
        triFusion(tab,p,r);
        triFusion(tab,r+1,q);
        fusionTableau(tab,p,q,r);
    }
}

void fusionTableau(int * tab,int p,int q,int r)
{
    int * tabTemp;           //tableau temporaire permettant de fusioner en triant deux tableaux
    //int tabTemp1[q-p+1];
    int i;
    int compt1 = p;         //debut premier tableau
    int compt2 = r + 1;     //debut second tableau
    
    tabTemp = malloc((q-p+1)*sizeof(int));
    
    for (i=p; i<=r; i++)
    {
        tabTemp[i - p] = tab[i];
        //printf("%d  /  %d",tabTemp1[i - p], tab[i] );
    }
    
    for (i=p; i<=q; i++)
    {
        if (compt1 == r + 1)
        {
            break;
        }
        else if (compt2 == q+1)
        {
            tab[i] = tabTemp[compt1 - p];
            compt1++;
        }
        else if (tabTemp[compt1-p]<tab[compt2])
        {
            tab[i] = tabTemp[compt1 -p];
            compt1++;
        }
        else
        {
            tab[i] = tab[compt2];
            compt2++;
        }
    }
}

void echanger(int tableau[], int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}
//Code openclassroom
void quickSort(int * tableau, int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];
    
    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;
    
    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
     autre de gauche à droite, à la recherche d'éléments mal placés,
     que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);
        
        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }
    
    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
     supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
     pour cela... la méthode quickSort elle-même ! */
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

