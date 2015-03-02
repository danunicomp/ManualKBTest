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

#include <usb.h>

#include "unicomp.h"
#include "clsKeyboardTest.h"
#include "clsConfig.h"
#include "clsNewKeyboard.h"

using namespace std;

extern void PlayPassSound(void);
extern void PlayFailSound(void);
//extern void PlayBeep(GPIOClass *);
extern void FailBeep(void);
extern void PassBeep(void);

extern "C" int * FullBuffer (void);
 
clsKeyboardTest::clsKeyboardTest(void) {
    cout << "No Config" << endl;
}

clsKeyboardTest::clsKeyboardTest(clsConfig* Config) {
    clsKeyboardTest::CurrentConfig = *Config;
  //  cout << "Config from new test: " << clsKeyboardTest::CurrentConfig.Version << endl;
    
}

clsKeyboardTest::clsKeyboardTest(const clsKeyboardTest& orig) {
}

clsKeyboardTest::~clsKeyboardTest() {
}

void clsKeyboardTest::StartTest() {
   
    int result, exits;
    int currentline = 0;
    int * wholebuffer;
    
    if (clsKeyboardTest::ExpectedLines.size() == 0) {
        return;
    }
        
    string bufferline;
//    cout << endl << "Enter Firmware number: " ;
//    cin >> NewKeyboard.FirmWareNumber;
//    NewKeyboard.FirmWareNumber = unicomp::strtoupper(NewKeyboard.FirmWareNumber);
//    NewKeyboard.WSEFilename = clsKeyboardTest::CurrentConfig.ExecutablePath;
//    NewKeyboard.WSEFilename.append(NewKeyboard.FirmWareNumber);
//    cout << "Firmware: " << NewKeyboard.WSEFilename << endl;

//    if (NewKeyboard.ReadFirmware(NewKeyboard.WSEFilename)) {
    result=1;
    system("stty -echo");
    usleep(900000);
    currentline = 0;
    cout << "Begin pressing keys" << endl; 
    cout << "Firmware: " << clsKeyboardTest::GetUSBPidFilename() << endl;
    while (currentline < clsKeyboardTest::ExpectedLines.size()) {
        wholebuffer = FullBuffer();
        bufferline = unicomp::int_array_to_string(wholebuffer, 19);
        if (wholebuffer[0] == 45) ++exits;
        else exits =0;
        if (exits == 3) break;
        cout << "Read: " << bufferline << "  \t  " << "Expected: " << clsKeyboardTest::ExpectedLines[currentline] << endl;
        if (bufferline == clsKeyboardTest::ExpectedLines[currentline] ) {
        //    cout << "Key #" << currentline << " Good" << endl;
        } else {
             //cout << "Bad" << endl;
            cout << endl << "FAIL FAIL FAIL FAIL" << endl;
            clsKeyboardTest::FailResult();
            result=0;
          //  PlayFailSound();
            FailBeep();
            break;
        }
        ++currentline;
    }
    system("stty echo");
    if (result == 1) {
        cout << endl << "PASS PASS PASS PASS" << endl;
        clsKeyboardTest::PassResult();
        //PlayPassSound();
        PassBeep();
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
    
    //NewKeyboard.FirmWareNumber = unicomp::strtoupper(NewKeyboard.FirmWareNumber);
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

int clsKeyboardTest::LoadWseWithUSBPID(std::string PID="") {
        int wseresult=0;

        if (PID == "" ) {
            cout << endl << "Enter Firmware number: " ;
            cin >> PID;
            cin.clear();
            cin.get();
        }
        
    clsNewKeyboard NewKeyboard;
    
    // cout << endl << "Enter Firmware number: " ;
    NewKeyboard.FirmWareNumber = PID;
     //cin.clear();
     //cin.get();
    
    //NewKeyboard.FirmWareNumber = unicomp::strtoupper(NewKeyboard.FirmWareNumber);
    NewKeyboard.WSEFilename = clsKeyboardTest::CurrentConfig.ExecutablePath;
    NewKeyboard.WSEFilename.append(NewKeyboard.FirmWareNumber);

    //cout << "Filename " << NewKeyboard.WSEFilename;
    
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
    string PID;
    PID = clsKeyboardTest::GetUSBPid();
    if (PID == "0x0000") {
        cout << "NO UNICOMP KEYBOARD DETECTED" << endl;
        return;
    }
    else {
        system("stty -echo");
        cout << "Detected Keyboard Product ID: " << PID << endl;
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
}

void clsKeyboardTest::RecordNewKeyboard(string PID) {
        string newfilename;
        string bufferline;
        ofstream outFile; 
        int exits;
        int * wholebuffer;
        
        cout << "Product ID Detected " << PID << endl; 
               
//        cout << "Are you sure you want to record new keyboard? (Y/N) ";
//        cin >> YN;
        
        if (unicomp::YesNo("Are you sure you want to record new keyboard? ")) {           
            // see if exists
            if (ifstream(PID.c_str())) {
                 std::cout << "File already exists" << std::endl;
                 if (! unicomp::YesNo("FILE " + PID + " EXISTS " +  "Over Write")) {
                    return;    
                 }
            }
            //cout << endl << "Enter new Filename: ";
            //cin >> newfilename;
            newfilename = PID;
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
                    cout << "to remove last few rows that start with 45" << endl << endl;
                    break;
                }
                outFile << bufferline << endl;
                if (wholebuffer[18] == 1999) cout << "Make:  " << wholebuffer[0] << '\t' << wholebuffer[1] << endl;
                if (wholebuffer[18] == 999) cout << "Break: " << wholebuffer[0] << '\t' << wholebuffer[1] << endl << endl;
            }    
        }
}

// Record Keyboard test mode. Will remove last two lines in recorded wse
void clsKeyboardTest::RecordNewKeyboard(string PID, int MODE) {
        string newfilename;
        string bufferline;
        ofstream outFile; 
        int exits;
        int * wholebuffer;
        bool stop = false;
        
        cout << "Product ID Detected " << PID << endl; 
        
        if (unicomp::YesNo("Are you sure you want to record new keyboard? ")) {           
            // see if exists
            if (ifstream(PID.c_str())) {
                 std::cout << "File already exists" << std::endl;
                 if (! unicomp::YesNo("FILE " + PID + " EXISTS " +  "Over Write")) {
                    return;    
                 }
            }
            newfilename = PID;
            outFile.open("newwse");
            usleep(1000000);
            cout << endl << "Begin pressing keys in order." << endl;
            cout << "Hold X for a few seconds to end" << endl << endl;
            while(1 && ! stop) {
                wholebuffer = FullBuffer();

                bufferline = unicomp::int_array_to_string(wholebuffer, 19);

                if (wholebuffer[0] == 45) ++exits;
                else exits =0;
                if (exits == 3) {
                    outFile.close();
                    system("stty -echo");
                    cout << endl << "Done: " << newfilename << endl;
                    //cout << "to remove last few rows that start with 45" << endl << endl;
                    usleep(100000);
                    cin.clear();
                    //cin.get();
                    usleep(100000);
                    stop = true;
                    break;
                }
                outFile << bufferline << endl;
                if (wholebuffer[18] == 1999) cout << "Make:  " << wholebuffer[0] << '\t' << wholebuffer[1] << endl;
                if (wholebuffer[18] == 999) cout << "Break: " << wholebuffer[0] << '\t' << wholebuffer[1] << endl << endl;
            }   
            int numlines, x;
            char str[255];
            numlines = clsKeyboardTest::GetNumberOfLinesInTextFile("newwse")-2;
            ifstream in("newwse");
            outFile.open(newfilename.c_str());
            for (x=1;  x<numlines; ++x)  {
                in.getline(str, 255);  // delim defaults to '\n'
                if(in) {
                   // cout << str << endl;
                    outFile << str << endl;
                }
            }
            outFile.close();
        }
}

void clsKeyboardTest::RecordNewKeyboard(void) {
        char YN;  //for "are you sure" questions
        string newfilename;
        string bufferline;
        ofstream outFile; 
        int exits;
        int * wholebuffer;
        
        cout << "Are you sure you want to record new keyboard? (Y/N) ";
        cin >> YN;

        if (YN == 'y' || YN == 'Y') {
            cout << endl << "Enter new Filename: ";
            cin >> newfilename;
            //newfilename = unicomp::strtoupper(newfilename);
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
                    cout << "to remove last few rows that start with 45" << endl << endl;
                    break;
                }
                outFile << bufferline << endl;
                if (wholebuffer[18] == 1999) cout << "Make:  " << wholebuffer[0] << '\t' << wholebuffer[1] << endl;
                if (wholebuffer[18] == 999) cout << "Break: " << wholebuffer[0] << '\t' << wholebuffer[1] << endl << endl;
            }    
        }
}

