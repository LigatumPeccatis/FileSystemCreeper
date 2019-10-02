#include <cstring>
#include <io.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void list(const char* dir)
{
    char originalDirectory[MAX_PATH];

    // Get the current directory so we can return to it
    _getcwd(originalDirectory, MAX_PATH);

    _chdir(dir);  // Change to the working directory
    _finddata_t fileinfo;

    // This will grab the first file in the directory
    // "*" can be changed if you only want to look for specific files
    intptr_t handle = _findfirst("*", &fileinfo);

    if(handle == -1)  // No files or directories found
    {
        perror("Error searching for file");
        exit(1);
    }

    do
    {
        if(!strcmp(fileinfo.name, ".") || !strcmp(fileinfo.name, ".."))
            continue;
        if(fileinfo.attrib & _A_SUBDIR) {// Use bitmask to see if this is a directory
            cout << fileinfo.name << " This is a directory." << endl;
            char newDir[100];   
            strcpy(newDir, dir);
            strcat(newDir, strcat(fileinfo.name,"\\"));
            list(newDir);
        }else{
            cout << fileinfo.name << " This is a file." << endl;
        }
    } while(! _findnext(handle, &fileinfo));

    _findclose(handle); // Close the stream

    _chdir(originalDirectory);
}

int main(int argc, char* argv[])
{   
   
    if(argc > 1)
        cout << argv[1];
    list("C:\\Users\\");
    return 0;
}