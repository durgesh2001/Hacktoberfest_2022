#include<bits/stdc++.h>
using namespace std;

const int n=1e3+10;
vector<pair<int,int>>adj[n+1];

void dijkstra(int src,int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>distance(n+1,INT_MAX);

    distance[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        for(auto child : adj[prev])
        {
            int next=child.first;
            int next_dis=child.second;
            if(distance[next]>distance[prev]+next_dis)
            {
                distance[next]=distance[prev]+next_dis;
                pq.push({distance[next],next});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<distance[i]<<"   ";
    }
}



int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        adj[v1].push_back({v2,wt});
        adj[v2].push_back({v1,wt});
    }
    int src;
    cin>>src;
    dijkstra(src,n);
    return 0;
}