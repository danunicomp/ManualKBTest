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

using namespace std;

clsBIOSTypeMenu::clsBIOSTypeMenu() {
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
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
		
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
	for(i = 0; i < foo; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
                choic = clsBIOSTypeMenu::choices[i];
			mvwprintw(menu_win, y, x, "%s", choic.c_str());
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", clsBIOSTypeMenu::choices[i].c_str());
		++y;
	}
	wrefresh(menu_win);
}