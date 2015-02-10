#include <stdlib.h>

int testsound(void)
{
 system("omxplayer /home/pi/ManualKBTest/exitfree wavraspberry  >/dev/null");
}

void PlayFailSound(void) {
 system("omxplayer /home/pi/ManualKBTest/snd-fail.wav >/dev/null");   
}

void PlayPassSound(void) {
 system("omxplayer /home/pi/ManualKBTest/snd-pass.wav >/dev/null");   
}
