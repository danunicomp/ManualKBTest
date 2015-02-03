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

#ifndef UNICOMP_H
#define	UNICOMP_H

namespace unicomp
{
  inline void strip(const std::string& in, std::string& out);
  inline void uni_split(const std::string& s, char c, std::vector<std::string>& v);
  //so forth...
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

#endif	/* UNICOMP_H */

