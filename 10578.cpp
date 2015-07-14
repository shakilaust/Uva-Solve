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


const int NX = 10 ;
int has[NX] ;
int dp[7][7][7][7][7][7] ;
string giv , play ;
int win( int a , int b , int c , int d , int e , int f , int sum )
{
   if( sum > 31 ) return 0 ;
   if( a > 4 || b > 4 || c > 4 || d > 4 || e > 4 || f > 4 ) return 0 ;
   int &ret = dp[a][b][c][d][e][f];
   if( ret != -1 ) return ret ;
   ret = 0 ;
   if( win( a  + 1 , b , c , d , e , f , sum + 1 ) == 0 && a + 1 <= 4 && sum + 1 <= 31 ) ret = 1 ;
   else if ( win( a  , b  + 1, c , d , e , f , sum + 2 ) == 0 && b + 1 <= 4 && sum + 2 <= 31 ) ret = 1 ;
   else if ( win( a  , b , c + 1, d , e , f , sum + 3 ) == 0 && c + 1 <= 4 && sum + 3 <= 31 ) ret = 1 ;
   else if ( win( a  , b , c , d + 1, e , f , sum + 4 ) == 0 && d + 1 <= 4 && sum + 4 <= 31 ) ret = 1 ;
   else if ( win( a  , b , c , d , e + 1, f , sum + 5 ) == 0 && e + 1 <= 4 && sum + 5 <= 31 ) ret = 1 ;
   else if ( win( a  , b , c , d , e , f + 1, sum + 6 ) == 0 && f + 1 <= 4 && sum + 6 <= 31 ) ret = 1 ;
   return ret ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   ms( dp , -1 );

   while( cin >> giv )
   {
       For( i , 6 ) has[i] = 0;
       int sz = giv.size();
       int sum = 0;
       rep( i , sz )
       {
           sum += (giv[i] - '0');
           has[giv[i]-'0']++;
       }
       cout << giv << " " ;
       int x = win( has[1] , has[2] , has[3] , has[4] , has[5] , has[6] , sum );
       if( x )
       {
           if( sz % 2 == 0 ) printf("A\n");
           else printf("B\n");
       }
       else
       {
           if(sz % 2 == 0 ) printf("B\n");
           else printf("A\n");
       }
   }

    return 0;
}
/*
50
30
24
5
28
45
98
52
60
-1
*/
