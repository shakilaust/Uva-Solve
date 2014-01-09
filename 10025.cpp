
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


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
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
/*	Let T[n] be the nth triangular number. Let i be the smallest number such that T[i] >= k. Obviously i is a lower bound for n.

Now, if T[i] - k is even, then we can negate some of the numbers from 1...i to make the formula work. If T[i] - k isn't even, then we can try T[i+1], and T[i+2]. The triangular number sequence goes {even, odd, odd, even, even, odd, odd, etc.} so we never need to check more than 2 triangular numbers above i.

Note that if k is negative, you can just negate the entire expression, so there is no difference in n.

Note the special case k = 0. n must be >= 1, so you cannot say n = 0 if k = 0.
*/
int main()
{
    int cs , t ;
    read(t);
    rep(cs,t)
    {   if(cs) puts("");
        int n , i ;
        read(n);
        n = abs(n);
        if(!n)
        {
            puts("3");
            continue;
        }
        for(i=0; ;i++)
        {
            if( (i*(i+1))/2 >= n && ((i*(i+1))/2-n)%2==0) break; 
        }
        printf("%d\n",i);
    }
   return 0;
}
