//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 10986
   Type   : Dijkstra
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
#define pb push_back
#define mp make_pair
 
#define pii pair <int,int>
#define MAX 20005
#define INF 1<<28
 
using namespace std;
 
//global variable
struct pq
{  int node,cost;
   void updtpq(int _node,int _cost)
   { node=_node;
         cost=_cost;
   }
 bool operator<(const pq &b)
        const{ return cost>b.cost;}
}x,y;
int dist[MAX];
vector <pii> adj[MAX];
priority_queue <pq> q;
bool visited[MAX];
int n,m,s,t;
void dijkstra()
{  int u,v;
  while(!q.empty()) q.pop();
 for(int i=0;i<n;i++) {dist[i]=INF;visited[i]=false;}
   dist[s]=0;
   x.updtpq(s,0);
   q.push(x);
   int cnt=0;
  while(!q.empty() && cnt<n) //this loop will run n time
  {   y=q.top();
      q.pop();
      u=y.node;
      if(visited[u]) continue;
      visited[u]=true;
      cnt++;
      if(u==t) break; //if we reach the destination
      for(int i=0;i<adj[u].size();i++)
          {  v=adj[u][i].first;
            if(dist[v]<=dist[u]+adj[u][i].second) continue;
            dist[v]=dist[u]+adj[u][i].second;
            x.updtpq(v,dist[v]);
           q.push(x);
          }
 
  }
}
int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
        int test,u,v,c;
        scanf("%d",&test);
        for(int kase=1;kase<=test;kase++)
        {  scanf("%d%d%d%d",&n,&m,&s,&t);
           for(int i=0;i<n;i++) adj[i].clear();
           for(int i=0;i<m;i++)
           { scanf("%d%d%d",&u,&v,&c);
                 getchar();
                 adj[u].pb(mp(v,c));
                 adj[v].pb(mp(u,c));
           }
         dijkstra();
         if(dist[t]==INF) printf("Case #%d: unreachable\n",kase);
         else printf("Case #%d: %d\n",kase,dist[t]);
        }
 
 
    return 0;
}
 
