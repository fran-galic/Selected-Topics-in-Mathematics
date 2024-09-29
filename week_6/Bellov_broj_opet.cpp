// zadatak generira sve moguce particije nekog skupa od n elemenata i broji koliko ih ima, tj racuna Bellov broj
// particije skupa su drugaicje od partcije nekog obicnog brojeva, zato sto elemente unutar skupa RAZLIKUJEMO


// NAPOMENA: Ako je zadatak: Koliko ima razlicitih relacija ekvivalencije na skupu od 10 elemenata?
                            // ODGOVOR NA OVKAVO PITANJE JE:   B(10), sto rjesava ovaj program
// NAPOMENA: Ukoliko trebam nac sve particije koje imaju tocno k elemenata mogu samo filtrirati ovu funkciju
                            // to cu vrlo vjeorvatno morat jos mlao doradit ali generlano je to ideja

#include <iostream>
#include <vector>
using namespace std;

//prototip:
int countP(int n, int k);

// Funkcija za ispis jedne particije
void ispisiParticiju(const vector<vector<int>>& particija) {
    for (const auto& podskup : particija) {
        cout << "{ ";
        for (auto element : podskup) {
            cout << element << " ";
        }
        cout << "} ";
    }
    cout << endl;
}

// Funkcija za generiranje svih particija
void Particija(vector<int> skup, int index, vector<vector<int>>& particija, int& brojParticija) {
    // Ako smo razmotrili sve elemente u skupu, ispisujemo particiju
    if (index == skup.size()) {

        //filter:

        if(1) {      // ukoliko je uvjet filtera zadovoljen
            ispisiParticiju(particija);
            brojParticija++;  // Povećavamo brojač za svaku generiranu particiju
        return;
        }
        return;
    }

    // Za svaki podskup u particiji dodajemo trenutni element u njega i rekurzivno pozivamo
    for (int i = 0; i < particija.size(); i++) {
        particija[i].push_back(skup[index]);
        Particija(skup, index + 1, particija, brojParticija);
        particija[i].pop_back();
    }

    // Dodajemo trenutni element kao singleton podskup i rekurzivno pozivamo
    particija.push_back({skup[index]});
    Particija(skup, index + 1, particija, brojParticija);
    particija.pop_back();
}

// Funkcija za generiranje svih particija za dani skup
void sveParticije(vector<int> skup, int& brojParticija) {
    vector<vector<int>> v;
    Particija(skup, 0, v, brojParticija);
}

// Glavna funkcija
int main() {
    int n;
    cout << "Unesite broj n: ";
    cin >> n;

    // Inicijaliziramo skup kao {1, 2, ..., n}
    vector<int> skup(n);
    for (int i = 0; i < n; i++) {
        skup[i] = i + 1;
    }
    cout << "Sve particije skupa su: " << endl;

    int brojParticija = 0;
    // Generiramo sve particije skupa
    sveParticije(skup, brojParticija);
    cout << "Ukupan broj generiranih particija: " << brojParticija << endl;
    return 0;
}








// Returns count of different partitions of n
// elements in k subsets
int countP(int n, int k)
{
  // Base cases
  if (n == 0 || k == 0 || k > n)
     return 0;
  if (k == 1 || k == n)
      return 1;
 
  // S(n+1, k) = k*S(n, k) + S(n, k-1)
  return  k*countP(n-1, k) + countP(n-1, k-1);
}
 
