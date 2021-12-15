//Dai Ca Di Hoc
#include <bits/stdc++.h>

typedef char NameFile[1000];

using namespace std;

NameFile input, output, answer;
ifstream fi, fo, fa;
#define Task "main"

int read()
{
    
}

int readInput()
{
    fi.open(input);
}

int readOutput()
{
    fo.open(output);
}

int readAnswer()
{
    fa.open(answer);
}

bool check()
{
    if (!fo.good())
    {
        cout << "No output\n";
        return 0;
    }
    //other here
    cout << " Accepted\n";
    return 1;
    
}

main()
{
    gets(input);
    gets(output);

    strcpy(answer, input);
    strcat(input,  Task".inp");
    strcat(output, Task".out");
    strcat(answer, Task".out");

    readInput();
    readOutput();

    readAnswer();
    read();
    cout << ((check()) ? "1.00" : "0.00");
    fi.close();
    fo.close();
    fa.close();
//  system("pause");
}
