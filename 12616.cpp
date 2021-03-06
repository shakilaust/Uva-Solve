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

vector < int > adj[ NX ] ;


int n , m ;

int discover[ NX ] , low[ NX ] , vis[ NX ] , cnt ;

Long ans ;


Long articulationpoint( int x , int par , Long tot )
{
    discover[ x ] = low[ x ] = ++cnt ;
    int  rootcheckchild = 0 ;
    int sz = adj[x].size();
    Long total = 0 ; // including itself
    Long canbeadd = 0 , child = 0 ;
    Long realchildcount = 0 ;
    bool arti = 0 ;
    for( int i = 0 ; i < sz ; i++ )
    {
        int u = adj[x][i];
        if( u == par ) continue ;
        if( discover[u] == -1 )
        {
            total = articulationpoint( u , x , tot );
            if( par == -1 ) rootcheckchild++;
            if( rootcheckchild > 1 ) arti = 1 ;
            if( par != -1 && low[u] >= discover[x] ) arti = 1 ;
            realchildcount += total ;
            if( low[u] >= discover[x] )
            {
                 canbeadd += ( child * total );
                 child += total ;
            }
            low[x] = min( low[u] , low[x] );
        }
        else low[ x ] = min( low[x] , discover[ u ] );
    }
    if( arti )
    {
    canbeadd += ( child * ( tot - child - 1 ) ); // excluding it self ;
    ans += ( canbeadd * 2 );
    }
    return realchildcount + 1 ; // including itself
}

Long dfs( int x )
{
    int sz = adj[x].size();
    vis[x] = 1 ;
    Long ret = 1 ;
    for( int i = 0 ; i < sz ; i++ )
    {
        int u = adj[x][i];
        if( vis[u] ) continue ;
        ret += dfs( u );
    }
    return ret ;
}

void ini()
{
    for( int i = 0 ; i <=  n + 2 ; i++ )
    {
        adj[i].clear();
        discover[i] = -1 ;
        vis[i] = 0 ;
    }
    cnt = 0 ;
}

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

     int cs , t = II ;
     for( cs = 1 ; cs <= t ; cs++ )
     {
         n = II , m = II  ;
         ini();
         for( int i = 0 ; i < m ; i++ )
         {
             int x = II , y = II ;
             adj[x].pb( y );
             adj[y].pb( x );
         }

         ans = 0 ;
         for( int i = 1 ; i <= n ; i++ )
         {
             if( vis[i] == 0 )
             {
                 Long total = dfs( i );
                 articulationpoint( i , -1 , total );
             }
         }


         printf("Case %d: %lld\n",cs,ans);
     }




    return 0;
}
