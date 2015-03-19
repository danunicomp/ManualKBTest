/* 
 * File:   clsBIOSTypeMenu.cpp
 * Author: dshaffer
 * 
 * Created on March 18, 2015, 1:12 PM
 */

#include <stdio.h>
#include <ncurses.h>
#include "clsBIOSTypeMenu.h"
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <vector>

#include "clsConfig.h"

using namespace std;

clsBIOSTypeMenu::clsBIOSTypeMenu(clsConfig* Config) {
      clsBIOSTypeMenu::CurrentConfig = *Config;
}

clsBIOSTypeMenu::clsBIOSTypeMenu(const clsBIOSTypeMenu& orig) {
}

clsBIOSTypeMenu::~clsBIOSTypeMenu() {
}

#define WIDTH 30
#define HEIGHT 10 




//void print_menu(WINDOW *menu_win, int highlight);

int clsBIOSTypeMenu::mainmenu() {
        int startx = 0;
        int starty = 0;

        clsBIOSTypeMenu::choices[0] =  "Choice 1";
        clsBIOSTypeMenu::choices[1] =  "Choice 2";
        clsBIOSTypeMenu::choices[2] =  "Choice 3";
        clsBIOSTypeMenu::choices[3] =  "Choice 4";
        clsBIOSTypeMenu::choices[4] =  "Exit";
         //cout << "IN Loop" << endl;

      clsBIOSTypeMenu::nchoices = 5;
      
      
        
      
      
      
	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;
	initscr();
	clear();
	noecho();
        
// ----- DEBUG STUFF -------------------
        start_color();
        init_pair(1,COLOR_BLACK, COLOR_WHITE);
        attron(COLOR_PAIR(1));

        
        //printw("HELLO\n");
        struct winsize size;
         if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
             printw("TIOCGWINSZ error");
        printw("%d rows, %d columns\n", size.ws_row, size.ws_col);

                int t;
        
        mvprintw(0,0,"");        
        for(t=0;t<size.ws_col;++t) {
            printw(" ");
        }
        
        mvprintw(0,0,"UNICOMP MANUAL KEYBOARD TESTING SYSTEM\t");
        string ver = "Version " + clsBIOSTypeMenu::CurrentConfig.Version;
        t=ver.length();
        mvprintw(0,size.ws_col-t,"%s",ver.c_str());
        refresh();
// ------- ---------- ---------- ---------
            
        getch();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (WIDTH) / 2;
	starty = ( HEIGHT) / 2;
		
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
 clsBIOSTypeMenu::print_menu(menu_win, highlight);


        
	while(1)
	{	
           
            c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = clsBIOSTypeMenu::nchoices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == clsBIOSTypeMenu::nchoices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
                            cout << "HIT 10" << endl;
				choice = highlight;
				break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		//clsBIOSTypeMenu::print_menu(&menu_win, highlight);
                
 /////////////////////////////////               
                clsBIOSTypeMenu::print_menu(menu_win, highlight);
 ////////////////////////////////////////////               
                
                
                
                
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}	
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1].c_str());
	clrtoeol();
	refresh();

	endwin();
	return 0;
}


void clsBIOSTypeMenu::print_menu(WINDOW *menu_win, int highlight)
{
    
	int x, y, i;	

	x = 2;
	y = 2;
        int foo; 
        string choic;
   foo = 5;
	box(menu_win, 0, 0);

	for(i = 0; i < foo; ++i) {
                if(highlight == i + 1) /* High light the present choice */
		{	
                    wattron(menu_win, A_REVERSE); 
                    choic = clsBIOSTypeMenu::choices[i];
                    mvwprintw(menu_win, y, x, "%s", choic.c_str());
                    wattroff(menu_win, A_REVERSE);
		}
		else {
                    choic = clsBIOSTypeMenu::choices[i];
                    mvwprintw(menu_win, y, x, "%s", choic.c_str());
                }
                ++y;
	}
	wrefresh(menu_win);
}

void clsBIOSTypeMenu::ShowKeyboard(){
    WINDOW *create_newwin(int height, int width, int starty, int startx);
    
    WINDOW *my_win;
    initscr();
    clear();
    	int startx, starty, width, height;
	int ch;
	height = 3;
	width = 4;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
//	printw("Press F1 to exit");
	refresh();

        
    	my_win = create_newwin(height, width, starty, startx);
    start_color();
    //init_pair(1,COLOR_WHITE, COLOR_BLACK);
    init_pair(1,COLOR_BLUE, COLOR_RED);
    wbkgd(my_win, COLOR_PAIR(1));
    //attron(COLOR_PAIR(1));
	wrefresh(my_win);
//        test_win = newwin(2, 3, 3, 3);
//        box(test_win,10,10);
//        keypad(test_win, TRUE);
//        printw("Hello");
//        wrefresh(test_win);
    
    getch();
    endwin();
    
///////////////////////////////////////////
   WINDOW *key;
   initscr();
   clear();
    refresh();
    key = create_newwin(3, 4, 10, 10);
    wrefresh(key);
    getch();
    endwin();
    
    ///////////////////////////////////////////////////////////////
    
           int i=0, keys = 105;
    WINDOW *my_wins[keys];
    
    int posx=0, posy=0;
    
    initscr(); 
    clear();
        printw("\n                                               Unicomp Manual Keyboard Test");
        refresh();
    cbreak();                                                                 
    noecho();      
    
    // starting posistion
    int Xstart = 10 , Ystart = 5;
    i=0;
    
    posx = Xstart; posy = Ystart;
    //main border box
    my_wins[i] = newwin(23, 105, posy-2, posx-3);     // main border  
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
    
        
    box(my_wins[10],0,0);
    box(my_wins[11],0,0);
    
    wrefresh(my_wins[10]);
    wrefresh(my_wins[11]);
 
    getch();
    endwin();
    
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}