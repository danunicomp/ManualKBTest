#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>
#include <fstream>
#include <unistd.h>

#include "unicomp.h"

#include "clsNewKeyboard.h"
#include "clsConfig.h"

using namespace std;

const string VERSION = "0.9.140221b";
const string CONFIG_FILE = "config.txt";
const string EXE_FILE = "manualkbtest";

//const string ConfigFilename = "config.txt";

//extern "C" int GetSingleKey (void);
//extern "C" int GetKeyCode (void);
//extern "C" int * GetWholeBuffer (void);
extern "C" int * FullBuffer (void );

int readcodes(vector<int>& keycodes, vector<string>& positions);
int TestNewKeyboard(vector<int>& keycodes, vector<string>& positions);
void clean_up ( void );
int ReadSingleCode() ;
int showkeys();
int testsound(void);

void PlayPassSound(void);
void PlayFailSound(void);

const string ConfigPath = unicomp::FindInstallPath(EXE_FILE).c_str();
// const string ConfigFilename = "/home/pi/ManualKBTest/config.txt";

int main ()
{
//  string ConfigFilename = ConfigPath;
//  const string ConfigFilename="config2.txt";

    int currentline = 0;
    string newfilename;
    int kbstat;
 //   clsNewKeyboard NewKeyboard;
    clsConfig CurrentConfig;
    
    int done =0, x = 0;
    int result;
    
    char YN;  //for "are you sure" questions
    
    CurrentConfig.Version = VERSION;
    
    // Read Config File
    cout << "Loading Config...";
    CurrentConfig.ExecutablePath = unicomp::FindInstallPath(CONFIG_FILE).c_str();
    if ( ! CurrentConfig.ReadConfig(CONFIG_FILE)) {
        cout << "ERROR OPENING CONFIG FILE: " << CONFIG_FILE << endl;
        exit(0);
    }
    cout << "OK" << endl;
    
    while (1 && done != 1) {
        int menu;
        clsNewKeyboard NewKeyboard;
        cout << endl;
        cout << "Unicomp Manual Keyboard Test, Version " << CurrentConfig.Version << endl;
        cout << "MENU" << endl;
        cout << "1 - NEW TEST" << endl;
        cout << "2 - START TEST (New showkey function)" << endl;
//        cout << "3 - SHOW KEYS (debugging)" << endl;
//        cout << "4 - Getting Single Key" << endl;
        cout << "5 - DEBUG - SHOW BUFFER" << endl;
//        cout << "6 - SHOW WHOLE BUFFER (New Showkey)" << endl;
//        cout << "7 - TEST SOUND" << endl;
        cout << "6 - RECORD NEW KEYBOARD" << endl;
        cout << endl;
        cout << "8 - Test Config" << endl;

        if (NewKeyboard.KeyboardSelected) {
            cout << "Current Part Number: " << NewKeyboard.WSEFilename << endl;
            cout << "13 - CHANGE PART NUMBER" << endl;
        }
        else {
            cout << "13 - SELECT PART NUMBER" << endl;
        }
        cout << endl;
        cout << "Chose: ";
        cin >> menu;

        int exits;
        int * wholebuffer;
        string bufferline;
        ofstream outFile;      
        switch (menu) {

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
            
            case 5:
                outFile.open("output.txt");
             
                while(1) {
                        wholebuffer = FullBuffer();
                        if (wholebuffer[0] == 45) ++exits;
                        else exits = 0;
                        if (exits == 3) break;
                    for (x=0; x<5; ++x)  {
                        cout << wholebuffer[x] << "\t";
                        wholebuffer[x] = 999;
                            //     printf("New Buf: %i\t", wholebuffer[x]);    
                        }
                    cout << endl;
                    free(wholebuffer)  ;
                }
                outFile.close();
                break;
            case 6:  //Record new keyboard
                cout << "Are you sure you want to record new keyboard? (Y/N) ";
                cin >> YN;
                
                if (YN == 'y' || YN == 'Y') {
                    cout << endl << "Enter new Filename: ";
                    cin >> newfilename;
                    newfilename = unicomp::strtoupper(newfilename);
                    outFile.open(newfilename.c_str());
                    usleep(1000000);
                    cout << endl << "Begin pressing keys in order." << endl;
                    cout << "Hold X for a few seconds to end" << endl << endl;
                    while(1) {
                        wholebuffer = FullBuffer();

                        bufferline = unicomp::int_array_to_string(wholebuffer, 19);

                        if (wholebuffer[0] == 45) ++exits;
                        else exits =0;
                        if (exits == 3) {
                            outFile.close();
                            cout << endl << "will have to edit file: " << newfilename << endl;
                            cout << "to remove last few rows that start with 45" << endl;
                            break;
                        }
                        outFile << bufferline << endl;
                        if (wholebuffer[18] == 1999) cout << "Make:  " << wholebuffer[0] << endl;
                        if (wholebuffer[18] == 999) cout << "Break: " << endl;
                    }
                }
            break;
             
            case 1:
                cout << endl << "Enter Firmware number: " ;
                cin >> NewKeyboard.FirmWareNumber;
                NewKeyboard.FirmWareNumber = unicomp::strtoupper(NewKeyboard.FirmWareNumber);
                NewKeyboard.WSEFilename = CurrentConfig.ExecutablePath;
                NewKeyboard.WSEFilename.append(NewKeyboard.FirmWareNumber);
                cout << "Firmware: " << NewKeyboard.WSEFilename << endl;
                
                if (NewKeyboard.ReadFirmware(NewKeyboard.WSEFilename)) {
                    result=1;
                    usleep(900000);
                    currentline = 0;
                    cout << "Begin pressing keys" << endl; 
                    while (currentline < NewKeyboard.InputLines.size()) {
                        wholebuffer = FullBuffer();
                        bufferline = unicomp::int_array_to_string(wholebuffer, 19);
                        if (wholebuffer[0] == 45) ++exits;
                        else exits =0;
                        if (exits == 3) break;
                        cout << "Read: " << bufferline << "\t" << "Expected: " << NewKeyboard.InputLines[currentline] << endl;
                        if (bufferline == NewKeyboard.InputLines[currentline] ) {
                            cout << "Key #" << currentline << " Good" << endl;
                        } else {
                             //cout << "Bad" << endl;
                            cout << endl << "FAIL  FAIL FAIL FAIL" << endl;
                            result=0;
                            PlayFailSound();
                            break;
                        }
                        ++currentline;
                    }
                    if (result == 1) {
                        cout << endl << "PASS  PASS PASSS" << endl;
                        PlayPassSound();
                    }
                }
                else {
                    cout << "Problem opening file: " << NewKeyboard.WSEFilename << endl;
                }
                break;

                case 13:  //Obsolete
                    NewKeyboard.WSEFilename = "/home/pi/ManualKBTest/122-UB40B5A.wse";
                    if (NewKeyboard.ReadWSE(NewKeyboard.WSEFilename)) {
                        cout << "Loaded " << NewKeyboard.KeysKeycode.size() << " Keys from File: " << NewKeyboard.WSEFilename << endl;
                        NewKeyboard.KeyboardSelected = 1;
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