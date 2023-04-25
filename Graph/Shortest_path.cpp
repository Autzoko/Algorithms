#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define MAXN 400
using namespace std;

//Floyd
int dist[MAXN][MAXN];

void Floyd(int n)
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

//Bellman-Ford
struct Edge
{
    int to, w, from;
}edges[MAXN];

void Bellman_Ford(int n, int m)
{
    for(int j = 0; j < n - 1; j++)
        for(int i = 1; i <= m; i++)
            dist[edges[i].to] = min(dist[edges[i].to], dist[edges[i].from] + edges[i].w);
}

//SPFA
struct Edge_
{
    int to, w, next;
}edges_[MAXN];

int inqueue[MAXN], head[MAXN];
void SPFA(int s)
{
    queue<int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        inqueue[p] = 0;
        for(int e = head[p]; e != 0; e = edges_[e].next)
        {
            int to = edges_[e].to;
            if(dist[to] > dist[p] + edges_[e].w)
            {
                dist[to] = dist[p] + edges_[e].w;
                if(!inqueue[to])
                {
                    inqueue[to] = 1;
                    Q.push(to);
                }
            }
        }
    }
}

//Dijkstra
struct Polar
{
    int dist. id;
    Polar(int dist, int id) : dist(dist), id(id){}
};

struct cmp
{
    bool operator()(Polar a, Polar b)
    {
        return a.dist > b.dist;
    }
};
priority_queue<Polar, vector<Polar>, cmp> Q;
int vis[MAXN];

void Dij(int s)
{
    dist[s] = 0;
    Q.push(Polar(0, s));
    while(!Q.empty())
    {
        int p = Q.top().id;
        Q.pop();
        if(vis[p])
            continue;
        vis[p] = 1;
        for(int e = head[p]; e != 0; e = edges[e].next)
        {
            int to = edges[e].to;
            dist[to] = min(dist[to], dist[p] + edges[e].w);
            if(!vis[to])
                Q.push(Polar(dist[to], to));
        }
    }
}
