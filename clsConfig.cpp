/* 
 * File:   clsConfig.cpp
 * Author: dshaffer
 * 
 * Created on February 2, 2015, 7:46 AM
 */

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "clsConfig.h"

using namespace std;

clsConfig::clsConfig() {
}

clsConfig::clsConfig(const clsConfig& orig) {
   
}

clsConfig::~clsConfig() {
}

int clsConfig::ReadConfig(string filename) {
    string line;
    vector<string> config; 
    try {
        ifstream inputFile(filename.c_str());


        vector<string> v; 
        int i = 0;
        int temp;
        while (getline(inputFile, line)) 
        {
            if (line[0] != '#') {
        //        cout << "LINE: " << line  << endl;
                clsConfig::split(line, '\t', v); 

///                KeysPosition.push_back(v.at(UKB_POSITION));
//                temp = atoi(v.at(UKB_KEYCODE).c_str());
//                KeysKeycode.push_back(temp);
//                KeysDescription.push_back(v.at(UKB_DESCRIPTION));

                v.clear();
            }
        }
        return(1);
    } catch(...) {
        cout << "Problem opening file" << endl;
        return(0);
    }
        
}



void clsConfig::split(const string& s, char c, vector<string>& v) {

   string::size_type i = 0; 
   string::size_type j = s.find(c); 
   while (j != string::npos) { 
      v.push_back(s.substr(i, j-i)); 
      i = ++j; 
      j = s.find(c, j); 
      if (j == string::npos) 
         v.push_back(s.substr(i, s.length( ))); 
   } 
} 
