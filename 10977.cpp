//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 10977 - Enchanted Forest
   Type   : bfs
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;
int row,col;
struct temp
{  int x;
   int y;
   int c;
   temp(int p,int q,int r)
   {  x=p;
    y=q;
     c=r;
   }
 temp() {}
} in;
 
char matrix[205][205];
int cost[205][205];
int x_axis[4]={1,-1,0,0};
int y_axis[4]={0,0,-1,1};
void intialization(int row,int col)
{   for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
{    matrix[i][j]='.';
     cost[i][j]=-1;}
}
 
void dangerous(int xC,int yC,int L)
{   int xl,yl,xr,yr;
    xl=max(xC-L,1),yl=max(yC-L,1),xr=min(xC+L,row),yr=min(yC+L,col);
    for(int i=xl;i<=xr;i++)
    {
        for(int j=yl;j<=yr;j++)
        {
            if((xC-i)*(xC-i)+(yC-j)*(yC-j)<=L*L)
            {
               matrix[i][j]='#';
            }
        }
    }
}
 
int bfs()
{  queue <temp> q;
  q.push(temp(1,1,0));
 if(row==1 && col==1) return 0;
   while(!q.empty())
   {  in=q.front();
      q.pop();
      for(int i=0;i<4;i++)
      {  int nx=in.x+x_axis[i];
         int ny=in.y+y_axis[i];
         if(nx>=1 && nx<=row && ny>=1 && ny<=col && matrix[nx][ny]!='#' && cost[nx][ny]==-1)
         {  cost[nx][ny]=in.c+1;
            if(nx==row && ny==col)
                    return cost[nx][ny];
            q.push(temp(nx,ny,in.c+1));
         }
      }
   }
 return -1;
 
}
 
int main()
{  while(cin>>row>>col)
{  if(row==0 && col==0) return 0;
  int m,n,x,y,l;
  intialization(row,col);
   cin>>m;
   for(int i=1;i<=m;i++)
   {  cin>>x>>y;
     matrix[x][y]='#';
   }
  cin>>n;
 for(int i=1;i<=n;i++)
   {  cin>>x>>y>>l;
     matrix[x][y]='#';
     dangerous(x,y,l);
   }
 
 int result=bfs();
 if(result==-1) printf("Impossible.\n");
 else printf("%d\n",result);
 
}
 return 0;
}
