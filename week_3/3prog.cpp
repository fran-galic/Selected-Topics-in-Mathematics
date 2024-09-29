// ZAD: ZADATAK NAM DAJE: 1. BROJ KOMBINACIJA BEZ PONAVLJANJA REDA  n C m   koji zadovoljavaju neki uvjet
   // to takoder odgovara 2. broju STROGO rastucih funkcija iz skupa A u skub B, |A| = m, |B| = n

#include <iostream>
#include <vector>

using namespace std;

int generirajKombinacije(int n, int m, int start, vector<int>& trenutnaKombinacija) {
   int br_trazenih = 0;

   if (m == 0) {    //tu smo generirali odgovarajucu kombinaicju
        
      //tu je mjesto di dolazi filter:

      if(1){       // tu testiramo filter i ako je on zadovoljen onda obradujemo te podatke
         // za sada ih samo ispisujemo
         for (int elem : trenutnaKombinacija) {
            cout << elem << " ";
         }
      cout << endl;
      return 1;
      }
      return 0;
   }

   for (int i = start; i <= n - m; ++i) {
        // Dodajemo i-ti element u kombinaciju
        trenutnaKombinacija.push_back(i + 1); // Dodajemo +1 da elementi počinju od 1 umjesto od 0
        // Rekurzivni poziv za preostale elemente
        br_trazenih += generirajKombinacije(n, m - 1, i + 1, trenutnaKombinacija);
        // Uklanjamo i-ti element kako bismo probali sljedeću kombinaciju
        trenutnaKombinacija.pop_back();
   }
   return br_trazenih;   
}

int main() {
    int n, m;
    cout << "Unesite ukupan broj elemenata, tj kardinlani broj skupa B, (n): ";
    cin >> n;
    cout << "Unesite broj elemenata za odabrati, broj elemenata skupa A, (m): ";
    cin >> m;

    vector<int> kombinacija;
    int br_trazenih = generirajKombinacije(n, m, 0, kombinacija);
    cout << "Broj STROGO rastucih funkcija iz skupa A u skup B, tj broj kombinacija bez ponavljanja reda n C m je: " << br_trazenih << endl;

    return 0;
}
