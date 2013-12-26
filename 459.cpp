//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: 459 - Graph Connectivity
   Type   : DFS
*/
 
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
bool visited[30];
vector <int> adjList[30];
void dfs(int now)
{  if(visited[now]) return ;
   visited[now]=true;
   for(int i=0;i<adjList[now].size();i++)
	   dfs(adjList[now][i]);
}
int main()
{  int T;
   cin>>T;
  cin.ignore(100,'\n');
 while(T--)
 {  int count=0;
    char str;
    for(int i=0;i<30;i++) visited[i]=false;
    cin>>str;
    cin.ignore(100,'\n');
    int limit=str-'A'+1;
    string input;
   while(getline(cin,input))
   {  if(input=="") break;
      int x=input[0]-'A'+1;
      int y=input[1]-'A'+1;
      adjList[x].push_back(y);
      adjList[y].push_back(x);  
   }
  for(int i=1;i<=limit;i++) if(!visited[i]) {dfs(i);count++;} 
  printf("%d\n",count);
  if(T) printf("\n");
  for(int i=1;i<=limit;i++) adjList[i].clear();
 }
 return 0;
 
}
