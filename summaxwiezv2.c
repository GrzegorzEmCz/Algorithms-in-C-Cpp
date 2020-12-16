#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

//funkcja obliczajaca sume wierszy i kolumn

int sum(int i, int j, int szach[i][j], int pozi, int pozj){

   int sum=0;

   for (int k=0; k<i; k++) {
      for(int l=0; l<j; l++)  {
         if ((k==pozi) || (l==pozj)) {
            sum+=szach[k][l];
         }
      }
   }
   sum-=szach[pozi][pozj];
   return sum;
}

int main() {

   int szach[8][8];
   int suma[8][8];
   int i=ROWS;
   int j=COLS;
   int r,t;

   //petla generujaca macierz[8][8] np. jako wartosc przyjeto sume pozycji wiersza i kolumny
   for (int n=0; n<i; n++) {
      for (int m=0; m<j; m++) {
         szach[n][m]=rand()%1000;
      }
   }

   //petla wpisująca sumy w komorki macierzy suma
   for (int n=0; n<i; n++) {
      for (int m=0; m<j; m++) {
         suma[n][m]=sum(i,j,szach,n,m);
      }
   }

   //petla drukujaca tablicę szachownica
   printf("Tablica SZACHOWNICA ma kolejno wartości:\n");
   for (int n=0; n<i; n++) {
      for (int m=0; m<j; m++) {
         printf("[%d][%d]=%d |",n,m,szach[n][m]);
      }
      printf("\n");
   }

   //petla drukujaca tablicę suma
   printf("Tablica SUMA ma kolejno wartości:\n");
   for (int n=0; n<i; n++) {
      for (int m=0; m<j; m++) {
         printf("[%d][%d]=%d |",n,m,suma[n][m]);
      }
      printf("\n");
   }

   //petla szukająca maksymalną wartosc
   int max=suma[0][0];
   for (int n=0; n<i; n++) {
      for (int m=0; m<j; m++) {
        if (suma[n][m] > max)  {
           max = suma[n][m];
           r=n;
           t=m;
        }
      }
   }
   printf("Wierza w polozeniu %d - wiersz i %d - kolumna daje najwieksza wartosc ktora wynosi %d\n",r,t,max);
}
