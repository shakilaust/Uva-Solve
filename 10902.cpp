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
const int NX = 1005 ;
struct Point
{
    double x , y ;
};
struct Line
{
    Point s , t ;
};

Line top[NX] ;
int ans[NX] ;
bool In( double a , double b , double c )
{
    return a <= c && c <= b ;
}
bool Online( Line &a , Point x )
{
    static double minx , maxx , miny , maxy ;
    minx = min( a.s.x , a.t.x );
    maxx = max( a.s.x , a.t.x );
    miny = min( a.s.y , a.t.y );
    maxy = max( a.s.y , a.t.y );
    if( In( minx , maxx , x.x ) != 0 && In(  miny , maxy , x.y ) != 0 )
    {
         if((a.s.x-a.t.x)*(x.y-a.s.y) == (a.s.y-a.t.y)*(x.x-a.s.x)) {
            return 1;
        }
    }
    return 0 ;
}
double cross(Point &o, Point &a, Point &b) {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

 bool isintersection( Line &a , Line &b ){
    if(Online(a, b.s) || Online(a, b.t) || Online(b, a.s) || Online(b, a.t))
        return 1;
    if(cross(a.s, a.t, b.s)*cross(a.s, a.t, b.t) < 0 &&
       cross(a.t, a.s, b.s)*cross(a.t, a.s, b.t) < 0 &&
       cross(b.s, b.t, a.s)*cross(b.s, b.t, a.t) < 0 &&
       cross(b.t, b.s, a.s)*cross(b.t, b.s, a.t) < 0
       )
        return 1;
    return 0;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int n , i , j , k ;
   while( scanf("%d",&n) && n )
   {
       Line T ;
       int idx = 0 ;
       rep( i , n )
       {
           cin >> T.s.x >> T.s.y >> T.t.x >> T.t.y ;
           for( j = 0 , k = 0 ; j < idx ; j++ )
           {
               if( !isintersection( T , top[j] ) )
               {
                   top[k] = top[j];
                   ans[k++] = ans[j] ;
               }

           }
               idx = k ;
               ans[idx] = i ;
               top[idx++] = T ;

       }
        printf("Top sticks:");
        for(i = 0; i < idx; i++) {
            if(i)   putchar(',');
            printf(" %d", ans[i]+1);
        }
        puts(".");
   }


    return 0;
}
/*
5
1 1 4 2
2 3 3 1
1 -2.0 8 4
1 4 8 2
3 3 6 -2.0
3
0 0 1 1
1 0 2 1
2 0 3 1
0

*/
