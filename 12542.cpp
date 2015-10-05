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

const int NX = 300 ;
const int MX = 1e5 + 10 ;
char str[ NX ] ;
int idx , T[ NX ] ;
string prime[ MX ] ;
int check[ MX ] , P[ MX ];

string to_string( int x )
{
     string s ;
     stringstream ss ;
     ss << x ;
     ss >> s ;
     return s ;
}
void ini()
{
    prime[ idx++ ] = to_string( 2 );
    P[ idx - 1 ] = 2 ;
    int i , j ;
    for ( i = 3 ; i * i < MX ; i += 2 )
    {
        if( check[ i ] == 0 )
        {
            prime[ idx++ ] = to_string( i );
            P[ idx - 1 ] = i ;
            for ( int j = i * i ; j < MX ; j += ( i + i ) ) check[ j ] = 1 ;
        }
    }
    while( i < MX )
    {
        if( check[ i ] == 0 ) { prime[ idx++ ] = to_string( i ); P[ idx - 1] = i ; }
        i += 2 ;
    }
}
bool ok( int x )
{
    T[1] = 0 ;
    int sz = prime[ x ].size();
    int SZ = strlen( str );
    if( SZ < sz ) return 0 ;
    int i = 0 , j ;
    for ( j = 2 ; j <= sz ; j++ )
    {
        while( i > 0 && prime[ x ][ j - 1 ] != prime[ x ][ i ] ) i = T[i];
        if( prime[ x ][ i ] == prime[ x ][ j ] ) i++ ;
        T[j] = i ;
    }
    int t = 0 ;
    for ( int i = 0 ; i < SZ ; i++ )
    {
        while( t > 0 && str[ i ] != prime[ x ][ t ] ) t = T[ t ];
        if( str[ i ] == prime[ x ][ t ] ) t++ ;
        if( t == sz ) return 1 ;
    }
    return 0 ;

}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

    ini();
    while( scanf("%s", str) == 1 )
    {
        if( strcmp( str , "0" ) == 0 ) break ;
        for ( int i = idx - 1 ; i >= 0 ; i-- )
        {
            if( ok( i ) )
            {
                printf("%d\n",P[i]);
                break ;

            }
        }
    }


    return 0;
}
