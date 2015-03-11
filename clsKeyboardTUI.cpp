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
#include <vector>
#include <iostream>

clsKeyboardTUI::clsKeyboardTUI() {
}

clsKeyboardTUI::clsKeyboardTUI(const clsKeyboardTUI& orig) {
}

clsKeyboardTUI::~clsKeyboardTUI() {
}
void clsKeyboardTUI::TestGrid (void) {
       int i=0, keys = 105;
    WINDOW *my_wins[keys];
    PANEL *my_panels[keys];  
    
    int posx=0, posy=0;
    
    initscr(); 
    clear();
        printw("\n                                                Unicomp Manual Keyboard Test");
        refresh();
    cbreak();                                                                 
    noecho();     
    
    // starting posistion
    int Xstart = 10 , Ystart = 5;
    i=0;
    
    posx = Xstart; posy = Ystart;
    //main border box
    my_wins[i] = newwin(23, 105, posy-2, posx-3);     // escape  
    // FUNCTION ROW
    
    ++i;my_wins[i] = newwin(3, 4, posy, posx);     // escape  
    posx +=4;
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F1
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F2
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F3
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F4
    posx +=4;
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F5
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F6
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F7
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F8    
    posx +=4;
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F9
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F10
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F11
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F12
    posx +=4;
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // Fprint screen
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // scroll lock
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // pause

    // Number Row
    posy +=4;
    ++i;posx = Xstart; my_wins[i] = newwin(3, 4, posy, posx);     // tilde
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 1
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 2
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 3
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 4
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 5
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 6
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 7
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 8
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 9
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // 0
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // dash
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // equal
    ++i;posx +=4; my_wins[i] = newwin(3, 12, posy, posx);     // backpace
    
    posx +=4; posx+=4; posx+=4;
    
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // insert
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // home    
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // page up
    
    posy +=3; posx -=12; 
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // delete
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // end  
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // page down    
    
    // NUMBER PAD
    posy = Ystart + 4; posx = Xstart + 80;
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numlock    
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad slash
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad asterick
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad minus
    posx = Xstart + 80;
    posy +=3;
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 7    
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 8
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 9
    ++i;posx +=4; my_wins[i] = newwin(6, 4, posy, posx);     // numpad plus
    posy +=3; posx = Xstart + 80;
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 4
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 5
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 6
    posy +=3; posx = Xstart + 80;
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 1
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 2
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // numpad 3
    ++i;posx +=4; my_wins[i] = newwin(6, 4, posy, posx);     // numpad enter
    posy +=3; posx = Xstart + 80;
    ++i;posx +=4; my_wins[i] = newwin(3, 8, posy, posx);     // numpad 0
    ++i;posx +=8; my_wins[i] = newwin(3, 4, posy, posx);     // numpad del
    
    // qwerty row
    posx = Xstart; posy = Ystart+7;
    ++i; my_wins[i] = newwin(3, 8, posy, posx);             // tab    
    ++i;posx +=8; my_wins[i] = newwin(3, 4, posy, posx);     // Q
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // W
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // E
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // R
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // T
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // Y
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // U
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // I
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // O
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // P
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // []
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // ]
    ++i;posx +=4; my_wins[i] = newwin(3, 8, posy, posx);     // back slash
    // home row
    posx = Xstart; posy = Ystart+10;
    ++i;my_wins[i] = newwin(3, 8, posy, posx);              // cap lock
    ++i;posx +=8; my_wins[i] = newwin(3, 4, posy, posx);    // A
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // S
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // D
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // F
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // G
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // H
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // J
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // K
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // L
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // semicolon
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);     // comma
    ++i;posx +=4; my_wins[i] = newwin(3, 12, posy, posx);     // enter
    //zx row
    posx = Xstart; posy = Ystart+13;
    ++i;my_wins[i] = newwin(3, 12, posy, posx);              // left shift
    ++i;posx +=12; my_wins[i] = newwin(3, 4, posy, posx);    // Z
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // X
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // C
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // V
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // B
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // N
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // M
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // comma
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // period
    ++i;posx +=4; my_wins[i] = newwin(3, 4, posy, posx);    // slash
    ++i;posx +=4; my_wins[i] = newwin(3, 12, posy, posx);    // right shift
    
    //spacebar row
    posx = Xstart; posy = Ystart+16;
    ++i;my_wins[i] = newwin(3, 6, posy, posx);              // left control
    ++i;posx +=6; my_wins[i] = newwin(3, 6, posy, posx);    // left windows
    ++i;posx +=6; my_wins[i] = newwin(3, 6, posy, posx);    // left alt
    ++i;posx +=6; my_wins[i] = newwin(3, 22, posy, posx);    // space bar
    ++i;posx +=22; my_wins[i] = newwin(3, 6, posy, posx);    // right alt
    ++i;posx +=6; my_wins[i] = newwin(3, 6, posy, posx);    // right windows
    ++i;posx +=6; my_wins[i] = newwin(3, 6, posy, posx);    // right application
    ++i;posx +=6; my_wins[i] = newwin(3, 6, posy, posx);    // right control
    
    // arrows
    posx = Xstart + 72; posy = Ystart+13;
    ++i;my_wins[i] = newwin(3, 4, posy, posx);              // up arrow
    posx = Xstart + 68; posy = Ystart+16;
    ++i;my_wins[i] = newwin(3, 4, posy, posx);     // left arrow
    ++i;posx +=4;my_wins[i] = newwin(3, 4, posy, posx);     // down arrow
    ++i;posx +=4;my_wins[i] = newwin(3, 4, posy, posx);     // right arrow
    
    
    
    keys = i+1;
    for(i = 0; i < keys; ++i)   {                                                 
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


void clsKeyboardTUI::Test(void) {
    int keys = 104;
    WINDOW *my_wins[keys];
    PANEL *my_panels[keys];                                                     
    
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

        my_wins[34] = newwin(lines, cols, 8, 52);    // insert
        my_wins[35] = newwin(lines, cols, 8, 55);    // home
        my_wins[36] = newwin(lines, cols, 8, 58);    // Page Up
        my_wins[37] = newwin(lines, cols, 10, 52);    // delete
        my_wins[38] = newwin(lines, cols, 10, 55);    // end
        my_wins[39] = newwin(lines, cols, 10, 58);    // Page Down      

//  NUMPAD
        my_wins[40] = newwin(lines, cols, 8, 63);    // Numpad numlock
        my_wins[41] = newwin(lines, cols, 8, 66);    // Numpad slash
        my_wins[42] = newwin(lines, cols, 8, 69);    // Numpad asterick
        my_wins[43] = newwin(lines, cols, 8, 72);    // Numpad minus
        
        my_wins[44] = newwin(lines, cols, 10, 63);    // Numpad 7
        my_wins[45] = newwin(lines, cols, 10, 66);    // Numpad 8
        my_wins[46] = newwin(lines, cols, 10, 69);    // Numpad 9
        
        my_wins[47] = newwin(lines, cols, 12, 63);    // Numpad 4
        my_wins[48] = newwin(lines, cols, 12, 66);    // Numpad 5        
        my_wins[49] = newwin(lines, cols, 12, 69);    // Numpad 6
        
        my_wins[50] = newwin(lines, cols, 14, 63);    // Numpad 1
        my_wins[51] = newwin(lines, cols, 14, 66);    // Numpad 2
        my_wins[52] = newwin(lines, cols, 14, 69);    // Numpad 3
        
        my_wins[53] = newwin(lines, 6, 16, 63);    // Numpad 0
        my_wins[54] = newwin(lines, cols, 16, 69);    // Numpad decimal
        
        my_wins[55] = newwin(4, cols, 10, 72);    // Numpad plus
        my_wins[56] = newwin(4, cols, 14, 72);    // Numpad enter

        // arrows        
        my_wins[57] = newwin(lines, cols, 14, 55);    // arrow up
        my_wins[58] = newwin(lines, cols, 16, 52);    // arrow left
        my_wins[59] = newwin(lines, cols, 16, 55);    // arrow down
        my_wins[60] = newwin(lines, cols, 16, 58);    // arrow right
  
        //qwert row
        my_wins[61] = newwin(lines, cols, 10, 10);      // Q
        my_wins[62] = newwin(lines, cols, 10, 13);      // W
        my_wins[63] = newwin(lines, cols, 10, 16);     // E
        my_wins[64] = newwin(lines, cols, 10, 19);     // R
        my_wins[65] = newwin(lines, cols, 10, 22);     // T
        my_wins[66] = newwin(lines, cols, 10, 25);     // Y
        my_wins[67] = newwin(lines, cols, 10, 28);     // U
        my_wins[68] = newwin(lines, cols, 10, 31);     // I
        my_wins[69] = newwin(lines, cols, 10, 34);     // O
        my_wins[70] = newwin(lines, cols, 10, 37);     // P
        my_wins[71] = newwin(lines, cols, 10, 40);     // [
        my_wins[72] = newwin(lines, cols, 10, 43);     // ]
        my_wins[73] = newwin(lines, 4, 10, 46);     // \
        
        // HOME ROW
        my_wins[74] = newwin(lines, cols, 12, 11);     // A
        my_wins[75] = newwin(lines, cols, 12, 14);     // S
        my_wins[76] = newwin(lines, cols, 12, 17);     // D
        my_wins[77] = newwin(lines, cols, 12, 20);     // F
        my_wins[78] = newwin(lines, cols, 12, 23);     // G
        my_wins[79] = newwin(lines, cols, 12, 26);     // H
        my_wins[80] = newwin(lines, cols, 12, 29);     // J
        my_wins[81] = newwin(lines, cols, 12, 32);     // K
        my_wins[82] = newwin(lines, cols, 12, 35);     // L
        my_wins[83] = newwin(lines, cols, 12, 38);     // ;
        my_wins[84] = newwin(lines, cols, 12, 41);     // '
        my_wins[85] = newwin(lines, 6, 12, 44);     // ENTER
        
        // zxcv
        my_wins[86] = newwin(lines, cols, 14, 12);     // Z
        my_wins[87] = newwin(lines, cols, 14, 15);     // X
        my_wins[88] = newwin(lines, cols, 14, 18);     // C
        my_wins[89] = newwin(lines, cols, 14, 21);     // V
        my_wins[90] = newwin(lines, cols, 14, 24);     // B
        my_wins[91] = newwin(lines, cols, 14, 27);     // N
        my_wins[92] = newwin(lines, cols, 14, 30);     // M
        my_wins[93] = newwin(lines, cols, 14, 33);     // ,
        my_wins[94] = newwin(lines, cols, 14, 36);     // .
        my_wins[95] = newwin(lines, cols, 14, 39);     // /
        my_wins[96] = newwin(lines, 8, 14, 42);     // RIGHT SHIFT
        
        //BOTTOM ROW
        my_wins[97] = newwin(lines, 4, 16, 10);       // left windows
        my_wins[98] = newwin(lines, 4, 16, 14);       // left alt
        my_wins[99] = newwin(lines, 17, 16, 18);       // space
        my_wins[100] = newwin(lines, 4, 16, 35);       // right alt
        my_wins[101] = newwin(lines, 4, 16, 39);       // right windows
        my_wins[102] = newwin(lines, 3, 16, 43);       // right function
        my_wins[103] = newwin(lines, 4, 16, 46);       // right control
        /*                                                                        
         * Create borders around the windows so that you can see the effect       
         * of panels                                                              
         */                                                                       
        for(i = 0; i < keys; ++i)   {                                                 
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