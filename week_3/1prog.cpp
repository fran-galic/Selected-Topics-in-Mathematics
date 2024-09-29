//ZAD: PROGRAM KOJI GENERIRA : 1. VARIJACIJE n-tog REDA S PONAVLJANJEM (poredak je bitan, ali elmenti se mogu ponavljati)
    // a to takoder odgovara   2. Ukupan broj funkcija iz skupa A u skup B, tj f: A -> B, 
                                // prilikom cega je |A| = n i elementi skupa A su predstavljen pozicijama u uredenoj n-torci, skup A 
                                // je Domena funkcije,  te |B| = m, a vrijendosti u toj n-torci predsatvlaju u koje se elemente skupa B preslikavaju odredeni 
                                // elementi iz skupa A
               
                                // I takvih funkcija, tj n-torki, bez ikakvih dodantih uvjeta ima n^m
#include <iostream>
#include <vector>

using namespace std;

int generirajNTorke(int n, int m, int dubina, vector<int>& trenutnaNTorka) {
    int br_trazenih = 0;

    if (dubina == n) { // tu je generirana n-torka, tu mozemo filtrirati ako je potrebno

        //mjesto za filter:

        if(1) {
            //za sada samo ispis:
            for (int i = 0; i < n; i++) {
            cout << trenutnaNTorka[i] << " ";
            }
        cout << endl;
        return 1;
        }
        return 0;
    }

    for (int i = 0; i < m; i++) { // Prolazimo kroz sve moguće elemente
        trenutnaNTorka[dubina] = i; // Postavljamo trenutni element na poziciju dubina
        br_trazenih += generirajNTorke(n, m, dubina + 1, trenutnaNTorka); // Rekurzivni poziv za sljedeću poziciju
    }
    return br_trazenih;
}

int main() {
    int n, m;
    cout << "Unesite duljinu n-torke (n): ";
    cin >> n;
    cout << "Unesite broj elemenata (m): ";
    cin >> m;

    vector<int> nTorka(n); // Vektor za pohranu trenutne n-torke
    int br_trazenih = generirajNTorke(n, m, 0, nTorka); // Pozivamo funkciju
    cout << "Broj funkcija/n-torki koji zadovoljavaju uvjete je " << br_trazenih << endl;
    return 0;
}
