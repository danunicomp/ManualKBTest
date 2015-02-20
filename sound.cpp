#include <stdlib.h>
#include "GPIOClass.h"

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

void PlayBeep(GPIOClass* GPIO) {
    GPIO->binoutput_gpio(1);
    usleep(50000);
    GPIO->binoutput_gpio(0);
    usleep(70000);
    GPIO->binoutput_gpio(1);
    usleep(100000);
    GPIO->binoutput_gpio(0);
    return;
}

void FailBeep(void) {

    GPIOClass gpio21;
    gpio21.gpionum = "21";
    gpio21.export_gpio();
    gpio21.setdir_gpio("out");
    gpio21.binoutput_gpio(1);
    usleep(50000);
    gpio21.binoutput_gpio(0);
    usleep(70000);
    gpio21.binoutput_gpio(1);
    usleep(100000);
    gpio21.binoutput_gpio(0);
    return;
}

void PassBeep(void) {

    GPIOClass gpio21;
    gpio21.gpionum = "21";
    gpio21.export_gpio();
    gpio21.setdir_gpio("out");
    gpio21.binoutput_gpio(1);
    usleep(40000);
    gpio21.binoutput_gpio(0);
    return;
}