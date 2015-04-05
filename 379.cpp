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
#include <tr1/unordered_map>
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

template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}

//Fast Reader
template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
const double eps = 1e-8 ;
struct point
{
    double x , y ;
};
// c lies between AB segment or not
double adjst( double x )
{
    return x > 0 ? x : -x ;
}
void solve( point A , point B , point C , point D)
{
    double t1 = ( B.x - A.x )*(C.y - D.y ) - ( B.y - A.y )*(C.x - D.x);
    double t2 = ( C.x - A.x)*(C.y - D.y ) - ( C.y - A.y )*(C.x - D.x);
    if( adjst(t1) < eps )
    {
        if(adjst(t2) < eps ) puts("LINE");
        else puts("NONE");
    }
    else printf("POINT %.2lf %.2lf\n",A.x + ( B.x - A.x)*(t2/t1) , A.y + (B.y - A.y)*(t2/t1));

}
void ins(point p1,point p2,point p3,point p4)
{
    double t1 = (p2.x-p1.x)*(p3.y-p4.y) - (p2.y-p1.y)*(p3.x-p4.x);
    double t2 = (p3.x-p1.x)*(p3.y-p4.y) - (p3.y-p1.y)*(p3.x-p4.x);
    if(adjst(t1) < eps)
    {
        if(adjst(t2) < eps) printf("LINE\n");
        else printf("NONE\n");
    }
    else printf("POINT %.2lf %.2lf\n",p1.x + (p2.x-p1.x)*(t2/t1),p1.y + (p2.y-p1.y)*(t2/t1));
}
int main()
{
    // I will always use scanf and printf
    // May be i won't be a good programmer but i will be a good human being

   int cs , t = II ;
   puts("INTERSECTING LINES OUTPUT");
   for( cs = 1 ; cs <= t ; cs++ )
   {
       point A , B , C , D ;
       scanf("%lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y);
       scanf("%lf %lf %lf %lf",&C.x,&C.y,&D.x,&D.y);
       ins(A,B,C,D);
   }
   puts("END OF OUTPUT");
    return 0;
}

