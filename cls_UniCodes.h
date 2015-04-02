/* 
 * File:   cls_UniCodes.h
 * Author: dshaffer
 *
 * Created on April 2, 2015, 10:03 AM
 */

#ifndef CLS_UNICODES_H
#define	CLS_UNICODES_H

#include <vector>
#include <termios.h>
class cls_UniCodes {
public:
    cls_UniCodes();
    cls_UniCodes(const cls_UniCodes& orig);
    virtual ~cls_UniCodes();
   //FullBuffer2 (void)
   std::vector<int> GetUnicodeBuffer (void);
    
private:
     void clean_up(int) ;
     void get_mode(int);
     int is_a_console(int);
     int open_a_console(const char *);
     int getfd(const char *);
     struct termios old;
     int oldkbmode;
};

#endif	/* CLS_UNICODES_H */

