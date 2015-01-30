

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class clsKeyboard {
public:
    clsKeyboard();
    clsKeyboard(const clsKeyboard& orig);
    virtual ~clsKeyboard();
   
    //vector <clsKeyboard::Key> myKeys; 
    string wsename;
    int readwse(string wsefile);
    
private:

};

int clsKeyboard::readwse(string wsefile)
{
    string input, temp1, temp2, temp3;
    ifstream fin;
    bool error;
    int whatkey = 0;
    int t;

    string segment;
    vector<Key> myKeys;
    Key currentline;

    fin.open("103.wse");
    error = false;

    vector<string> seglist;

    while (true)
    {
        whatkey = 0;
        getline(fin,input);
        if (!fin) break;  //EOF ??
        if (input.at(0) != '#')  {    // check for comment

            stringstream buffer(input);
            while(getline(buffer, segment, '\t')) {
                seglist.push_back(segment);
                // cout << segment << endl;
            }					


            //buffer >> temp1 >> temp2 >> temp3;




                currentline.position = seglist[0];	
                  currentline.keycode = seglist[1];
                  currentline.description = seglist[2];
                  seglist.clear();  
    //	cout << temp1 << '\t' << temp2 << endl;
            //	cout << myKeys[whatkey].position << "\t" << myKeys[whatkey].keycode << "\t" << myKeys[whatkey].description << endl;
                    //cout << seglist[0] << endl;

            myKeys.push_back (currentline);

            ++whatkey;
        }
    }
    if (error)
            cout << "file is corrupted..." << endl;

    cout << "hit enter to show values..." ;
    cin.get();

    for(int i=0; i < myKeys.size(); ++i) {
            cout <<  myKeys[i].keycode << endl;

    } 

//	for_each (myKeys.begin(), myKeys.end(), [](int i) {
//		 cout <<  myKeys.size() << endl;

//	}

    return 0;

}