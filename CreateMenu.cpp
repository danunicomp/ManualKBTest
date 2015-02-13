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

void CreateMenu::Display(void) {
    std::cout << "=== " << m_title << " ===" << std::endl;
    std::cout << "\n";

    for (int i = 0; i < m_textEntries.size(); i++)
    {
        std::cout << m_SelectNumber.at(i) << " - " << m_textEntries.at(i) << std::endl;
    }
}

int CreateMenu::GetInput()
{
    
    
    std::cout << ">";
    string input;
    int result;
    //getline(cin, input);
    
    int x=0;
    cin.clear();
    std::string s;
    std::getline(std::cin, s);
    std::stringstream stream(s);
    stream >> x;   
    
    return (x);
    

    //cin.get();
    
    
    
    
    while(cin.get() != '\n');
    cin >> result;
//    result = stoi(input);
    return (result);
}