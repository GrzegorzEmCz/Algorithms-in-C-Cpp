#include <stdio.h>


int main() {

    int k;

    printf("Podaj liczbę naturalną k do obliczenia k-tego wyrazu ciągu cn\n k:");
    scanf("%d",&k);

    int An[k];

    An[0]=1;
    An[1]=1;

    for (int i=2; i<k; i++) {
        An[i]=An[i-1]+An[i-2];
    }


    for (int i = 0; i < k; i++) {
       printf("%d,",An[i]);
    }

  }