void clsKeyboardTest::PassResult() {
    cout << endl;
    cout << "\tPPPPPPPPPP  AAAAAAAAAA  SSSSSSSSSS  SSSSSSSSSS   " << endl;
    cout << "\tPP      PP  AA      AA  SS          SS           " << endl;
    cout << "\tPP      PP  AA      AA  SS          SS           " << endl;
    cout << "\tPP      PP  AA      AA  SS          SS           " << endl;
    cout << "\tPPPPPPPPPP  AAAAAAAAAA  SSSSSSSSSS  SSSSSSSSSS   " << endl;
    cout << "\tPP          AA      AA          SS          SS   " << endl;
    cout << "\tPP          AA      AA          SS          SS   " << endl;
    cout << "\tPP          AA      AA          SS          SS   " << endl;
    cout << "\tPP          AA      AA   SSSSSSSSS  SSSSSSSSSS   " << endl;
    cout << endl;
    return;
}

void clsKeyboardTest::FailResult() {
    cout << endl;
    cout << "\tFFFFFFFFFF  AAAAAAAAAA  IIIIIIIIIIII    LL           " << endl;
    cout << "\tFF          AA      AA       II         LL           " << endl;
    cout << "\tFF          AA      AA       II         LL           " << endl;
    cout << "\tFF          AA      AA       II         LL           " << endl;
    cout << "\tFFFFFFFFFF  AAAAAAAAAA       II         LL           " << endl;
    cout << "\tFF          AA      AA       II         LL           " << endl;
    cout << "\tFF          AA      AA       II         LL           " << endl;
    cout << "\tFF          AA      AA       II         LL           " << endl;
    cout << "\tFF          AA      AA  IIIIIIIIIIII    LLLLLLLLLLLL " << endl;
    cout << endl;
    return;
}
    
