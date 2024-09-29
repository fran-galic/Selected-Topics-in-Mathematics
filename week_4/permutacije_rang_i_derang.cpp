// ZAD: napisi funkcije koje raucnaju rang i dernag od neke permutacije

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int faktorijel(int n) {
    return (n == 0) ? 1 : n * faktorijel(n - 1);
}

int rangPermutacije(const vector<int>& permutacija) {
    int rang = 0;
    int n = permutacija.size();
    for (int i = 0; i < n; ++i) {
        int manji = 0;
        for (int j = i + 1; j < n; ++j) {
            if (permutacija[j] < permutacija[i]) {
                ++manji;
            }
        }
        rang += manji * faktorijel(n - i - 1);
    }
    return rang;
}

vector<int> derangFunkcija(int rang, int n) {
    vector<int> permutacija(n), elementi(n);
    iota(elementi.begin(), elementi.end(), 1); // Inicijalizira elemente s 1 do n

    for (int i = 0; i < n; ++i) {
        int fakt = faktorijel(n - i - 1);
        int index = rang / fakt;
        rang %= fakt;
        
        permutacija[i] = elementi[index];
        elementi.erase(elementi.begin() + index);
    }

    return permutacija;
}

//rangovi krecu od 0, ako je potrebno samo cu pri ispisu povecati za 1
int main() {
    int n;
    cout << "Unesite duljinu permutacije: ";
    cin >> n;
    vector<int> permutacija(n);

    cout << "Unesite elemente permutacije: ";
    for (int& elem : permutacija) {
        cin >> elem;
    }

    int rang = rangPermutacije(permutacija);
    cout << "Rang unesene permutacije je: " << rang << endl;

    auto rekonstruiranaPermutacija = derangFunkcija(rang, n);
    cout << "Permutacija za rang " << rang << " je: ";
    for (int elem : rekonstruiranaPermutacija) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}