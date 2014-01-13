

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
struct Graph
{
    int node , cost ;
    Graph() {}
    Graph ( int n , int c )
    {
        node = n ;
        cost = c ;
    }
    bool operator < ( const Graph &A) const
    {
        return A.cost < cost ;
    }
};

vector < pii > adj[15];

bool visit[15];

int N , dis[15] ,path[15]  ;
void Clean()
{
    int i ;
    FOR(i,1,N) adj[i].clear() , visit[i] = 0  , dis[i] = INF , path[i] = -1 ;
}
void rasta(int node)
{
    if( path[node]==-1)
    {
        printf("%d",node);
        return ;
    }
    rasta(path[node]);
    printf(" %d",node);
}
void Dijkstra(int s , int d )
{
     priority_queue < Graph > pq ;
     pq.push(Graph(s,0));
     dis[s] = 0 ;
     while(!pq.empty())
     {
         Graph prev = pq.top();
         pq.pop();
         if(visit[prev.node]) continue ; // already discover
         visit[prev.node] = 1 ;

         int i ,  u = prev.node , c = prev.cost ;
         if( u == d ) break ; // reach destination
         int sz = adj[u].size();
         rep(i,sz)
         {
             int v = adj[u][i].first ;
             int tmp = adj[u][i].second ;
             if ( dis[v] > dis[u] + tmp )
             {
                 dis[v] = dis[u] + tmp ;
                 path[v] = u ; // parent ;
                 pq.push(Graph(v,dis[v]));
             }
         }
     }
     rasta(d);
     printf("; %d second delay\n",dis[d]);
}
int main()
{   int cs  = 1 ;
    while( read(N) && N)
    {   Clean();
        int i , j , k , x , y ;
        for ( i = 1 ; i <= N ; i++ )
        {
            read(k);
            rep(j,k)
            {
                read(x) ;
                read(y) ;
                adj[i].pb(mp(x,y));
            }
        }
        read(x) , read(y) ;
        printf("Case %d: Path = ",cs++);
      Dijkstra(x,y);

    }
   return 0;
}
