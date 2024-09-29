// zadatak generira sve moguce particije nekog skupa od n elemenata i broji koliko ih ima, tj racuna Bellov broj
// particije skupa su drugaicje od partcije nekog obicnog brojeva, zato sto elemente unutar skupa RAZLIKUJEMO


// NAPOMENA: Ako je zadatak: Koliko ima razlicitih relacija ekvivalencije na skupu od 10 elemenata?
                            // ODGOVOR NA OVKAVO PITANJE JE:   B(10), sto rjesava ovaj program

#include <iostream>
#include <vector>

using namespace std;

// Pomoćna funkcija za ispis particije.
void ispisiParticiju(const vector<vector<int>>& particija) {
    cout << "{ ";
    for (const auto& podskup : particija) {
        cout << "{";
        for (auto elem : podskup) {
            cout << elem << " ";
        }
        cout << "} ";
    }
    cout << "}" << endl;
}

// Rekurzivna funkcija za generiranje particija.
void generirajParticije(int n, int max, vector<vector<int>>& particija, int& brojac) {
    if (n > max) {
        //ispisiParticiju(particija);
        brojac++;
        return;
    }

    // Dodajemo element 'n' u svaki postojeći podskup.
    for (auto& podskup : particija) {
        podskup.push_back(n);
        generirajParticije(n + 1, max, particija, brojac);
        podskup.pop_back();
    }

    // Kreiramo novi podskup s elementom 'n'.
    particija.push_back({n});
    generirajParticije(n + 1, max, particija, brojac);
    particija.pop_back();
}

int main() {
    int n;
    cout << "Unesite broj n: ";
    cin >> n;

    vector<vector<int>> particija;
    int brojac = 0;
    generirajParticije(1, n, particija, brojac);

    cout << "Ukupan broj generiranih particija: " << brojac << endl;

    return 0;
}
