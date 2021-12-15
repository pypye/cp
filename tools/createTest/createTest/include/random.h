#ifndef RANDOM_H
#define RANDOM_H
#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <dirent.h>

using namespace std;

namespace rd
{
    double RandReal(double from,double to);
    long long RandLLong(long long from, long long to);
    int RandInt(int from,int to);
    vector<int> RandArray(int len,int from,int to);
    vector<vector<int>> RandMatrix(int row,int col,int from,int to);
    string RandString(int length,int from,int to);
    string RandString(int length,string type);
    vector<pair<int,int>> RandTree(int node);
    vector<pair<int,int>> RandMultigraph(int node,int edge);
    vector<pair<int,int>> RandGraph(int node,int edge);
}

#endif
