#include <signal.h>
#include <termios.h>
#include <linux/kd.h>
#include <linux/keyboard.h>
#include <stdlib.h>
#include <unistd.h> /* close */
#include "getfd.h"
#include <stdio.h>
#include <sys/ioctl.h> /* ioctl */
#include <fcntl.h> /* open */

//#include <iostream>

#include <stdio.h>
//#include <unistd.h>
//#include <getopt.h>
//#include <fcntl.h>
//#include <sys/ioctl.h>
//#include <assert.h>
// #include "nls.h"
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
            close(fd);
        return;
    }
    if (tcsetattr(fd, 0, &old) == -1)
        perror("tcsetattr");
    close(fd);
    return;
}

int
die(int x) {
      close(fd);
    clean_up();
    return x;
}

static void
watch_dog(int x) {
    clean_up();
    return;
}

void LEDTurnOn (void)
{
//  ioctl(0, KDSETLED, 255);
    int tty = open("/dev/console", 0), led;
    ioctl(tty,KDSETLED, 7);
    
    
}

int * FullBuffer (void) {

    int show_keycodes = 1;

    struct termios new;

    static char buf[18];
    int *newbuf = malloc(sizeof(int) * 19); 

    int i, n;

   fd = getfd(NULL);
//    fd = open("/proc/self/fd/0", O_RDONLY);
//  printf ("FD: %i\n", fd);
    // close(fd);
    
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
    int t, kc,xxx;
    while (1) {
     //   alarm(100);
        n = read(fd, buf, sizeof(buf));
      //   printf( "Size of Buff  %i\n"), n;
     //   for(xxx=0; xxx<sizeof(buf); ++xxx) {
     //       printf("%i ", buf[xxx]);
      //  }
     //    printf("\n");
      
        //for (int yy=0; yy<n; ++yy )  {cout << "BUF #" << yy << "=" << buf[yy] << " "; }
        //cout << endl;
        i = 0;
        while (i < n) {
            char *s;
            s = (buf[i] & 0x80) ? "BREAK" : "MAKE";
            if (i+2 < n && (buf[i] & 0x7f) == 0 && (buf[i+1] & 0x80) != 0 && (buf[i+2] & 0x80) != 0) 
            {
                kc = ((buf[i+1] & 0x7f) << 7) | (buf[i+2] & 0x7f);
                i += 3;
            } else {
                kc = (buf[i] & 0x7f);
                i++;
            }
            // ******** SELECT MAKE OR BREAK
            if (s=="MAKE") newbuf[18] = 1999;
            else newbuf[18] = 999;

            for (t=0;t<sizeof(buf);++t) {
                newbuf[t] = buf[t];
                buf[t] = 0;  //flush buffer
            }
            clean_up();
            close(fd);
            return newbuf;
        }
    }
}