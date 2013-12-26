//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 572, Oil Deposits
   Type   : DFS
*/
#include <stdio.h>
char maze[105][105];
int row,col;
int x_axis[8]={-1,-1,-1,0,0,1,1,1};
int y_axis[8]={0,1,-1,1,-1,0,1,-1};
void dfs(int x,int y)
{  maze[x][y]='*';
   int i;
   for(i=0;i<8;i++)
   {  int nx=x_axis[i]+x;
      int ny=y_axis[i]+y;
      if(nx>=0 && nx<row && ny>=0 && ny<col && maze[nx][ny]=='@')
	      dfs(nx,ny);
   }
}
int main()
{  while(scanf("%d %d",&row,&col) && row && col)
{  int i,j,count=0;
   for(i=0;i<row;i++) scanf("%s",maze[i]);
   for(i=0;i<row;i++)
	   for(j=0;j<col;j++)
     if(maze[i][j]=='@')
   { count++;
     dfs(i,j);
   }
   printf("%d\n",count);
}
 return 0;
}
