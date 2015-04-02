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
     refresh();
             doupdate(); 
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

void clsKeyboardDisplay::ShowKeyboard_PC122(){

    //clsKeyboardDisplay::KeyGridLayout

        initscr();
    clear();
     cbreak();  
    refresh();


    
WINDOW *create_newwin2(int height, int width, int starty, int startx);
    
    
KeyGridLayout currkey;
    
    currkey = NewKey(122,    12, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(123,    16, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(124,    20, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(125,    24, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(126,    28, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(127,    32, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(128,    36, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(129,    40, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(130,    44, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(131,    48, 0,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(132,    52, 0,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(133,    56, 0,  2,  2);    GridLayout.push_back (currkey);    
    
    currkey = NewKey(110,    12, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(111,    16, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(112,    20, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(113,    24, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(114,    28, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(115,    32, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(116,    36, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(117,    40, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(118,    44, 4,  2,  2);    GridLayout.push_back (currkey);    
 currkey = NewKey(119,    48, 4,  2,  2);    GridLayout.push_back (currkey);    
    // currkey = NewKey(119,70   48, 4  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(120,    52, 4,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(121,   56, 4,  2,  2);    GridLayout.push_back (currkey);    
    
    
    
    currkey = NewKey(70, 0, 10,  2,  2);    GridLayout.push_back (currkey);  // Pos 70. Left F1
    currkey = NewKey(71, 0, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(72, 0, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(73, 0, 22,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(74, 0, 26,  2,  2);    GridLayout.push_back (currkey);
    
    currkey = NewKey(65, 4, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(66, 4, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(67, 4, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(68, 4, 22,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(69, 4, 26,  2,  2);    GridLayout.push_back (currkey);
    
    currkey = NewKey(1, 12, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(2, 16, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(3, 20, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(4, 24, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(5, 28, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(6, 32, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(7, 36, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(8, 40, 10,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(9, 44, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(10, 48, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(11, 52, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(12, 56, 10,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(13, 60, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(15, 64, 10,  4,  2);    GridLayout.push_back (currkey);

    currkey = NewKey(16, 12, 14,  3,  2);    GridLayout.push_back (currkey); // TAB
    currkey = NewKey(17, 19, 14,  2,  2);    GridLayout.push_back (currkey); // Q
    currkey = NewKey(18, 23, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(19, 27, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(20, 31, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(21, 35, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(22, 39, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(23, 43, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(24, 47, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(25, 51, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(26, 55, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(27, 59, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(28, 63, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(43, 68, 14,  2,  4);    GridLayout.push_back (currkey); // ENTER
    
    currkey = NewKey(30, 12, 18,  4,  2);    GridLayout.push_back (currkey);  ///////// CAP LOCK
    currkey = NewKey(31, 20, 18,  2,  2);    GridLayout.push_back (currkey);    // A
    currkey = NewKey(32, 24, 18,  2,  2);    GridLayout.push_back (currkey);
    
     currkey = NewKey(33, 28, 18,  2,  2);    GridLayout.push_back (currkey);
     currkey = NewKey(34, 32, 18,  2,  2);    GridLayout.push_back (currkey);
     currkey = NewKey(35, 36, 18,  2,  2);    GridLayout.push_back (currkey);
     currkey = NewKey(36, 40, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(37, 44, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(38, 48, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(39, 52, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(40, 56, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(41, 60, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(42, 64, 18,  2,  2);    GridLayout.push_back (currkey);
    
    currkey = NewKey(44, 12, 22,  2,  2);    GridLayout.push_back (currkey);  ///////// LEFT SHIFT
    currkey = NewKey(58, 12, 26,  3,  2);    GridLayout.push_back (currkey);  ///////// LEFT CONTROL
    
    
    // ******************************************************
    
    currkey = NewKey(75, 75, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(80, 79, 10,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(85, 83, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(76, 75, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(81, 79, 14,  2,  2);    GridLayout.push_back (currkey);    
    currkey = NewKey(86, 83, 14,  2,  2);    GridLayout.push_back (currkey);    
    
    // **************  ARROWS **********************************

    currkey = NewKey(82, 79, 18,  2,  2);    GridLayout.push_back (currkey);       // UP ARROW
    currkey = NewKey(83, 79, 22,  2,  2);    GridLayout.push_back (currkey);       // MIDDLE ARROW
    currkey = NewKey(84, 79, 26,  2,  2);    GridLayout.push_back (currkey);       // DOWN ARROW
    currkey = NewKey(88, 83, 22,  2,  2);    GridLayout.push_back (currkey);       // RIGHT ARROW
    currkey = NewKey(78, 75, 22,  2,  2);    GridLayout.push_back (currkey);       // LEFT ARROW
    
    
    // ****************  NUMPAD ************************************************
    currkey = NewKey(90, 90, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(95, 94, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(100, 98, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(105, 102, 10,  2,  2);    GridLayout.push_back (currkey);

    currkey = NewKey(91, 90, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(96, 94, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(101, 98, 14,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(106, 102, 14,  2,  2);    GridLayout.push_back (currkey);    
    
    currkey = NewKey(92, 90, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(97, 94, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(102, 98, 18,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(107, 102, 18,  2,  2);    GridLayout.push_back (currkey);    

    currkey = NewKey(93, 90, 22,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(98, 94, 22,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(103, 98, 22,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(108, 102, 22,  2,  4);    GridLayout.push_back (currkey);    
    
    currkey = NewKey(99, 90, 26,  4,  2);    GridLayout.push_back (currkey);
    //currkey = NewKey(95, 94, 10,  2,  2);    GridLayout.push_back (currkey);
    currkey = NewKey(104, 98, 26,  2,  2);    GridLayout.push_back (currkey);
    //currkey = NewKey(105, 102, 10,  2,  2);    GridLayout.push_back (currkey);
    
        refresh();
    
   // WINDOW *key;

   int x;
   for(x=0; x<GridLayout.size(); ++x) 
   {
//    //   cout << "Key: " << x << " " << GridLayout[x].position << endl; 
//        refresh();
        box(GridLayout[x].window, 0 , 0);
      wrefresh(GridLayout[x].window);
//
//        
  //  key = GridLayout[x].window;
      //GridLayout.insert(x).base()->window=key;
  //  key = create_newwin2(GridLayout[x].Ywidth*2, GridLayout[x].Xwidth*2,  GridLayout[x].Ygridposition, GridLayout[x].Xgridposition);
//
   }
    
//    start_color();
//    init_pair(1,COLOR_BLUE, COLOR_GREEN);
//    init_pair(2,COLOR_WHITE, COLOR_BLACK);
//    
//    for(x=0; x<GridLayout.size(); ++x) 
//    {
////    //   cout << "Key: " << x << " " << GridLayout[x].position << endl; 
////        key = create_newwin2(GridLayout[x].Ywidth*2, GridLayout[x].Xwidth*2,  GridLayout[x].Ygridposition, GridLayout[x].Xgridposition);
//        wbkgd(GridLayout[x].window, COLOR_PAIR(1));
//   //     usleep(50000);
//        wrefresh(GridLayout[x].window);
//    }
    
    mvprintw(20,20,"FInish");
    getch();
    endwin();
}