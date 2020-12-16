#include <stdio.h>

int lp(int a)
{
  for (int i = 2; i*i<a; i++)
  {
    if (a%i==0)
       return 0;
    else
       return 1;
  }

}

int main()
{
 int v=0;
 printf("PODAJ LICZBĘ: ");
 scanf("%d",&v);
 if(lp(v)==0)
 {
   printf("LICZBA %i NIE JEST LICZBĄ PIERWSZĄ\n",v);
 }
 else
 {
   printf("LICZBA %i JEST LICZBĄ PIERWSZĄ\n",v);
 }
 return 0;
}
