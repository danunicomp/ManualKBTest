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
    int GetWSEFile();
    std::string CurrentFirmware;
    std::string CurrentPID;
    void DebugShowBuffer (void);
    void RecordNewKeyboard(void);
    void RecordNewKeyboard(std::string PID);
    void RecordNewKeyboard(std::string, int);
    int GetUSBPid(void);
    std::string GetUSBPidFilename(void);
    std::string USBPID;
    int LoadWseWithUSBPID(std::string);
private:
    clsConfig CurrentConfig;
    std::vector<std::string> ExpectedLines; 
    void PassResult(void);
    void FailResult(void);
    int GetNumberOfLinesInTextFile (std::string filename);
};

#endif	/* CLSKEYBOARDTEST_H */