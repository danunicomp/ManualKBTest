/* 
 * File:   clsBIOSTypeMenu.h
 * Author: dshaffer
 *
 * Created on March 18, 2015, 1:12 PM
 */

#ifndef CLSBIOSTYPEMENU_H
#define	CLSBIOSTYPEMENU_H

#include <ncurses.h>
#include <string>
#include "clsConfig.h"

class clsBIOSTypeMenu {
public:
    clsBIOSTypeMenu();
    clsBIOSTypeMenu( clsConfig* Config);
    clsBIOSTypeMenu(const clsBIOSTypeMenu& orig);
    virtual ~clsBIOSTypeMenu();
    
    int mainmenu();
    std::string choices[5];
    //std::string *choices = new std::string[5] ;
    void print_menu(WINDOW *menu_win, int highlight);
    int nchoices;
    void ShowKeyboard(void);
private:
clsConfig CurrentConfig;

};

#endif	/* CLSBIOSTYPEMENU_H */

