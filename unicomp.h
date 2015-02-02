/* 
 * File:   unicomp.h
 * Author: dshaffer
 *
 * Created on February 2, 2015, 11:49 AM
 */

#include <iostream>
#include <string>
#include <ctype.h>

#ifndef UNICOMP_H
#define	UNICOMP_H




/// strip a string, remove leading and trailing spaces
void strip(const std::string& in, std::string& out)
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

#endif	/* UNICOMP_H */

