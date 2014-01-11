//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva,11747 - Heavy Cycle Edges
   Type   : Kruskal
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1005
struct graph
{  int node1,node2,cost;
   bool operator < (const graph &a) const
   {  return cost<a.cost;
   }
}G[MAX];
int prev[MAX];
int parent(int a)
{  if(a==prev[a]) return a;
   return prev[a]=parent(prev[a]);
}
int main()
{  int node,edge,i,u,v;
   while(scanf("%d %d",&node,&edge) && node && edge)
   {  for(i=0;i<node;++i) prev[i]=i;
	  for(i=0;i<edge;++i) scanf("%d %d %d",&G[i].node1,&G[i].node2,&G[i].cost);
	 sort(G,G+edge);
	 bool check=true;
	 for(i=0;i<edge;i++)
	 {  u=parent(G[i].node1);
	    v=parent(G[i].node2);
	    if(u==v)
		{ if(check) printf("%d",G[i].cost);
		 else printf(" %d",G[i].cost);
		 check=false;
        }
	    else
		{ prev[u]=v;
		}
	 }
	 if(check) printf("forest\n");
	 else printf("\n");
   }
 return 0;
}
