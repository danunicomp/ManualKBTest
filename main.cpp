#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>
#include <fstream>
#include <unistd.h>
// #include <usb.h>

#include "unicomp.h"

#include "clsNewKeyboard.h"
#include "clsConfig.h"
#include "clsKeyboardTest.h"
#include "CreateMenu.h"

// #include <usb.h>
// #include <libudev.h>

const std::string VERSION = "0.9.15.0224-D";
const std::string CONFIG_FILE = "config.txt";

using namespace std;

/* TODO
 * - add way to have position # in wse file
*   ise LSUSB in linux to autoselect part number
 *  */

extern "C" int * FullBuffer (void );

void clean_up ( void );

void OldTest(clsConfig *);

// /////////////////////////////////////////
// MAIN
///////////////////////////////////////////

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
        KeyboardTest.USBPID = KeyboardTest.GetUSBPidFilename();
        cout << "Current PID: " << KeyboardTest.USBPID << endl;
        KeyboardTest.LoadWseWithUSBPID(KeyboardTest.USBPID);
        entries.clear();
        entries.push_back("Start Test");  selectnumber.push_back(1);
        entries.push_back("Debug - Show Keycode Buffer");  selectnumber.push_back(2);
        entries.push_back("Change Firmware Number");  selectnumber.push_back(9);
        entries.push_back("Old Test"); selectnumber.push_back(10);
        entries.push_back("Record New"); selectnumber.push_back(13);
        entries.push_back("Exit"); selectnumber.push_back(99);

        CreateMenu MainMenu("Unicomp Keyboard Test, Version " + CurrentConfig.Version  , entries, selectnumber);
        // MainMenu.Display(KeyboardTest.CurrentFirmware);
        MainMenu.Display(KeyboardTest.USBPID);
        
        input = MainMenu.GetInput();

        switch (input)
        {
            case 1:  // Start Test
                
                KeyboardTest.StartTest();
                break;
            case 2:     // debug - show buffer
                KeyboardTest.DebugShowBuffer();
                break;
            case 8:     // test for LSUSB
 //               lsusb();
                break;
            case 9:    // change firmware number
                KeyboardTest.GetWSEFile();
                break;
            case 10:    // old test
              OldTest(&CurrentConfig);
              break;
            case 13:    // Record New
              KeyboardTest.RecordNewKeyboard();
              break;
            case 99:    // exit
                quit = true;
                break;
        }
    }
    cout << "Exiting program..." << endl;
}
