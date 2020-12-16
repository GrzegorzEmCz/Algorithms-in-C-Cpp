// Grzegorz Czernecki

void DFS(int u, bool odwiedzony[]) {
   odwiedzony[u] = true;
   for(int v = 0; v<NODE; v++) {
      if(graf[u][v]) {
         if(!odwiedzony[v])
            DFS(v, odwiedzony);
      }
   }
}
bool jestSpojny() {
   bool *odw = new bool[NODE];
   for(int u; u < NODE; u++) {
      for(int i = 0; i<NODE; i++)
         odw[i] = false;
         DFS(u, odw);
      for(int i = 0; i<NODE; i++) {
         if(!odw[i])
            return false;
      }
   }
   return true;
}

void usunWezel(int x) {

int i;
   while (x < v) {
     // przesynięcie wiersza w góre
     for (i = 0; i < v; ++i) {
       g[i][x] = g[i][x + 1];
     }
     // przesunięcie kolumny w lewo
    for (i = 0; i < v; ++i) {
       g[x][i] = g[x + 1][i];
     }
   x++;
   }
}

int Rozpad( bool G[v][v]; int c) {

  for(int i=0; i < v; i++) {
    if(!jestSpojny()) return c        // sprawdzam czy graf jest nie spójny
    c[i];
    else {                             //sprawdam usuniecie każego wezła
      usunWezel(int x);                //funkcja usuwajaca zadeklarowany wezeł
      c[i]++;                          //zliczan usuniecie
      rozpad(G[v-1][v-1], c);          //ponownie uruchamiam funcję aby sprawdzić czy jest już nie spójna
      }
  }
}


int main() {
  int G[v][v];
  int c[v]=0;
  Rozpad(G[v][v], c[v]);

  m=c[0];
  for(int i=0; i < v; i++) {
    if(c[i]>0 && c[i]<m) m=c[i];
  }

  if (m>0) cout<< "Minimalna ilość wierzchołków do usunięcia wynosi"<<m<<" aby graf przestałbyć spójny";
  else cout<< "Graf jest nie spójny lub usuniecie wierzchołków nie powoduje jego niespójnosci";


}
