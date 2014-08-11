//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::   WA :'( )
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
const int mod  = 10000007 ;
int N , num[105] , sz;
string inp ;
int dp[2][12][102][102] , vis[2][12][102][102] , cs;
void Adjust(int &ret)
{
    if ( ret >= mod ) ret -= mod ;
}
int table[105];
void ComputePreFix()
{
    table[1]  = 0 ;
    int i , k = 0;
    for ( i = 2 ; i <= sz ; i++ )
    {
        while( k > 0 && num[k] != num[i-1] ) k = table[k];
        if(num[k] == num[i-1] ) k++;
        table[i] = k ;
    }

}
int Next(int match , int now )
{
    while(match && num[match] != now ) match = table[match];
    if( now == num[match] ) match += 1 ;
    return match;
}
int DP(int Isbegin ,int prev , int match , int len )
{
    if ( match == sz )  return 0 ;
    if ( !len ) return 1 ;
    int &ret = dp[Isbegin][prev][match][len];
    if( vis[Isbegin][prev][match][len]==cs) return ret ;
    vis[Isbegin][prev][match][len] = cs ;
    int s = Isbegin ? 0 : 1 ;
    int i ;
    ret = 0 ;
    for ( i = s ; i < 10 ; i++ ) { ret += DP(1, i , (i == num[match] ? match + 1 : Next(match,i)) , len - 1)%10000007 ;
    //Adjust(ret);
    }
    return ret%10000007;
}
int main()
{
     ios :: sync_with_stdio(false);
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int t , len;
     cin >> t ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         cin >> len >> inp ;
         sz = inp.size();
         int idx = 0 , i;
         for ( i = 0 ; i < sz ; i++ )
         {
             num[i] = inp[i]-'0';

         }
         ComputePreFix();
         int Ans = DP(0,10 , 0,len);
         if ( len == 1 && num[0] != 0 ) Ans++;
         // Adjust(Ans);
         cout<<(Ans)%10000007<<endl;
     }

   return 0;
}
