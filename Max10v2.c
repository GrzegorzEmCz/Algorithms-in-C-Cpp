#include<stdio.h>
#include <stdlib.h>

int main()  {

   int max;
   int* tab;
   int temp, gora, dol;
   int suma=0;

   printf("Podaj wielkosc tablicy: ");
   scanf("%d",&max);
   tab=(int*) malloc(max*sizeof(*tab));

   printf("\nPodaj zakres losowania:\nGórna granica - ");
   scanf("%d",&gora);
   printf("Dolna granica - ");
   scanf("%d",&dol);
   printf("\n");

   for(int i=0; i<max; i++)  {              //wypelnienie tablicy losowymi liczbami
      tab[i]=rand()%(gora-dol+1)+dol;
   }

   for(int i=0; i<max; i++) {               //wypisanie utworzonej tablicy
      printf("tab[%d]=%d\n",i,tab[i]);
   }

   for(int c=0;c<(max-1);c++)  {            //sortowanie babelkowe
      for(int d=0;d<(max-1-c);d++)  {
         if(tab[d]<tab[d+1]) {
            temp=tab[d];
            tab[d]=tab[d+1];
            tab[d+1]=temp;
         }
      }
   }

   printf("\n");

   for(int i=0; i<10; i++) {                 //wypisanie i policzenie sumy 10 najwyzszych elementow
      printf("tab[%d]=%d\n",i,tab[i]);
      suma+=tab[i];
   }
   printf("\nSuma 10 najwyzszych elementow wynosi: %d\n\n",suma);
   free(tab);
}
