// ZAD: ZADATAK NAM DAJE: 1. BROJ KOMBINACIJA S PONAVLJANJA REDA  (m + n - 1) C m   koji zadovoljavaju neki uvjet
   // to takoder odgovara 2. broju rastucih funkcija iz skupa A u skub B, |A| = m, |B| = n

#include <iostream>
#include <vector>

using namespace std;

// Funkcija za generiranje kombinacija s ponavljanjem
int generirajKombinacijeSPonavljanjem(int n, int m, vector<int>& trenutnaKombinacija) {
    int br_trazenih = 0;

    if (m == 0) { //tu je izgenerirana nasa kombinacija s ponavljanjima

      //tu je mjesto za filter:

      if(1){      //tu testiramo filter i ako je on zadovoljen onda obradujemo te podatke
        //za sada samo ispisujemo
        for (int elem : trenutnaKombinacija) {
            cout << elem << " ";
        }
        cout << endl;
        return 1;
      }
        return 0;
    }

    // Počinjemo od 1 ako želimo da elementi skupa počinju od 1
    int start = trenutnaKombinacija.empty() ? 1 : trenutnaKombinacija.back();    //vraca ti zadnji element koji se nalazi u vektoru
    for (int i = start; i <= n; ++i) {
        trenutnaKombinacija.push_back(i); // Dodajemo element u kombinaciju
        br_trazenih += generirajKombinacijeSPonavljanjem(n, m - 1, trenutnaKombinacija); // Rekurzivni poziv za preostale elemente
        trenutnaKombinacija.pop_back(); // Uklanjamo zadnji dodani element kako bismo probali sljedeću kombinaciju
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
    int br_trazenih = generirajKombinacijeSPonavljanjem(n, m, kombinacija);
    cout << "Broj rastucih funkcija iz skupa A u skup B, tj broj kombinacija S ponavljanja reda (m + n - 1) C m je: " << br_trazenih << endl;
    cout << "Broj koji se ispisuje oznacva koliko ih ima a da zadovoljavaju uvjete" << endl;
    
    return 0;
}
