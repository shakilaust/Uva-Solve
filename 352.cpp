//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: 352 - The Seasonal War
   Type   : DFS
*/
#include <stdio.h>
char maze[105][105];
int n;
int x_axis[8]={-1,-1,-1,0,0,1,1,1};
int y_axis[8]={0,1,-1,1,-1,0,1,-1};
void dfs(int x,int y)
{  maze[x][y]='0';
   int i;
   for(i=0;i<8;i++)
   {  int nx=x_axis[i]+x;
      int ny=y_axis[i]+y;
      if(nx>=0 && nx<n && ny>=0 && ny<n && maze[nx][ny]=='1')
              dfs(nx,ny);
   }
}
int main()
{  int test=1;
  while(scanf("%d",&n)==1)
{  int i,j,count=0;
   for(i=0;i<n;i++) scanf("%s",maze[i]);
   for(i=0;i<n;i++)
           for(j=0;j<n;j++)
     if(maze[i][j]=='1')
   { count++;
     dfs(i,j);
   }
   printf("Image number %d contains %d war eagles.\n",test++,count);
}
 return 0;
}
