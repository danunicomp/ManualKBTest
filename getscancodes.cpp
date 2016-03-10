

#include <signal.h>
#include <vector>
#include <termios.h>
#include <linux/keyboard.h>
#include <stdlib.h>
#include <sys/ioctl.h> /* ioctl */
#include <fcntl.h> /* open */
#include <unistd.h> /* close */
#include <stdio.h>
#include <linux/kd.h>
#include <string>
#include <iostream>
#include <signal.h>

int getfd(const char *fnam);
int tmp;	/* for debugging */


int oldkbmode;
struct termios old;
using namespace std;

std::vector<int> FullBuffer2 (void);

static void
clean_up(int fd) {
    if (ioctl(fd, KDSKBMODE, oldkbmode)) {
        return;
    }
    if (tcsetattr(fd, 0, &old) == -1)
        perror("tcsetattr");
    close(fd);
    return;
}

static void
get_mode(int fd) {
    string m;

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

int
die(int x, int fd) {
      close(fd);
    clean_up(fd);
    return x;
}

std::vector<int> FullBuffer2 (void) {

    int show_keycodes = 1;
    int fd;
    struct termios newkb;

    int  buf[19];
    std::vector<int> newbuf(19);
    int i, n;

    fd = getfd(NULL);

    get_mode(fd);
    if (tcgetattr(fd, &old) == -1)
            perror("tcgetattr");
    if (tcgetattr(fd, &newkb) == -1)
            perror("tcgetattr");

    newkb.c_lflag &= ~ (ICANON | ECHO | ISIG);
    newkb.c_iflag = 0;
    
    // new.c_cc[VMIN] = sizeof(buf);
    newkb.c_cc[VMIN] = 1;
    newkb.c_cc[VTIME] = 1;	/* 0.1 sec intercharacter timeout */

    if (tcsetattr(fd, TCSAFLUSH, &newkb) == -1)
            perror("tcsetattr");
    if (ioctl(fd, KDSKBMODE, show_keycodes ? K_MEDIUMRAW : K_RAW)) {
         clean_up(fd);
        perror("KDSKBMODE");
        return newbuf;
    }
    /* show keycodes - 2.6 allows 3-byte reports */
    int t;
 //     
    for (t=0; t<19; ++t) {
        buf[t] = 0;
    }
 //    usleep(1000000);
  while (1) {
     alarm(100);
     
        n = read(fd, buf, sizeof(buf));
 
        i = 0;
  
        while (i < n) {
            string s;
            s = (buf[i] & 0x80) ? "BREAK" : "MAKE";
            if (i+2 < n && (buf[i] & 0x7f) == 0 && (buf[i+1] & 0x80) != 0 && (buf[i+2] & 0x80) != 0) 
            {
  
                i += 3;
            } else {
  
                i++;
            }
            // ******** SELECT MAKE OR BREAK
  
            if (s=="MAKE") {
                buf[18] = 1999;
            }
            else
            {
               buf[18] = 999;
            }
      
            for (t=0;t<19;++t) {
                newbuf.push_back(buf[t]);
                buf[t] = 0;  //flush buffer
            }
            cout << endl;
            clean_up(fd);
            close(fd);
       return newbuf;
       }
    
    }
}


static int
is_a_console(int fd) {
	char arg;

	arg = 0;
	return (isatty (fd)
		&& ioctl(fd, KDGKBTYPE, &arg) == 0
		&& ((arg == KB_101) || (arg == KB_84)));
}

static int
open_a_console(const char *fnam) {
	int fd;

	/*
	 * For ioctl purposes we only need some fd and permissions
	 * do not matter. But setfont:activatemap() does a write.
	 */
	fd = open(fnam, O_RDWR);
	if (fd < 0)
		fd = open(fnam, O_WRONLY);
	if (fd < 0)
		fd = open(fnam, O_RDONLY);
	if (fd < 0)
		return -1;
	if (!is_a_console(fd)) {
		close(fd);
		return -1;
	}
	return fd;
}

int getfd(const char *fnam) {
	int fd;

	if (fnam) {
		fd = open_a_console(fnam);
		if (fd >= 0) {

			return fd;
                }
		fprintf(stderr,"Couldn't open %s\n", fnam);
		exit(1);
	}

	fd = open_a_console("/proc/self/fd/0");
	if (fd >= 0) {

            return fd;  
        }

	fd = open_a_console("/dev/tty");
	if (fd >= 0) {

            return fd;
        }

	fd = open_a_console("/dev/tty0");
	if (fd >= 0) {

            return fd;
        }
	fd = open_a_console("/dev/vc/0");
	if (fd >= 0)  {

            return fd;
        }
	fd = open_a_console("/dev/console");
	if (fd >= 0)  {

            return fd;
        }

	for (fd = 0; fd < 3; fd++)
		if (is_a_console(fd))
			return fd;

	fprintf(stderr, "Couldn't get a file descriptor referring to the console\n");
	exit(1);		/* total failure */
}
