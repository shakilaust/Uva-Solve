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

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   double x1 , y1 , x2 , y2 , x3 , y3 ,x4 , y4 ,  cx , cy , ux , uy , vx , vy ;
   while( cin >> x1 >> y1 >> x2 >> y2 )
   {
       /*
The centre of a square is the midpoint of either of its diagonals; so in your case we have

cx = (x1+x2)/2
cy = (y1+y2)/2
The vector from the centre of the square to the endpoint of a diagonal is at right angles to, and the same length as, the vector from the centre to an endpoint of the other diagonal. So we can compute the vector from the centre to x1,y1 say, rotate it through 90 degrees and use that to get both the endpoints of the other diagonal:

vx = x1 - cx; vy = y1 - cy; // vector c->(x1,y1)
ux = vy; uy = -vx;          // rotate through 90 degrees
x3 = cx + ux; y3 = cy + uy; // one of the endpoints of other diagonal
x4 = cx - ux; y4 = cy - uy; // the other endpoint
The vertices of your square are (x1,y1), (x3,y3), (x2,y2), (x4,y4).

*/

       cx = ( x1 + x2 )/2 ;
       cy = ( y1 + y2 )/2 ;
       vx = x1 - cx ;
       vy = y1 - cy ;
       ux = vy ;
       uy = -vx ;
       x3 = cx + ux ;
       y3 = cy + uy ;
       x4 = cx - ux ;
       y4 = cy - uy ;
      // cout << setprecision(10) << x3 << " " << y3 << " " << x4 << " " << y4 << endl ;
      printf("%.10lf %.10lf %.10lf %.10lf\n",x3,y3,x4,y4);


   }


    return 0;
}
