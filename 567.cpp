//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 567,Risk
   Type   : BFS
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> adjList[25];
int cost[25];
void bfs(int scr,int dest)
{ memset(cost,-1,sizeof(cost));
queue <int> q;
q.push(scr);
cost[scr]=0;
while(!q.empty() && cost[dest]==-1)
 { int house=q.front();
   q.pop();
   for(int i=0;i<adjList[house].size();i++)
   { 
    int next=adjList[house][i];
    if(cost[next]<0)
        {  cost[next]=cost[house]+1;
           q.push(next);
           if(next==dest) return ;
        }
   }
 }
}
 
int main()
{
int n,u,Ts=1,T;
while(scanf("%d",&n)==1)
{ for(int i=0;i<n;i++)
  {    cin>>u;
       adjList[1].push_back(u);
       adjList[u].push_back(1);
  }
for(int j=2;j<=19;j++)
 {   cin>>n;
   for(int i=0;i<n;i++)
    {   cin>>u;
        adjList[j].push_back(u);
        adjList[u].push_back(j);
    }
 } 
cin>>T;
printf("Test Set #%d\n",Ts++);
while(T--)
{ int a,b;
  cin>>a>>b;
  bfs(a,b);
if(a>9 && b>9) printf("%d to %d: %d\n",a,b,cost[b]);
else if(a>9 && b<10) printf("%d to  %d: %d\n",a,b,cost[b]);
else if(a<10 && b>9) printf(" %d to %d: %d\n",a,b,cost[b]);
else printf(" %d to  %d: %d\n",a,b,cost[b]);
}
printf("\n");
for(int i=1;i<=20;i++) adjList[i].clear();
 
}
return 0;
}
