#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <Windows.h>
using namespace std;

std::ofstream ofs ("permute.csv", std::ofstream::app);

static int p=0, w=0;

void moveUpNLines(int n) {
    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &coninfo);
    coninfo.dwCursorPosition.Y -= n;    // move up one line
    coninfo.dwCursorPosition.X = 0;    // move to the right the length of the word
    SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);
}

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
void permute(char *a, int l, int r) 
{ 
   int i = 0; 
   if (l == r) {
       p++;
       ofs<<a<<endl;
       cout<<"Current Permutation..."<<a<<endl;
       cout<<"Permutations Checked: ( " << p << " )"<<endl;
       moveUpNLines(2);
   }
   else { 
       for (i = l; i <= r; i++) {
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i));
       }
   } 
} 

int main()
{
    char arr[10] = { 'A', 'Z', 'O', 'Z', 'I', 'A', 'D', 'N', 'K', 'X'};
    char str[10] = {};
    int p = 1<<10;
    for(int n=0; n<p; n++) {
        vector<char> sel;
        if(__builtin_popcount(n)<4) continue;
        for(int j=0; j<10; j++)
            if((1<<j)&n) 
                sel.push_back(arr[j]);

        for(int k=0; k<sel.size(); k++)
            str[k] = sel[k];

        cout<<endl;
        w++;
        cout<<"Checking all Combinations and Permutations..."<<endl;
        cout<<"Currently checking word: "<<str<<endl;
        cout<<"Words Checked: ( " << w << " )"<<endl;
        
        permute(str, 0, __builtin_popcount(n)-1);
        moveUpNLines(4);

        ofs<<",";
    }
    ofs.close();
    return 0;
}
