//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.
 Don't let your dreams be dreams.


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
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 1e5 + 10 ;

int cs , vis[ NX ] ;

int notok[ NX ] ;

int n , k ;

vector < int > adj[ NX ];

vector < pair < int , int > > E[ NX ];


struct Edge
{
    int frm , x , y ;
};

Edge inp[ NX ];


bool cmp( Edge A , Edge B )
{

}
void ini()
{
    for( int i = 0 ; i <= n + 2 ; i++ )
    {
       E[i].clear();
       //adj[i].clear();
    }
}

int bfs( int s , int d )
{
    if( s == d ) return 0 ;
    queue < int > q , c ;
    q.push( s );
    c.push( 0 );
    vis[ s ] = cs ;
    int i , idx , lst , sz ;
    while( !q.empty() )
    {
        int u = q.front();
        int p = c.front();
        c.pop();
        q.pop();
        sz = E[u].size();
        idx = 0 ;
        for( i = 0 ; i < n ; i++ )
        {
            while( idx < sz && i > E[u][idx].ss ) idx++;
            if( idx < sz && i >= E[u][idx].ff && i <= E[u][idx].ss )
            {
                i = E[u][idx].ss ;
                idx++;
                continue ;
            }
            if( vis[i] == cs ) continue ;
            vis[ i ] = cs ;
           // printf(" u :: %d i :: %d\n",u , i );
            if( i == d ) return p + 1 ;
            q.push( i );
            c.push( p + 1 );

        }
    }
    return -1 ;

}

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int t = II ;
    for( cs = 1 ; cs <= t ; cs++ )
    {
        n = II , k = II ;
        ini( ) ;
        rep( i , k )
        {
            int u , x , y ;
            scanf("%d %d-%d",&u,&x,&y);
            if( x > y ) swap( x , y );
            E[ u ].pb( mp( x , y ) );

        }
        for( int i = 0 ; i < n ; i++ )
        {
            sort( E[i].begin() , E[i].end() );
        }
        int s = II , d = II ;
        int ans = bfs( s , d );
        if( ans < 0 ) printf("Case #%d: Impossible\n",cs);
        else printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}
/*

1
3
1
0 1-2
0 2

4
3
1
0 2-2
0 2
3
1
0 1-2
0 2
4
4
0 0-3
1 0-3
2 0-3
3 0-3
0 0
100000
3
0 1-99998
99999 1-50000
99999 50002-99999
0 1


*/
