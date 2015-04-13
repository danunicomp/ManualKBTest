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
#include <string>
#include "unicomp.h"

#include "clsConfig.h"


using namespace std;

clsConfig::clsConfig() {
}

clsConfig::clsConfig(const clsConfig& orig) {
   
}

clsConfig::~clsConfig() {
}

int clsConfig::ReadConfig(string filename) {
    
    WSEFiles.clear();
    PartNumbers.clear();
    
    string line, pathandfile;
    vector<string> config; 
    pathandfile = ExecutablePath;
    ConfigFilename = filename;
    pathandfile.append(ConfigFilename);
    
  //  cout << "FILE: " << pathandfile << endl;
    try {
        ifstream inputFile(pathandfile.c_str());
        if (! inputFile.good()) return 0;
        vector<string> v; 
        string property;
        
        while (getline(inputFile, line)) 
        {
            unicomp::strip(line,line);
            if (line[0] != '#' && line[0] != '\n' && line[0] != '\0') {
 //               cout << "LINE: " << line  << endl;
                unicomp::uni_split(line, ',', v); 
               
                property =  v.at(PROPERTY);
                if (property == "version" ) {
                    Version = v.at(PROP_VALUE);
                }
                if (property == "pnlist" ) {
                    PartNumberList = v.at(PROP_VALUE);
                }
                if (property== "WSE") {
                    PartNumbers.push_back(unicomp::strtoupper(v.at(PROP_VALUE))) ;
                    WSEFiles.push_back(v.at(PROP_VALUE_SEC)) ;
                }
                v.clear();
            }
        }
        return(1);
    } catch(std::exception const& e) {
        cout << "*****Problem opening file: " << filename << endl;
        cout << "There was an error: " << e.what() << endl;
        return(0);
    }
        
}


