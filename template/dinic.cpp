bool bfs()
{
    memset(lv, -1, sizeof(lv));
    queue<int> qu;
    qu.push(1);
    lv[1] = 0;
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();
        for (int id : ss[u])
        {
            int v = ((edge[id].f < edge[id].c) ? edge[id].v : 1);
            if (lv[v] != -1)
                continue;
            lv[v] = lv[u] + 1;
            qu.push(v);
        }
    }
    return lv[ed] > 0;
}

int dfs(int u, int val)
{
    if (u == ed)
        return val;
    for (int &i = cp[u]; i < (int)ss[u].size(); i++)
    {
        int id = ss[u][i];
        int v = edge[id].v;
        if (lv[v] == lv[u] + 1 && edge[id].f < edge[id].c)
        {
            int cv = dfs(v, min(val, edge[id].c - edge[id].f));
            if (!cv)
                continue;
            edge[id].f += cv;
            edge[id ^ 1].f -= cv;
            return cv;
        }
    }
    return 0;
}

int dinic()
{
    int rev = 0;
    while (bfs())
    {
        for (int i = 1; i <= n; i++)
            cp[i] = 0;
        while (1)
        {
            int cv = dfs(1, 2e9);
            if (cv == 0)
                break;
            rev += cv;
        }
    }
    return rev;
}