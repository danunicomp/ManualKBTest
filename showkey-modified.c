#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <linux/keyboard.h>
#include <assert.h>
#include <stdlib.h>
#include "getfd.h"
#include "nls.h"
//#include "version.h"

int tmp;	/* for debugging */

int fd;
int oldkbmode;
struct termios old;

/*
 * version 0.81 of showkey would restore kbmode unconditially to XLATE,
 * thus making the console unusable when it was called under X.
 */
static void
get_mode(void) {
        char *m;

	if (ioctl(fd, KDGKBMODE, &oldkbmode)) {
		perror("KDGKBMODE");
		return;
	}
	switch(oldkbmode) {
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

static void
clean_up(void) {
	if (ioctl(fd, KDSKBMODE, oldkbmode)) {
		return;
	}
	if (tcsetattr(fd, 0, &old) == -1)
		perror("tcsetattr");
	close(fd);
        return;
}

int
die(int x) {
    clean_up();
    return x;
}

static void
watch_dog(int x) {
    clean_up();
    return;
}

int GetKeyCode (void) {
	const char *short_opts = "haskV";

	int c;
	int show_keycodes = 1;
	int print_ascii = 0;

	struct termios new;
     
        static char buf[18];
        
	int i, n;

	fd = getfd(NULL);

	/* the program terminates when there is no input for 10 secs */
	signal(SIGALRM, watch_dog);

	get_mode();
	if (tcgetattr(fd, &old) == -1)
		perror("tcgetattr");
	if (tcgetattr(fd, &new) == -1)
		perror("tcgetattr");

	new.c_lflag &= ~ (ICANON | ECHO | ISIG);
	new.c_iflag = 0;
        
        new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 1;	/* 0.1 sec intercharacter timeout */

	if (tcsetattr(fd, TCSAFLUSH, &new) == -1)
		perror("tcsetattr");
	if (ioctl(fd, KDSKBMODE, show_keycodes ? K_MEDIUMRAW : K_RAW)) {
		perror("KDSKBMODE");
		return 0;
	}

	/* show keycodes - 2.6 allows 3-byte reports */
        int t;
        int kc;
	while (1) {
		alarm(100);
		n = read(fd, buf, sizeof(buf));
		i = 0;
		while (i < n) {
			
			char *s;

			s = (buf[i] & 0x80) ? _("break") : _("make");

			if (i+2 < n && (buf[i] & 0x7f) == 0
				&& (buf[i+1] & 0x80) != 0
				&& (buf[i+2] & 0x80) != 0) {
				kc = ((buf[i+1] & 0x7f) << 7) |
					(buf[i+2] & 0x7f);
				i += 3;
			} else {
				kc = (buf[i] & 0x7f);
				i++;
			}
                        if (s == "make") {
                            //printf("%i\t%i\t%i\t%i\t %i\t%i\t%i\t%i",buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
 //                           printf("%s   \t", s);


                            for (t=0;t<sizeof(buf);++t) {
 //                               if (buf[t] > 127) buf[t] = 0;
                               printf("SM%i\t", buf[t]);
                                if (buf[1] !=0 ) kc = buf[1];  // for double keycode
                                buf[t] = 0;  //flush buffer
                            }

                            
                         printf("\n");


                            die(kc);
                            close(fd);
                            return kc;
                        } 
                        else
                        {
                    //        printf("%s   \t", s);
                     //       printf("%i\t%i\n", buf[0], buf[1]);
                        }
                        
		}
	}

	clean_up();
	return 0;
}

int * GetWholeBuffer (void) {
	const char *short_opts = "haskV";
    char stbuf[100] = "";
    static int wholebuffer[18];
    int c;
	int show_keycodes = 1;
	int print_ascii = 0;

	struct termios new;
	//unsigned char buf[9];	/* divisible by 3 */
     
        static char buf[18];
        int * newbuf = malloc (18 * sizeof(int));
   //      char* buf = malloc(sizeof(char) * 18); 
        
	int i, n;

//	set_progname(argv[0]);

//	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE_NAME, LOCALEDIR);
	textdomain(PACKAGE_NAME);

	fd = getfd(NULL);

	/* the program terminates when there is no input for 10 secs */
	signal(SIGALRM, watch_dog);

	get_mode();
	if (tcgetattr(fd, &old) == -1)
		perror("tcgetattr");
	if (tcgetattr(fd, &new) == -1)
		perror("tcgetattr");

	new.c_lflag &= ~ (ICANON | ECHO | ISIG);
	new.c_iflag = 0;
        
	// new.c_cc[VMIN] = sizeof(buf);
        new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 1;	/* 0.1 sec intercharacter timeout */

	if (tcsetattr(fd, TCSAFLUSH, &new) == -1)
		perror("tcsetattr");
	if (ioctl(fd, KDSKBMODE, show_keycodes ? K_MEDIUMRAW : K_RAW)) {
		perror("KDSKBMODE");
		return 0;
	}

	/* show keycodes - 2.6 allows 3-byte reports */
        int t;
        int kc;
	while (1) {
		alarm(100);
		n = read(fd, newbuf, sizeof(newbuf));
               // clean_up();
               // return buf;
		i = 0;
		while (i < n) {
			
			char *s;

			s = (newbuf[i] & 0x80) ? _("break") : _("make");

			if (i+2 < n && (newbuf[i] & 0x7f) == 0
				&& (newbuf[i+1] & 0x80) != 0
				&& (newbuf[i+2] & 0x80) != 0) {
				kc = ((newbuf[i+1] & 0x7f) << 7) |
					(newbuf[i+2] & 0x7f);
				i += 3;
			} else {
				kc = (newbuf[i] & 0x7f);
				i++;
			}
                        if (s == "make") {
//                           printf("%i\t%i\t%i\t%i\t %i\t%i\t%i\t%i",buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
                         printf("S: %s   \t", s);


                            for (t=0;t<sizeof(newbuf);++t) {
                                wholebuffer[t] = newbuf[t];
 //                               if (buf[t] > 127) buf[t] = 0;
                            //   printf("%i\t", buf[t]);
                                if (newbuf[1] !=0 ) kc = newbuf[1];  // for double keycode
                                newbuf[t] = 0;  //flush buffer
                            }
                         //   return wholebuffer;
                            
    //                        printf("\n");
                            //printf("BUffer 0: %i\tBuf 1: %i\n", buf[0], buf[1]);
                            
                            
                           // kc = buf[0];
/*
                            printf("Buffer 1: %i\t",buf[1]);
                            printf("Buffer 2: %i\t",buf[2]);
                            printf("Buffer 3: %i\t",buf[3]);
*/
                            
 //                          t = transform_ints_to_string(buf, 3, stbuf, sizeof stbuf);                           
                            if (kc > 127) kc = kc-128;    
  //                          printf(_("keycode %3d %s\n"), kc, s);
                            die(kc);
                            close(fd);
//                            return buf;
                        } 
                        else
                        {
                    //        printf("%s   \t", s);
                     //       printf("%i\t%i\n", buf[0], buf[1]);
                        }
                        
		}
                
	}
        
                            clean_up();
                            return 0;
}

int * FullBuffer (void) {
	const char *short_opts = "haskV";

	int c;
	int show_keycodes = 1;
	int print_ascii = 0;

	struct termios new;
	//unsigned char buf[9];	/* divisible by 3 */
     
        static char buf[18];
        int *newbuf = malloc(sizeof(int) * 19); 
        
	int i, n;

	fd = getfd(NULL);

	/* the program terminates when there is no input for 10 secs */
	signal(SIGALRM, watch_dog);

	get_mode();
	if (tcgetattr(fd, &old) == -1)
		perror("tcgetattr");
	if (tcgetattr(fd, &new) == -1)
		perror("tcgetattr");

	new.c_lflag &= ~ (ICANON | ECHO | ISIG);
	new.c_iflag = 0;
        
	// new.c_cc[VMIN] = sizeof(buf);
        new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 1;	/* 0.1 sec intercharacter timeout */

	if (tcsetattr(fd, TCSAFLUSH, &new) == -1)
		perror("tcsetattr");
	if (ioctl(fd, KDSKBMODE, show_keycodes ? K_MEDIUMRAW : K_RAW)) {
		perror("KDSKBMODE");
		return 0;
	}
	/* show keycodes - 2.6 allows 3-byte reports */
        int t;
        int kc;
	while (1) {
		alarm(100);
		n = read(fd, buf, sizeof(buf));
               // clean_up();
               // return buf;
		i = 0;
		while (i < n) {
			
			char *s;

			s = (buf[i] & 0x80) ? _("BREAK") : _("MAKE");

			if (i+2 < n && (buf[i] & 0x7f) == 0
				&& (buf[i+1] & 0x80) != 0
				&& (buf[i+2] & 0x80) != 0) {
				kc = ((buf[i+1] & 0x7f) << 7) |
					(buf[i+2] & 0x7f);
				i += 3;
			} else {
				kc = (buf[i] & 0x7f);
				i++;
			}
                       // if (s == "make") {
                            //printf("%i\t%i\t%i\t%i\t %i\t%i\t%i\t%i",buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
 //                         printf("%s ", s);
                   //       return buf;

//      *******************   PRINTS BUFFER
                        if (s=="MAKE") newbuf[18] = 1999;
                        else newbuf[18] = 999;
                            for (t=0;t<sizeof(buf);++t) {
                             //  printf("Old %i\t", buf[t]);
                               newbuf[t] = buf[t];
                             
                    //        printf("New %i\t", newbuf[t]);
                  //              if (buf[1] !=0 ) kc = buf[1];  // for double keycode
                              buf[t] = 0;  //flush buffer
                            }
                          
                            
                     // printf("\n");
                           


  //                          if (kc > 127) kc = kc-128;    
  //                          printf(_("keycode %3d %s\n"), kc, s);
                            //die(kc);
                      clean_up();
                            close(fd);
                            return newbuf;
                       // } 
                       // else
                       // {
                     //      printf("%s   \t", s);
                     //       printf("%i\t%i\n", buf[0], buf[1]);
                       // }
                        
		}
	}
}
