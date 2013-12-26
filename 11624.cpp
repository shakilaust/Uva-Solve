#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
 
using namespace std;
#define INF_MAX 2147483647
#define INF_MIN -2147483647
struct temp
{
	int x,y,c;
   temp(int p,int q,int r)
   { x=p;
     y=q;
    c=r;
   }
	temp() {}
}in;
int row,col;
int x_axis[4]={1,-1,0,0};
int y_axis[4]={0,0,1,-1};
char matrix[1005][1005];
int cost_joe[1005][1005];
int cost_fire[1005][1005];
 
void bfs_joe()
{  queue <temp> q;
   for(int i=0;i<row;i++)
	   for(int j=0;j<col;j++)
   {   if(matrix[i][j]=='J')
   {   cost_joe[i][j]=0;
       q.push(temp(i,j,0));
   }
   }
   while(!q.empty())
   {  in=q.front();
      q.pop();
      for(int i=0;i<4;i++)
      {  int nx=in.x+x_axis[i];
         int ny=in.y+y_axis[i];
         if(nx>=0 && nx<row && ny>=0 && ny<col && matrix[nx][ny]!='#' && cost_joe[nx][ny]==INF_MAX)
	 {cost_joe[nx][ny]=in.c+1;
         q.push(temp(nx,ny,in.c+1));
	 }
      }
   }
}
void bfs_fire()
{  queue <temp> q;
   for(int i=0;i<row;i++)
	   for(int j=0;j<col;j++)
   {   if(matrix[i][j]=='F')
   {   cost_fire[i][j]=0;
       q.push(temp(i,j,0));
   }
   }
   while(!q.empty())
   {  in=q.front();
      q.pop();
      for(int i=0;i<4;i++)
      {  int nx=in.x+x_axis[i];
         int ny=in.y+y_axis[i];
         if(nx>=0 && nx<row && ny>=0 && ny<col && matrix[nx][ny]!='#' && cost_fire[nx][ny]==INF_MAX)
	 {cost_fire[nx][ny]=in.c+1;
         q.push(temp(nx,ny,in.c+1));
	 }
      }
   }
}
 
void reset ()
{
    for ( int i = 0; i < 1005; i++ ) {
        for ( int j = 0; j < 1005; j++ )
            cost_joe [i] [j] = cost_fire [i] [j] = INF_MAX;
    }
}
 
 
int main()
{  int kase;
   scanf("%d",&kase);
   while(kase--)
   {   scanf("%d %d",&row,&col);
       for(int i=0;i<row;i++)  scanf("%s",matrix[i]);
      reset();
       bfs_joe();
       bfs_fire();
       int resTime=INF_MAX;
    for(int i=0;i<row;i++) { if( cost_fire[0][i]>cost_joe[0][i])  resTime=min(resTime,cost_joe[0][i]);
			    if( cost_fire[row-1][i]>cost_joe[row-1][i])  resTime=min(resTime,cost_joe[row-1][i]);
			   }
    for(int i=0;i<col;i++) { if( cost_fire[i][0]>cost_joe[i][0])  resTime=min(resTime,cost_joe[i][0]);
			    if( cost_fire[i][col-1]>cost_joe[i][col-1])  resTime=min(resTime,cost_joe[i][col-1]);
			   }
    if(resTime==INF_MAX) printf("IMPOSSIBLE\n");
    else printf("%d\n",resTime+1);
 
   }
 return 0;
}
