
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
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

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
typedef long long ll ;
const int MX = 505 ;
const ll INF = 1e16 ;
struct NODE
{
    ll v , Cap , Cost , RevInd ;
};
vector < NODE > edge[MX+7];
ll par[MX] , pid[MX];
ll nV , nE , scr , sink ; // here source will ne always 0 and sink will be nV+1
ll dis[MX+7];
void ini()
{
    rep(i,nV+2) edge[i].clear();
}
void setEdge(ll u , ll v , ll cap , ll cost)
{
    NODE U = {v,cap,cost,edge[v].size()};
    NODE V = {u,0,-cost,edge[u].size()};
    edge[u].pb(U);
    edge[v].pb(V);
}
void input()
{
          ini();
          scr = 0 ;
          sink = nV+1 ;
          setEdge(0,1,INF,0);
          setEdge(nV,sink,2,0);
          ll u , v , cos , extra ;
         rep(i,nE)
         {
             read(u) , read(v) , read(cos) , read(extra);
             setEdge(u,v,1,cos);
             setEdge(u,v,1,cos+extra);
         }
}
bool BFORD()
{
    ll i , u , tmp ;
    for ( i = 0 ; i <= sink ; i++ )
    {
        dis[i] = INF ;
        par[i] = -1 ;
    }
    dis[scr] = 0 ;
    bool Ischange = true ;
    while(Ischange)
    {
        Ischange = false ;
        for ( u = scr ; u <= sink ; u++ )
        {
            int sz = edge[u].size();
            for ( i = 0 ; i < sz ; i++ )
            {
                if(!edge[u][i].Cap) continue;
                ll v = edge[u][i].v ;
                tmp = dis[u] + edge[u][i].Cost ;
                if( dis[v] > tmp )
                {
                    dis[v] = tmp ;
                    par[v] = u ;
                    pid[v] = i ; // koto number edge ;
                    Ischange = 1 ;
                }
            }
        }
    }
    return par[sink] != -1 ;
}
ll findflow( ll s , ll t )
{
    ll Cap = edge[par[t]][pid[t]].Cap ;
    if( s == par[t] ) return Cap ;
    return min( Cap , findflow(s,par[t]));
}
ll AgumentPath(ll s , ll t , ll v )
{
    if( s == t ) return 0 ;
    ll Cost = edge[par[t]][pid[t]].Cost*v ;
    edge[par[t]][pid[t]].Cap -= v ;
    edge[t][edge[par[t]][pid[t]].RevInd].Cap += v ;
    return Cost + AgumentPath(s,par[t],v);
}
void MinCost( ll &Flow , ll &Cost)
{
    Flow = 0 , Cost = 0 ;
    while(BFORD())
    {
        ll v = findflow(scr,sink);
        Flow += v ;
        Cost += AgumentPath(scr,sink,v);
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int cs = 1 ;
    while(scanf("%lld %lld",&nV,&nE)==2)
    {

            input();
            ll flow , cost ;
            MinCost(flow,cost);
            printf("Case %d: %lld\n",cs++,cost);
    }
    return 0;
}
