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
const int MX = 301 ;
int check[MX] , prime[MX] , idx , t ;
int dp[79][1005][20] , cs , n , ans[MX]  ;
bool cmp(int a, int b )
{
    stringstream ss1 , ss2 ;
    ss1 << a ;
    ss2 << b ;
    return ss1.str() < ss2.str() ;
}
void ini()
{
    idx = 0 ;
    int i , j ;
    prime[idx++] = 2 ;
    for ( i = 3 ; i < MX ; i+=2 )
    {
        if( check[i] == 0 )
        {
            prime[idx++] = i ;
            for ( j = i * i  ; j < MX ; j += i + i )
                check[j] = 1 ;
        }
    }

    sort( prime, prime + idx , cmp );

}

bool solve( int id , int n , int taken )
{
    if( taken > t ) return 0 ;
    if( taken == t )
    {
        if( n == 0 ) return 1 ;
        else return 0 ;
    }
    if( id == idx ) return 0 ;
    int  &ret = dp[id][n][taken] ;
    if( ret == cs ) return false ;
    ret = cs ;
    if( prime[id] != 2 && (n - ( 2 * prime[id] ) )>= 0 && taken + 2 <= t )
    {
        ans[taken] = prime[id] ;
        ans[taken+1] = prime[id] ;
        if( solve( id + 1 , n - ( 2 * prime[id] ) , taken + 2 ) ) return 1 ;
    }
    if( n - ( prime[id] ) >= 0 && taken + 1 <= t )
    {
        ans[taken] = prime[id];
        if( solve( id + 1 , n - prime[id] , taken+ 1 ) ) return 1 ;
    }
    if( solve( id + 1 , n , taken ) ) return 1 ;
    return 0 ;
}

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   ini();
   cs = 1 ;
   while( scanf("%d %d",&n,&t) && ( n | t ) )
   {
       printf("CASE %d:\n",cs);
       if( solve( 0 ,  n , 0 ) )
       {
           rep ( i , t )
           {
               if( i ) printf("+");
               printf("%d",ans[i]);
           }
           puts("");
       }
       else puts("No Solution.");
       cs++;
   }
    return 0;
}
