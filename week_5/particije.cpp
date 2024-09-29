// ZAD: generiranje svih particija nekog brojai potnecijalno filtrirnje po potrebi

#include <iostream>
#include <vector>

using namespace std;

// Ispisuje jednu particiju
void ispisiParticiju(const vector<int>& particija) {
    for (int i = 0; i < particija.size(); ++i) {
        cout << particija[i] << (i < particija.size() - 1 ? "+" : "");
    }
    cout << endl;
}

// Rekurzivno generira sve particije broja m
void generirajParticije(int m, vector<int>& trenutnaParticija, int& brojac) {
    if (m == 0) {
        //mjesto za ubacit filter:
        if(trenutnaParticija.size() == 5) {

            //unutranji filter:
            bool zadovoljava = true;

            for(auto i = trenutnaParticija.begin(); i != trenutnaParticija.end(); i++) {
                if(*i > 6) {
                    zadovoljava = false;
                    break;
                }
            }

            if(zadovoljava) {    // ukoliko je filter zadvoljen nesot radi
            //ispisiParticiju(trenutnaParticija);
            brojac++; // Broji svaku validnu particiju
            return;
            }
        }
        return;
    }

    // Početna vrijednost za sljedeći sabirak
    int pocetak = trenutnaParticija.empty() ? 1 : trenutnaParticija.back();
    for (int sljedeci = pocetak; sljedeci <= m; ++sljedeci) {
        trenutnaParticija.push_back(sljedeci);
        generirajParticije(m - sljedeci, trenutnaParticija, brojac);
        trenutnaParticija.pop_back(); // Vraća stanje za sljedeću iteraciju
    }
}

int main() {
    int m;
    cout << "Unesite broj m za generiranje particija: ";
    cin >> m;

    vector<int> trenutnaParticija;
    int brojac = 0;

    generirajParticije(m, trenutnaParticija, brojac);

    cout << "Ukupan broj particija: " << brojac << endl;

    return 0;
}
