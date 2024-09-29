// ZAD: ZADATAK NAM: 1.generira sve moguce RASTUCE SURJEKCIJE iz skupa skupa A (m) u skup B (n)
                     
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool jeSurjekcija(const vector<int>& vektor, int n) {
    vector<bool> pojavioSe(n, false);
    for (int elem : vektor) {
        pojavioSe[elem - 1] = true;
    }
    return find(pojavioSe.begin(), pojavioSe.end(), false) == pojavioSe.end();
}

bool jeRastuca(const std::vector<int>& vektor) {
    for (size_t i = 1; i < vektor.size(); ++i) {
        // Provjeravamo je li trenutni element manji od prethodnog
        if (vektor[i] < vektor[i - 1]) {
            return false; // Niz nije rastući
        }
    }
    return true; // Niz je rastući
}

//zapravo generira sve moguce Kombinaicje s ponavlajnima reda m sa elementima iz B i onda filtrira sve one koji nisu surjekcije i onda rastuce funkcije
int generirajSurjekcije(int m, int n, int dubina, vector<int>& trenutnaSurjekcija) {
    int br_trazenih = 0;

    if (dubina == m) {
        if (jeSurjekcija(trenutnaSurjekcija, n)) { //tu si tek nasao svoje surjekcije
            if(jeRastuca(trenutnaSurjekcija)) {
               //tu je mjesto za filter:

               if(1) {              //tu testiramo filter i ako je on zadovoljen onda obradujemo te podatke
                  //za sada samo ispisujemo
                  for (int elem : trenutnaSurjekcija) {
                  cout << elem << " ";
               }
               cout << endl;
               return 1;
               }
               return 0;   //ukoliko to je surjekcija i rastuca je ali ne zadovoljava uvjet
            }
            return 0;   //ako nije rastuca vrati 0
        }
        return 0; //ako nije surjekcija onda vrait 0
    }

    for (int i = 1; i <= n; ++i) {
        trenutnaSurjekcija[dubina] = i;
        br_trazenih += generirajSurjekcije(m, n, dubina + 1, trenutnaSurjekcija);
    }
    return br_trazenih;
}

int main() {
    int m, n;
    cout << "Unesite broj elemenata skupa A (m): ";
    cin >> m;
    cout << "Unesite broj elemenata skupa B (n): ";
    cin >> n;

    if (n > m) {
        cout << "Surjekcija nije moguća jer je n > m." << endl;
        return 1;
    }

    vector<int> surjekcija(m);
    int br_trazenih = generirajSurjekcije(m, n, 0, surjekcija);
    cout << "Broj trazenih rastucih surjekcija iz skupa A (m) u skup B (n) je: " << br_trazenih << endl;
    return 0;
}
