#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <usb.h>

#include "unicomp.h"

#include "clsNewKeyboard.h"
#include "clsConfig.h"
#include "clsKeyboardTest.h"
#include "CreateMenu.h"

// #include <usb.h>
// #include <libudev.h>


const std::string VERSION = "0.9.15.0220-F";
const std::string CONFIG_FILE = "config.txt";

using namespace std;

/* TODO
 * - add way to have position # in wse file
*   ise LSUSB in linux to autoselect part number
 *  */

extern "C" int * FullBuffer (void );

void clean_up ( void );

void PlayPassSound(void);
void PlayFailSound(void);

void OldTest(clsConfig *);

void getusbinfo(void){
    struct usb_bus *bus;
    struct usb_device *dev;
    usb_init();
    usb_find_busses();
    usb_find_devices();
    for (bus = usb_busses; bus; bus = bus->next)
        for (dev = bus->devices; dev; dev = dev->next){
        //    printf("Trying device %s/%s\n", bus->dirname, dev->filename);
            if (dev->descriptor.idVendor == 0x17f6) {
                cout << "Unicomp Device Found" << endl;
                printf("\tID_VENDOR = 0x%04x\n", dev->descriptor.idVendor);
                printf("\tID_PRODUCT = 0x%04x\n", dev->descriptor.idProduct);
            }
        }
}

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
        entries.clear();
        entries.push_back("Start Test");  selectnumber.push_back(1);
        entries.push_back("Debug - Show Keycode Buffer");  selectnumber.push_back(2);
        entries.push_back("Change Firmware Number");  selectnumber.push_back(9);
        entries.push_back("Old Test"); selectnumber.push_back(10);
        entries.push_back("Record New"); selectnumber.push_back(13);
        entries.push_back("Exit"); selectnumber.push_back(99);

        CreateMenu MainMenu("Unicomp Keyboard Test, Version " + CurrentConfig.Version  , entries, selectnumber);
        MainMenu.Display(KeyboardTest.CurrentFirmware);
        
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
            case 20:
                getusbinfo();
                break;
            case 99:    // exit
                quit = true;
                break;
        }
    }
    cout << "Exiting program.." << endl;
}
