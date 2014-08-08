
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
#define MOD
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
const int maxn = 100005 ;
vector <int> Div[10*maxn];
int tree[maxn] , Left[maxn] , Right[maxn] , n , q;
vector <int> freq[10*maxn] , Value_Adj[maxn];
vector <int> :: iterator low ;
int ans[maxn];
bool Vis[10*maxn];
struct abc
{
    int lft , rgt , op , val ;
}inp[maxn+maxn+10];
void Pre()
{
    int i , j ;
    int lim = 10*maxn - 5 ;
    for ( i = 1 ; i <= lim ; i++ )
    {
        for( j = i ; j <= lim ; j+=i) Div[j].pb(i);
    }
}
int Lower (int pos,int hi , int cur )
{
    int lo = 0 ;
    hi -=1 ;
    int mid ;
    int bestsofar = 0 ;
    while(lo <= hi)
    {
        mid = (lo + hi )/2 ;
        if ( freq[cur][mid] <= pos)
        {
            bestsofar = freq[cur][mid];
            lo = mid + 1 ;
        }
        else hi = mid - 1 ;
    }
    return bestsofar;
}
int Uper (int pos , int hi , int cur )
{
    int lo = 0 ;
    hi -= 1 ;
    int mid ;
    int best_so_far = n+1;
    while( lo <= hi )
    {
        mid = (lo + hi ) /2 ;
        if ( freq[cur][mid] >= pos )
        {
            best_so_far = freq[cur][mid];
            hi = mid - 1;
        }
        else lo = mid + 1 ;
    }
    return best_so_far;
}
bool cmp( abc A , abc B)
{
    if(A.rgt == B.rgt ) return A.op < B.op ;
    return A.rgt < B.rgt ;
}
int Read(int x)
{
    int sum = 0 ;
    while(x)
    {
        sum += tree[x];
        x -= ( x & -x) ;
    }
    return sum ;
}
void write(int x, int val)
{
    while(x <= n )
    {
        tree[x] += val;
        x += ( x & -x);
    }
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     Pre();
     int cs , t ;
     read(t);

     for ( cs = 1 ; cs <= t ; cs++ )
     {
         int mx = -1 ;
         read(n) , read(q) ;
         int i , val , j;
         for ( i = 1 ; i <= n ; i++ )
         {
             read(val);
             freq[val].pb(i);
             inp[i].lft = val ;
             inp[i].rgt = i ;
             inp[i].op = 1 ; // input sign
             if(val > mx ) mx = val ;
             Vis[val] = 1 ;
             Right[i] = n+1;
             Left[i] = 0 ;
             Value_Adj[i].clear();
             tree[i] = 0 ;

         }
         int x , y , sz;
         for (  x = 1; i <= (n+q) ; i++ , x++)
         {
            read(inp[i].lft);
            read(inp[i].rgt);
            inp[i].op = 2 ;
            inp[i].val = x ;
         }


         for ( i = 1 ; i <= n ; i++ )
         {

             x = inp[i].lft ;
             sz = Div[x].size();
             //printf("\n\n x ::::: %d\n" , x);
             for ( j = 0 ; j < sz ; j++ )
             {
                 y = Div[x][j];

                 if(Vis[y]==0) continue ; // not present ;
                 int z = Lower(i-1,freq[y].size(),y);
                 {
                     Left[i] = max(Left[i],z);
                 }
                 z = Uper(i+1,freq[y].size(),y);
                 Right[i] = min(Right[i],z);

             }
              Value_Adj[Right[i]].pb(i);

         }
          sort(inp+1,inp+1+n+q,cmp);
         for ( i = 1 ; i <= (n+q) ; i++ )
         {
             if(inp[i].op == 1 )
             {
                 write(inp[i].rgt,1);
                 if(Left[inp[i].rgt]) write(Left[inp[i].rgt],-1);
                 x = Value_Adj[inp[i].rgt].size();
                 for ( y = 0 ; y < x ; y++ )
                 {
                     int z = Value_Adj[inp[i].rgt][y];
                     write(z,-1);
                     if(Left[z]) write(Left[z],+1);
                 }

             }
             else
             {
                 ans[inp[i].val] = Read(inp[i].rgt) - Read(inp[i].lft-1);
             }
         }
         printf("Case %d:\n",cs);
         for ( i = 1 ; i <= q ; i++ )
         {
             printf("%d\n",ans[i]);
         }
         if( cs != t )
         {

             for ( i = 0 ; i <= mx ; i++ ) { freq[i].clear(); Vis[i] = 0 ; }
         }

     }
   return 0;
}
/*
2
10 5
4 6 2 7 5 11 14 21 13 2
2 6
4 8
2 8
3 7
4 9
5 3
4 6 8 1 5
1 5
2 3
3 3
*/
