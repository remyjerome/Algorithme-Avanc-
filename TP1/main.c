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
void triRapide(int * tab, int p, int q);
int partitionner(int * tab, int p,int q);

int main(int argc, const char * argv[]) {

    int tab[] = {7,2,1,8,4,9,0,3,5,6};
    //afficheTableau(tab, 10);
    //triFusion(tab, 0, 9);
    //quickSort(tab, 0, 9);
    triRapide(tab, 0, 9);
    afficheTableau(tab, 10);
    return 0;
}

void afficheTableau(int * tab, int taille)
{
    int i;
    for(i=0;i<taille;i++)
    {
        printf("tab[%d]=%d,",i,tab[i]);
    }
    printf("\n");
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

void quickSort(int * tableau, int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];
    

    if(debut >= fin)
        return;

    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);
        
        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }
    

    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

void triRapide(int * tab, int p, int q)
{
    int r=0;
    if (p < q)
    {
        r = partitionner(tab, p, q);
        triRapide(tab, p, r);
        triRapide(tab, r+1, q);
    }
}
int partitionner(int * tab, int p,int q)
{
    int clef = tab[p];
    int i = p-1;
    int j = q+1;
    while (1)
    {
        do
        {
            j --;
        }while (tab[j]>clef);
        do
        {
            i ++;
        }while (tab[i]<clef);
        if(i<j)
        {
            echanger(tab, i, j);
        }
        else
        {
            return j;
        }
    }
}


