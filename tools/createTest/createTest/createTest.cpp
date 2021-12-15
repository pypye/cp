/// Created by Ruiiya ///
#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <dirent.h>
#include "random.h"
#include "create.h"

using namespace std;
using namespace rd;

#define USING_CPP

int amount_of_test = 10;
int test_start_from = 41;
string name = "eqn"; ///Problem's name
string direct = "..//Tasks";

void create_inp(int T)
{
	//Code here
    int a = RandInt(-1000, 1000);
    int b = RandInt(-1000, 1000);
    int c = RandInt(-1000, 1000);
    cout << 0 << " " << b << " "<< c;

}
///Don't edit main code
int main()
{
#ifdef USING_CPP
    if(system(("g++ -std=c++14 " + name + ".cpp -o " + name).c_str())) exit(0);
#endif // USING_CPP
    create Test(direct, name);
    for(int nth_test = test_start_from; nth_test <= test_start_from + amount_of_test - 1; nth_test++)
    {
        freopen((name + ".inp").c_str(), "w", stdout);
        create_inp(nth_test);
        fclose(stdout);
        if(system((name + ".exe").c_str())) DeleteFile((name + ".inp").c_str()), exit(0);
        Test.Generate(nth_test);
        cerr << "Test" << nth_test << ": Complete! \n";
    }
    return 0;
}
