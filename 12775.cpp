//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


//template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
//template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
typedef long long ll ;
ll A , B , C , P ;
const int maxn = 100000000 ;

ll gcd (ll a, ll b, ll &x, ll &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}
void shift_solution (ll & x, ll & y, ll a, ll b, ll cnt) {
	x += cnt * b;
	y -= cnt * a;
}

ll find_all_solutions ( ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
	ll x, y, g;
	if (!find_any_solution (a, b, c, x, y, g))
		return 0;
	a /= g;  b /= g;

	ll sign_a = a>0 ? +1 : -1;
	ll sign_b = b>0 ? +1 : -1;

	shift_solution (x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution (x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	ll lx1 = x;

	shift_solution (x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution (x, y, a, b, -sign_b);
	ll rx1 = x;

	shift_solution (x, y, a, b, - (miny - y) / a);
	if (y < miny)
		shift_solution (x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	ll lx2 = x;

	shift_solution (x, y, a, b, - (maxy - y) / a);
	if (y > maxy)
		shift_solution (x, y, a, b, sign_a);
	ll rx2 = x;

	if (lx2 > rx2)
		swap (lx2, rx2);
	ll lx = max (lx1, lx2);
	ll rx = min (rx1, rx2);

	return (rx - lx) / abs(b) + 1;
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
   int cs , t ;
   read(t);
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       read(A) , read(B) , read(C) , read(P);
       long long int g = __gcd(A,__gcd(B,C));
       A /= g ;
       B /= g ;
       C /= g ;
       if( P % g != 0 )
       {
           printf("Case %d: 0\n",cs);
           continue;
       }
       P /= g ;
        long long int x , y , z = 0, nx , ny , i;
        long long int ans = 0 ;

     /*  int d = extended_Euclid(A,B,x,y);

       g = gcd(A,B);
       int a = A/g;
       int b = B/g ;
       printf("d :: %d a ::%d b :: %d x::%d y::%d g::%d C :: %d\n",d,a,b,x,y,g,C);

       if( x >= 0 && y >= 0 ) ans++;  */
       while(1)
       {
           ll tmp = P - (z*C);
           if( 0 > tmp ) break;
           ans += find_all_solutions(A,B,tmp,0,P,0,P);
           z++;
       }
       printf("Case %d: %lld\n",cs,ans);

   }
   return 0;
}
