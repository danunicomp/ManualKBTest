/* 
 * File:   unicomp.h
 * Author: dshaffer
 *
 * Created on February 2, 2015, 11:49 AM
 */

#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <locale>

#include <fstream>
#include <sstream>
#include <iomanip>   
#include <usb.h>

#ifndef UNICOMP_H
#define	UNICOMP_H

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

namespace unicomp
{
 // template< typename T >
  ///Strip leading and tailiing
  inline void strip(const std::string& in, std::string& out);
  ///Split a delimanated string
  inline void uni_split(const std::string& s, char c, std::vector<std::string>& v);
  ///Find path where current exe is. Used to find config file
  inline std::string FindInstallPath(std::string exename);
  /// Convert a string to upper case.
  inline std::string strtoupper(std::string& str);
  inline std::string int_array_to_string(int int_array[], int size_of_array);
  inline  std::string int_to_hex( int );
  inline bool YesNo(std::string question);
  inline void ShowHeader(void);
  inline std::string stripspace(const std::string in);
  inline std::string IntVectorToString (std::vector<int>);
}


//template< typename T >
std::string unicomp::int_to_hex( int i )
{
  std::stringstream stream;
  stream << "0x" 
         << std::setfill ('0') << std::setw(4) 
         << std::hex << i;
  return stream.str();
}

/// strip a string, remove leading and trailing spaces
void unicomp::strip(const std::string& in, std::string& out)
{
    std::string::const_iterator b = in.begin(), e = in.end();

    // skipping leading spaces
    while (isspace(*b)){
        ++b;
    }

    if (b != e){
        // skipping trailing spaces
        while (isspace(*(e-1))){
            --e;
        }
    }

    out.assign(b, e);
}

//Remove trailing space
std::string unicomp::stripspace(const std::string in)
{
    std::string cleanstring;
    
    std::string::const_iterator b = in.begin(), e = in.end();
    if (b != e){
        // skipping trailing spaces
        while (isspace(*(e-1))){
            --e;
        }
         cleanstring.assign(b, e);

         return cleanstring;
    }
    return in;
}

///Split a delimanated string
void unicomp::uni_split(const std::string& s, char c, std::vector<std::string>& v) {

   std::string::size_type i = 0; 
   std::string::size_type j = s.find(c); 
   while (j != std::string::npos) { 
      v.push_back(s.substr(i, j-i)); 
      i = ++j; 
      j = s.find(c, j); 
      if (j == std::string::npos) 
         v.push_back(s.substr(i, s.length( ))); 
   } 
} 

///Find path where current exe is. Used to find config file
std::string unicomp::FindInstallPath(std::string exename)
{
    std::string sret="";
    int pid = (int)getpid();
    bool b=false;
    std::string sf, s;
    std::stringstream ss;
    ss << "/proc/" << pid << "/maps";
    sf = ss.str();
    std::ifstream ifs(sf.c_str());
    size_t pos1, pos2;
    while (!b && ifs.good())
    {
        std::getline(ifs, s);
        if ((pos1 = s.rfind("manualkbtest")) != std::string::npos)
        {
            if ((pos2 = s.find_first_of('/')) != std::string::npos)
            sret = s.substr(pos2, pos1 - pos2);
            b = true;
        }
    }
    if (!b) sret = "";
    ifs.close();
    // cout << sret;
    return sret;
}

/// Convert a string to upper case.
/// if already is uppercase, ignores.
std::string unicomp::strtoupper(std::string& str)
{
	std::locale settings;
	std::string converted;

	for(unsigned int i = 0; i < str.size(); ++i)
		converted += (std::toupper(str[i], settings));
	
	return converted;
}

std::string unicomp::int_array_to_string(int int_array[], int size_of_array) {
    std::string line;
    std::ostringstream oss("");
  for (int temp = 0; temp < size_of_array; temp++) {
    oss << int_array[temp] << " ";
  }
  line = oss.str();
  unicomp::strip(line, line);
  return line;

}

bool unicomp::YesNo(std::string question) {
    char YN;
    std::cout << question << " (Y/N) ";
    // std::cin >> YN;
    
    std::string s;
    std::cin.fail();
    std::cin.clear();
    getline(std::cin, s);
    std::stringstream stream(s);
    stream >> YN;   
    std::cin.clear();
    
    if (YN == 'y' || YN == 'Y') {
        std::cin.clear();
       return true; 
    }
    else
    {
        std::cin.clear();
        return false;
    }
}


void unicomp::ShowHeader(void){
    std::cout << std::endl;
    std::cout << "UU       UU  NN       NN  IIIIIIIIII  CCCCCCCCC  OOOOOOOOOOO  MM          MM  PPPPPPPPPP" << std::endl;
    std::cout << "UU       UU  NN N     NN      II      CC         OO       OO  MMM        MMM  PP      PP" << std::endl;
    std::cout << "UU       UU  NN  N    NN      II      CC         OO       OO  MM  M     M MM  PP      PP" << std::endl;
    std::cout << "UU       UU  NN   N   NN      II      CC         OO       OO  MM   M   M  MM  PPPPPPPPPP" << std::endl;
    std::cout << "UU       UU  NN    N  NN      II      CC         OO       OO  MM    M M   MM  PP" << std::endl;
    std::cout << "UU       UU  NN     N NN      II      CC         OO       OO  MM     M    MM  PP" << std::endl;
    std::cout << "UU       UU  NN      NNN      II      CC         OO       OO  MM          MM  PP" << std::endl;
    std::cout << "UUUUUUUUUUU  NN       NN  IIIIIIIIII  CCCCCCCCC  OOOOOOOOOOO  MM          MM  PP" << std::endl;
    std::cout << std::endl;
}

std::string unicomp::IntVectorToString (std::vector<int> intvector) {
    unsigned int x;
    std::string line;
       std::ostringstream oss(""); 

    
    for (x=0; x<intvector.size(); ++x) {
    
        oss << intvector.at(x) << " ";
    }
  //     oss << intvector.at(intvector.size()-1);   // do this so no space at end
       
      line = oss.str();
      return line;
}


#endif	/* UNICOMP_H */

