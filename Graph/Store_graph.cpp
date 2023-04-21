#include <bits/stdc++.h>
#include <vector>
#define MAXN 5005

//邻接矩阵
int mat[MAXN][MAXN];

inline void add(int u, int v, int w)
{
    //带权无向图
    mat[u][v] = w;
    mat[v][u] = w;
}

//邻接表
struct Edge
{
    int to, w;
};

std::vector<Edge> edges[MAXN];

inline void add(int from, int to, int w)
{
    //有向图
    Edge e = {to, w};
    edges[from].push_back(e);
}

inline void add2(int u, int v, int w)
{
    //无向图
    add(u, v, w);
    add(v, u, w);
}

//链式前向星
struct Edge_
{
    int to, w, next;
}edges_[MAXN];

int head[MAXN], cnt;

inline void add(int from, int to, int w)
{
    edges_[++cnt].w = w;
    edges_[cnt].to = to;
    edges_[cnt].next = head[from];
    head[from] = cnt;
}

