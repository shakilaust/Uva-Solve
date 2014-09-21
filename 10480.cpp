//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::  Loj 1155
 Type   ::
 verdict::  WA
 */
#include <bits/stdc++.h>

#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
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
typedef long long Long;
double const EPS=3e-8;
using namespace std;
const int N=105;
int adj[N][N],deg[N],cap[N][N],visit[N],n,m,B,D,prev[N],q[1000000],END[N],end;
vector <int> shk ;
void CLR()
{
    int i , j;
    for ( i = 0 ; i <= n ; i++ )
    {
        deg[i] = 0 ;
        visit[i] = 0 ;
        for ( j = 0 ; j <= n ; j++ ) cap[i][j] = 0 ;
    }
    shk.clear();
}
int DINIC( int s, int t )
{
    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        int qf = 0, qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prev[v = adj[u][i]] == -1 && cap[u][v] )
                    prev[q[qb++] = v] = u;

        // see if we're done
        if( prev[t] == -1 ) break;

        // try finding more paths
        for( int z = 1 ; z <= n; z++ ) if( cap[z][t] && prev[z] != -1 )
        {
            int bot = cap[z][t];
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
                bot = min( bot , cap[u][v] );
            if( !bot ) continue;

            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
            {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }

    return flow;
}
void DFS(int u)
{
    visit[u] = 1 ;
    //printf(" u ::: %d\n" , u );
    shk.pb(u);
    int i ;
    for ( i = 0 ; i < deg[u] ; i++ )
    {
        int v = adj[u][i];
     //   printf(" v :: %d visit[%d] = %d cap[%d][%d]:: %d\n",v,v,visit[v] , u , v );
        if( visit[v] == 0 && cap[u][v] > 0 ) DFS(v);
    }
}
bool input()
{
    cin >> n >> m ;
    if( n == 0 && m == 0 ) return 0 ;
    CLR();
    int i , u , v , c ;
    for ( i = 0 ; i < m ; i++ )
    {
        cin >> u >> v >> c ;
        adj[u][deg[u]++] = v ;
        adj[v][deg[v]++] = u ;
        cap[u][v] = c ;
        cap[v][u] = c ;
    }
    return 1;
}
void MINCUT()
{

    DINIC(1,2);
    memo(visit,0);
    DFS(1);
    int sz = shk.size() , i , j;
    for ( i = 0 ; i < sz ; i++ )
    {
        int x = shk[i];
        for ( j = 0 ; j < deg[x] ; j++ )
        {
            int y = adj[x][j];
            if( visit[y] ) continue;
            if( visit[x] && !visit[y] )
            printf("%d %d\n",x,y);
        }
    }
    printf("\n");
}
int main()
{  int cs,t,i,u,v,c;
   while( input() )
   {
          MINCUT();
   }
   return 0;
}
/*

*/
