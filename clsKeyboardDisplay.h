/* 
 * File:   clsKeyboardDisplay.h
 * Author: dshaffer
 *
 * Created on March 19, 2015, 12:28 PM
 */

#ifndef CLSKEYBOARDDISPLAY_H
#define	CLSKEYBOARDDISPLAY_H

#include <string>
#include <vector>
#include <ncurses.h>

class clsKeyboardDisplay {
public:
    clsKeyboardDisplay();
    clsKeyboardDisplay(const clsKeyboardDisplay& orig);
    virtual ~clsKeyboardDisplay();
    
    void ShowKeyboard_PC104(void);

    struct KeyGridLayout {
        int Xwidth;
        int Ywidth;
        int Xgridposition;
        int Ygridposition;
        int position;
        std::string graphic;
        std::string scancode;
        WINDOW *window;
        
    };
    std::vector<KeyGridLayout> GridLayout;
     KeyGridLayout NewKey(int, int, int, int, int);
private:
   
};

#endif	/* CLSKEYBOARDDISPLAY_H */

