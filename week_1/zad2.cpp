// Zad: Na koliko se nacina iz skupa S = {1,2,...,10} moze izabrati cetvero clani podskup koji ne sadrzi dva uzastopna broja?

//Nacin: pisem fnkciju sljedebenicu na neki naicn koji mi govori sljedeci element

#include <iostream>

using namespace std;

void print(int *polje){
   for(int i = 0; i < 4; i++) {
      cout << polje[i] << " ";
   }
   cout << endl;
}

bool sljedeci(int *polje){
   polje[3]++;
   if(polje[3] < 11) return true;

   polje[2]++;
   polje[3] = polje[2] + 2;
   if(polje[3] < 11 && polje[2] < 11) return true;

   polje[1]++;
   polje[2] = polje[1] + 2;
   polje[3] = polje[2] + 2;
   if(polje[3] < 11 && polje[2] < 11 && polje[1] < 11) return true;

   polje[0]++;
   polje[1] = polje[0] + 2;
   polje[2] = polje[1] + 2;
   polje[3] = polje[2] + 2;
   if(polje[3] < 11 && polje[2] < 11 && polje[1] < 11 && polje[0] < 11) return true;

   else return false;
}

int main() {
   int podskup[4] = {1, 3, 5, 7};

   int brojac = 1;

   print(podskup);

   while(podskup[0] < 5){
      if(sljedeci(podskup)){
         print(podskup);
         brojac++;
      }
   } 

   cout << " na kraju ih ima: " << brojac;
   return 0;
}






