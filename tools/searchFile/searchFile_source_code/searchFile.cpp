#include <bits/stdc++.h>
#include <random>
#include <dirent.h>
#include <windows.h>

using namespace std;

string file_type,dest,sour;
int cnt = 0;

void find_file(string source)
{
    string file_name;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (source.c_str())) != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            file_name = ent->d_name;
            if(file_name == "." || file_name == "..") continue;
            if(file_name.find(file_type) != -1)
            {
                string in = source + "\\" + file_name;
                cerr << in << "\n";
                string ou = dest + "\\" + to_string(++cnt) + "." + file_name;
                CopyFile(in.c_str(),ou.c_str(),0);
            }
            else
            {
                string newsource = source + "\\" + file_name;
                {
                    find_file(newsource);
                }
            }
        }
        closedir(dir);
    }
    return;
}
int main()
{
    cerr << "Source : ";getline(cin,sour);
    cerr << "Dest : ";getline(cin,dest);
    cerr << "File Type : ";getline(cin,file_type);
    find_file(sour);
    if(fopen("config.txt","r"))
    {
        freopen("config.txt","r",stdin);
        cin >> cnt;
        fclose(stdin);
    }
    else cnt = 0;
    freopen("config.txt","w",stdout);
    cout << cnt;
}
