#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include "clsNewKeyboard.h"
//#include <array>

using namespace std;

//const string WSEPATH = "/usr/root/";

//int arr[] = {1, 59,60,61,62,63,64,65,66,67,68,87,88,99,70,119,41,2,3,4,5,6,7,8,9,10,11,12,13,14,110,102,104,69,98,55,74,78,73,72,71,109,107,111,43,27,26,25,24,23,22,21,20,19,18,17,16,15,58,30,31,32,33,34,35,36,37,38,39,40,28,75,76,77,78,96,81,80,79,103,54,53,52,51,50,49,48,47,46,45,44,42,29,125,56,57,100,127,97,105,108,106,82,83 };
//vector<int> keycodes(arr, arr+104);


// multi dimensional array. first is position then keycode
//int test[][2] = { 
//    {110,1},    {112,59},   {113,60},   {114,61},   {115,62},
//    {116,63},   {117,64},   {118,65},   {119,66},   {120,67},
//    {121,68},   {122,87},   {123,88},   {124,99},   {125,70},
//    {126,119},  {1,41},     {2,2},      {3,3},      {4,4},
//    {5,5},      {6,6},      {7,7},      {8,8},      {9,9},
//    {10,10},    {11,11},    {12,12},    {13,13},    {15,14},
//    {75,110},   {80,102},   {85,104},   {90,69},    {95,98},
//    {100,55},   {105,74},   {106,78},   {101,73},   {96,72},
//    {91,71},    {86,109},   {81,107},   {76,111},   {29,43},
//    {28,27},    {27,26},    {26,25},    {25,24},    {24,23},
//    {23,22},    {22,21},    {20,19},    {19,18},    {18,17},
//    {17,16},    {16,15},    {30,58},    {31,30},    {32,31},
//    {33,32},    {34,33},    {35,34},    {36,35},    {37,36},
//    {38,37},    {39,38},    {40,39},    {31,40},    {43,28},
//    {92,75},    {97,76},    {102,77},   {106,78},   {108,96},
//    {103,81},   {98,80},    {93,79},    {83,103},   {57,54},
//    {55,53},    {54,52},    {53,51},    {52,50},    {51,49},
//    {50,48},    {49,47},    {48,46},    {47,45},    {46,44},
//    {44,42},    {58,29},    {59,125},   {60,56},    {61,57},
//    {62,100},   {65,127},   {64,97},    {79,105},   {84,108},
//    {89,106},   {99,82},    {104,83}
//};


//int keycodes[] {1, 59,60,61,62,63 };
//vector<int> keycodes = {1, 59,60,61,62,63}; 


int readcodes(vector<int>& keycodes, vector<string>& positions);
int TestNewKeyboard(vector<int>& keycodes, vector<string>& positions);
void clean_up ( void );
int ReadSingleCode() ;
int showkeys();
int testsound(void);
void PlayPassSound(void);
void PlayFailSound(void);
//int *kbbuf;

extern "C" int GetSingleKey (void);
extern "C" int GetKeyBuffer (void);



int main ()
{
//    string wsefile = WSEPATH + "103.wse";
    
   // cout << wsefile;
    int kbstat;
//     clsNewKeyboard* NewKeyboard = new clsNewKeyboard();
    clsNewKeyboard NewKeyboard;
  //  char *kbbuf;
    int done =0, x = 0;
    while (1 && done != 1) {
        int menu;
         cout << "MENU" << endl;
         if (NewKeyboard.KeyboardSelected) {
//             delete NewKeyboard;
  //           clsNewKeyboard NewKeyboard;
             cout << "Current Part Number: " << NewKeyboard.WSEFilename << endl;
            cout << "1 - CHANGE PART NUMBER" << endl;
         }
         else {
             cout << "1 - SELECT PART NUMBER" << endl;
         }
         cout << "2 - START TEST (New showkey function)" << endl;
         cout << "3 - SHOW KEYS (debugging)" << endl;
         cout << "4 - Getting Single Key" << endl;
         cout << "5 - TEST WHOLE KEYBOARD WITH NEW SHOWKEY" << endl;
         cout << "6 - SHOW WHOLE BUFFER (New Showkey)" << endl;
         cout << "7 - TEST SOUND" << endl;
         cout << endl;
         cout << "Chose: ";
         cin >> menu;

         int keypressed;
         int keycode, exits;
         switch (menu) {
            case 1:
                NewKeyboard.WSEFilename = "/root/NetBeansProjects/ManualKBTest/122-UB40B5A.wse";
                if (NewKeyboard.ReadWSE(NewKeyboard.WSEFilename)) {
                    cout << "Loaded " << NewKeyboard.KeysKeycode.size() << " Keys from File: " << NewKeyboard.WSEFilename << endl;
                    NewKeyboard.KeyboardSelected = 1;
                }
                //NewKeyboard.ReadWSE();
                 break;
            case 12:
                cout << "Begin pressing keys" << endl;
                kbstat = readcodes(NewKeyboard.KeysKeycode, NewKeyboard.KeysPosition);
                //cout << "STATUSL " << kbstat;
                switch (kbstat){
                    case 0:
                        cout << "FAIL" << endl;
                        break;
                    case 1:
                        cout << "PASS" << endl;
                        break;
                }
                
                // cout << "Keyboard Status: " << kbstat<< endl;
                
                clean_up();
                break;
            case 3:
                 showkeys();
                 clean_up();
                 break;
            case 4:
                  int x;
                    for (x=0; x<20; ++x)  {
                        printf("Key Pressed: %i\n", GetSingleKey());    
                    }
               done = 1;
                break;
             case 2:
                cout << "Begin pressing keys" << endl;
                kbstat = TestNewKeyboard(NewKeyboard.KeysKeycode, NewKeyboard.KeysPosition);
                switch (kbstat){
                    case 0:
                        cout << "***************************  FAIL" << endl;
                        PlayFailSound();
                        break;
                    case 1:
                       
                        cout << "PASS PASS PASS PASS" << endl;
                         PlayPassSound();
                        break;
                }
                clean_up();
                break;
             case 6:
                 while(1) {
                    if (keycode == 45) ++exits;
                    else exits =0;
                    if (exits == 3) break;
                    keycode = GetKeyBuffer();
 //                   printf("\nBuffer Dump: ");
//                    for (x=0; x<18; ++x)  {
//                        printf("%i\t", kbbuf[x]);    
//                    }
                     cout << "Keycode: " << keycode << endl; 
                 }
                 break;
             case 7:
               testsound();
                 break;
             default:
                done = 1;
                 clean_up();
                 break;                 
         } 
       
    }
    
    cout << "Exiting program.." << endl;
    
}