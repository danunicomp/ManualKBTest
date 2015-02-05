#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <linux/keyboard.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>  
//#include "clsKeyboard.h"

int fd=-1, oldkbmode=K_RAW;
struct termios orig_kb;
float linvel=0, rotvel=0;

using namespace std;
extern "C" int GetSingleKey (void);
extern "C" int GetKeyCode (void);

void clean_up ( void ) {
	//printf("CLEANING UP\n");
	tcflush(STDIN_FILENO, TCIFLUSH);
	system("stty echo");

	ioctl ( fd, KDSKBMODE, oldkbmode );
	tcsetattr ( fd, 0, &orig_kb );

	close ( fd );
        tcflush(STDIN_FILENO, TCIFLUSH);

}

/*
void printVel(int i) {
	printf("%f %f\n", linvel, rotvel);
	alarm(1);
}
*/
int ReadSingleCode() {
    int keycode, pressed, controlPressed=0;
    unsigned char buf[18]; /* divisible by 3 */
    int i,n;
    struct termios newkbd;

    //clsKeyboard myKeyboard;

    /* Open and configure the keyboard */
    fd = open("/dev/tty0", O_RDONLY);
    tcgetattr ( fd, &orig_kb );
    tcgetattr ( fd, &newkbd );
    newkbd.c_lflag &= ~ (ECHO | ICANON | ISIG);

    // 
    newkbd.c_cc[VMIN] = 1; //was 18
    newkbd.c_cc[VTIME] = 1; // IN TENTH OF A SECOND
    tcsetattr ( fd, TCSAFLUSH, &newkbd );

    /* Set medium raw mode: we receive keycodes. */
    ioctl ( fd, KDGKBMODE, &oldkbmode );
    ioctl ( fd, KDSKBMODE, K_MEDIUMRAW );
    system("stty -echo");

    n = read ( fd, buf, sizeof ( buf ) );

    /* Retrieve the key code and whether the key was pressed or released */
    i = 0;
   
        while ( i < n ) {
            pressed = (buf[i] & 0x80)==0x80 ? 0 : 1;
            if ( i+2 < n && ( buf[i] & 0x7f ) == 0 && ( buf[i+1] & 0x80 ) != 0 && ( buf[i+2] & 0x80 ) != 0 )
            {
                keycode = ( ( buf[i+1] & 0x7f ) << 7 ) | ( buf[i+2] & 0x7f );
                i += 3;
            }
            else keycode = ( buf[i++] & 0x7f );
        }
    
    if(pressed == 1) {
        return(keycode);
     }

}

int TestNewKeyboard(vector<int>& keycodes, vector<string>& positions) 
{
    int currentkey = 0;
     int status = 1;
     int keycode;
        int exits = 0;
        
    system("stty -echo");
 
        while( currentkey < keycodes.size() ){

        // for (currentkey=0; currentkey < keycodes.size(); ++currentkey) {
        /* Wait until a key is pressed or released */
        
        //keycode = GetSingleKey();
        keycode = GetKeyCode();
        
        if (keycode == 45) ++exits;
        else exits =0;
        if (exits == 3) return(0);


        //cout << "Expected: " << keycodes[currentkey] << " Read: " << keycode << endl;
        if (keycodes[currentkey] != keycode) {
            cout << "FAIL  FAIL FAIL FAIL" << endl;
            cout << "Key Position: " << positions[currentkey] << endl;
            cout << "Expected: " << keycodes[currentkey] << " Read: " << keycode << endl;

            status = 0;
            return status;
            break;
        }
        else {
            cout << "Position " << positions[currentkey] << " OK" << endl;
             ++currentkey;
        }
          
      
    }
    
    system("stty echo");

    return status;
}

