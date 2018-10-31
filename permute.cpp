#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

std::ofstream ofs ("permute.csv", std::ofstream::app);

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
void permute(char *a, int l, int r) 
{ 
   int i; 
   if (l == r){
       ofs<<a<<endl;
       cout<<a<<endl;
   }
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i));
       }
   } 
} 

int main() 
{
    char str[] = "AZOIDNKX";
    // string str[10] = { "A", "Z", "O", "Z", "I", "A", "D", "N", "K", "X"};
    
    int n = strlen(str); 
    // int p = 1<<n;
    // for(int i=0; i<p; i++) {
    //     string sel;
    //     if(__builtin_popcount(i)<4) continue;
    //     for(int j=0; j<10; j++) {
    //         if((1<<j)&i) sel.append(str[j]);
    //     }
    //     permute((char*)sel.front(), 0, n-1);
    // }
    
    for(int j=0; j<n-5; j++) {
        permute(&str[j], 0, n-1);
    }

    ofs.close();
    return 0; 
} 