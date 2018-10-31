#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    cout<<"something\nsome";
    Sleep(2000);
    
    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &coninfo);
    coninfo.dwCursorPosition.Y -= 1;    // move up one line
    coninfo.dwCursorPosition.X = 0;    // move to the right the length of the word
    SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);

    Sleep(2000);
    cout<<"something else";
    Sleep(2000);
    return 0;
}
