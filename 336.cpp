
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
int m ;
vector <int> adj[35];
int cost[35][35] ;
bool calculated[35];
void Clean()
{
    int i , j ;
    for ( i = 1 ; i < 35 ; i++ ) {

        calculated[i]  = 0 ;
        adj[i].clear();
        for ( j = 1  ; j < 35 ; j++)

        {
            cost[i][j] = -1 ;
        }
        cost[i][i] = 0 ;


    }
}
void bfs(int s)
{
    queue < int > q ;
    q.push(s);
    cost[s][s] = 0 ;
    while(!q.empty())
    {   int v = q.front();
        q.pop();
        int i , sz = adj[v].size();
        for( i = 0 ; i < sz ; i++ )
        {
            int w = adj[v][i] ;
            if( cost[s][w]==-1) // not calculated
            {
                cost[s][w] = cost[s][v] + 1 ;
                q.push(w);
            }
        }
    }
}
int main()
{   int cs = 1 ;
    while( read(m) && m )
    {
        Clean();
        int x , y , i ;
        map < int , int > Idx;
        int id = 1 ;
        rep(i,m)
        {
            read(x);
            read(y);
            if(Idx[x]==0) Idx[x] = id++;
            if(Idx[y]==0) Idx[y] = id++;
            adj[Idx[x]].pb(Idx[y]);
            adj[Idx[y]].pb(Idx[x]);

        }
        while( 1)
        {     read(x);
              read(y);
             if( x == 0 && y == 0 ) break;
            int s = Idx[x]  , ans = 0;
            if(calculated[s]) // already done
            {
                  for( i = 1 ; i < id ; i++ )
                  {
                     // if( i == s ) continue ;
                      if ( cost[s][i] > y || cost[s][i]==-1 ) ans++;
                  }
            }
            else
            {
                bfs(s);
                calculated[s] = 1 ;
                 for( i = 1 ; i < id ; i++ )
                  {

                      if ( cost[s][i] > y || cost[s][i]==-1) ans++;
                  }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs++,ans,x,y);

        }
    }
   return 0;
}
