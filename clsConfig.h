/* 
 * File:   clsConfig.h
 * Author: dshaffer
 *
 * Created on February 2, 2015, 7:46 AM
 */

#ifndef CLSCONFIG_H
#define	CLSCONFIG_H

class clsConfig {
public:
    clsConfig();
    clsConfig(const clsConfig& orig);
    virtual ~clsConfig();
    int ReadConfig(std::string filename);
    std::vector<std::string> WSEFiles;
    std::vector<std::string> PartNumbers;
    std::vector<std::string> ConfigFilename;
     void split(const std::string& s, char c, std::vector<std::string>& v);
     
private:
    
};

#endif	/* CLSCONFIG_H */

