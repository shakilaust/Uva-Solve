//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 871
   Type   : DFS
*/ 
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
int x_axis[8]={-1,-1,-1,0,0,1,1,1};
int y_axis[8]={1,0,-1,1,-1,1,0,-1};
int count,row,col;
char maze[30][30];
void dfs(int x,int y)
{  maze[x][y]='0';
  for(int i=0;i<8;i++)
  { int nx=x_axis[i]+x;
    int ny=y_axis[i]+y;
   if(nx>=0 && nx<row && ny>=0 && ny<col && maze[nx][ny]=='1') { dfs(nx,ny);++count;}
  }
 
}
int main()
 {  int T;
    cin>>T;
    cin.ignore(100,'\n');
     cin.ignore(100, '\n');
    while(T--)
    {  string input;
       row=0; count=0;
       int k=0;
       while(getline(cin,input))
       {   if (input == "")
        break;
	   col=input.size();
          for(int i=0,sz=input.size();i<sz;i++)
                  maze[row][i]=input[i];
         row++;
       }
     int res=0;
      for(int i=0;i<row;i++)
              for(int j=0;j<col;j++)
      { if(maze[i][j]=='1') 
         {dfs(i,j);
        if((count+1)>res) res=count+1;
         count=0; 
         }
      }
     printf("%d\n",res);
     if(T) printf("\n");
    }
  return 0;
 }