string clsKeyboardTest::GetUSBPid(void){
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
                cout << "dev->descriptor.bDescriptorType - " << dev->descriptor.bDescriptorType << endl;
                cout << "dev->descriptor.bDeviceClass: " << dev->descriptor.bDeviceClass << endl;
                cout << "dev->descriptor.bDeviceProtocol: " << dev->descriptor.bDeviceProtocol << endl;
                cout << "dev->descriptor.bDeviceSubClas" << dev->descriptor.bDeviceSubClass << endl;
                cout << "dev->descriptor.bLength" << dev->descriptor.bLength << endl;
                cout << "ev->descriptor.bcdDevice: " << unicomp::int_to_hex(dev->descriptor.bcdDevice) << endl;
                cout << "dev->descriptor.bcdUSB: " << unicomp::int_to_hex(dev->descriptor.bcdUSB) << endl;
                cout << "dev->descriptor.iManufacturer: " << dev->descriptor.iManufacturer << endl;
                cout << "dev->descriptor.iSerialNumber: " << dev->descriptor.iSerialNumber << endl;
                cout << "dev->descriptor.idVendor: " << unicomp::int_to_hex(dev->descriptor.idVendor) << endl;
                cout << "dev->descriptor.idProduct: " << unicomp::int_to_hex(dev->descriptor.idProduct) << endl;
                cout << "dev->filename: " << dev->filename << endl;
                cout << "dev->devnum: " << dev->devnum << endl;
                cout << endl;
            //    cout << "Unicomp Device Found" << endl;
            //    printf("\tID_VENDOR = 0x%04x\n", dev->descriptor.idVendor);
            //    printf("\tID_PRODUCT = 0x%04x\n", dev->descriptor.idProduct);
                return unicomp::int_to_hex(dev->descriptor.idProduct);
              
            }
        }
    return ("0x0000");
}

string clsKeyboardTest::GetUSBPidFilename(void) {
    struct usb_bus *bus;
    struct usb_device *dev;
    usb_init();
    usb_find_busses();
    usb_find_devices();
     
    for (bus = usb_busses; bus; bus = bus->next)
         
        for (dev = bus->devices; dev; dev = dev->next){
            
        //    printf("Trying device %s/%s\n", bus->dirname, dev->filename);
            if (dev->descriptor.idVendor == 0x17f6) {

            //    printf("\tID_VENDOR = 0x%04x\n", dev->descriptor.idVendor);
            //    printf("\tID_PRODUCT = 0x%04x\n", dev->descriptor.idProduct);
                  return unicomp::int_to_hex(dev->descriptor.idProduct);
            }
        }
    cout << "NO UNICOMP USB DEVICES FOUND" << endl;
    return ("0x0000");
}

int clsKeyboardTest::GetNumberOfLinesInTextFile (string filename) {
    string line;
    int number_of_lines = 0;
    ifstream myfile(filename.c_str());

    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
 //           cout<< line << endl;
            number_of_lines++;
        }
        myfile.close();
    }
    return(number_of_lines);
}

