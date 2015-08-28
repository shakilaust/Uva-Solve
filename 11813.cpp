//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

// Macro
#define eps 1e-9
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a)*(a))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define eps (1e-9)
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 100000 + 10 ;
const Long INF = 1e17 ;
vector < int > adj[NX] , cost[NX] ;
int n , m , shop[ NX ] , lim , ID[ NX ] ;
Long dis[ NX ] , d[ 12 ][ 12 ] ;
bool vis[ NX ];
int v[ 12 ][ ( 1 << 12 ) + 1 ] , cs ;
Long dp[ 12 ][ ( 1 << 12 ) + 1 ];
void dijkstra( int s )
{
    rep( i , n )
    {
        dis[i] = INF ;
        vis[i] = 0 ;
    }
    priority_queue < pair < Long , int > > pq ;
    pq.push( mp( 0 , s ) );
    dis[s] = 0 ;
    while( !pq.empty() )
    {
        pair < Long , int > now = pq.top();
        pq.pop();
        Long c = ( now.ff * -1 );
        int x = now.ss ;
        if( vis[x] ) continue ;
        vis[x] = 1 ;
        int sz = adj[x].size();
        rep( i , sz )
        {
            int u = adj[x][i];
            Long nn = c + cost[x][i];
            if( vis[u] || dis[u] <= nn ) continue ;
            dis[u] = nn ;
            pq.push( mp( -nn , u ) );
        }

    }
    rep( i , lim )
    {
        d[ID[s]][i] = d[i][ID[s]] = dis[shop[i]];
    }

}

Long DP( int pos , int mask )
{
    if( mask == ( 1 << lim ) - 1 ) return d[ pos ][ 0 ] ;
    Long &ret = dp[ pos ][ mask ];
    if( v[ pos ][ mask ] == cs ) return ret ;
    v[ pos ][ mask ] = cs ;
    ret = INF ;
    rep( i , lim )
    {
        if( mask & ( 1 << i ) ) continue ;
        ret = min( ret , DP( i , mask | ( 1 << i ) ) + d[ pos ][ i ] ) ;

    }
    return ret ;
}

void ini()
{
    rep( i , n )
    {
        adj[i].clear();
        cost[i].clear();
    }
}
int main()
{
   // I will always use scanf and printf
   // xint t = II ;
     int t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         n = II , m = II ;
         rep( i , m )
         {
             int x = II , y = II , c = II ;
             adj[x].pb( y );
             adj[y].pb( x );
             cost[x].pb( c );
             cost[y].pb( c );
         }
         lim = II ;
         shop[0] = 0 ;
         ID[0] = 0 ;
         rep( i , lim )
         {
             int x = II ;
             shop[ i + 1 ] = x ;
             ID [ x  ] =   i + 1 ;
         }
         lim++;
         rep( i , lim ) dijkstra( shop[i] );
         Long ans = DP( 0 , 1 ) ;
         printf("%lld\n",ans);
     }
    return 0;
}
