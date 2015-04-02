/* 
 * File:   cls_UniCodes.cpp
 * Author: dshaffer
 * 
 * Created on April 2, 2015, 10:03 AM
 */


#include <vector>
#include <termios.h>
#include <linux/keyboard.h>
#include <stdlib.h>
#include <sys/ioctl.h> /* ioctl */
#include <fcntl.h> /* open */
#include <stdio.h>
#include <linux/kd.h>
#include <string>
#include <iostream>
#include <signal.h>

#include "cls_UniCodes.h"

cls_UniCodes::cls_UniCodes() {
}

cls_UniCodes::cls_UniCodes(const cls_UniCodes& orig) {
}

cls_UniCodes::~cls_UniCodes() {
}


using namespace std;

///////////////////////////////////////////////////////
 std::vector<int> GetUnicodeBuffer (void) {
     
 }
 
 int getfd(const char *fnam);
//int tmp;	/* for debugging */





 // ******* CLEAN UP ************************
void cls_UniCodes::clean_up(int fd) {
    if (ioctl(fd, KDSKBMODE, cls_UniCodes::oldkbmode)) {
        close(fd);
        return;
    }
    //if (tcsetattr(fd, 0, &cls_UniCodes.old.) == -1)
    //    perror("tcsetattr");
    close(fd);
    return;
}

// ************ GET MODE ***********************

void cls_UniCodes::get_mode(int fd) {
    string m;

    if (ioctl(fd, KDGKBMODE, &cls_UniCodes::oldkbmode)) {
            perror("KDGKBMODE");
            return;
    }
    switch(cls_UniCodes::oldkbmode) {
        case K_RAW:
            m = "RAW"; break;
        case K_XLATE:
            m = "XLATE"; break;
        case K_MEDIUMRAW:
            m = "MEDIUMRAW"; break;
        case K_UNICODE:
            m = "UNICODE"; break;
    }
}