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


const int NX = 255 ;
const int INF =  1 << 29 ;
const int MX = 60 ;

int t[ MX ] , dp[ NX ][ MX ] , have_train[ NX ][ MX ][ 2 ] ; // 0 for left , 1 for right

int T , n , m1 , m2 ;





int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs = 1 ;
    while( n = II )
    {
        ms( t , 0 );
       // ms( have_train , 0 );
        T = II ;
        int i ;
        for ( i = 1 ; i < n ; i++ )
        {
            t[i] = II ;
        }
        m1 = II ;
        rep ( j , m1 )
        {
            int x = II ; // starting from station 1
            for ( i = 1 ; i < n ; i++ )
            {
                x += t[i-1];
                if( x <= T )
                have_train[ x ][ i ][ 0 ] = cs ;
            }
        }
        m2 = II ;
        rep ( j , m2 )
        {
            int x = II ;
            for ( i = n ; i > 0 ; i-- )
            {
                x += t[i];
                if( x <= T )
                {
                   have_train[x][i][1] = cs ;
                }
            }
        }
        for ( i = 1 ; i < n ; i++ ) dp[T][i] = INF ;
        dp[T][n] = 0 ;
        int j ;
      for ( i = T - 1 ; i >= 0 ; i-- )
        {
            for ( j = 1 ; j <= n ; j++ )
            {
                dp[i][j] = dp[i+1][j] + 1; // wait a minute
                if( j < n && have_train[i][j][0] == cs && i + t[j] <= T ) // ager station e jacche
                {
                    dp[i][j] = min( dp[i][j] , dp[i + t[j]][j + 1] );
                }
                if( j > 1 && have_train[i][j][1] == cs && i + t[j - 1] <= T )
                {
                    dp[i][j] = min( dp[i][j] , dp[ i + t[j - 1]][j-1] );
                }
            }
        }

        printf("Case Number %d:",cs++);
        if (dp[0][1]>=INF)
            printf(" impossible\n");
        else
            printf(" %d\n",dp[0][1]);
    }


}

/*
4
55
5 10 15
4
0 5 10 20
4
0 5 10 15
4
18
1 2 3
5
0 3 6 10 12
6
0 3 5 7 12 15
2
30
20
1
20
7
1 3 5 7 11 13 17

*/
