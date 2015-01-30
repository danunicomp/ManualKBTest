/* 
 * File:   clsNewKeyboard.h
 * Author: dshaffer
 *
 * Created on January 26, 2015, 7:45 AM
 */
#include <string>
#include <vector>
//#include <boolean>

#ifndef CLSNEWKEYBOARD_H
#define	CLSNEWKEYBOARD_H

#define UKB_POSITION 0
#define UKB_KEYCODE 1
#define UKB_DESCRIPTION 2

class clsNewKeyboard {
public:
    clsNewKeyboard();
    clsNewKeyboard(const clsNewKeyboard& orig);
    virtual ~clsNewKeyboard();
    
    int ReadWSE(std::string);
    
    std::string WSEFilename;
    std::string SingleKey[3];
    std::vector<std::string> KeysPosition;
    std::vector<int> KeysKeycode;
    std::vector<std::string> KeysDescription;
    
    bool KeyboardSelected;
    
    void split(const std::string& s, char c, std::vector<std::string>& v);
    void test(std::string);
    
private:
  
};

#endif	/* CLSNEWKEYBOARD_H */

