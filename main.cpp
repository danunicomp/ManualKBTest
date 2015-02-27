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

const std::string VERSION = "1.0.0227-B";
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
    bool autodetect = true;
    vector<string> entries;
    vector<int> selectnumber;
    
    clsConfig CurrentConfig;
    CurrentConfig.Version = VERSION;
    // Read Config File
//    cout << "Loading Config...";
//    CurrentConfig.ExecutablePath = unicomp::FindInstallPath(CONFIG_FILE).c_str();
//    if ( ! CurrentConfig.ReadConfig(CONFIG_FILE)) {
//        cout << "ERROR OPENING CONFIG FILE: " << CONFIG_FILE << endl;
//        exit(0);
//    }
//    cout << "OK" << endl;

    clsKeyboardTest KeyboardTest(&CurrentConfig);

    unicomp::ShowHeader();
    
    while (1 && ! quit) {

        entries.clear();
        entries.push_back("Start Test");  selectnumber.push_back(1);
        entries.push_back("Debug - Show Keycode Buffer");  selectnumber.push_back(2);
        entries.push_back("Change Firmware Number");  selectnumber.push_back(9);
        entries.push_back("Old Test"); selectnumber.push_back(10);
        entries.push_back("Record New"); selectnumber.push_back(13);
        entries.push_back("Exit"); selectnumber.push_back(99);

        CreateMenu MainMenu("Unicomp Keyboard Test, Version " + CurrentConfig.Version  , entries, selectnumber);
     
        // MainMenu.Display(KeyboardTest.CurrentFirmware);
        if (autodetect) {
             KeyboardTest.USBPID = KeyboardTest.GetUSBPidFilename();
            if (KeyboardTest.USBPID != "0x0000") {
                cout << "Current Detected PID: " << KeyboardTest.USBPID << endl;
                KeyboardTest.LoadWseWithUSBPID(KeyboardTest.USBPID);
            }
            MainMenu.Display(KeyboardTest.USBPID);
        }
        else
        {
            KeyboardTest.USBPID = KeyboardTest.GetUSBPidFilename();
            cout << "Current PID: " << KeyboardTest.USBPID << endl;
            KeyboardTest.LoadWseWithUSBPID("");
            MainMenu.Display(KeyboardTest.USBPID);
        }
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
                autodetect = false;
                //KeyboardTest.GetWSEFile();
                break;
            case 10:    // old test
              OldTest(&CurrentConfig);
              break;
            case 14:    // Record New
              KeyboardTest.RecordNewKeyboard();
              break;
            case 13:    // record new with automatic filename
                KeyboardTest.RecordNewKeyboard(KeyboardTest.USBPID,1);
                break;
            case 99:    // exit
                quit = true;
                break;
        }
    }
    cout << "Exiting program..." << endl;
}
