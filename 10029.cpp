


 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD 1000000007
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
int mem[20][20] , dp[ 25000 + 5 ] , lena , lenb , len[ 25000 + 5] , i , j , idx;
char A[20] , B[20] , inp[ 25000 + 5][20];
long long int vis[20][20] , cs ;
vector <int> adj[25000+5];
int taken[2500+5] ,  check ;
int trie[500005][30];
int value(char ch)
{
    return ch - 'a';
}
void insert(char *str, int id)
{
    int i , cur = 0 , j;
    for( i = 0 ; str[i] ; i++ )
    {
        j = value(str[i]);
        if(trie[cur][j]==-1)
        {
            trie[cur][j] = ++idx;
            memo(trie[idx],-1);
        }
        cur = trie[cur][j];
    }
   // printf("id :: %d cur :: %d\n",id,cur);
    trie[cur][28] = id;
    //printf("cur ::%d trie[cur][28]::%d\n",cur,trie[cur][28]);
}
int traverse(char *str )
{
    int i , cur = 0 , j ;
    for ( i = 0 ; str[i] ; i++ )
    {
        j  = value(str[i]);
        if(trie[cur][j]==-1) return -1;
        cur = trie[cur][j];
        //if(trie[cur][28]!=-1)
        //printf("cur :: %d  val::%d \n",cur,trie[cur][28]);
    }
   // printf(" now :: %d val :: %d\n",cur,trie[cur][28]);
    return trie[cur][28];
}
int main()
{
  int iidx = 0 ;
  idx = 0 ;
  memo(trie[0],-1);
   while(scanf("%s",&inp[iidx])==1)
   {
      // if(inp[iidx][0]=='X') break;
       insert(inp[iidx],iidx);
       dp[iidx] = 1 ;
       iidx++;
   }
   int i , j , k , r , x , y , t;
   int ans = 1  ;
   //for( i = 0 ; i <iidx ; i++ ) printf("i :: %d inp[i]::%s\n",i,inp[i]);
   for ( i = 0 ; i < iidx ; i++)
   {
       int len = strlen(inp[i]);
       // printf("i:: %d len:: %d %s\n",i ,len,inp[i]);
      // printf("Before\n");
       for ( j = 0 ; j < len ; j++ ) A[j] = inp[i][j];
       A[len] = '\0';
       // for replace
       for ( j = 0 ; j < len ; j++ )
       {
           for ( k = 'a' ; k <='z' ; k++ )
           {
               if(inp[i][j]==k) continue;
               A[j] = k ;
              // printf("i:: %d %s\n",i,A);
               if(( r = traverse(A)) > i )
               {
                   //printf("shakil yes r::%d i::%d\n",r,i);
                   dp[r] = max(dp[r] , dp[i]+1);
                  // printf("i :: %d  r = %d dp[r] :: %d dp[i]::%d\n",i,r,dp[r],dp[i]);
                   if(ans < dp[r] ) ans = dp[r];
               }
               A[j] = inp[i][j];
           }
       }
      // printf("\nAfter replace\n");
      //  for( j = 0 ; j <iidx ; j++ ) printf("j :: %d inp[j]::%s\n",j,inp[j]);
       // for add
      // int x , y ;
       len = strlen(inp[i]);
       for( j = 0 ; j <= len ; j++ )
       {
           for( x = 0 ; x < j ; x++ ) A[x] = inp[i][x];
           for( k = 'a' ; k <= 'z' ; k++  )
           {

               A[x] = k ;
               for ( t = x+1 , y = j ; y < len ; y++ , t++ ) A[t] = inp[i][y];
               A[t] = '\0';
               if(( r = traverse(A)) > i )
               { //  printf("shakil add r::%d i::%d\n",r,i);
                   dp[r] = max(dp[r] , dp[i]+1);
                   if(ans < dp[r] ) ans = dp[r];
               }
            //   printf("K ::: %c i::%d %s\n",k,i,inp[i]);

           }
           // printf("Adding\n");
           // for( k = 0 ; k <iidx ; k++ ) printf("j :: %d inp[j]::%s\n",k,inp[k]);
       }
      // printf("\nAfter add\n");
      // for( j = 0 ; j <iidx ; j++ ) printf("j :: %d inp[j]::%s\n",j,inp[j]);
       // for delete
       for ( j = 0 ; j < len ; j++ )
       {
           for ( x = 0 ; x < j ; x++ ) A[x] = inp[i][x] ;
           for ( y = j+1 ; y < len ; x++ , y++  ) A[x] = inp[i][y];
           A[x] = '\0';
            if(( r = traverse(A)) > i )
               {  
                   dp[r] = max(dp[r] , dp[i]+1);
                   if(ans < dp[r] ) ans = dp[r];
               }
       }
     
   }

   printf("%d\n",ans);
   return 0;
}
