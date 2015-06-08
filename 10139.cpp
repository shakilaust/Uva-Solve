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
const int NX = 1000005 ;
int check[NX] , prime[NX] , idx ;
void seive()
{
    prime[idx++] = 2 ;
    int i , j ;
    for ( i = 3 ; i * i < NX ; i+= 2)
    {
        if( check[i] == 0 )
        {
            prime[idx++] = i ;
            for ( j = i * i ; j < NX ; j += ( 2 * i ) )
            {
                check[j] = 1 ;
            }

        }
    }
    while( i < NX )
    {
        if( check[i] == 0 ) prime[idx++] = i ;
        i +=2 ;
    }
}
int power_to( int n , int p )
{
    int tot = 0 ;
    while( n )
    {
        tot += ( n/p );
        n /= p ;
    }
    return tot ;
}
bool ok( int n , int m )
{
    int i ;
    for ( i = 0 ; i < idx && prime[i] * prime[i] <= m ; i++ )
    {
        if( m % prime[i] == 0 )
        {
            int cnt = 0 ;
            while( m % prime[i] == 0 )
            {
                m /= prime[i];
                cnt++;
            }
            if( cnt > power_to(n , prime[i] ) ) return 0 ;
        }
    }
    if( m > 1 && m > n ) return 0 ;
    else return 1 ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   //ini();
    seive();
    int n , m ;
    while( scanf("%d %d" , &n , &m ) == 2 )
    {
        if( ok( n , m ) )
        {
            printf("%d divides %d!\n",m,n);
        }
        else  printf("%d does not divide %d!\n",m,n);
    }

    return 0;
}
