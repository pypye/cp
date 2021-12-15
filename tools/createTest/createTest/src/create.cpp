#include "create.h"
#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <dirent.h>

using namespace std;

string create::get_dir(int i)
{
    ostringstream f;
    f << create::Dir << "//" << create::Name << "//" << create::Name << i;
    mkdir(f.str().c_str());
    return f.str();
}

void create::Generate(int i)
{
    string dir = create::get_dir(i);
    string dirinp = dir + "//" + create::Name + ".inp";
    string dirout = dir + "//" + create::Name + ".out";
    string fileinp = create::Name + ".inp";
    string fileout = create::Name + ".out";
    CopyFile(fileinp.c_str(),dirinp.c_str(),false);
    CopyFile(fileout.c_str(),dirout.c_str(),false);
    DeleteFile(fileinp.c_str());
    DeleteFile(fileout.c_str());
    DeleteFile("createTest.layout");
}
