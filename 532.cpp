//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 532
   Type   : BFS
*/
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct temp
{
	int level;
	int row;
	int col;
 
}sn,pn,cn;
int x_axis[6]={1,-1,0,0,0,0};
int y_axis[6]={0,0,1,-1,0,0};
int z_axis[6]={0,0,0,0,1,-1};
int L,R,C;
char maze[32][32][32];
int cost[32][32][32];
int bfs()
{        queue <temp> q;
       int i,j,k;
	for(i=0;i<L;i++)
	for(j=0;j<R;j++)
	   for( k=0;k<C;k++)
            if(maze[i][j][k]=='S')
           {  
              sn.level=i;
              sn.row=j;
              sn.col=k;
           }
       q.push(sn);
       cost[sn.level][sn.row][sn.col]=0;
 
 
    while(!q.empty())
    {   pn=q.front();
       q.pop();
       for(size_t i=0;i<6;i++)
       {  cn.level=pn.level+z_axis[i];
	  cn.row=pn.row+x_axis[i];
	  cn.col=pn.col+y_axis[i];
 if(cn.level>=0 && cn.level<L && cn.row>=0 && cn.row<R && cn.col>=0 && cn.col<C && maze[cn.level][cn.row][cn.col]!='#' &&cost[cn.level][cn.row][cn.col]==-1)
	  { cost[cn.level][cn.row][cn.col]=cost[pn.level][pn.row][pn.col]+1;
	     if(maze[cn.level][cn.row][cn.col]=='E')
		    return cost[cn.level][cn.row][cn.col];
	     q.push(cn);
 
	  }
       }
 
    }
 return -1;
}
void initialization(int L,int R,int C)
{  for(size_t i=0;i<L;i++)
	for(size_t j=0;j<R;j++)
	   for(size_t k=0;k<C;k++)
{              cost[i][j][k]=-1;
}
}
 int main()
 {
   while(scanf("%d %d %d",&L,&R,&C)==3)
 {        
	 if(L==0 && R==0 && C==0) return 0;
	 initialization(L,R,C);
	 for(size_t i=0;i<L;i++)
	    for(size_t j=0;j<R;j++) scanf("%s",maze[i][j]);
    int res=bfs();
	  if(res==-1) printf("Trapped!\n");
          else printf("Escaped in %d minute(s).\n",res);
 
 }
return 0;
 
}
 
