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


class clsBIOSTypeMenu {
public:
    clsBIOSTypeMenu();
    clsBIOSTypeMenu(const clsBIOSTypeMenu& orig);
    virtual ~clsBIOSTypeMenu();
    int mainmenu();
    std::string choices[5];
    //std::string *choices = new std::string[5] ;
    void print_menu(WINDOW *menu_win, int highlight);
    int nchoices;
private:


};

#endif	/* CLSBIOSTYPEMENU_H */

