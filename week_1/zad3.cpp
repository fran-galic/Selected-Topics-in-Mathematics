// Zad: Na koliko se naˇcina iz skupa S = {1,2,...,10} moˇze izabrati podskup koji ne sadrˇ zi dva uzastopna broja?
// !!! ovdje je sad pitanje koiko ima SVIH MOGUCIH PODKSUPOVA koji zadovoljavaju uvjet a ne samo 4-clanih

// 1. naicn rjesavanaj: generairanje sovje funckije sljedebenika koja mi pronaloazi samo zadane podksupove

// Koristim polje od 10 elemenata sa jedincicma i nulama da naznaicm koji elementi skupa S ulaze u podksup a koji ne

#include <iostream>
#include <cstring>

using namespace std;


void print(int *polje, int n){
   bool prazan_skup = true;
   for(int i = 0; i < n; i++) {
      if(polje[i] == 1) {
         cout << polje[i] * (i + 1) << " ";
         prazan_skup = false;
      }
   }
   if(prazan_skup) cout << "Prazan Skup";
   cout << endl;
}




int main() {
   int n = 10;
   int elementi_skupa_S[n] = {0};

   int i = -1; // -1 predstavlja prazan skup, inace i predstavlja na kojem se idneksu nalazi 1. element nekom skupa
   int j;
   int counter = 0;

   cout << "Skupovi: " << endl;

   print(elementi_skupa_S, n);
   counter++;

   while(i < n) {
      i++;
      j = i;
      //resetiraj polje
      memset(elementi_skupa_S, 0, n * sizeof(elementi_skupa_S[0])); 
      while(j < n) {
         elementi_skupa_S[j] = 1;
         j += 2;
         print(elementi_skupa_S, n);
         counter++;
      }
   }

   cout << "Sve zajedno ih ima: " << counter;
   return 0;
}