#include<stdio.h>
#include<stdlib.h>

int main()
{
  char a[10]={0};
  char b[10]={0};
  char c[10]={0};
  int wybor;
  float x, y, wynik;

  printf("\nPodaj pierwszą liczbę i potwierdź klawiszem Enter:");
  gets(a);  //coś jak scanf
  x=atof(a); // zamaiana znaków na liczbę typ double
  printf("\nPodaj drugą liczbę i potwierdź klawiszem Enter:");
  gets(b);
  y=atof(b);

  do
  {
     printf("\nWybierz rodzaj działania: \n 1-dodawanie\n 2-odejmowanie\n 3-mnożenie\n 4-dzielenie\n:");
     gets(c);
     wybor=atoi(c); // zamaiana znaków na liczbę typ integr
     if(wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4) {
        printf("\n\nNie podałeś liczby z zakresu 1-4\n\n");
        continue;
        }
     else {
        switch (wybor) {
          case 1:
             wynik=x+y;
             break;
          case 2:
             wynik=x-y;
             break;
          case 3:
             wynik=x*y;
             break;
          case 4:
             wynik=x/y;
             break;
          default:
             wynik=x+y;
             break;
            }
        break;
        }
  } while(1);
  printf("\nWynik działania wynosi: %f.",wynik);
}
