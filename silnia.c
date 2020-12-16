#include <stdio.h>

int obliczS(int x) {
  if(x>1)
    return x*obliczS(x-1);
  else {
    return 1;
  }
}

int main()  {

  int n;
  int s;

  printf("Podaj wartość n do onliczenia silni:\nn - ");
  scanf("%d",&n);

  s=obliczS(n);

  printf("Suma z %d liczb wynosi: %d\n",n,s);
}
