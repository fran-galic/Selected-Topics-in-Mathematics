// ZAD: ZADATAK NAM: 1.GENERIRA sve moguce SURJEKCIJE iz skupa skupa A (m) u skup B (n)
                     // ! u slucaju da je n == m, zapravo sto dobivamo jes PERMUTACIJA skupa B

                     // ako je n < m, zapravo dobivamo nkeu vrstu permutacija di se elementi smiju ponavljat, 
                     // ali tkao da je BAS svaki element iz B sadrzan unutar te permutacije BAREM JEDNOM  -> vijdeti jos sto bi to tocno bilo u kombinatorci
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

//zapravo generira sve moguce Kombinaicje s ponavlajnima reda m sa elementima iz B i onda filtrira sve one koji nisu surjekcije
int generirajSurjekcije(int m, int n, int dubina, vector<int>& trenutnaSurjekcija) {
    int br_trazenih = 0;

    if (dubina == m) {
        if (jeSurjekcija(trenutnaSurjekcija, n)) { //tu si tek nasao svoje surjekcije

            //tu je mjesto za filter:

            if(1) {              //tu testiramo filter i ako je on zadovoljen onda obradujemo te podatke
               //za sada samo ispisujemo
               for (int elem : trenutnaSurjekcija) {
               cout << elem << " ";
            }
            cout << endl;
            return 1;
            }
            return 0;   //ukoliko to je surjekcija ali ona ne zadovoljava uvjet
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
    cout << "Broj trazenih surjekcija iz skupa A (m) u skup B (n) je: " << br_trazenih << endl;
    return 0;
}
