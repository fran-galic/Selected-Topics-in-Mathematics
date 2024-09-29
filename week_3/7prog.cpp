// ZAD: geneira sve 2-surjektivne funkcije iz skupa A u skup B

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Funkcija za provjeru je li trenutna funkcija 2-surjektivna
bool je2Surjektivna(const vector<int>& funkcija, int n) {
    map<int, int> brojac;
    for (int elem : funkcija) {
        brojac[elem]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (brojac[i] < 3) {
            return false; // Ako bilo koji element nema barem dva preimagea
        }
    }
    return true;
}

// Rekurzivna funkcija za generiranje i ispis svih 2-surjektivnih funkcija
int generiraj2Surjektivne(int m, int n, int poz, vector<int>& trenutnaFunkcija) {
   int br_trazenih = 0;

    if (poz == m) {
        if (je2Surjektivna(trenutnaFunkcija, n)) {

            //mjesto za filter
            
            if(1) {
               for (int elem : trenutnaFunkcija) {
                //cout << elem << " ";   
               }
            //cout << endl;
            return 1;
            }
            return 0;
        }
        return 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        trenutnaFunkcija[poz] = i;
        br_trazenih += generiraj2Surjektivne(m, n, poz + 1, trenutnaFunkcija);
    }
    return br_trazenih;
}

int main() {
    int m, n;
    cout << "Unesite broj elemenata skupa A (m): ";
    cin >> m;
    cout << "Unesite broj elemenata skupa B (n): ";
    cin >> n;

    if (m < 3 * n) {
        cout << "Nije moguce generirati 2-surjektivne funkcije jer m nije barem dvostruko vece od n." << endl;
        return 1;
    }

    vector<int> funkcija(m);
    int br_trazenih = generiraj2Surjektivne(m, n, 0, funkcija);
    cout << "Ima ih " << br_trazenih << endl;
    return 0;
}