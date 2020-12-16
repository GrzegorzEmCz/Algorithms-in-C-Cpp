#include <stdio.h>

int main()
{
  int a1=1;
  int a2=2;
  int b1=1;
  int b2=3;
  int b3=5;
  int k;

  printf("Podaj liczbę naturalną k do obliczenia k-tego wyrazu ciągu cn\n k:");
  scanf("%d",&k);

   for(int i=0;i<k;++i)
  {
        for(int i=0;i<k;++i)
        {
            if(a1==b1 || a1<k)
               {
               printf("%d ,",a1);
               int temp=a1;
               a1=a2;
               a2=a2+temp;
               break;
               }
            if(a1<b1 || a1<k)
               {
               printf("%d ,",a1);
               }
            if(b1<a1 || b1<k)
            {
              printf("%d ,",b1);
              break;
            }
            int temp=a1;
            a1=a2;
            a2=a2+temp;
        }
        int temp=b1;
        int temp2=b2;
        b1=b2;
        b2=b3;
        b3=temp+temp2+b3;
  }


  return 0;
}
