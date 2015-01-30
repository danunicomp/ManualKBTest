#include <stdlib.h>

int testsound(void)
{
 system("omxplayer /root/NetBeansProjects/ManualKBTest/exitfree wavraspberry  >/dev/null");
}

void PlayFailSound(void) {
 system("omxplayer /root/NetBeansProjects/ManualKBTest/beep-05.wav >/dev/null");   
}

void PlayPassSound(void) {
 system("omxplayer /root/NetBeansProjects/ManualKBTest/beep-05.wav >/dev/null");   
}
