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
int EQ(double d)
{
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

struct point {
    double x,y;
    point(){
        x = y = 0;
    }
    point(double x, double y) : x(x), y(y) {}
    void input(){
        scanf("%lf %lf",&x,&y);
    }
    point (const point &p) {
        x = p.x, y = p.y;
    }
    void translate(double tx, double ty) {
        x += tx;
        y += ty;
    }
    point translate(point t) {
        x += t.x;
        y += t.y;
    }
    point operator+(point k){
        return point(x + k.x , y + k.y );
    }
    point operator-(point k){
        return point(x - k.x , y - k.y );
    }
    point operator*(double k) {
        return point(k * x , k * y );
    }
    point operator/(double k) {
        return point(x / k , y/k );
    }
    point rotleft(){
        return point(-y,x);
    }
    point rotright(){
        return point(y,-x);
    }
    point rotate(point p,double angle) {
        point v(x - p.x , y-p.y );
        double c = cos(angle) , s = sin(angle);
        return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
    }
    #define sqr(x) ((x)*(x))
    double sqrdis(const point &b)const {
        return sqr(x - b.x) + sqr(y - b.y);
    }
    double dis(const point &b)const {
        return sqrt(sqrdis(b));
    }
    bool operator ==(const point &p)const {
        return ((x==p.x) && (y==p.y));
    }
    bool collinear(const point &p1, const point &p2)const  {
        return (p1.y - y) * (p2.x - x) == (p2.y - y) * (p1.x - x);
    }
    double cross(const point &i)const
    {
        return x*i.y-y*i.x;
    }
    double dot(const point &i)const
    {
        return x*i.x+y*i.y;
    }

    point trunc(double r)
    {
        double l = hypot(x,y);
        if ( !EQ(l) )return *this;
        r /= l ;
        return point(x*r,y*r);
    }
    bool in_box(const point &a, const point &b) const { // rectangle : a = leftDown , b = rightTop
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return x >= lox && x <= hix && y >= loy && y <= hiy; // remove = (eq) if strictly in box need
    }

    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    } // sorting angle by x axis
    /*
    bool operator <(const point &p) const {
                 return y < p.y || (y == p.y && x < p.x);
    } // sorting angle by y axis
    */
    friend ostream& operator<<(ostream& out, const point& p) {
        return out << '(' << p.x << ',' << p.y << ')' << endl;
    }
};

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
// **use LinesParallel and LinesColliner to detect wether they intersect
point ComputeLineIntersection(point a, point b, point c, point d)
{
    b = b - a ;
    d = c - d ;
    c = c - a ;
    assert( b.dot(b) > EPS && d.dot(d) > EPS);
    return a + b* c.cross(d) / b.cross(d) ;
}

// compute center of circle given three points
point ComputeCircleCenter(point a, point b, point c) {
  b=(a+b)/2;
  c=(a+c)/2;
  return ComputeLineIntersection(b, b+(a-b).rotright(), c, c+(a-c).rotright());
}
char chk(double A)
{
    if( A + EPS  < 0.0 ) return '+' ;
    else return '-';
}
char chk1(double A)
{
    if( A + EPS  < 0.0 ) return '-' ;
    else return '+';
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   point A , B , C ;
    while(scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y)==6)
   {
       point cen =  ComputeCircleCenter(A,B,C);
       //cen.x = 1.0;
       //cen.y = 2.0 ;
       double radius = sqrt( (cen.x - A.x)*(cen.x-A.x) + (cen.y-A.y)*(cen.y-A.y));
       double g = -(2.0*cen.x);
       double f = -(2.0*cen.y);
       //printf("here\n");
       double c = ( cen.x*cen.x + cen.y*cen.y - radius*radius);
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",chk(cen.x),fabs(cen.x),chk(cen.y),fabs(cen.y),radius);
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n",(g<0.0)?'-':'+',fabs(g),(f<0.0)?'-':'+',fabs(f),(c<0.0)?'-':'+',fabs(c));
        puts("");
   }


    return 0;
}
