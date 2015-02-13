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
#include<stdio.h>
//#include "clsConfig.h"

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
private:
    clsConfig CurrentConfig;
    std::vector<std::string> ExpectedLines;
    
};

#endif	/* CLSKEYBOARDTEST_H */

