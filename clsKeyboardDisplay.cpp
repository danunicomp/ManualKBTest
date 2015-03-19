/* 
 * File:   clsKeyboardDisplay.cpp
 * Author: dshaffer
 * 
 * Created on March 19, 2015, 12:29 PM
 */

#include "clsKeyboardDisplay.h"
#include <vector>
#include <iostream>
#include <ncurses.h>

using namespace std;

clsKeyboardDisplay::clsKeyboardDisplay() {
}

clsKeyboardDisplay::clsKeyboardDisplay(const clsKeyboardDisplay& orig) {
}

clsKeyboardDisplay::~clsKeyboardDisplay() {
}

void clsKeyboardDisplay::ShowKeyboard_PC104(){

    //clsKeyboardDisplay::KeyGridLayout
    
WINDOW *create_newwin2(int height, int width, int starty, int startx);
    
    KeyGridLayout currkey;
    
    currkey = NewKey(110,    0, 0,  2,  2);    GridLayout.push_back (currkey);
    
    currkey = NewKey(112,    8, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(113,    12, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(114,    16, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(115,    20, 0,  2,  2);    GridLayout.push_back (currkey);    

    currkey = NewKey(116,    28, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(117,    32, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(118,    36, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(119,    40, 0,  2,  2);    GridLayout.push_back (currkey);

    currkey = NewKey(116,    48, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(117,    52, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(118,    56, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(119,    60, 0,  2,  2);    GridLayout.push_back (currkey);    

    currkey = NewKey(117,    68, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(118,    72, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(119,    76, 0,  2,  2);    GridLayout.push_back (currkey);    
    
//    currkey = NewKey(120,    15, 0,  2,  2);    GridLayout.push_back (currkey);    
//    currkey = NewKey(121,    15, 0,  2,  2);    GridLayout.push_back (currkey);    
//    currkey = NewKey(122,    15, 0,  2,  2);    GridLayout.push_back (currkey);    
//    currkey = NewKey(123,    15, 0,  2,  2);    GridLayout.push_back (currkey);    
//    currkey = NewKey(124,    15, 0,  2,  2);    GridLayout.push_back (currkey);    
//    currkey = NewKey(125,   15, 0,  2,  2);    GridLayout.push_back (currkey);    
//    currkey = NewKey(126,   15, 0,  2,  2);    GridLayout.push_back (currkey);    
//    currkey = NewKey(1, 15, 0,  2,  2);    GridLayout.push_back (currkey);    
//    currkey = NewKey(2, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(3, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(4, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(5, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(6, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(7, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(8, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(9, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(10, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(11, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(12, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(13, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(15, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(75, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(80, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(85, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(90, 15, 0,  2,  2);    GridLayout.push_back (currkey);
//    currkey = NewKey(95, 15, 0,  2,  2);    GridLayout.push_back (currkey);    
    
    
    WINDOW *key;
    initscr();
    clear();
    refresh();

    int x;
    for(x=0; x<GridLayout.size(); ++x) 
    {
    //   cout << "Key: " << x << " " << GridLayout[x].position << endl; 
        refresh();
        box(GridLayout[x].window, 0 , 0);
        wrefresh(GridLayout[x].window);

        
  //      key = GridLayout[x].window;
  //      GridLayout.insert(x).base()->window=key;
        //key = create_newwin2(GridLayout[x].Ywidth*2, GridLayout[x].Xwidth*2,  GridLayout[x].Ygridposition, GridLayout[x].Xgridposition);

    }
    
    start_color();
    init_pair(1,COLOR_BLUE, COLOR_GREEN);
    init_pair(2,COLOR_WHITE, COLOR_BLACK);
    
    for(x=0; x<GridLayout.size(); ++x) 
    {
//    //   cout << "Key: " << x << " " << GridLayout[x].position << endl; 
//        key = create_newwin2(GridLayout[x].Ywidth*2, GridLayout[x].Xwidth*2,  GridLayout[x].Ygridposition, GridLayout[x].Xgridposition);
        wbkgd(GridLayout[x].window, COLOR_PAIR(1));
        usleep(150000);
        wrefresh(GridLayout[x].window);
    }
    
    mvprintw(20,20,"FInish");
    getch();
    endwin();
}

    clsKeyboardDisplay::KeyGridLayout clsKeyboardDisplay::NewKey(int Pos, int Xgr, int Ygr, int Xwid, int Ywid) {
        WINDOW *create_newwin2(int height, int width, int starty, int startx);
        clsKeyboardDisplay::KeyGridLayout nwkey;
        nwkey.position =Pos ;
        nwkey.Xgridposition = Xgr;
        nwkey.Ygridposition=Ygr;
        nwkey.Xwidth=Xwid;
        nwkey.Ywidth=Ywid;
        nwkey.window= newwin(Ywid*2, Xwid*2, Ygr, Xgr );
        
        return nwkey;
        
    }
    
WINDOW *create_newwin2(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}