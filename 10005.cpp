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

struct point
{
    double x , y ;
    point() {}
    point( double _x , double _y )
    {
        x = _x ;
        y = _y ;
    }
};

struct circle
{
    point center ;
    double redius ;
    circle() {}
    circle( point _c , double r )
    {
        redius = r ;
        center = _c ;
    }
};
inline double distancepp( point a, point b ) {
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
inline double sq_distance( point a, point b ) {
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}
point p[105] ;
double r ;
int n ;
bool ok( circle c1 )
{
    int i ;
    for ( i = 0 ; i < n ; i++ ) if( distancepp( c1.center , p[i] ) > c1.redius ) return 0 ;
    return 1 ;
}
bool ispossible( point p1 , point p2)
{
    circle c1 = circle( p1 , r );
    circle c2 = circle( p2 , r );
    double x1 = p1.x , x2 = p2.x , y1 = p1.y , y2 = p2.y ;
    double q = distancepp( p1 , p2 );
    double x3 = 0.5 * ( x1 + x2 );
    double y3 = 0.5 * ( y1 + y2 );
    double x_part = sqrt( r * r - 0.25 * q * q ) * ( y1 - y2 ) / q ;
    double y_part = sqrt( r * r - 0.25 * q * q ) * ( x1 - x2 ) / q ;

    point p = point( x3 + x_part , y3 + y_part );
    circle c = circle( p , r );
    if( ok( c ) ) return 1 ;
    p = point( x3 - x_part , y3 - y_part );
    c = circle( p , r );
    if( ok( c ) ) return 1 ;
    return 0 ;

}


bool check()
{
    int i , j ;
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = i + 1 ; j < n ; j++ )
        {
            if( sq_distance( p[i] , p[j] )> 4 * r * r ) return 0 ;
            if( ispossible( p[i] , p[j] ) ) return 1 ;
        }
    }
    return 0 ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    while( n = II )
    {
        if( !n ) break ;
        rep( i , n )
        {
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        scanf("%lf",&r);
        if( check() ) puts("The polygon can be packed in the circle.");
        else puts("There is no way of packing that polygon.");
    }


    return 0;
}
/*
3
0 0
1 0
0 1
1.0
3
0 0
1 0
0 1
0.1
0
*/
