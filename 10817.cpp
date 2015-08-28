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

const int NX = 104 ;
const int INF = 1 << 29 ;
const int MX = ( 1 << 8 ) + 3 ;
int vis[ NX ][ MX ][ MX ] , cs , dp[ NX ][ MX ][ MX ];
int sv[ NX ] , n , m , lim  , need[ NX ] ;

int DP( int pos , int mask1 , int mask2 )
{

    if( mask1 == lim && mask2 == lim ) return 0 ;

    if( pos == n ) return INF ;
    int &v = vis[pos][mask1][mask2];
    int &ret = dp[pos][mask1][mask2];
    if( v == cs ) return ret ;
    v = cs ;
    ret = INF ;
    int tmp = ( mask1 & sv[pos] );
    ret = min( ret , DP ( pos + 1 , mask1 | sv[pos] , mask2 | tmp  ) + need[pos] );
    ret = min( ret , DP( pos + 1  , mask1 , mask2 ) );

    return ret ;
}
int main()
{
   // I will always use scanf and printf

    while( scanf("%d %d %d",&lim,&m,&n ) == 3 )
    {
        cs++;
        getchar();
        if( lim == 0 && n == 0 && m == 0 ) break ;
        lim = ( 1 << lim ) - 1 ;

        int mask1 = 0 , mask2 = 0 ;
        int ans = 0 ;
        string inp ;
        stringstream ss ;
        rep( i , m )
        {
            ss.clear();
            getline( cin , inp );

            ss << inp ;
            int fst = 1 , val ;
            int mask = 0 ;
            while( ss >> val )
            {

                if( fst )
                {
                    ans += val ;
                    fst = 0 ;
                }
                else
                {

                    mask |= ( 1 << ( val - 1 ) );

                }
            }
            int tmp = ( mask1 & mask );
            mask1 |= ( mask );
            mask2 |= tmp ;

        }

         rep( i , n )
        {
            ss.clear(); // clear is important
            getline( cin , inp );
            ss << inp ;
            int fst = 1 , val ;
            sv[i] = 0 ;
            while( ss >> val )
            {

                if( fst )
                {
                    need[i] = val ;
                    fst = 0 ;
                }
                else
                {
                    sv[i] |= ( 1 << (val - 1 ));
                }
            }

        }

        printf("%d\n",DP( 0 , mask1 , mask2 ) + ans );
    }
    return 0;
}
/*
2 2 2
10000 1
20000 2
30000 1 2
40000 1 2
0 0 0

*/
