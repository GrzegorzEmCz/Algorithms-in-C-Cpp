#include <iostream>
#include <cstring>
using namespace std;
#define N 100


void Droga(int t[N][N], int x, int y, int p[N][N], int& c) {
	// jeżeli dochodę do t[N-1][N-1] kończę funkcję
	if (x==N-1 && y==N-1) {
		c++;
		return;
	}
	// oznaczam odwiedzoną komórkę
	p[x][y] = 1;

	// sprawdzam czy nie opuściłem t i czy komórka na które chce przejść spełnia warunek ilości jedynek
	if ((x>=0 || y>=0 || x<N || y<N) && t[x][y]==t[0][0]) {
		// idę w dół do komórki(x+1,y) pod warunkiem że już tam nie byłem
		if (x+1<N && !p[x+1][y])
			Droga(t, x+1, y, p, c);
		// idę w górę do komórki(x-1,y) pod warunkiem że już tam nie byłem
		if (x-1>=0 && !p[x-1][y])
			Droga(t, x-1, y, p, c);
		// ide w prawo do komórki(x,y+1) pod warunkiem że już tam nie byłem
		if (y+1<N && !p[x][y+1])
			Droga(t, x, y+1, p, c);
		// go left (x, y) --> (x, y - 1) pod warunkiem że już tam nie byłem
		if (y-1>=0 && !p[x][y-1])
			Droga(t, x, y-1, p, c);
	}
	p[x][y] = 0;
}

int main() {
/*	int t[N][N] =
	{
		{10,20,40,20,40,10,10,20},
		{1,1,10,30,60,70,30,10},
		{1,1,20,30,40,50,1,10},
		{1,1,20,30,40,50,1,40},
		{1,1,20,30,40,50,30,10},
		{1,1,20,30,40,50,50,20},
		{1,1,20,30,40,50,70,10},
		{10,20,40,20,40,10,10,20}
	};                                 macierz dla której istnieje droga
*/
	int t[N][N];
//pętla generująca losowe wartości dla t[N][N]
	  for(int i=0; i<N; i++) {
	    for(int j=0; j<N; j++) {
	      t[i][j]=rand()%1000;
	    }
  }

	//pętla wyświetlająca tablicę
	for(int i = 0; i < N; i++) {
		for(int j=0; j<N;j++) {
			cout<<t[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;

	//Przepisuje t[N][N] gdzie w wartość komkórek wpisuje ilość jedynek liczny w zapisie dwójkowym
  for(int i = 0; i < N; i++) {
    for(int j=0; j<N;j++) {
      int g=t[i][j];
      int l=0;
      while(g!=0) {
        if(g%2==1) l++;
        g=g/2;
      }
      t[i][j]=l;
    }
  }
	//Wyświetlam t z informacją ile jest jedynek
  for(int i = 0; i < N; i++) {
    for(int j=0; j<N;j++) {
      cout<<t[i][j]<<" ";
    }
    cout << endl;
  }
	cout << endl;



	int c=0;
  int p[N][N];
	memset(p, 0, sizeof p);            //zeruje p
	Droga(t, 0, 0, p, c);          //uruchamiam funkcje

  //sprawdam czy istnieje droga
  if (c>0)
	cout << "Istnieje droga z t[0][0] do t[N-1][N-1]";
	else
	cout << "Nie istnieje droga z t[0][0] do t[N-1][N-1]";

	return 0;
}
