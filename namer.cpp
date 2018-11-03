#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <Windows.h>
using namespace std;

std::ofstream ofs;

static int p=0, w=0;

void moveUpNLines(int n) {
    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &coninfo);

    // Go up N lines
    coninfo.dwCursorPosition.Y -= n;
    coninfo.dwCursorPosition.X = 0;
    SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);

    // Print N new lines, clear N lines
    // for(int k=0; k<n; k++) cout<<'\n';

    // // Go up N lines again
    // coninfo.dwCursorPosition.Y -= n;
    // coninfo.dwCursorPosition.X = 0;
    // SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);
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
    char arr[10] = { 'A', 'Z', 'O', 'Z', 'I', 'A', 'D', 'N', 'K', 'X' };
    char str[10] = {};
    int p = 1<<10;

    char ch[2];
    cout<<"Append(ap) or Overwrite(ow)?...";
    cin>>ch;
    if(strcmp(ch, "ap")==0) ofs.open("names.csv", std::ofstream::app);
    else if(strcmp(ch, "ow")==0) ofs.open("names.csv", std::ofstream::out);
    //moveUpNLines(2);

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
