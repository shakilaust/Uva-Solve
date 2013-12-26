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

/* **************************************  My code start here ****************************************** */
const int MAXN = 47000;
bool check[1000000+10] ;
int prime[MAXN+50];
int idx = 0 ;
void pre()
{
    prime[idx++]=2;
    int i , j ;
    check[0] = check[1] = 1;
    for(i=3;i*i<=MAXN;i+=2) for(j=i*i;j<=MAXN;j+=2*i) check[j] = 1;
    for(i=3;i<=MAXN;i+=2) if(!check[i]) prime[idx++] = i ;
}

int main()
{
    LL L , R , Res[5];
    pre();
    while(scanf("%lld %lld",&L,&R)==2)
    {
        LL i , prev = -1 , start , j;
        LL D = ( R - L ) + 1;
        for(i=0;i<=D;i++) check[i] = 0 ;
        // space Reduction
        for(i=0;prime[i]*prime[i]<=R && i<idx;i++)
        {
            if(L==prime[i]) // special case
            start = 3*prime[i];
            else if( L < prime[i] ) start = prime[i]*2;
            else if(L%prime[i]==0) start = L  ;
            else start = L + prime[i] - (L%prime[i]);
            for( j = start ; j-L<=D ; j+= prime[i] ) check[j-L] = 1;
        }
        // as first prime is 2
        if(L==1) check[0] = 1;
        LL mx = -1 , mini = 1000000 + 100 ;

      //  printf("L:: %lld R::%lld\n",L,R);
        for(i=L ; i<=R ; i++)
        {
            if(!check[i-L])
            {
                if(prev==-1) prev = i ;
                else
                {
                    int dif = i - prev ;
                    if(dif>mx)
                    {
                        Res[0] = prev ;
                        Res[1] = i ;
                        mx = dif;
                    }
                    if(dif<mini)
                    {
                        Res[2] = prev;
                        Res[3] = i ;
                        mini = dif;
                    }
                    prev = i ;
                }
            }
        }
        if(mx==-1)
        {
            puts("There are no adjacent primes.");
        }
        else
        {
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",Res[2],Res[3],Res[0],Res[1]);
        }
    }
   return 0;
}
