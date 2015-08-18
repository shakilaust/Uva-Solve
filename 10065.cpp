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
    int x , y ;
    Point( int dx = 0 ,  int dy = 0 ) { x = dx ; y = dy ; };
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
int n ;

vector < Point > ConvexHull ( vector < Point > P )
{
    //vector < Point > H( 2 * sz );
    int sz = P.size() ;
    vector < Point > H( 2 * sz );
    sort( P.begin() , P.end() );
    int i , k = 0 , l ;
   /* for ( i = 0 , k = 0 ; i < sz ; i++ )
    {
        while( k >= 2 && cross( H[k-2] , H[k-1] , P[i] ) <= 0 ) k-- ;
        H[k++] = P[i];
    }
    for ( i = sz - 2 , l = k + 1 ; i >= 0 ; i--  )
    {
        while( k >= l && cross( H[k-2] , H[k-1] , P[i] ) <= 0 ) k--;
        H[k++] = P[i];
    } */
        for (int i = 0; i < n; i++) {
                while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }

        // Build upper hull
        for (int i = n-2, t = k+1; i >= 0; i--) {
                while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }

    H.resize(k);
   // H.pop_back();
   // cout << " k " << k << endl ;
    return H ;
}
vector<Point> convexHull(vector<Point> P)
{
        int n = P.size(), k = 0;
        vector<Point> H(2*n);

        // Sort points lexicographically by angles
        sort(P.begin(), P.end());

        // Build lower hull
        for (int i = 0; i < n; i++) {
                while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }

        // Build upper hull
        for (int i = n-2, t = k+1; i >= 0; i--) {
                while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }

        H.resize(k);
        return H;
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

void input( int n)
{

    P.clear();
    rep( i , n )
    {
        int x = II , y = II ;
        P.pb( Point( x , y ) );
    }
}
int main()
{



     int cs  = 1 ;
     while( scanf("%d",&n) && n )
     {
         input(n);
         vector < Point > H = ConvexHull( P ) ;
         H.pop_back() ;
         double convex_area = Area( H );
         double area = Area( P );
        printf("Tile #%d\n",cs++);
        printf("Wasted Space = %.2f %%\n\n",(1- (area/convex_area))*100);
     }



    return 0 ;
}
/*
5
0 0
2 0
2 2
1 1
0 2
5
0 0
0 2
1 3
2 2
2 0
0

*/
