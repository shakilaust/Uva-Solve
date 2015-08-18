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


struct Point
{
    double x , y ;
    Point() {}
    Point( double dx ,  double dy ) { x = dx ; y = dy ; };
    bool operator < ( const Point &p) const
    {
        return ( x < p.x || ( p.x == x && y < p.y ) );
    }
};

vector < Point > P ;
// return positive is its counter clockwise turn
// return negative for clock wise turn
// return 0 for co-liner
double cross( const Point &O , const Point &A , const Point &B )
{
    return (A.x - O.x )*( B.y - O.y ) - ( A.y - O.y ) * ( B.x - O.x );
}

vector < Point > ConvexHull ( )
{
    vector < Point > H( 2 * P.size() );
    int sz = P.size() ;
    sort( P.begin() , P.end() );
    int i , k = 0 , l ;
    for ( i = 0 , k = 0 ; i < sz ; i++ )
    {
        while( k >= 2 && cross( H[k-2] , H[k-1] , P[i] ) <= 0 ) k-- ;
        H[k++] = P[i];
    }
    for ( i = sz - 2 , l = k + 1 ; i >= 0 ; i--  )
    {
        while( k >= l && cross( H[k-2] , H[k-1] , P[i] ) <= 0 ) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    H.pop_back();
   // cout << " k " << k << endl ;
    return H ;
}
double Area( vector < Point > H )
{
    double ans = 0 ;
    int sz = H.size();
    rep( i , sz ) ans += cross( H[i] , H[( i + 1 )%sz ] , H[0] );
    ans = fabs( ans ) * 0.5 ;
  //  cout << setprecision( 10 ) << " AAA "  << ans << endl ;
    return ans ;

}
Point central( vector < Point > H )
{
    double area = Area( H ) ;
    double fac = 1.0 / ( 6.0 * area );
    double cx = 0 , cy = 0 ;
    int sz = H.size();
    rep( i , sz )
    {
            Point cur = H[i], next = H[(i + 1) % sz];
        cx += (cur.x + next.x) * (cur.x * next.y - cur.y * next.x);
        cy += (cur.y + next.y) * (cur.x * next.y - cur.y * next.x);
    }
    cx *= fac ;
    cy *= fac ;
    return Point( cx , cy ) ;

}
bool input()
{
    int n = II ;
    if( n < 3 ) return 0 ;
    P.clear();
    rep( i , n )
    {
        double x , y ;
        scanf("%lf %lf",&x,&y);
        P.pb( Point( x , y ) );
    }
    return 1 ;
}
int main()
{



     while( input() )
     {
         vector < Point > H = ConvexHull() ;
         Point ans = central(H) ;
         printf("%.3lf %.3lf\n",ans.x , ans.y );
     }



    return 0 ;
}
