#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
//#include "clsReadKBMap.h"

using namespace std;

// main() is where program execution begins.
//bool FileReader::getrow(RowMap &row);

void split(const string& s, char c, 
           vector<string>& v) { 
   string::size_type i = 0; 
   string::size_type j = s.find(c); 
   while (j != string::npos) { 
      v.push_back(s.substr(i, j-i)); 
      i = ++j; 
      j = s.find(c, j); 
      if (j == string::npos) 
         v.push_back(s.substr(i, s.length( ))); 
   } 
} 
//class clsReadKBMap;
int ReadWSE()  // COMMA DELIMINATED
{
    
//        clsReadKBMap NewKeyboard;
//        NewKeyboard.WSEFileName = "103.wse.ini";
//        cout << NewKeyboard.WSEFileName;
//        Keyboard.ReadWSEFile("103.wse.ini");
       
       
//////////////////////////
    string line;

    //ifstream inputFile("E:/CLOUD/Work/TestC++ReadList/TestReadList/103.wse.ini");
    ifstream inputFile("103.wse.ini");
    string temp;
    
   
    
    
    
    ///////////////////////////////////////////
    vector<string> v; 
    vector<string> Key;
    // typedef vector<string> AllKeys;
    vector<string> AllKeys; 
    
    
    while (getline(inputFile, line)) 
    {
	cout << "LINE: " << line  << endl;
	split(line, ',', v); 
	
	//Key.swap(v);
	
	int i = 0;
	for (i = 0; i < v.size(); ++i)
	{
	    cout << "All: " << v.at(i) << endl;
	   //AllKeys.push_back(; 
	}
	
	//
	
	//vector<string> Key_v);
	
	v.clear();
    }
    
    	for (int i = 0; i < v.size(); ++i) 
	{ 
	    cout << "Keys: " << v[1][i] << '\n'; 
	} 
    
    cout << "=================ORIGINAL------------" << endl;
//   vector<string> items; 
//    
//       ifstream inputFile("E:/CLOUD/Work/TestC++ReadList/TestReadList/103.wse.ini");
//    while (getline(inputFile, temp, '\t'))
//    {
//	cout << "LINE: " << temp << endl;
//	if(temp.at(0) != '#')
//	    items.push_back(temp);
//	else break;
//    }
//    for (unsigned i = 0; i < items.size(); i++)
//        cout << items[i] << endl;
//    return 0; 
 
    

}

