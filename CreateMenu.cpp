/* 
 * File:   CreateMenu.cpp
 * Author: dshaffer
 * 
 * Created on February 12, 2015, 12:08 PM
 */
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>  
#include "CreateMenu.h"
#include <sstream>
#include <iostream>
#include <string>
#include <istream>
#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

CreateMenu::CreateMenu(std::string title, std::vector<std::string> textEntries, std::vector<int> selectnumber) {
    this->m_title = title;
    this->m_textEntries = textEntries;
    this->m_SelectNumber = selectnumber;
}

//CreateMenu::CreateMenu(const CreateMenu& orig) {
//}

CreateMenu::~CreateMenu() {
}

void CreateMenu::Display(std::string CurrentFirmware = "") {
    std::cout << "=== " << m_title << " ===" << std::endl;
    std::cout << "\n";
    if (CurrentFirmware != "") {
        cout << "Current Firmware: " << CurrentFirmware << endl;
    }
    for (int i = 0; i < m_textEntries.size(); i++)
    {
        std::cout << m_SelectNumber.at(i) << " - " << m_textEntries.at(i) << std::endl;
    }
}

int CreateMenu::GetInput()
{
     std::string s;
    std::cout << ">";
    string input;
    int result;
    //getline(cin, input);
    cin.fail();
    int x=0;
    cin.clear();

    std::getline(std::cin, s);
    
    if (s[0] != '\0') {
        std::stringstream stream(s);
        stream >> x;   
        cin.clear();
        return (x);
    }
    else
    {
        cout << "Found 0" << endl;
        return(0);
    }

}