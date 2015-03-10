/* 
 * File:   clsKeyboardTUI.h
 * Author: dshaffer
 *
 * Created on March 10, 2015, 2:17 PM
 */

#ifndef CLSKEYBOARDTUI_H
#define	CLSKEYBOARDTUI_H

class clsKeyboardTUI {
public:
    clsKeyboardTUI();
    clsKeyboardTUI(const clsKeyboardTUI& orig);
    virtual ~clsKeyboardTUI();
    void Test(void);
private:
void rectangle(int y1, int x1, int y2, int x2);
};

#endif	/* CLSKEYBOARDTUI_H */

