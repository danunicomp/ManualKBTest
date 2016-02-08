#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>  
#include <sstream>
#include <fstream>


#include <sys/ioctl.h> /* ioctl */
#include <unistd.h>
#include <ncurses.h>
//#include <stdio.h>
#include <unistd.h> /* close */
#include <fcntl.h> /* open */
#include <errno.h> /* perror */
#include <linux/kd.h> /* Keyboard macros */

#include "unicomp.h"

#include "clsMenu.h"
#include "clsNewKeyboard.h"
#include "clsConfig.h"
#include "clsKeyboardTest.h"
#include "CreateMenu.h"
#include "cls_UniCodes.h"

using namespace std;

const string VERSION = "1.3.20160208.C";
const string CONFIG_FILE = "config.txt";

/* TODO
 * - add way to have position # in wse file
*   ise LSUSB in linux to autoselect part number
 *  */

extern "C" int * FullBuffer (void );
//extern "C" void LEDTurnOn (void);


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
        entries.push_back("Debug - Show Scancodes");  selectnumber.push_back(2);
        entries.push_back("TEST (old, C usage code");  selectnumber.push_back(3);
        entries.push_back("Change Firmware Number");  selectnumber.push_back(9);
       // entries.push_back("Old Test"); selectnumber.push_back(10);
        entries.push_back("Record New"); selectnumber.push_back(13);
       // entries.push_back("Debug - Cycle over keys"); selectnumber.push_back(70);
       // entries.push_back("Debug - Show 122 Layout"); selectnumber.push_back(71);
       //entries.push_back("Debug - Show TUI GRID"); selectnumber.push_back(80);
       //entries.push_back("Debug - Show TUI"); selectnumber.push_back(90);
       //entries.push_back("Debug - FROM NEW CLASS Show Keycode Buffer");  selectnumber.push_back(97);
        entries.push_back("Debug - Show all USB Devices"); selectnumber.push_back(98);
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
                 cls_UniCodes GetUnicode;
                 vector<int> UniBuffer;
        switch (input)
        {
            case 3:  // ORiginal TEST
                KeyboardTest.LoadWseWithUSBPID(KeyboardTest.USBPID);
                KeyboardTest.StartTest();
              
                break;
            case 97:     // debug - show buffer
            case 2:
                KeyboardTest.DebugShowBuffer();
                break;
            case 1: // NEW TEST, USES VECTOR TO GET UNICODES
                KeyboardTest.LoadWseWithUSBPID(KeyboardTest.USBPID);
                KeyboardTest.StartTestNEW();
                break;
            case 87:     // debug - show buffer
                KeyboardTest.DebugShowBuffer3();
                break;
            case 88:     // debug - show buffer
                KeyboardTest.DebugShowBuffer3();
                break;
            case 9:    // change firmware number
                autodetect = false;
                //KeyboardTest.GetWSEFile();
                break;
            case 14:    // Record New
              KeyboardTest.RecordNewKeyboard();
              break;
            case 13:    // record new with automatic filename
                KeyboardTest.RecordNewKeyboard(KeyboardTest.USBPID,1);
                break;
            case 98:  //DEBUG Show all USB devices
                KeyboardTest.ShowAllUSBInfo();
                break;
            case 99:    // exit
                quit = true;
                break;

        }
    }
    cout << "Exiting program..." << endl;
}