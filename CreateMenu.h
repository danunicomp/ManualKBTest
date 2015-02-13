/* 
 * File:   CreateMenu.h
 * Author: dshaffer
 *
 * Created on February 12, 2015, 12:08 PM
 */

#include <vector>

#ifndef CREATEMENU_H
#define	CREATEMENU_H

class CreateMenu {
public:
    CreateMenu(std::string title, std::vector<std::string> textEntries, std::vector<int> selectnumber);
//    CreateMenu(const CreateMenu& orig);
    void Display(std::string);
    virtual ~CreateMenu();
    int GetInput();
private:
    std::string m_title;
    std::vector<std::string> m_textEntries;
    std::vector<int> m_SelectNumber;
};

#endif	/* CREATEMENU_H */

