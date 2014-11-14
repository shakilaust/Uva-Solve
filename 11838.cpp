//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
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
const int MX = 2005 ;
vector < int > adj[MX] , Rev[MX] , topo ;
int vis[MX] , n , e ;
void ini()
{
    int x;
    for ( x = 0 ; x <= n + 1 ; x++ )
    {
        adj[x].clear();
        Rev[x].clear();
        vis[x] = 0 ;
    }
    topo.clear();
}
void dfs(int x )
{
    int sz = adj[x].size();
    vis[x] = 1 ;
    rep(o,sz)
    {
        int u = adj[x][o];
        if( vis[u] == 1 ) continue ;
        dfs(u);
    }
    topo.pb(x);
}
void toposort(int x)
{
  //  printf("x :: %d\n",x);
    int sz = Rev[x].size();
    vis[x] = 2 ;
    rep(i,sz)
    {
        int u = Rev[x][i];
        if( vis[u] == 2 ) continue ;
        toposort(u);
    }
}
void input()
{
    int x , y , p ;
    rep(i,e)
    {
        x = II , y = II , p = II ;
        if( p == 1 )
        {
            adj[x].pb(y);
            Rev[y].pb(x);
        }
        else
        {
            adj[x].pb(y);
            Rev[y].pb(x);
            adj[y].pb(x);
            Rev[x].pb(y);
        }
    }
    topo.clear();
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    while(scanf("%d %d",&n,&e)==2)
    {
        if(!n && !e ) break ;
        ini();
        input();
        For(i,n) if( vis[i] != 1 ) dfs(i);
        int ok = 1 ;
        toposort(topo[n-1]);
        For(i,n-1) if( vis[topo[n-i-1]] != 2 ) { ok = 0 ; break ;}
        printf("%d\n",ok);
    }
    return 0;

}
/*
3
1 1
2 2 5 3
0 0 2 4
0 1
4 0 6 4
3 1
1 2 2 4
1 0 2 4
1 2 5 4
0 1 4 4
3 5
4 0 5 5
0 2 2 4
1 0 2 3
0 2 1 4
2 3 5 4
2 1 4 3
0 0 5 4
0 1 1 3
0 0
5 1
0 2 4 3
2 1 3 3
1 4 5 5
0 3 3 5
0 0 4 5
1 1 4 5
*/
