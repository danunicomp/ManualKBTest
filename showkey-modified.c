#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <linux/keyboard.h>
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
	 // default:
	//    m = _("?UNKNOWN?"); break;
	}

}

static void
clean_up(void) {
	if (ioctl(fd, KDSKBMODE, oldkbmode)) {
//		perror("KDSKBMODE");
		return;
	}
	if (tcsetattr(fd, 0, &old) == -1)
//		perror("tcsetattr");
	close(fd);
  //      return;
}

int
die(int x) {
//	printf(_("caught signal %i, cleaning up...\n"), x);
	clean_up();
	return x;
}

static void
watch_dog(int x) {
	clean_up();
	return;
}

int GetKeyBuffer (void) {
	const char *short_opts = "haskV";

	int c;
	int show_keycodes = 1;
	int print_ascii = 0;

	struct termios new;
	//unsigned char buf[9];	/* divisible by 3 */
     
        static char buf[18];
   //      char* buf = malloc(sizeof(char) * 18); 
        
	int i, n;

//	set_progname(argv[0]);

//	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE_NAME, LOCALEDIR);
	textdomain(PACKAGE_NAME);





	if (print_ascii) {
		/* no mode and signal and timer stuff - just read stdin */
	        fd = 0;

		if (tcgetattr(fd, &old) == -1)
			perror("tcgetattr");
		if (tcgetattr(fd, &new) == -1)
			perror("tcgetattr");

		new.c_lflag &= ~ (ICANON | ISIG);
//		new.c_lflag |= (ECHO | ECHOCTL);
		new.c_iflag = 0;
		new.c_cc[VMIN] = 1;
		new.c_cc[VTIME] = 0;

		if (tcsetattr(fd, TCSAFLUSH, &new) == -1)
			perror("tcgetattr");
//		printf(_("\nPress any keys - "
//		         "Ctrl-D will terminate this program\n\n"));

		while (1) {
			n = read(fd, buf, 1);
			if (n == 1)
				printf(" \t%3d 0%03o 0x%02x\n",
				       buf[0], buf[0], buf[0]);
			if (n != 1 || buf[0] == 04)
				break;
		}

		if (tcsetattr(fd, 0, &old) == -1)
			perror("tcsetattr");
		return 0;
	}


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

//	printf(_("press any key (program terminates 10s after last keypress)...\n"));

	/* show scancodes */


	/* show keycodes - 2.6 allows 3-byte reports */
        int t;
        int kc;
	while (1) {
		alarm(10);
		n = read(fd, buf, sizeof(buf));
               // clean_up();
               // return buf;
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
                               printf("%i\t", buf[t]);
                                if (buf[1] !=0 ) kc = buf[1];  // for double keycode
                                buf[t] = 0;  //flush buffer
                            }

                            
    //                        printf("\n");
                            //printf("BUffer 0: %i\tBuf 1: %i\n", buf[0], buf[1]);
                            
                            
                           // kc = buf[0];
/*
                            printf("Buffer 1: %i\t",buf[1]);
                            printf("Buffer 2: %i\t",buf[2]);
                            printf("Buffer 3: %i\t",buf[3]);
*/
                            if (kc > 127) kc = kc-128;    
  //                          printf(_("keycode %3d %s\n"), kc, s);
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
die2(kc);
	clean_up();
	return 0;
}
