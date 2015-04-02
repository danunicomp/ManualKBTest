/* 
 * File:   clsMenu.h
 * Author: dshaffer
 *
 * Created on March 31, 2015, 11:44 AM
 */

#ifndef CLSMENU_H
#define	CLSMENU_H

const int MENU_START = 1;
const int MENU_MANUAL_CODE = 9;

const int MENU_DEB_SHOW_TUI = 90;
const int MENU_DEB_SHOW_BUFF = 97;


class clsMenu {
public:
    clsMenu();
    clsMenu(const clsMenu& orig);
    virtual ~clsMenu();
    
    int MainMenu(void);
    
private:

};

#endif	/* CLSMENU_H */

