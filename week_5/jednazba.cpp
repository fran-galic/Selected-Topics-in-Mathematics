// program koji rjesava sve one probleme s jedadbama, 5 preza

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Ogranicenje {
    int min, max;
};

void ispisiRjesenje(const vector<int>& rjesenje) {
    for (int val : rjesenje) {
        cout << val << " ";
    }
    cout << endl;
}

void pronadjiRjesenja(int n, int trenutniIndex, vector<int>& trenutnoRjesenje, const vector<Ogranicenje>& ogranicenja, int& brojac, const string& usporedba) {
    if (n < 0) return; 
    if (trenutniIndex == trenutnoRjesenje.size()) {
        if ((usporedba == "=" && n == 0) || (usporedba == "<=") || (usporedba == "<" && n > 0)) {

            //mjesto za filter ukoliko jos dodatno zelimo filtrirait rjesenja:

            //ispisiRjesenje(trenutnoRjesenje);
            brojac++;
        }
        return;
    }

    for (int i = ogranicenja[trenutniIndex].min; i <= min(ogranicenja[trenutniIndex].max, n) && (usporedba == "<=" || usporedba == "=" ? i <= n : i < n); i++) {
        trenutnoRjesenje[trenutniIndex] = i;
        pronadjiRjesenja(n - i, trenutniIndex + 1, trenutnoRjesenje, ogranicenja, brojac, usporedba);
    }
}

int main() {
    int n, brojVarijabli;
    string usporedba;
    cout << "Unesite ukupan broj n: ";
    cin >> n;
    cout << "Unesite vrstu usporedbe (<=, <, =): ";
    cin >> usporedba;
    cout << "Unesite broj varijabli xi: ";
    cin >> brojVarijabli;

    vector<Ogranicenje> ogranicenja;
    for (int i = 0; i < brojVarijabli; ++i) {
        cout << "Unesite donju i gornju granicu za x" << i + 1 << " (u formatu: donja gornja): ";
        int donja, gornja;
        cin >> donja >> gornja;
        ogranicenja.push_back({donja, gornja});
    }

    vector<int> trenutnoRjesenje(brojVarijabli, 0);
    int brojac = 0;

    pronadjiRjesenja(n, 0, trenutnoRjesenje, ogranicenja, brojac, usporedba);

    cout << "Ukupan broj valjanih rjesenja: " << brojac << endl;

    return 0;
}
