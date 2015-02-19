/* 
 * File:   clsKeyboardTest.cpp
 * Author: dshaffer
 * 
 * Created on February 13, 2015, 7:12 AM
 */

/*
 TODO:
 * put length off buffer to show on test in config
 * change unicomp function that converts int array to string so changes 1999 to make and 999 to break
 
 */


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>
#include <fstream>
#include <unistd.h>

#include "unicomp.h"
#include "clsKeyboardTest.h"
#include "clsConfig.h"
#include "clsNewKeyboard.h"

using namespace std;

extern void PlayPassSound(void);
extern void PlayFailSound(void);
extern "C" int * FullBuffer (void);
 
clsKeyboardTest::clsKeyboardTest(void) {
    cout << "No Config" << endl;
}

clsKeyboardTest::clsKeyboardTest(clsConfig* Config) {
    clsKeyboardTest::CurrentConfig = *Config;
    cout << "Config from new test: " << clsKeyboardTest::CurrentConfig.Version << endl;
    
}

clsKeyboardTest::clsKeyboardTest(const clsKeyboardTest& orig) {
}

clsKeyboardTest::~clsKeyboardTest() {
}

void clsKeyboardTest::StartTest() {
   
    clsNewKeyboard NewKeyboard;
     int result, exits;
     int currentline = 0;
     int * wholebuffer;
     
     string bufferline;
//    cout << endl << "Enter Firmware number: " ;
//    cin >> NewKeyboard.FirmWareNumber;
//    NewKeyboard.FirmWareNumber = unicomp::strtoupper(NewKeyboard.FirmWareNumber);
//    NewKeyboard.WSEFilename = clsKeyboardTest::CurrentConfig.ExecutablePath;
//    NewKeyboard.WSEFilename.append(NewKeyboard.FirmWareNumber);
//    cout << "Firmware: " << NewKeyboard.WSEFilename << endl;

//    if (NewKeyboard.ReadFirmware(NewKeyboard.WSEFilename)) {
    result=1;
    usleep(900000);
    currentline = 0;
    cout << "Begin pressing keys" << endl; 
    while (currentline < clsKeyboardTest::ExpectedLines.size()) {
        wholebuffer = FullBuffer();
        bufferline = unicomp::int_array_to_string(wholebuffer, 19);
        if (wholebuffer[0] == 45) ++exits;
        else exits =0;
        if (exits == 3) break;
        cout << "Read: " << bufferline << "\t" << "Expected: " << clsKeyboardTest::ExpectedLines[currentline] << endl;
        if (bufferline == clsKeyboardTest::ExpectedLines[currentline] ) {
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
//    }
//    else {
//        cout << "Problem opening file: " << NewKeyboard.WSEFilename << endl;
//    }
    
}

int clsKeyboardTest::GetWSEFile(void)
{
    int wseresult=0;

    clsNewKeyboard NewKeyboard;
    
    cout << endl << "Enter Firmware number: " ;
    cin >> NewKeyboard.FirmWareNumber;
     cin.clear();
     cin.get();
    
    NewKeyboard.FirmWareNumber = unicomp::strtoupper(NewKeyboard.FirmWareNumber);
    NewKeyboard.WSEFilename = clsKeyboardTest::CurrentConfig.ExecutablePath;
    NewKeyboard.WSEFilename.append(NewKeyboard.FirmWareNumber);

    wseresult = NewKeyboard.ReadFirmware(NewKeyboard.WSEFilename);
    
    if (wseresult==1) {
        clsKeyboardTest::CurrentFirmware = NewKeyboard.FirmWareNumber;
        NewKeyboard.InputLines.swap(clsKeyboardTest::ExpectedLines);
    }
    else {
        cout << endl << "** PROBLEM LOADED FIRMWARE NUMBER **" << endl << endl;
    }
}

void clsKeyboardTest::DebugShowBuffer (void) {
    usleep(900000);
    cout << "Debug Test - Hold X to cancel" << endl;
    int * wholebuffer;
    int exits, x;
    while(1 && exits < 3) {
        wholebuffer = FullBuffer();
        if (wholebuffer[0] == 45) ++exits;
        else exits = 0;
        for (x=0; x<6; ++x)  {
            cout << wholebuffer[x] << "\t";
        }
        if (wholebuffer[18] == 1999) {
            cout << "MAKE" << endl;
        }
        else if (wholebuffer[18] == 999) {
            cout << "BREAK" << endl << endl;
        }
        else {
            cout << endl;
        }
        
        free(wholebuffer)  ;
    }
}