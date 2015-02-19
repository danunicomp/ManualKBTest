/* 
 * File:   CreateMenu.cpp
 * Author: dshaffer
 * 
 * Created on February 12, 2015, 12:08 PM
 */
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "CreateMenu.h"

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
    else {
        cout << "NO File Slected" << endl;
    }
    for (int i = 0; i < m_textEntries.size(); i++)
    {
        std::cout << m_SelectNumber.at(i) << " - " << m_textEntries.at(i) << std::endl;
    }
}

int CreateMenu::GetInput()
{
    string s;
    cout << "> ";
    cin.fail();
    int x=0;
    cin.clear();

    getline(std::cin, s);
    stringstream stream(s);
    stream >> x;   
    cin.clear();
    return (x);
}