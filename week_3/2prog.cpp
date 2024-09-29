//ZAD: ZADATAK NAM DAJE : 1, BROJ INJEKTICVNIH FUNKCIJA IZ A U B
                     //   2, BROJ VARIJACIJA BEZ PONAVLJANJA, (poredak je bitan, ali se elementi ne smiju ponavljati)

                     // takvih brojeva ima n(n −1)(n −2)····· (n −m+1)
#include <iostream>
#include <vector>

using namespace std;

// Funkcija za generiranje varijacija bez ponavljanja
int generirajVarijacije(int n, int m, int dubina, vector<int>& trenutnaVarijacija, vector<bool>& koristeni) {
   int br_trazenih = 0;
   
   if (dubina == n) { // u potpunosti je generirana n-torka
         
      //mjesto za filter:

      if(1) {                    //tu se ispita filter i ako je zadovoljeno obradi podatak kako zelis
         //za sada sao ispis
         for (int i = 0; i < n; i++) {
         cout << trenutnaVarijacija[i]  + 1 << " ";
         }
      cout << endl;
      return 1;
      }
      return 0;
   }

   for (int i = 0; i < m; i++) { // Prolazimo kroz sve moguće elemente
      if (!koristeni[i]) { // Ako element nije već korišten
            trenutnaVarijacija[dubina] = i; // Postavljamo trenutni element na poziciju dubina
            koristeni[i] = true; // Označavamo element kao korišten
            br_trazenih += generirajVarijacije(n, m, dubina + 1, trenutnaVarijacija, koristeni); // Rekurzivni poziv za sljedeću poziciju
            koristeni[i] = false; // Resetiramo element kao nekorišten za sljedeće kombinacije
      }
    }
   return br_trazenih;
}

int main() {
    int n, m;
    cout << "Unesite duljinu n-torke, tj broj elemenata skupa A (n): ";
    cin >> n;
    cout << "Unesite broj elemenata skupa B (m): ";
    cin >> m;
    if(m < n) {
      cout << "m nesmije biti manji on n\n";
      return 1;
    }

    vector<int> varijacija(n); // Vektor za pohranu trenutne varijacije
    vector<bool> koristeni(m, false); // Vektor za praćenje korištenih elemenata

    int br_trazenih = generirajVarijacije(n, m, 0, varijacija, koristeni); // Pozivamo funkciju
    cout << "Broj injektivnih funkcija iz A u B, tj broj varijacija bez ponavljanja koji zadovoljavaju uvjete je: " << br_trazenih << endl;

    return 0;
}
