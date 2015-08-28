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
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 52 ;
const double INF = 1e18 ;
double dp[ NX ][ ( 1 << 14 ) + 2 ] ;
int vis[ NX ][ ( 1 << 14 ) +  2 ]  , cs , n , m , p  ;
double store[ NX ] ;
double dif[ NX ];
double dis[ NX ][ NX ] ;
int shop[ NX ] , flag[ NX ] , ID[NX] ;

void ini()
{
    int i , j ;
    for ( i = 0 ; i <= n ; i++ )
    {
        for ( j = 0 ; j <= n ; j++ ) dis[i][j] = INF ;
        dis[i][i] = 0 ;
    }
}
void floyd()
{
    int i , j , k ;
    for ( k = 0 ; k <= n ; k++ )
    {
        for ( i = 0 ; i <= n ; i++ )
        {
            for ( j = 0 ; j <= n ; j++ )
            {
                dis[i][j] = min( dis[i][j] , dis[i][k] + dis[k][j] );
            }
        }
    }
}

double DP( int pos , int mask  )
{
    if( mask == ( 1 << p ) - 1 ) return -dis[ID[pos]][0] ;

    int &v = vis[pos][mask];
    if( v == cs ) return dp[pos][mask];
    v = cs ;
    double one , two ;
    one = -dis[ID[pos]][0];
    int i ;
    for ( i = 1 ; i < p ; i++ )
    {
        if( mask & ( 1 << i ) ) continue ;
        two = DP( i , mask | ( 1 << i ) ) + store[ i ] - dis[ ID[pos] ][ ID[i] ];
        one = max( one , two );

    }
    dp[pos][mask] = one ;
    return one ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

      int t = II ;
      for ( cs = 1 ; cs <= t ; cs++ )
      {
          n = II , m = II ;
          ini();
          double d ;
          rep( i , m )
          {
              int x = II , y = II ;

              scanf("%lf",&d);
              dis[x][y] = dis[y][x] = min( dis[x][y] , d );
          }
          floyd();
          p = II ;
          int i , j , k ;
          ms( shop , 0 );
          ms( store , 0 );
          shop[0] = 0 ;
          ID[0] = 0 ;

          for ( i = 1 , j = 1 ; i <= p ; i++ )
          {
              scanf("%d %lf",&k,&d);
              if( shop[k] == 0 )
              {
                  shop[k] = j ;
                  ID[j] = k ;
                  store[j] = d ;
                  j++ ;
              }
              else
              {
                  store[shop[k]] += d ;
              }
          }
          p = j ;
          double ans = DP( 0 , 1 );
          if( iseq( ans , 0.0 ) ) puts("Don't leave the house");
          else printf("Daniel can save $%.2lf\n",ans+eps);

      }
    return 0;
}
