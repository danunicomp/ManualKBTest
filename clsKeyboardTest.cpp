/* 
 * File:   clsKeyboardTest.cpp
 * Author: dshaffer
 * 
 * Created on February 13, 2015, 7:12 AM
 */


 #include "clsKeyboardTest.h"
 #include "clsConfig.h"

using namespace std;

clsKeyboardTest::clsKeyboardTest(void) {
    cout << "No Config" << endl;
}

clsKeyboardTest::clsKeyboardTest(clsConfig* CurrentConfig) {
    cout << "Config from new test: " << CurrentConfig->Version << endl;
}

clsKeyboardTest::clsKeyboardTest(const clsKeyboardTest& orig) {
}

clsKeyboardTest::~clsKeyboardTest() {
}

void clsKeyboardTest::StartTest() {
    
}

