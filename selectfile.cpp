#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  
#include <sstream>
#include <fstream>
#include <unistd.h>

void getFilesList(String filePath,String extension, vector<string> & returnFileName)
{
    WIN32_FIND_DATA fileInfo;
    HANDLE hFind;   
    String  fullPath = filePath + extension;
    hFind = FindFirstFile(fullPath.c_str(), &fileInfo);
    if (hFind == INVALID_HANDLE_VALUE){return;} 
    else {
        return FileName.push_back(filePath+fileInfo.cFileName);
        while (FindNextFile(hFind, &fileInfo) != 0){
            return FileName.push_back(filePath+fileInfo.cFileName);
        }
    }
}
