#include "random.h"
#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <dirent.h>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rs(seed);

double RandReal(double from,double to)
{
    uniform_real_distribution<double> Rand(from, to);
    return Rand((rs));
}

long long RandLLong(long long from, long long to)
{
    uniform_int_distribution<long long> Rand(from,to);
    return Rand(rs);
}

int RandInt(int from,int to)
{
    uniform_int_distribution<int> Rand(from,to);
    return Rand(rs);
}

pair<int,int> RandPair(int from,int to,bool A_less_than_B = 0)
{
    pair<int,int> Pair =  make_pair(RandInt(from,to),RandInt(from,to));
    if(A_less_than_B) if(Pair.first > Pair.second) swap(Pair.first,Pair.second);
    return Pair;
}

vector<int> RandArray(int length,int from,int to)
{
    vector<int> Array;
    for(int i = 1;i <= length;i++) Array.push_back(RandInt(from,to));
    return Array;
}

vector<vector<int>> RandMatrix(int row,int col,int from,int to)
{
    vector<vector<int>> Matrix;
    for(int i = 1;i <= row;i++) Matrix.push_back(RandArray(col,from,to));
    return Matrix;
}

vector<pair<int,int>> RandArrayPair(int length,int from,int to,bool A_less_than_B = 0)
{
    vector<pair<int,int>> ArrayPair;
    for(int i = 1;i <= length;i++) ArrayPair.push_back(RandPair(from,to,A_less_than_B));
    return ArrayPair;
}

char RandChar(int from, int to)
{
    uniform_int_distribution<char> Rand(from,to);
    return Rand(rs);
}

string RandString(int length,int from, int to)
{
    uniform_int_distribution<char> Rand(from,to);
    string s = "";
    for(int i = 1;i <= length;i++) s += Rand(rs);
    return s;
}

char RandChar(string type)
{
    return char(type[RandInt(0,type.size()-1)]);
}

string RandString(int length,string type)
{
    string s = "";
    for(int i = 1;i <= length;i++) s += type[RandInt(0,type.size()-1)];
    return s;
}

vector<pair<int,int>> RandTree(int node)
{
    vector<pair<int,int>> a;
    for(int i = 2;i <= node;i++)
    {
        int type = RandInt(0,1);
        if(type == 0)a.push_back({i,RandInt(1,i-1)});
        else a.push_back({RandInt(1,i-1),i});
    }
    shuffle(a.begin(),a.end(),rs);
    return a;
}

vector<pair<int,int>> RandMultigraph(int node,int edge)
{
    vector<pair<int,int>> g = RandTree(node);
    edge -= node - 1;
    while(edge--) g.push_back({RandInt(1,node),RandInt(1,node)});
    return g;
}

vector<pair<int,int>> RandGraph(int node,int edge)
{
    vector<pair<int,int>> g = RandTree(node);
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
            int u = RandInt(1,node);
            int v = RandInt(1,node);
            while(u == v || m[{u,v}]) v = RandInt(1,node),u = RandInt(1,node);
            m[{u,v}] = m[{v,u}] = 1;
            g.push_back({u,v});
        }
    }
    return g;
}



