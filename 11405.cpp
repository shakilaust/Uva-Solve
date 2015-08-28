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
const int INF = 1 << 28 ;
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
int vis[ 8 ][ 8 ][ 64 ][ ( 1 << 8 ) + 1 ] , cs ;
bool dp[ 8 ][ 8 ][ 64 ][ ( 1 << 8 ) + 1 ] ;
int dis[ 8 ][ 8 ];
char grid[ 8 ][ 8 ];
pii pawn[ 10 ] , me ;

int tot ;

bool ok( int x , int y )
{
    if( x < 0 || x >= 8 || y < 0 || y >= 8 ) return 0 ;
    if( grid[x][y] == 'K' || grid[x][y] == 'p' ) return 0 ;
    return 1 ;
}
int bfs( int sx , int sy , int ddx , int ddy )
{
    queue < pii > q ;
    queue < int > cost ;
    q.push( mp( sx , sy ) );
    cost.push( 0 );
    int i , j ;
    rep( i , 8 ) rep( j , 8 ) dis[i][j] = INF ;
    dis[sx][sy] = 0 ;
    while( !q.empty() )
    {
        int x = q.front().ff ;
        int y = q.front().ss ;
        int c = cost.front();
        cost.pop();
        q.pop();
        rep( i , 8 )
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( ok( nx , ny ) == 0 ) continue ;

            if( nx == ddx && ddy == ny )
            {

                return c + 1 ;
            }
            if( grid[nx][ny] == 'P') continue ;
            if( c + 1 < dis[nx][ny] )
            {
                dis[nx][ny] = c + 1 ;
                q.push( mp( nx , ny ) );
                cost.push( c + 1 );
            }
        }
    }
    return -1 ;
}

bool DP( int sx , int sy , int lft , int mask )
{
    if( mask == ( 1 << tot ) - 1 ) return 1 ;
    int &v = vis[sx][sy][lft][mask];
    bool &ret = dp[sx][sy][lft][mask];
    if( v == cs ) return ret ;
    v = cs ;
    ret = 0 ;
    rep( i , tot )
    {
        if( mask & ( 1 << i ) ) continue ;
        pii go = pawn[i];
        int d = bfs( sx , sy , go.ff , go.ss );
        if( d !=-1 && d <= lft )
        {
            grid[go.ff][go.ss] = '.';
            bool tmp = DP( go.ff , go.ss , lft - d , mask | ( 1 << i ) );
            if( tmp == 1 ) return ret = 1 ;
            grid[ go.ff ][go.ss] = 'P';
        }
    }
    return ret ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
      cout << 8 * 8 * 64 * ( 1 << 8 ) << endl ;
      int t = II ;
      for ( cs = 1 ;  cs <= t ; cs++ )
      {
          int n = II ;
          rep( i , 8 ) scanf("%s",grid[i]);
          rep( i , 8 ) rep( j , 8 )
          if( grid[i][j] == 'k' )
          {
              me = mp( i , j );
              break ;
          }
          tot = 0 ;
          rep( i , 8 ) rep( j , 8 )
          {
              if( grid[i][j] == 'P')
              {
                  pawn[tot].ff = i ;
                  pawn[tot++].ss = j ;
              }
          }
          if( DP( me.ff , me.ss , n , 0 ) ) printf("Yes\n");
          else printf("No\n");
      }
    return 0;
}
/*
2
3
...pP...
..P..k.K
p.....p.
...p....
...p....
........
.p......
........
2
.....kp.
........
...Kp...
.P...p..
.p.....p
...p....
........
.p......

*/
