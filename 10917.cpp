


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
typedef long long ll;
const int maxn = 1005;

struct graph
{
    ll c , x;
    graph() {}
    graph(ll _x ,ll _c)
    {
         x = _x;
         c = _c;
    }
    bool operator < ( const graph &a ) const
    {
        return a.c < c ;
    }
}inp[maxn] , prev , cur ;
ll dp[maxn] , dp2[maxn];
bool vis[maxn];
int n , m ;
vector <ll > adj[maxn];
vector < pair < ll , ll > > g[maxn];
map < pair < ll , ll > , int > chk;
void Pre()
{
    int i ;
    for ( i = 1 ; i <= n ; i++ )
    {
        dp[i] = 1e17;
        adj[i].clear();
        g[i].clear();
        vis[i] = 0 ;
        dp2[i] = -1;
    }
    chk.clear();
}
void Dijkstra()
{
    priority_queue  <graph> pq;
    pq.push(graph(2,0));
    dp[2] = 0 ;
    while(!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        vis[cur.x] = 1 ;
       // printf("cur.x :: %d cur.c :: %lld\n",cur.x,cur.c);
        // if(cur.x == 2 ) break;
        int i , sz = g[cur.x].size();
        for ( i = 0 ; i < sz ; i++ )
        {
            int v = g[cur.x][i].first;
            if(vis[v]) continue;
            if(cur.c + g[cur.x][i].second < dp[v] )
            {
                dp[v] = cur.c + g[cur.x][i].second;
                pq.push(graph(v,dp[v]));
            }

        }
    }
}

ll DP(int x)
{
    if( x == 2) { return 1ll ; }
   // vis[x] = 1 ;
    ll &ret = dp2[x];
    if(ret > -1 ) return ret ;
    ret = 0 ;
    int i , sz = adj[x].size();
    for ( i = 0 ; i <sz ; i++ )
    {
        int v = adj[x][i];
        //if(vis[v]) continue;
        if( dp[v] < dp[x])
        ret += DP(v);
    }
    return ret;
}
int main()
{

   while(scanf("%d",&n) && n)
   {
       scanf("%d",&m);
       Pre();
       int i , u , v , c;
       for ( i = 0 ; i < m ; i++ )
       {
           read(u) , read(v) , read(c);
           g[u].pb(mp(v,c));
           adj[u].pb(v);
           adj[v].pb(u);
           g[v].pb(mp(u,c));
       }
       Dijkstra();
    
       printf("%lld\n",DP(1));
   }
   return 0;
}
/*
7 9
1 3 1
3 4 1
1 4 2
4 5 2
4 7 1
7 5 1
5 6 1
6 2 1
2 5 2
*/
