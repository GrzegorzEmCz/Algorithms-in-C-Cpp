#include<stdio.h>
#include <stdlib.h>

int main()  {

   int max=50;
   unsigned int tab[max];
   int temp;
   int suma=0;

   for(int i=0; i<max; i++)  {
      tab[i]=rand()%10000;                               /* %(35-18+1)+18; to jest z przedzialu 18-35*/
   }

   for(int i=0; i<max; i++) {
      printf("tab[%d]=%d\n",i,tab[i]);
   }

   for(int c=0;c<(max-1);c++)  {
      for(int d=0;d<(max-1-c);d++)  {
         if(tab[d]<tab[d+1]) {
            temp=tab[d];
            tab[d]=tab[d+1];
            tab[d+1]=temp;
         }
      }
   }

   printf("\n");

   for(int i=0; i<10; i++) {
      printf("tab[%d]=%d\n",i,tab[i]);
      suma+=tab[i];
   }
   printf("\nSuma 10 najwyzszych elementow wynosi: %d\n\n",suma);
}
