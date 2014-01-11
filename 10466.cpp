//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 10466,The Marriage Interview
   Type   : dp
*/
#include <stdio.h>
#include <string.h>
unsigned long long int dp[65][65];
unsigned long long int my_firstDp(int n,int back)
{  if(n<=1) return 1;
   if(dp[n][back]!=-1) return dp[n][back];
   dp[n][back]=1;
   for(int i=1;i<=back;i++) dp[n][back]+=my_firstDp(n-i,back);
   return dp[n][back];
}
int main()
{  int n,back,kase=1;
   while(scanf("%d %d",&n,&back)==2)
   { if(n>60) break;
     memset(dp,-1,sizeof(dp));
     unsigned long long int result=my_firstDp(n,back);
     printf("Case %d: %llu\n",kase++,result);
   }
 return 0;
}
