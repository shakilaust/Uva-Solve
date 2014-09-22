
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
const int MX = 5005 ;
int cap[MX][MX] , deg[MX] , adj[MX][MX] , prev[MX] , Idx[MX/10][MX/10];
int row , col , bank  , sink , scr ;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool ok ( int x , int y )
{
    if ( x < 0 || x > row || y < 0 || y > col ) return 0;
    return 1 ;
}
void ini()
{
    memo(cap,0);
    memo(deg,0);
}
bool dinic(int scr , int sink)
{
    int flow = 0 ;
    while( 1 )
    {


        int x , u , v;
        queue < int > q ;
        memo(prev,-1);
        prev[ scr ] = -2 ;
        q.push(scr);
        while( !q.empty() && prev[sink] == -1 )
        {
            int  x = q.front();
            q.pop();
            for (   int z = 0 ; z < deg[x] ; z++ )
            {
                int y = adj[x][z] ;
                if( prev[y] == -1 && cap[x][y] > 0 )
                {
                    prev[y] = x ;
                    q.push(y) ;
                }
            }
        }
        if( prev[sink] == -1 ) break ;
        for ( int z = 0 ; z < deg[sink] ; z++ )
        {
            if ( prev[ u = adj[sink][z] ] != -1  && cap[u][sink] > 0 )
            {

                int add = cap[u][sink];

                for ( v = prev[u] ,x = u ; v >= 0  ;  v = prev[v] )
                {

                    add = min(add , cap[v][x] );
                    x = v ;
                }
                if( add == 0 ) continue ;
                cap[u][sink] -= add;
                cap[sink][u] += add;
                 for ( v = prev[u] ,x = u ; v >= 0  ;  v = prev[v] )
                {

                    cap[v][x] -= add;
                    cap[x][v] += add;
                     x = v ;
                }
                flow += add;
                if( flow >= bank ) return 1;

            }
        }
    }
  //  printf("flow :: %d\n",flow);
    return flow>=bank;
}
void input()
{
    ini();
    int i ,  j , x , y , id = 1 , k;
    read(row) , read(col) , read(bank);
    int add = row*col;
    sink = add + add + 1 ;
    scr  = 0 ;
    for ( i = 1 ; i <= row ; i++ )
    {
        for ( j = 1 ; j <= col ; j++ )
        {
            Idx[i][j] = id ;
            x = id ;
            y = id + add;
            cap[x][y] = 1 ; // id -- > id + N e dummy node add korchi
            adj[x][deg[x]++] = y ;
            adj[y][deg[y]++] = x ;
            // baunady place theke sink e jaowar rasta ase
            if( i == 1 || j == 1 || i == row || j == col )
            {
                adj[y][deg[y]++] = sink ;
                adj[sink][deg[sink]++] = y ;
                cap[y][sink] = 1 ;
            }
            id = id+1 ;

        }
    }

    for ( i = 1 ; i <= bank ; i++ )
    {
        read(x) , read(y) ;
        id = Idx[x][y] ;
        adj[scr][deg[scr]++] = id ;
        adj[id][deg[id]++] = scr ;
        cap[scr][id] = 1 ;
    }
    for ( i =  1 ; i <= row ; i++ )
    {
        for ( j = 1  ; j <= col ; j++ )
        {
            id = Idx[i][j] + add;
            for ( k = 0 ; k < 4 ; k++ )
            {
                 x = i + dx[k];
                 y = j + dy[k];
                 if(!ok(x,y)) continue;
                 int d = Idx[x][y];
                 adj[id][deg[id]++] = d ;
                 adj[d][deg[d]++] = id;
                 cap[id][d] = 1 ;
            }

        }
    }

}
int main()
{
    int cs , t ;
    read(t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
          input();
          if(dinic(scr,sink)) puts("possible");
          else puts("not possible");
    }
    return 0;
}
