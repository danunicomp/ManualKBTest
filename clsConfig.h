/* 
 * File:   clsConfig.h
 * Author: dshaffer
 *
 * Created on February 2, 2015, 7:46 AM
 */

#ifndef CLSCONFIG_H
#define	CLSCONFIG_H
// #include "unicomp.h"

#define PROPERTY 0
#define PROP_VALUE 1

class clsConfig {
public:
    clsConfig();
    clsConfig(const clsConfig& orig);
    virtual ~clsConfig();
    int ReadConfig(std::string filename);
    std::string Version;
    std::string PartNumberList;
    std::string ExecutablePath;
    std::string ConfigFilename;
    std::vector<std::string> WSEFiles;
    std::vector<std::string> PartNumbers;
    // std::vector<std::string> ConfigFilename;
    
     //void split(const std::string& s, char c, std::vector<std::string>& v);
     
private:
    
};

#endif	/* CLSCONFIG_H */

