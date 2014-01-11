//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 10739  String to Palindrome
   Type   : DP
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int cost[1002][1002];
string str;
int len;
int cal(int start,int end)
{  int x;
   if(start>=end) return 0;
   if(cost[start][end]) return cost[start][end];
   if(str[start]==str[end]) cost[start][end]=cal(start+1,end-1);
   else
   {  cost[start][end]=cal(start,end-1)+1;
	   x=cal(start+1,end)+1;
	  if(x<cost[start][end]) cost[start][end]=x;
	  x=cal(start+1,end-1)+1;
	  if(x<cost[start][end]) cost[start][end]=x;
   }
   return cost[start][end];
}
void free()
{  for(int i=0;i<=len;i++)
	   for(int j=0;j<=len;j++)  cost[i][j]=0;
}
int main()
{  int t;
   scanf("%d",&t);
   getchar();
   for(int kase=1;kase<=t;kase++)
   {  
	  getline(cin,str);
	  len=str.size()-1;
	  printf("Case %d: %d\n",kase,cal(0,len));
	  if(kase<t) free();
   }
 return 0;
}
 