int readcodes(vector<int>& keycodes, vector<string>& positions){
    int keycode, pressed, controlPressed=0;
    unsigned char buf[18]; /* divisible by 3 */
    int i,n;
    struct termios newkbd;

    int status = 1;
    //clsKeyboard myKeyboard;

    /* Open and configure the keyboard */
    fd = open("/dev/tty0", O_RDONLY);
    tcgetattr ( fd, &orig_kb );
    tcgetattr ( fd, &newkbd );
    newkbd.c_lflag &= ~ (ECHO | ICANON | ISIG);

    // 
    newkbd.c_cc[VMIN] = 1; //was 18
    newkbd.c_cc[VTIME] = 1; // IN TENTH OF A SECOND
    tcsetattr ( fd, TCSAFLUSH, &newkbd );

    /* Set medium raw mode: we receive keycodes. */
    ioctl ( fd, KDGKBMODE, &oldkbmode );
    ioctl ( fd, KDSKBMODE, K_MEDIUMRAW );

    /* Restore the normal keyboard mode on exit */
    atexit(clean_up);


    system("stty -echo");

    int currentkey = 0;
    int exits = 0;
  //   cout << "Position: " ;
    while( currentkey < keycodes.size() ){

        // for (currentkey=0; currentkey < keycodes.size(); ++currentkey) {
        /* Wait until a key is pressed or released */
        
        n = read ( fd, buf, sizeof ( buf ) );

        /* Retrieve the key code and whether the key was pressed or released */
        i = 0;
        while ( i < n ) {
            // printf("Wait\tKeycode: %i\tI: %i\tN: %i\n", keycode, i, n);
            pressed = (buf[i] & 0x80)==0x80 ? 0 : 1;
            if ( i+2 < n && ( buf[i] & 0x7f ) == 0 && ( buf[i+1] & 0x80 ) != 0 && ( buf[i+2] & 0x80 ) != 0 )
            {
                keycode = ( ( buf[i+1] & 0x7f ) << 7 ) | ( buf[i+2] & 0x7f );
                i += 3;
            }
            else keycode = ( buf[i++] & 0x7f );

        }
       
        if(pressed == 1) {
            if (keycode == 45) ++exits;
            else exits =0;
            if (exits == 3) return(0);
                
            
            //cout << "Expected: " << keycodes[currentkey] << " Read: " << keycode << endl;
            if (keycodes[currentkey] != keycode) {
                cout << "FAIL  FAIL FAIL FAIL" << endl;
                cout << "Key Position: " << positions[currentkey] << endl;
                cout << "Expected: " << keycodes[currentkey] << " Read: " << keycode << endl;

                status = 0;
                return status;
                break;
            }
            else {
                cout << "Position " << positions[currentkey] << " OK" << endl;
                 ++currentkey;
            }
          
        }
    }
     // cout << "PASS" << endl;
    system("stty echo");

    return status;
}

//////////////////////////////////////////////////////////////////
// SHOW THE KEYCODES LIKE SHOWKEY, DON'T CHECK IF MAP CORRECT
//////////////////////////////////////////////////////////////////
int showkeys(){
    int keycode, pressed, controlPressed=0;
    unsigned char buf[18]; /* divisible by 3 */
    int i,n;
    struct termios newkbd;

    /* Open and configure the keyboard */
    fd = open("/dev/tty0", O_RDONLY);
    tcgetattr ( fd, &orig_kb );   //get the parameters associated with the terminal
    tcgetattr ( fd, &newkbd );
    newkbd.c_lflag &= ~ (ECHO | ICANON | ISIG);

    // 
    newkbd.c_cc[VMIN] = 18; //was 18
    newkbd.c_cc[VTIME] = 1; // IN TENTH OF A SECOND
    tcsetattr ( fd, TCSAFLUSH, &newkbd );

    /* Set medium raw mode: we receive keycodes. */
    ioctl ( fd, KDGKBMODE, &oldkbmode );
    ioctl ( fd, KDSKBMODE, K_MEDIUMRAW ); // K_XLATE, K_MEDIUMRAW , K_RAW, K_UNICODE

    /* Restore the normal keyboard mode on exit */
    atexit(clean_up);


    system("stty -echo");

    int exits = 0;
    while( 1 ){
        /* Wait until a key is pressed or released */
        n = read ( fd, buf, sizeof(buf) );
       // cout << "READ: " << n << endl;
        /* Retrieve the key code and whether the key was pressed or released */
        i = 0;
        while ( i < n ) {
           //  printf("Wait\tKeycode: %i\tI: %i\tN: %i\n", keycode, i, n);
            pressed = (buf[i] & 0x80)==0x80 ? 0 : 1;
            if ( i+2 < n && ( buf[i] & 0x7f ) == 0 && ( buf[i+1] & 0x80 ) != 0 && ( buf[i+2] & 0x80 ) != 0 )
            {
                keycode = ( ( buf[i+1] & 0x7f ) << 7 ) | ( buf[i+2] & 0x7f );
                i += 3;
                cout << "IF: " << keycode << endl;
            }
            else keycode = ( buf[i++] & 0x7f );
            
        }

        // CHECKS FIOR XXX pressed
        if(pressed == 1) {
        if (keycode == 45) ++exits;
        else exits =0;
        if (exits == 3) return(0);


                printf("Keycode: %i\t%i\n", keycode, pressed);

        int xx;
    //   printf("%i", buf[0]);
       for(xx=0; xx < sizeof(buf); ++xx) {
           printf("%i\t", buf[xx] );
           
       }
        printf("\n");
       for(xx=0; xx < sizeof(buf); ++xx) {
        //   cout << "And :" << (buf[xx] & 0x7f) << "\t";
           printf("%i\t", buf[xx] & 0x7f );
       }
        printf("\n");
        //CLEAR BUFFER
            fill(buf, buf+18, 0);
        }
    }

    system("stty echo");

    return 0;
}


