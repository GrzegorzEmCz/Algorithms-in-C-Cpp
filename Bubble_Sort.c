#include <stdio.h>

int main()
{
   int array[100],n,swap;
   printf("Wrowadź wielkość tablicy do posortowania\n");
   scanf("%d",&n);
   printf("wprowadź %d liczb\n",n);
   for(int c=0;c<n;c++)
      {
      scanf("%d",&array[c]);
      }

   for(int c=0;c<(n-1);c++)
      {
      for(int d=0;d<n-c-1;d++)
         {
         if(array[d]>array[d+1])
            {
            swap=array[d];
            array[d]=array[d+1];
            array[d+1]=swap;
            }
         }
      }
   printf("Posortowana lista w porządku rosnącym wyglada:\n");
   for(int c=0;c<n;c++)
      {
      printf("%d ,",array[c]);
      }
   printf("\n");
}
