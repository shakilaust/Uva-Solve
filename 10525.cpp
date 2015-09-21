//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.


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
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 100005 ;


vector < Long > adj[ NX ] , cost[ NX ] , t[ NX ];
Long dis[ NX ] , need[ NX ] , vis[ NX ];

int n , m ;

void ini()
{
    rep ( i , n + 2 )
    {
        adj[ i ].clear();
        cost[ i ].clear();
        t[i].clear();
    }
}


pair < Long , Long > dijkstra( int s , int d)
{
    int i , x , u , z ;
    for ( i = 1 ; i  <= n ; i++ )
    {
        dis[ i ] = ( 1e15);
        need[ i ] = ( 1e15 );
        vis[ i ] = 0 ;
    }
    dis[ s ] = need[ s ] = 0 ;
    priority_queue < pair < pll , int > > pq ;
    pq.push( mp( mp( 0 , 0 ) , s ) );
    while( !pq.empty () )
    {
        pair < pll , int > now = pq.top();
        pq.pop();
        Long prvd = now.ff.ss * -1 ;
        Long prvt = now.ff.ff * -1 ;
        int x = now.ss ;
        if( x == d ) return mp( prvd , prvt );
        if( vis[ x ] ) continue ;
        vis[ x ] = 1 ;
        int sz = adj[x].size();
        rep ( i , sz )
        {
            int u = adj[x][i];
            Long c = cost[x][i];
            Long ex = t[x][i];
            if( vis[ u ] || need[ u ] < need[ x ] + ex ) continue;
            if( need[ u ] > need[ x ] + ex )
            {
                dis[ u ] = dis[ x ] + c ;
                need[ u ] = ex + need[ x ];
                pq.push( mp ( mp( -need[u] , -dis[ u ] ) , u ) );
            }
            else if( need[ u ] ==  need[ x] + ex && dis[ u ] > dis[ x ] + c )
            {
                need[ u ] = need[ x ] + ex ;
                dis[ u ] = dis[ x ] + c ;
                pq.push( mp( mp ( -need[ u ] , -dis[ u ] ) , u ) );
            }
        }
    }
    return mp( -1 , -1 );
}


int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , tt = II ;
    for ( cs = 1 ; cs <= tt ; cs++ )
    {
        if( cs > 1 ) puts("");
        n = II , m = II ;
        ini();
        rep ( i , m )
        {
            int x = II , y = II ;
            Long a  = LL , b = LL ;
            adj[x].pb( y );
            cost[x].pb( b );
            t[x].pb( a );
            adj[y].pb( x );
            cost[ y ].pb( b );
            t[ y ].pb ( a );

        }
        int q = II ;
        while( q-- )
        {
            int x = II , y = II ;
            pll ans = dijkstra( x , y );
            if( ans.ff == -1 && ans.ss == -1 ) printf("No Path.\n");
            else
            {
                printf("Distance and time to reach destination is %lld & %lld.\n",ans.ff , ans.ss );
            }
        }

    }
    return 0;
}

/*
2
3 2
1 2 2 5
2 3 3 6
2
1 3
1 3
4 2
1 2 5 2
2 3 6 3
1
1 4

*/
