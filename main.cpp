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
#include "clsKeyboardTest.h"
#include "CreateMenu.h"

const std::string VERSION = "0.9.15.0213-F";
const std::string CONFIG_FILE = "config.txt";

using namespace std;



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

void OldTest(clsConfig *);

// const string ConfigFilename = "/home/pi/ManualKBTest/config.txt";

int main ()
{
    bool quit = false;
    int input;
    vector<string> entries;
    vector<int> selectnumber;
    
    clsConfig CurrentConfig;
    CurrentConfig.Version = VERSION;
    // Read Config File
    cout << "Loading Config...";
    CurrentConfig.ExecutablePath = unicomp::FindInstallPath(CONFIG_FILE).c_str();
    if ( ! CurrentConfig.ReadConfig(CONFIG_FILE)) {
        cout << "ERROR OPENING CONFIG FILE: " << CONFIG_FILE << endl;
        exit(0);
    }
    cout << "OK" << endl;

    clsKeyboardTest KeyboardTest(&CurrentConfig);
  
    
    while (1 && ! quit) {
        entries.clear();
        entries.push_back("Start Test");  selectnumber.push_back(1);
        entries.push_back("Debug - Show Keycode Buffer");  selectnumber.push_back(2);
        entries.push_back("Change Firmware Number");  selectnumber.push_back(9);
        entries.push_back("Old Test"); selectnumber.push_back(10);
        entries.push_back("Exit"); selectnumber.push_back(99);

        CreateMenu MainMenu("Unicomp Keyboard Test, Version " + CurrentConfig.Version  , entries, selectnumber);
   //     cout << "FIRWARE: " << KeyboardTest.CurrentFirmware << endl;
        MainMenu.Display(KeyboardTest.CurrentFirmware);
        
        input = MainMenu.GetInput();
//        cout << "Input: " << input << endl;
        if (input != 0) {
            switch (input)
            {
                case 1:  // Start Test
                    KeyboardTest.StartTest();
                    break;
                case 2:     // debug - show buffer
                    KeyboardTest.DebugShowBuffer();
                    break;
                case 9:    // change firmware number
                    KeyboardTest.GetWSEFile();
                    break;
                case 10:    // old test
                  OldTest(&CurrentConfig);
                  break;
                case 99:
                    quit = true;
                    break;
            }
        }
    }
    //////////////////////////////
    //Do Main Test
//    OldTest();
    ///////////////////////////////
    cout << "Exiting program.." << endl;
}