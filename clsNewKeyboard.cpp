/* 
 * File:   clsNewKeyboard.cpp
 * Author: dshaffer
 * 
 * Created on January 26, 2015, 7:45 AM
 */
#include <fstream>
#include <iostream>  // just temporary
#include <string>
#include <cstdlib>
#include "unicomp.h"
#include "clsNewKeyboard.h"


using namespace std;
using namespace unicomp;

void clsNewKeyboard::test(string testinput){
    
}



clsNewKeyboard::clsNewKeyboard() {
    KeyboardSelected = 0;
}

clsNewKeyboard::clsNewKeyboard(const clsNewKeyboard& orig) {
}

clsNewKeyboard::~clsNewKeyboard() {
}

int clsNewKeyboard::NewReadWSE (string filename) {
        string line;
    try {
        ifstream inputFile(filename.c_str());

        KeysPosition.clear();
        KeysKeycode.clear();
        KeysDescription.clear();
        vector<string> v; 
        int i = 0;
        int temp;
        while (getline(inputFile, line)) 
        {
            if (line[0] != '#') {
        //        cout << "LINE: " << line  << endl;
                unicomp::uni_split(line, '\t', v); 

                KeysPosition.push_back(v.at(UKB_POSITION));
                temp = atoi(v.at(UKB_KEYCODE).c_str());
                KeysKeycode.push_back(temp);
                KeysDescription.push_back(v.at(UKB_DESCRIPTION));

                v.clear();
            }
        }
        return(1);
    } catch(...) {
        cout << "Problem opening file" << endl;
        return(0);
    }
}

int clsNewKeyboard::ReadWSE(string filename) {
    string line;
    try {
        ifstream inputFile(filename.c_str());

        KeysPosition.clear();
        KeysKeycode.clear();
        KeysDescription.clear();
        vector<string> v; 
        int i = 0;
        int temp;
        while (getline(inputFile, line)) 
        {
            if (line[0] != '#') {
        //        cout << "LINE: " << line  << endl;
                unicomp::uni_split(line, '\t', v); 

                KeysPosition.push_back(v.at(UKB_POSITION));
                temp = atoi(v.at(UKB_KEYCODE).c_str());
                KeysKeycode.push_back(temp);
                KeysDescription.push_back(v.at(UKB_DESCRIPTION));

                v.clear();
            }
        }
        return(1);
    } catch(...) {
        cout << "Problem opening file" << endl;
        return(0);
    }
        
}