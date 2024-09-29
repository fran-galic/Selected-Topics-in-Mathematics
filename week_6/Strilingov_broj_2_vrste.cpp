//program pronalazi Strilingov broj 2. vrste, tj koliko ima particija nekog skupa od m elemenata 
                //koje se sastoje od tocno n nepraznih podskupova, takoder ih generira i ispisuje

                  //ovdje je tu rijec o particijima skupova, gdje se elementi razlikuju, **i ot nema veze s proslim tjednom i partijcijom brojeva
#include <iostream>
#include <vector>

using namespace std;

// Pomoćna funkcija za ispis particije
void ispisiParticiju(const vector<vector<int>>& particija) {
    for (const auto& podskup : particija) {
        cout << "{ ";
        for (auto elem : podskup) {
            cout << elem << " ";
        }
        cout << "} ";
    }
    cout << "\n";
}

// Rekurzivna funkcija za generiranje particija
void generirajParticije(int n, vector<vector<int>>& trenutnaParticija, vector<int>& ostatak, int& brojParticija) {
    if (ostatak.empty()) {
        ispisiParticiju(trenutnaParticija);
        ++brojParticija;
        return;
    }
    
    for (int i = 0, n = ostatak.size(); i < n; ++i) {
        int elem = ostatak.back();
        ostatak.pop_back();
        
        // Dodaj element u postojeće podskupove
        for (auto& podskup : trenutnaParticija) {
            podskup.push_back(elem);
            generirajParticije(n, trenutnaParticija, ostatak, brojParticija);
            podskup.pop_back();
        }
        
        // Kreiraj novi podskup s trenutnim elementom
        trenutnaParticija.push_back({elem});
        generirajParticije(n, trenutnaParticija, ostatak, brojParticija);
        trenutnaParticija.pop_back();
        
        ostatak.insert(ostatak.begin(), elem); // Vrati element za sljedeće iteracije
    }
}

int main() {
    int m;
    cout << "Unesite broj m: ";
    cin >> m;
    
    vector<int> ostatak;
    for (int i = 1; i <= m; ++i) {
        ostatak.push_back(i);
    }
    
    vector<vector<int>> trenutnaParticija;
    int brojParticija = 0;
    generirajParticije(m, trenutnaParticija, ostatak, brojParticija);
    
    cout << "Ukupan broj particija: " << brojParticija << endl;
    
    return 0;
}
