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

const int NX = 105 ;
int has[NX][NX] , ways[NX][NX] , dp[NX][NX] ;
int n , m ;
int vis[NX][NX];
pii parnt[NX][NX];
stack < int > ans ;
int Way( int x , int y )
{
    int &cnt = ways[x][y];
    if( cnt != -1 ) return cnt  ;
    if( dp[x][y] == 1 ) return cnt = 1 ;
    cnt = 0 ;
    int i , j ;
    for ( i = x ; i  <= n; i++ )
    {
        for ( j = y ; j  <= m ; j++ )
        {
            if( has[i][j] && dp[x][y] == ( dp[ i ][  j ] + has[x][y] ) )
            {
                cnt += Way(  i ,  j);
            }
        }
    }
    return cnt ;
}
int DP ( int x , int y )
{
    int &cnt = dp[x][y];
    if( cnt != -1 ) return cnt ;
    if( x == n && y == m )
    {
        return cnt = has[x][y];
    }
    cnt = 0 ;
    if( x + 1 <= n ) cnt = max( cnt , DP( x + 1 , y ) + has[x][y] );
    if( y + 1 <= m ) cnt = max( cnt , DP( x , y + 1 ) + has[x][y] );
    return cnt ;
}
void print( int x , int y )
{
    if( dp[x][y] == 1 && has[x][y] )
    {
        printf(" %d\n",( x - 1 ) * m + y );
        return ;
    }
    printf(" %d",( x - 1 ) * m + y );
    int i , j ;
    for ( i = x ; i <= n ; i++ )
    {
        for (  j = y ;  j <=  m ; j++ )
        {
            if( has[i][j] && dp[x][y] == dp[i][j] + has[x][y] )
            {
                print(  i , j );
                return ;
            }
        }
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs = 1 ;
   while( scanf("%d %d",&n , &m ) == 2 )
   {
       if( n == -1 && m == -1 ) break ;
       ms( has , 0 );
       ms( ways , -1 );
       ms( dp , -1 );
       int x , y , i , j ;
       while( scanf("%d %d",&x,&y) == 2 )
       {
           if( x == 0 && y == 0 ) break ;
           has[x][y] = 1 ;
       }



       DP( 1 , 1 );
       Way( 1 , 1 );
       printf("CASE#%d: %d %d",cs++, dp[1][1] , ways[1][1] );
       bool prn = 0 ;
       for ( i = 1 ; i <= n && !prn ; i++ )
       {
           for ( j = 1; j  <= m && !prn ; j++ )
           {
               if( has[i][j] && dp[i][j] == DP( 1 , 1 ) )
               {
                   print( i , j );
                   prn = 1 ;
               }
           }
       }


   }
    return 0;
}
