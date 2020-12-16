#include <stdio.h>
#include <math.h>

// Petla generujaca ciag A
long int CiagA(int n) {
    int a0=1;
    int a1=1;

    for(int i=0; i<n; ++i) {
        int tempA=a0+a1;
        a0=a1;
        a1=tempA;
    }
    return a0;
}

// Petla generujaca ciag B
long int CiagB(int n) {
    int b0=1;
    int b1=1;
    int b2=1;

    for(int i=0; i<n; ++i) {
        int tempB=b0+b1+b2;
        b0=b1;
        b1=b2;
        b2=tempB;
    }
    return b0;
}


int main() {

    int k;
    int n=0;
    int c0=0;

    // Okreslenie dlugosci ciagu
    printf("Podaj liczbę naturalną k do obliczenia k-tego wyrazu ciągu cn\n k:");
    scanf("%d",&k);

    //Drukowanie ciagu A
    for (int i = 0; i < k; i++) {
       printf("%ld,",CiagA(i));
    }
    printf("\n");

    //Drukowanie ciagu B
    for (int i = 0; i < k; i++) {
       printf("%ld,",CiagB(i));
    }
    printf("\n");


    // Generowanie i drukowanie ciagu C
    for(int m=0; m<k+3; m++){
       for(int i=0; i<k+3; i++) {
          if (CiagA(m)==CiagB(i) && CiagA(m)>c0 && CiagB(i)>c0 && n<k) {
             c0=CiagA(m);
             printf("%d,",c0);
             n++;
          }
          else if (CiagA(m)<CiagB(i) && CiagA(m)>c0 && CiagB(i)>c0 && n<k) {
             c0=CiagA(m);
             printf("%d,",c0);
             n++;
          }
          else if ( CiagA(m)>c0 && CiagB(i)>c0 && n<k)
          {
             c0=CiagB(i);
             printf("%d,",c0);
             n++;

          }
       }
    }
    printf("\n\n%d wyraz ciagu c0 wynosi: %d\n\n",k,c0);
}