//////////////////////////////////////////////////////////////////
// NOT WRITTEN YET. THIS ONE WILL USE POSITION AND KEYCODE
//////////////////////////////////////////////////////////////////
int TestKeyboard(vector<int>& keycodes){

    int keycode, pressed, controlPressed=0;
    unsigned char buf[18]; /* divisible by 3 */
    int i,n;
    struct termios newkbd;

    int status = 1;
    //clsKeyboard myKeyboard;

    /* Open and configure the keyboard */
    fd = open("/dev/tty0", O_RDONLY);
    tcgetattr ( fd, &orig_kb );
    tcgetattr ( fd, &newkbd );
    newkbd.c_lflag &= ~ (ECHO | ICANON | ISIG);

    // 
    newkbd.c_cc[VMIN] = 1; //was 18
    newkbd.c_cc[VTIME] = 1; // IN TENTH OF A SECOND
    tcsetattr ( fd, TCSAFLUSH, &newkbd );

    /* Set medium raw mode: we receive keycodes. */
    ioctl ( fd, KDGKBMODE, &oldkbmode );
    ioctl ( fd, KDSKBMODE, K_MEDIUMRAW );

    /* Restore the normal keyboard mode on exit */
    atexit(clean_up);


    system("stty -echo");

    int currentkey = 0;
    int exits = 0;
    while( currentkey < keycodes.size() ){

        // for (currentkey=0; currentkey < keycodes.size(); ++currentkey) {
        /* Wait until a key is pressed or released */
        
        n = read ( fd, buf, sizeof ( buf ) );

        /* Retrieve the key code and whether the key was pressed or released */
        i = 0;
        while ( i < n ) {
            // printf("Wait\tKeycode: %i\tI: %i\tN: %i\n", keycode, i, n);
            pressed = (buf[i] & 0x80)==0x80 ? 0 : 1;
            if ( i+2 < n && ( buf[i] & 0x7f ) == 0 && ( buf[i+1] & 0x80 ) != 0 && ( buf[i+2] & 0x80 ) != 0 )
            {
                keycode = ( ( buf[i+1] & 0x7f ) << 7 ) | ( buf[i+2] & 0x7f );
                i += 3;
            }
            else keycode = ( buf[i++] & 0x7f );

        }
        if(pressed == 1) {
            if (keycode == 45) ++exits;
            else exits =0;

            if (exits == 3) return(0);
            
                
                cout << "Expected: " << keycodes[currentkey] << " Read: " << keycode << endl;
                if (keycodes[currentkey] != keycode) {
                    cout << "FAIL  FAIL FAIL FAIL" << endl;
                    status = 0;
                    break;
                 }
                ++currentkey;
        
            
        
        
    //        printf("Keycode: %i\t%i\n", keycode, pressed);
            
    //        int xx;
    //        printf("%i", buf[0]);
    //        for(xx=0; xx < sizeof(buf); ++xx) {
    //          printf("%i\t", buf[xx]);
    //        }
    //        printf("\n");   
        }
    }
 //   cout << "DONE";
    system("stty echo");

    return status;
}