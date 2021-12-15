#ifndef CREATE_H
#define CREATE_H
#include<bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <dirent.h>

using namespace std;

class create
{
    public:
        create(string direct,string name)
        {
            Name = name;
            Dir = direct;
            mkdir(Dir.c_str());
            string namefile = Dir + "//" + Name;
            mkdir(namefile.c_str());
            DeleteFile("createTest.depend");
        }
        string get_dir(int i);

        void Generate(int i);

    private:
        string Dir,Name;
};

#endif // CREATE_H
