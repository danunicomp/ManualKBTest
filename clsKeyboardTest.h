/* 
 * File:   clsKeyboardTest.h
 * Author: dshaffer
 *
 * Created on February 13, 2015, 7:12 AM
 */
#include "clsConfig.h"
//#include "clsConfig.h"

#ifndef CLSKEYBOARDTEST_H
#define	CLSKEYBOARDTEST_H

class clsKeyboardTest  {
public:
    clsKeyboardTest(void);
    clsKeyboardTest(clsConfig* CurrentConfig);
   clsKeyboardTest(const clsKeyboardTest& orig);
    virtual ~clsKeyboardTest();
    void StartTest(void);
private:

};

#endif	/* CLSKEYBOARDTEST_H */

