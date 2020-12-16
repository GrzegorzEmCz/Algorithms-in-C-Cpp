#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int size=50;

int getMaxEl(int arr[]){
   static int i=0;
   static int max=-9999;

   if(i<size){
      if(max<arr[i]){
         max=arr[i];
      }
      i++;
      getMaxEl(arr);
   }
   return max;

}

int main()  {


   int arr[size], max;

   for(int i=0; i<size; i++)  {
      arr[i]=rand()%10000;
   }

   for(int i=0; i<size; i++) {
      printf("tab[%d]=%d\n",i,arr[i]);
   }

  max=getMaxEl(arr);
  printf("najwieksza wartość to %d",max);
}
