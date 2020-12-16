#include<stdio.h>
#include<math.h>

int main()
{
   int zakres, doklad;
   int tablica[10000];
   printf("Podaj górny zakres, do którego chcesz odnaleźć liczby pierwsze\n");
   scanf("%d",&zakres);
   doklad=floor(sqrt(zakres));
   //inicjuje tablice
   for(int i=1;i<=zakres;i++)
      {
        tablica[i]=1;
      }
   //algorytm główny - sito Eratostenesa
   for(int i=2;i<=doklad;i++)
      {
      if(tablica[i]!=0)
         {
         int j=i+i;
         while(j<=zakres)
            {
            tablica[j]=0;
            j+=i;
            }
         }
      }
   printf("Liczby pierwsze z zakresu od 1 do %d\n",zakres);
   for(int i=2;i<=zakres;i++)
      {
      if(tablica[i]!=0)
         {
         printf("%d, ",i);
         }
      }
  printf("\n");
  }
