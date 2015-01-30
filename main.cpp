#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include "clsNewKeyboard.h"

using namespace std;


int readcodes(vector<int>& keycodes, vector<string>& positions);
int TestNewKeyboard(vector<int>& keycodes, vector<string>& positions);
void clean_up ( void );
int ReadSingleCode() ;
int showkeys();
int testsound(void);

void PlayPassSound(void);
void PlayFailSound(void);

extern "C" int GetSingleKey (void);
extern "C" int GetKeyBuffer (void);

int main ()
{

    const string ConfigPath = "/root/NetBeansProjects/ManualKBTest/";

    int kbstat;
    clsNewKeyboard NewKeyboard;
    int done =0, x = 0;
    while (1 && done != 1) {
        int menu;
        cout << "MENU" << endl;
        if (NewKeyboard.KeyboardSelected) {
            cout << "Current Part Number: " << NewKeyboard.WSEFilename << endl;
            cout << "1 - CHANGE PART NUMBER" << endl;
        }
        else {
             cout << "1 - SELECT PART NUMBER" << endl;
        }
        cout << "2 - START TEST (New showkey function)" << endl;
//        cout << "3 - SHOW KEYS (debugging)" << endl;
//        cout << "4 - Getting Single Key" << endl;
//        cout << "5 - TEST WHOLE KEYBOARD WITH NEW SHOWKEY" << endl;
//        cout << "6 - SHOW WHOLE BUFFER (New Showkey)" << endl;
//        cout << "7 - TEST SOUND" << endl;
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
//            case 12:
//                cout << "Begin pressing keys" << endl;
//                kbstat = readcodes(NewKeyboard.KeysKeycode, NewKeyboard.KeysPosition);
//
//                switch (kbstat){
//                    case 0:
//                        cout << "FAIL" << endl;
//                        break;
//                    case 1:
//                        cout << "PASS" << endl;
//                        break;
//                }
//                clean_up();
//                break;
//            case 3:
//                 showkeys();
//                 clean_up();
//                 break;
//            case 4:
//                  int x;
//                    for (x=0; x<20; ++x)  {
//                        printf("Key Pressed: %i\n", GetSingleKey());    
//                    }
//               done = 1;
//                break;
//             case 6:
//                 while(1) {
//                    if (keycode == 45) ++exits;
//                    else exits =0;
//                    if (exits == 3) break;
//                    keycode = GetKeyBuffer();
//                   printf("\nBuffer Dump: ");
//                    for (x=0; x<18; ++x)  {
//                        printf("%i\t", kbbuf[x]);    
//                    }
//                     cout << "Keycode: " << keycode << endl; 
//                 }
//                 break;
//             case 7:
//               testsound();
//                 break;
             default:
                done = 1;
                 clean_up();
                 break;                 
         }    
    }
    cout << "Exiting program.." << endl;
}