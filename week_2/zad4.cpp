//ZAD:   PROGRAM KOJI GENERIRA SVE MOGUCE k-clane podksupove nekog n-clanog skupa S, !!!(KOMBINACIJE BEZ PONAVLJANJA)
//       Program doraditi s nekim ekstra primjerima iz Predavanja_2 i napisat mogucnost filtriranja kao i moguncost pronalazenja ranga

// Ovaj zadatak cmeo rjesiti u KOLEKSIKOGRAFSKOM POREDKU i pronalazenju ranga za njega, on je drugaciji od obicnog leksikografskog poredka 
// ali to nam ni nije pretjerano bitno nego je bitno da samo da mogu generirait sve moguce k-clane pdoksupove n-clanog ksupa i onda ih kansije filtrarati

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool zadnji(int *k_clani_podskup, int k, int n) {
   bool zadnji = true;
   for(int i = 0; i < k; i++) {
      if(k_clani_podskup[i] != n - i) {
         zadnji = false;
         break;
      }
   }
   return zadnji;
}

void print_k_clani_podksup(int *polje, int k){
   for(int i = 0; i < k; i++) {
         cout << polje[i] << " ";
   }
   cout << endl;
}

//funkcija koja vraca bionomni koeficijent
int binomialCoefficients(int n, int k) {
   int C[k+1];
   memset(C, 0, sizeof(C));
   C[0] = 1;
   for (int i = 1; i <= n; i++) {
      for (int j = min(i, k); j > 0; j--)
         C[j] = C[j] + C[j-1];
   }
   return C[k];
}

// funkcija pronlazi rang za neki k-clani podksup zadan u koleksikografskom poretku
int rang_koleksikografski_poredak(int *k_clani_podskup, int k){
   int suma = 0;
   for (int i = 0; i < k; i++) {
      suma += binomialCoefficients(k_clani_podskup[i] - 1, k - i);
   }
   //+1 tako da rnag krece od 1 a ne od 0
   return suma + 1;
}


//glavni dio programa, tj glavna funkcija
void k_clani_podskupovi_uz_uvjet(int n, int k) {

   int k_clani_podskup[k];

   //setiranje pocetnog k-clanog podksupa po KOLEKSIKOGRAFSKOM poretku
   for(int i = 0; i < k; i++) k_clani_podskup[i] = k - i;
   
   //filter tj ispitvanje uvjeta za pocetni k-clani podksup
      if (/*filter...*/ 1) {
         // jos neki kod po potrebi

         //isprintaj taj k-clani podksup
         print_k_clani_podksup(k_clani_podskup, k);

         //cout << "KP: " << rang_koleksikografski_poredak(k_clani_podskup, k) << endl;    // u ovom sma slucjau mogao doslovnu ispisivait i redni 
         //bi bilo istoba ru ovoj funkciji ali inac emoze biti korsimo ako me za neki opceinti pokdsup izvan funkcije zanima kojeg je ona ranga
      }

   //Ova petlja generira sve k-clane podksupove u koleksikografskom poretku ukljucujuci i zadnji, jeidno ne ukljucuje pocetni poredak
   while(!zadnji(k_clani_podskup, k, n)) {
      for(int i = k - 1; i >= 0; i--) {
         if(i != 0) {
            if(k_clani_podskup[i] + 1 == k_clani_podskup[i - 1]) k_clani_podskup[i] = k - i;
            else {
               k_clani_podskup[i]++;
               break;
            }
         }
         if (i == 0) {
            k_clani_podskup[i]++;
            break;    //ovaj break nije ni potreban, ali moze ostat zbog semantike
         }

      }

      //mjesto za filtriranje svih k-clanih podksupova po nekom uvjetu iz zadatka:
      if (/*filter...*/ 1) {
         // napravi nesto dodatno

         //isprintaj taj k-clani podksup
         print_k_clani_podksup(k_clani_podskup, k);
         
         //cout << rang_koleksikografski_poredak(k_clani_podskup, k) << endl;     //  u ovom lsucjau je to nepotrebo za sada, ali neka
         //sotji tu kao primjer
      }
   }
}


int main() {
   int n, k;
   cout << "Upisite Kardinalni broj skupa S i zeljeni k za generiranje k-clnih podskupova, tj n i k: ";
   cin >> n >> k;

   k_clani_podskupovi_uz_uvjet(n, k);

   return 0;
}
