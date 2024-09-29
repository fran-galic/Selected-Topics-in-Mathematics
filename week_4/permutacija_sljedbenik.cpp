// ZAD: funkcija Sljedbenik permutacije

#include <iostream>
#include <vector>
#include <algorithm> // Za std::reverse
#include <sstream>   // Za std::istringstream

using namespace std;

bool sljedecaPermutacija(vector<int>& permutacija) {
    int n = permutacija.size(), k, l;
    
    for (k = n - 2; k >= 0; k--) {     // krnei gledat stvari odozada
        if (permutacija[k] < permutacija[k + 1]) {
            break;
        }
    }
    
    if (k < 0) {
        return false;
    }
    
    for (l = n - 1; l > k; l--) {
        if (permutacija[k] < permutacija[l]) {
            break;
        }
    }
    
    swap(permutacija[k], permutacija[l]);
    reverse(permutacija.begin() + k + 1, permutacija.end());
    
    return true;
}

int main() {
    string linija;
    vector<int> permutacija;

    cout << "Unesite pocetnu permutaciju (brojeve odvojene razmakom): ";
    getline(cin, linija);
    istringstream iss(linija);
    int broj;
    while (iss >> broj) {
        permutacija.push_back(broj);
    }

    cout << "Pocetna permutacija: ";
    for (int elem : permutacija) {
        cout << elem << " ";
    }
    cout << endl;
    
    if (sljedecaPermutacija(permutacija)) {
        cout << "Sljedeca permutacija: ";
        for (int elem : permutacija) {
            cout << elem << " ";
        }
        cout << endl;
    } else {
        cout << "Permutacija je vec posljednja u leksikografskom poredku." << endl;
    }
    
    return 0;
}