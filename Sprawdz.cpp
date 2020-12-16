//Grzegorz Czernecki

struct node {
  string klucz;
  string wartosc;
  bool zajety;
  bool usuniety;        //dopisane pole czy
};

const int N=2021;
node tab[N];

unsigned int fnk(string klucz);
unsigned int h(unsigned int kn, int np);

void sprawdz(node tab[], int size, string klucz) {

  if(size==0) return cout<<"'Brak' tablicy";       //sprawdzenie czy tablica istnieje

  int kn=fnk(klucz);                               // wywołanie zdefiniowanej funkcja numeryzacji klucza

  for(int np=0; np<size; np++) {

    int adres=h(kn,np);

    int i=1;
    while(!tab[adres].zajety && tab[adres].wartosc==NULL) {                                             //sprawdzam dla "wolnego" rekordu, czy dla kolejnej próby mam równiez "wolny rekord" {jeżeli nie to ten rekord został nieprawidlowo usunięty}
       if(tab[h(kn,np+i)].zajety || tab[h(kn,np+i)].wartosc!=NULL || tab[h(kn,np+i)].wartosc!=NULL) {  // sprawdzam czy kolejna próba ma jakąś wartość zakładając że mogły zostać "wyczyszczone pojedyncze wartosci lub flagi
         tab[adres].usuniety=true;
         tab[adres].zajety=true;
         i++;                                                         // oznaczam wolny rekord jako nieprawidłowo usunięty
       }
    }

    if(tab[adres].zajety && tab[adres].wartosc==NULL) {                   //sprawdzam czy rekord został nie w pełni usunięty i jezeli tak była oznaczona to jako usuniete
      if(!tab[adres].usuniety) tab[adres].usuniety=true;
    }
  }
}
