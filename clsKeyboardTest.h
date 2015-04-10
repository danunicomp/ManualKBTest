/* 
 * File:   clsKeyboardTest.h
 * Author: dshaffer
 *
 * Created on February 13, 2015, 7:12 AM
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>
#include <fstream>
#include <unistd.h>

#include "clsConfig.h"

#ifndef CLSKEYBOARDTEST_H
#define	CLSKEYBOARDTEST_H

class clsKeyboardTest  {
   
public:
    clsKeyboardTest(void);
    clsKeyboardTest(clsConfig* CurrentConfig);
   clsKeyboardTest(const clsKeyboardTest& orig);
    virtual ~clsKeyboardTest();
    void StartTest(void);
    void StartTestAuto(void);
    int GetWSEFile();
    std::string CurrentFirmware;
    std::string CurrentPID;
    void DebugShowBuffer (void);
    void DebugShowBuffer2 (void);  // *************   TEST
    void RecordNewKeyboard(void);
    void RecordNewKeyboard(std::string PID);
    void RecordNewKeyboard(std::string, int);
    std::string GetUSBPid(void);
    std::string GetUSBPidFilename(void);
    std::string USBPID;
    int LoadWseWithUSBPID(std::string);
    void ShowAllUSBInfo(void);
    void FlashLEDs(void);
    void DebugShowBuffer3 (void);
    void StartTestNEW(void);
    std::vector<int> DebugTestingKeyPress (void);
private:
    clsConfig CurrentConfig;
    std::vector<std::string> ExpectedLines; 
    void PassResult(void);
    void FailResult(void);
    int GetNumberOfLinesInTextFile (std::string filename);
};

#endif	/* CLSKEYBOARDTEST_H */