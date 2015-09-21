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

vector < int > adj[ NX ] ;

int discover[ NX ] , low[ NX ] , Inqueue[ NX ] , vis[ NX ] , Color[ NX ];
int EntryTime , col , n , m , scc ;

int parnt[ NX ] , cnt[ NX ] ;

bool isreuse( int v , int u )
{
    while( parnt[u] != v )
    {
        cnt[u]++;
        if( cnt[u] > 1 ) return 1 ;
        u = parnt[u];
    }
    return  false ;
}

bool dfs( int x )
{
    low[ x ] = discover[ x ] = ++EntryTime;
    int sz = adj[x].size();
    rep ( i , sz )
    {
        int u = adj[x][i];
        if( discover[ u ] == -1 )
        {
            parnt[ u ] = x ;
            if( dfs( u ) == false ) return false ;
            low[ x ] = min( low[ x ] , low[ u ] );
        }
        else
        {
            low[ x ] = min( low[ x ] , discover[ u ] );
            if( isreuse( u , x ) ) return false ;
        }
    }
    if( low[x] == discover[x] )
    {
        scc++;
        if( scc == 2 ) return false ;
    }
    return true ;
}

bool check()
{
    ms( discover , -1 );
    ms( cnt , 0 );
    EntryTime = scc = 0 ;
    rep ( i , n )
    {
        if( discover[ i ] == -1 && dfs( i ) == false ) return false ;
    }
    return true ;

}
void ini()
{
    rep ( i , n )
    {
        adj[i].clear();
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        n = II , m = II ;
        ini();
        rep ( i , m )
        {
            int x = II , y = II ;
            adj[x].pb( y );

        }
        if( check() ) puts("YES");
        else puts("NO");
    }
    return 0;
}
