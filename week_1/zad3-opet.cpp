// Zad: Na koliko se naˇcina iz skupa S = {1,2,...,10} moˇze izabrati podskup koji ne sadrˇ zi dva uzastopna broja?
// !!! ovdje je sad pitanje koiko ima SVIH MOGUCIH PODKSUPOVA koji zadovoljavaju uvjet a ne samo 4-clanih


// 1. naicn rjesavanaj: generairanje sovje funckije sljedebenika koja mi pronaloazi samo zadane podksupove

// Koristim polje od 10 elemenata sa jedincicma i nulama da naznaicm koji elementi skupa S ulaze u podksup a koji ne


//Nacin rjesavanaja: GENERIRMA SVE MOGUCE PODSKUPOVE pa filtriram

#include <iostream>
#include <cstring>

using namespace std;

//printa elemente podskupova kao brojeve
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

//printa n-torku 0 i 1 koja govori koji se elemtni nalaze u kojem podksupu
void print_01(int *polje, int n){
   for(int i = 0; i < n; i++) {
         cout << polje[i] << " ";
   }

   cout << endl;
}

//filter koji govori dali neki odredeni podksup zadovoljava trazene uvjete zadatka
bool filter(int *polje, int n) {
   //lijevi i desni rubni slucaj
   if(polje[0] == 1 && polje[1] == 1) return false;
   else if (polje[n - 1] == 1 && polje[n - 2] == 1) return false;
   else  for(int i = 1; i < n - 1; i++){
            if(polje[i] == 1 && polje[i - 1] == 1 || polje[i] == 1 && polje[i + 1] == 1) return false;
         }
   return true;
}

bool filter_zbroj_elemenata(int *polje, int n) {
   int zbroj = 0;
   for(int i = 0; i < n; i++){
      zbroj += polje[i] * (i + 1);
   }
   if(zbroj == 22) return true;
   else return false;
}

bool filter_zbroj_elemenata_2n(int *polje, int n) {
   int zbroj = 0;
   for(int i = 0; i < n; i++){
      zbroj += polje[i] * (i + 1);
   }
   if(zbroj == 2 * n) return true;
   else return false;
}

//FUKNCIJA KOJA GENERIRA SVE MOGUCE PODKSUPOVE NEKOG SKUPA
//fukncija prima prazno polje od n elemenata, gdje je n kardinalni broj elemanata u nekom skupu, npr skup S = {1,2,...,10} |S| = 10, tj n = 10
//int i nam govori na koju pozicju cemo u tom trentuku posatvljati 1, 1 znaci da se element nalazi u podskupu a 0 da se ne nalazi, u pocektu je i = 0;
//brojac je varijabla u koju se sprema koliko ima podskupova koje zadovoljavaju nkei uvjet iz zadatka

//samo generira SVE MOGUCE PODSKUPOVE
void podskupovi(int *polje, int i, int n) {
   if(i == 0) {
      //ipis, moze s ezakomentirati ili mijenjati
      print(polje, n);
      //mjesto za postavljanje filtera za prazan skup, tj dali prazan skup zadvoljava ili ne neke uvjete na zadatak:
   }
   if (i >= n) return;
   polje[i] = 1;
   //ipis, moze s ezakomentirati ili mijenjati
   print(polje, n);
   //mjesto za postavljanje filtera za sve ostale podskupove, tj da se vidi dali neki podskup zadvoljava ili ne neke uvjete na zadatak:

   podskupovi(polje, i + 1, n);
   polje[i] = 0;
   if(i + 1 < n) podskupovi(polje, i + 1, n);
   return;
} 

//Generira i dalje sve moguce podskupove ali ipsisuje i prebrojava samo one koje zadovoljavaju zadani filter odnosno uvjet zadatka
void podskupovi_uz_uvjete(int *polje, int i, int n, int &brojac) {
   if(i == 0) {
      //mjesto za postavljanje filtera za prazan skup, tj dali prazan skup zadvoljava ili ne neke uvjete na zadatak:
      if(filter_zbroj_elemenata_2n(polje, n)) {
         //ipis, moze s ezakomentirati ili mijenjati
         print(polje, n);
         brojac++;
      }
   }
   if (i >= n) return;
   polje[i] = 1;
   //mjesto za postavljanje filtera za sve ostale podskupove, tj da se vidi dali neki podskup zadvoljava ili ne neke uvjete na zadatak:
      if(filter_zbroj_elemenata_2n(polje, n)) {
      //ipis, moze s ezakomentirati ili mijenjati
      print(polje, n);
      brojac++;
      }

   podskupovi_uz_uvjete(polje, i + 1, n, brojac);
   polje[i] = 0;
   if(i + 1 < n) podskupovi_uz_uvjete(polje, i + 1, n, brojac);
   return;
} 

// JOS BI BILO DOBRO DODAT KOD KOJI ODMAH GENERIRA SAMO TRAZENE PODKSUPOVE ZA ZADANI UVJET, TO BI BILO SIGRUNO BRZE OD GORNJA DVA PRSITUPA
// ALI TAJ KOD BI BIO JAKO SPECIFICNA ZA SVAKI POPJEDINACNI ZADATAK, U OVOM PRISTUPU KOJEM SADA IMAM MI JE DOVOLJNO SMAO PROMIJENITI FILTER
// a s ovim brzim pristupom bi morao pisati cijeli kod ispocetka, bar mi se za sad tkao cini, TAKO D ABIH REKAO DA MI JE ZA SADA DOVOLJAN 
// OVAJ VISE GENERALAN PRSITUP S FILTEROM

int main() {
   int n;

   cout << "Unesite Kardinalni broj skupa S: ";
   cin >> n;
   cout << endl;

   int elementi_skupa_S[n] = {0};
   int brojac = 0;         // varijabla koja mjeri koliko ima SVIH MOGUCIH PODKSUPOVA koji zadovoljavju uvjet zadatka
                           // za svaki pojedini zadatak je potrebno prigoditi uvjetno ispitivanje u funkciji
   
   cout << "Svi podskupovi koji zadovoljavaju trazene uvjete zadatka su: " << endl << endl;
   //!!!!! Poznato je da svih mogucih podskupova ima 2^n
   podskupovi_uz_uvjete(elementi_skupa_S, 0, n, brojac);
   //podskupovi(elementi_skupa_S, 0, n);
   cout << "Sve zajendo ih ima " << brojac << endl;

}
