#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>

#include "unicomp.h"

#include "clsNewKeyboard.h"
#include "clsConfig.h"

// Define control keys as part of a 16 bit number
#define LEFT_SHIFT  32768   // 1000 0000 0000 0000  0x8000
#define LEFT_CTRL   16384   // 0100 0000 0000 0000  0x4000
#define LEFT_ALT    8192    // 0010 0000 0000 0000  0x2000 
#define LEFT_GUI    4096    // 0001 0000 0000 0000  0x1000
#define RIGHT_SHIFT 2048    // 0000 1000 0000 0000  0x0800
#define RIGHT_CTRL  1024    // 0000 0100 0000 0000  0x0400
#define RIGHT_ALT   512     // 0000 0010 0000 0000  0x0200
#define RIGHT_GUI   256     // 0000 0001 0000 0000  0x0100

using namespace std;


//const string ConfigFilename = "config.txt";

extern "C" int GetSingleKey (void);
extern "C" int GetKeyBuffer (void);

int readcodes(vector<int>& keycodes, vector<string>& positions);
int TestNewKeyboard(vector<int>& keycodes, vector<string>& positions);
void clean_up ( void );
int ReadSingleCode() ;
int showkeys();
int testsound(void);

void PlayPassSound(void);
void PlayFailSound(void);

const string ConfigPath = unicomp::FindInstallPath("manualkbtest").c_str();
// const string ConfigFilename = "/root/NetBeansProjects/ManualKBTest/config.txt";

int main ()
{
//string ConfigFilename = ConfigPath;
const string ConfigFilename="config.txt";

    
    int kbstat;
    clsNewKeyboard NewKeyboard;
    clsConfig CurrentConfig;

    
    int done =0, x = 0;
    // Read Config File
    cout << "Loading Config...";
    CurrentConfig.ExecutablePath = unicomp::FindInstallPath(ConfigFilename).c_str();
    if ( ! CurrentConfig.ReadConfig(ConfigFilename)) {
        cout << "ERROR OPENING CONFIG FILE: " << ConfigFilename << endl;
        exit(0);
    }
    cout << "OK" << endl;
    
    while (1 && done != 1) {
        int menu;
        cout << endl;
        cout << "Unicomp Manual Keyboard Test, Version " << CurrentConfig.Version << endl;
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
        cout << "5 - DEBUG - SHOW BUFFER" << endl;
//        cout << "6 - SHOW WHOLE BUFFER (New Showkey)" << endl;
//        cout << "7 - TEST SOUND" << endl;
        cout << endl;
        cout << "8 - Test Config" << endl;
        cout << endl;
        cout << "Chose: ";
        cin >> menu;

         int keypressed;
         int keycode, exits;
     ofstream outFile;      
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
             case 8:
                CurrentConfig.ExecutablePath = unicomp::FindInstallPath(ConfigFilename).c_str();
                CurrentConfig.ReadConfig(ConfigFilename);
                cout << "Exe Path: " << CurrentConfig.ExecutablePath << endl;
                cout << "Config file: " << CurrentConfig.ConfigFilename << endl;
                cout << "Version: " << CurrentConfig.Version << endl;
                cout << "Part Numbers: " << CurrentConfig.PartNumberList << endl;
                break;
             case 9: //Show Partnumbers Found
                 for(x=0; x<CurrentConfig.PartNumbers.size(); ++x) {
                     cout << "Part Number: " << CurrentConfig.PartNumbers[x] << "\t" << CurrentConfig.WSEFiles[x] <<  endl;
                 }
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
            
             case 5:
                while(1) {

                if (keycode == 45) ++exits;
                else exits =0;
                if (exits == 3) break;
                keycode = GetKeyBuffer();
                printf("\nBuffer Dump: ");
                 for (x=0; x<18; ++x)  {
//                     printf("%i\t", kbbuf[x]);    
                  }
                cout << keycode << endl; 
                outFile << keycode << endl;
                        
                 }
                 break;
             case 6: 
                
                     
                 outFile.open("output.txt");
             
                 
                 
                 while(1) {
                      
                    if (keycode == 45) ++exits;
                    else exits =0;
                    if (exits == 3) break;
                    keycode = GetKeyBuffer();
 //                  printf("\nBuffer Dump: ");
//                    for (x=0; x<18; ++x)  {
//                        printf("%i\t", kbbuf[x]);    
//                    }
                        cout << keycode << endl; 
                        outFile << keycode << endl;
                        
                 }
                 
             break;
             default:
                done = 1;
                 clean_up();
                 break;                 
         }    
    }
    cout << "Exiting program.." << endl;
}







