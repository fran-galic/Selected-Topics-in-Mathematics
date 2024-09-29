// Zad: koliko ima 5 znamenakstih brojeva, u koima se 1 i 2 ponavlajuju ili 0 puta ili 1
//      a ako se pojavluju oba dvovoje 2 je iza 1

// Naicn rjesavanja: Generiranje svih mogucih elemenatta veceg skupa i onda filtriranje

#include <iostream>

using namespace std;

int main() {
   int jedinica_set = 0;
   int dvojka_set = 0;
   int broj, znamenka;
   bool preskoci = false;
   int counter = 0;

   for(int i = 10000; i < 100000; i++) {
      broj = i;
      for(int j = 0; j < 5; j++) {
         znamenka = broj % 10;
         broj = broj / 10;
         if(znamenka == 1) {
            jedinica_set++;
            if(jedinica_set > 1) {
               preskoci = true;
               break;
            }
         }
         if(znamenka == 2) {
            dvojka_set++;
            if(jedinica_set != 0 || dvojka_set > 1) {
               preskoci = true;
               break;
            }
         }
      }

      if(!preskoci) {
         cout << i << endl;
         counter++;
      }

      jedinica_set = 0;
      dvojka_set = 0;
      preskoci = false;
      
   }

   cout << "Sveukupno ih ima: " << counter << endl;
   return 0;
}
