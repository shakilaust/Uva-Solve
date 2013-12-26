//BISMILLAHIRRAHMANIRRAHIM
/* Author : Shakil_AUST
   problem: uva 260,Il Gioco dell'X
   Type   : DFS
*/
#include <stdio.h>
#include <string.h>
char maze[205][205];
bool visit[205][205];
int x_axis [6] = {-1, -1, 0, 0, 1, 1};
 int y_axis [6] = {-1, 0, -1, 1, 0, 1};
char result;
int n;
void dfs(int x,int y,char curr)
{  if(x<0 || x>=n || y<0 || y>=n || maze[x][y]!=curr || visit[x][y]) return;
 if(x==n-1 && maze[x][y]=='b') {result='B'; return ;}
 if(y==n-1 && maze[x][y]=='w') {result='W'; return;}
 visit[x][y]=true;
 
         for ( int i = 0; i < 6; i++ )
         dfs (x+x_axis[i], y+y_axis[i], curr);
}
 
int main()
{       int kase=1;
	while(scanf("%d",&n) && n)
{       memset(visit,false,sizeof(visit));
	for(int i=0;i<n;i++) scanf("%s",maze[i]);
        for(int i=0;i<n;i++) if(!visit[0][i] && maze[0][i]=='b') dfs(0,i,'b');
        for(int i=0;i<n;i++) if(!visit[i][0] && maze[i][0]=='w') dfs(i,0,'w');
        printf("%d %c\n",kase++,result);
}
	return 0;
}
 
