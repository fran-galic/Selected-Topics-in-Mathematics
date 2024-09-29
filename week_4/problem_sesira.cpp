// ZAD: tu se rjesava problem sa sesirima i kolika je vjerovantost da tocno k ljudi od mogucih n dobije sovj sesir
         // NAPOMNEA: ukoliko nas zanima neki raspon, izracunamo vjerovatnost za sve i zbrojimo
         // NAPOMENA: ukoliko nas zanima koliko ima tkavih slucaja samo ne podijelimo sa n!
         // tu sma takoder napisao funkciju u kojoj racunamo broj DERANGEMANA

#include <iostream>
#include <vector>

using namespace std;

// Funkcija za izračunavanje faktorijela s plutajućom točkom
double faktorijel(int n) {
    double rezultat = 1.0;
    for (int i = 2; i <= n; ++i) {
        rezultat *= i;
    }
    return rezultat;
}

// Funkcija za izračunavanje broja derangemenata D(n) s plutajućom točkom
double derangement(int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        double term = (i % 2 == 0 ? 1 : -1) * faktorijel(n) / faktorijel(i);
        sum += term;
    }
    return sum;
}

// Funkcija za izračunavanje vjerojatnosti da točno k ljudi uzme svoj šešir, n C k smo izraucnunali kao n!/(n - k)!*k!
double vjerojatnost(int n, int k) {
    return faktorijel(n) / (faktorijel(k) * faktorijel(n - k)) * derangement(n - k) / faktorijel(n);
}

int main() {
    int n, k;
    cout << "Unesite ukupan broj ljudi (n): ";
    cin >> n;
    cout << "Unesite broj ljudi koji uzimaju svoj sesir (k): ";
    cin >> k;

    double rezultat = vjerojatnost(n, k);
    cout << "Vjerojatnost da tocno " << k << " od " << n << " ljudi uzme svoj sesir je: ";
    cout.precision(17); // Postavlja preciznost ispisa
    cout << rezultat << endl;

    return 0;
}