//Grzegorz Czernecki
#include <iostream>

using namespace std;

const int N=6;

// złożoność jak dla Quicksortu czyli n*log(n) - do złożoności dochodzą dwie stałe 10 i wielkość liczby

void pretty_sort(int T[], int N) {

  bool swapped=true;
  int top,gap;

  gap=N;
  while(gap>1 || swapped == true) {
    gap=max(int(gap/1.3),1);
    top=N-1-gap;
    swapped=false;
    for(int i=0; i<=top; i++) {
      int j=i+gap;
      int ctrTi=0,rTi=0,lTi1=0,lTiW=0;              // zmienne dla wyrażenia T[i] do określenia ilości cyfr jedno i wielokrotnych
      int ctrTj=0,rTj=0,lTj1=0,lTjW=0;              // zmienne dla wyrażenia T[i] do określenia ilości cyfr jedno i wielokrotnych

      for(int l=0; l<10;l++) {    //pętla zliczająca poszczególne cyfry w liczbach T[i] i T[j]
          ctrTi=0;                                  //zerownie licznika dla liczby T[i]
          for (int k = T[i]; k > 0; k = k / 10) {   //pętla przechodzaca przez poszczególne pozycje(jedności, dziesiątki itp.) w liczbie
              rTi = k % 10;
              if (rTi == l) ctrTi++;
          }
          if(ctrTi==1) lTi1++;                     // warunek zlizający ilość cyfr jednokrotnych dla T[i]
          if(ctrTi>1) lTiW++;                      // warunek zlizający ilość cyfr wielokrotnych dla T[i]

          ctrTj=0;                                 //zerowanie licznika dla liczby T[j]
          for (int k = T[j]; k > 0; k = k / 10) {   //pętla przechodzaca przez poszczególne pozycje(jedności, dziesiątki itp.) w liczbie
              rTj = k % 10;
              if (rTj == l) ctrTj++;
          }
          if(ctrTj==1) lTj1++;                     // warunek zlizający ilość cyfr jednokrotnych dla T[j]
          if(ctrTj>1) lTjW++;                      // warunek zlizający ilość cyfr wielokrotnych dla T[j]
      }
          if((lTi1>lTj1) || ((lTi1==lTj1)&&(lTiW>lTjW))) {  //warunek sortujący najpierw sortuje po cyfrach jednokrotnych jeżeli ilość ich jest taka samo to wtedy sortuje po cyfrach wielokrotnych
             int temp=T[i];
             T[i]=T[j];
             T[j]=temp;
             swapped=true;
          }
    }
  }

  // Wyświetlamy wynik sortowania
  cout << "\n\nSortowanie Quciksort:\n";
  for(int i = 0; i < N; i++) cout<<T[i]<<" ";
  cout << endl;
}


// Program główny
int main()
{
  int T[]={123, 455, 23344, 114577, 67333, 12663};               //wprowadzenie dowolnej tablicy do posortowania

  cout << " Sortowanie metoda Quciksort liczb pieknych\n"
          "-----------------------------\n\n"
          "Przed sortowaniem:\n";

  for(int i = 0; i < N; i++) cout<<T[i]<<" ";
  cout << endl;

  pretty_sort(T,N);

}
