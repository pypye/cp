#include "random.h"
#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <dirent.h>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rs(seed);

double rd::RandReal(double from,double to)
{
    uniform_real_distribution<double> Rand(from, to);
    return Rand((rs));
}

long long rd::RandLLong(long long from, long long to)
{
    uniform_int_distribution<long long> Rand(from,to);
    return Rand(rs);
}

int rd::RandInt(int from,int to)
{
    uniform_int_distribution<int> Rand(from,to);
    return Rand(rs);
}

vector<int> rd::RandArray(int len,int from,int to)
{
    vector<int> Array;
    for(int i = 1;i <= len;i++) Array.push_back(rd::RandInt(from,to));
    return Array;
}

vector<vector<int>> rd::RandMatrix(int row,int col,int from,int to)
{
    vector<vector<int>> Matrix;
    for(int i = 1;i <= row;i++) Matrix.push_back(rd::RandArray(col,from,to));
    return Matrix;
}

string rd::RandString(int length,int from, int to)
{
    uniform_int_distribution<char> Rand(from,to);
    string s = "";
    for(int i = 1;i <= length;i++) s += Rand(rs);
    return s;
}

string rd::RandString(int length,string type)
{
    string s = "";
    for(int i = 1;i <= length;i++) s += type[rd::RandInt(0,type.size()-1)];
    return s;
}

vector<pair<int,int>> rd::RandTree(int node)
{
    vector<pair<int,int>> a;
    for(int i = 2;i <= node;i++)
    {
        int type = rd::RandInt(0,1);
        if(type == 0)a.push_back({i,rd::RandInt(1,i-1)});
        else a.push_back({rd::RandInt(1,i-1),i});
    }
    shuffle(a.begin(),a.end(),rs);
    return a;
}

vector<pair<int,int>> rd::RandMultigraph(int node,int edge)
{
    vector<pair<int,int>> g = rd::RandTree(node);
    edge -= node - 1;
    while(edge--) g.push_back({rd::RandInt(1,node),rd::RandInt(1,node)});
    return g;
}

vector<pair<int,int>> rd::RandGraph(int node,int edge)
{
    vector<pair<int,int>> g = rd::RandTree(node);
    edge -= node - 1;
    if(node <= 4000)
    {
        vector<vector<int>> m(node + 1,vector<int>(node + 1));
        vector<pair<int,int>> q;
        for(auto e : g) m[e.first][e.second] = m[e.second][e.first] = 1;
        for(int i = 1;i <= node;i++)
            for(int j = i + 1;j <= node;j++) if(!m[i][j]) q.push_back({i,j});
        shuffle(q.begin(),q.end(),rs);
        for(int i = 0;i < edge;i++)
        {
            int type = RandInt(0,1);
            if(type)g.push_back({q[i].first,q[i].second});
            else g.push_back({q[i].second,q[i].first});
        }
    }
    else
    {
        map<pair<int,int>,bool> m;
        for(auto e : g) m[e] = m[{e.second,e.first}] = 1;
        for(int i = 0;i < edge;i++)
        {
            int u = rd::RandInt(1,node);
            int v = rd::RandInt(1,node);
            while(u == v || m[{u,v}]) v = rd::RandInt(1,node),u = rd::RandInt(1,node);
            m[{u,v}] = m[{v,u}] = 1;
            g.push_back({u,v});
        }
    }
    return g;
}



