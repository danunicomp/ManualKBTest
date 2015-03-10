/* 
 * File:   clsKeyboardTUI.cpp
 * Author: dshaffer
 * 
 * Created on March 10, 2015, 2:18 PM
 */

#include "clsKeyboardTUI.h"
#include <ncurses.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cdk.h>
#include <panel.h> 

clsKeyboardTUI::clsKeyboardTUI() {
}

clsKeyboardTUI::clsKeyboardTUI(const clsKeyboardTUI& orig) {
}

clsKeyboardTUI::~clsKeyboardTUI() {
}

void clsKeyboardTUI::Test(void) {
    WINDOW *my_wins[34];
    PANEL *my_panels[34];                                                     
        int lines = 2, cols = 3, y = 5, x = 5, i;                               
                                                                                  
        initscr();                                                                
        cbreak();                                                                 
        noecho();                                                                 
                                                                                  
        /* Create windows for the panels */                                       
        my_wins[0] = newwin(lines, cols, 5, 5);     // escape                            
        
        my_wins[1] = newwin(lines, cols, 5, 10);    // F1                             
        my_wins[2] = newwin(lines, cols, 5, 13);    // F2
        my_wins[3] = newwin(lines, cols, 5, 16);    // F3
        my_wins[4] = newwin(lines, cols, 5, 19);    // F4
        
        my_wins[5] = newwin(lines, cols, 5, 24);    // F5
        my_wins[6] = newwin(lines, cols, 5, 27);    // F6
        my_wins[7] = newwin(lines, cols, 5, 30);    // F7
        my_wins[8] = newwin(lines, cols, 5, 33);    // F8
        
        my_wins[9] = newwin(lines, cols, 5, 38);    // F9
        my_wins[10] = newwin(lines, cols, 5, 41);    // F10
        my_wins[11] = newwin(lines, cols, 5, 44);    // F11
        my_wins[12] = newwin(lines, cols, 5, 47);    // F12
        
        my_wins[13] = newwin(lines, cols, 5, 52);    // print screen
        my_wins[14] = newwin(lines, cols, 5, 55);    // scroll lock
        my_wins[15] = newwin(lines, cols, 5, 58);    // pause
        
        
        my_wins[16] = newwin(lines, cols, 8, 5);     // tilde
        my_wins[17] = newwin(lines, cols, 8, 8);     // 1
        my_wins[18] = newwin(lines, cols, 8, 11);     // 2
        my_wins[19] = newwin(lines, cols, 8, 14);     // 3
        my_wins[20] = newwin(lines, cols, 8, 17);     // 4
        my_wins[21] = newwin(lines, cols, 8, 20);     // 5
        my_wins[22] = newwin(lines, cols, 8, 23);     // 6
        my_wins[23] = newwin(lines, cols, 8, 26);     // 7
        my_wins[24] = newwin(lines, cols, 8, 29);     // 8
        my_wins[25] = newwin(lines, cols, 8, 32);     // 9
        my_wins[26] = newwin(lines, cols, 8, 35);     // 0
        my_wins[27] = newwin(lines, cols, 8, 38);     // dash
        my_wins[28] = newwin(lines, cols, 8, 41);     // equals
        my_wins[29] = newwin(lines, 6, 8, 44);     // backspace
        
        my_wins[30] = newwin(lines, 5, 10, 5);       // tab
        my_wins[31] = newwin(lines, 6, 12, 5);       // caps lock
        my_wins[32] = newwin(lines, 7, 14, 5);       //left shift
        my_wins[33] = newwin(lines, 5, 16, 5);       // left control
                                                                                  
        /*                                                                        
         * Create borders around the windows so that you can see the effect       
         * of panels                                                              
         */                                                                       
        for(i = 0; i < 34; ++i)   {                                                 
            box(my_wins[i], 0, 0);                                                                                                                  
        /* Attach a panel to each window */     /* Order is bottom up */          
            my_panels[i] = new_panel(my_wins[i]);   /* Push 0, order: stdscr-0 */     
        }
        /* Update the stacking order. 2nd panel will be on top */                 
        update_panels();                                                          
                                                                                  
        /* Show it on the screen */                                               
        doupdate();                                                               
                                                                                  
        getch();                                                                  
        endwin();  
    return ;
}

void clsKeyboardTUI::rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}