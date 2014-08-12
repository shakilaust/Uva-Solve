
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
const int maxn = 30 ;
typedef long long ll ;
ll dp1[maxn][maxn] , dp2[maxn][maxn] ;
int Y , M , n = 26;
void CLEAN()
{
    int i , j ;
    rep(i,n)
    {
        rep(j,n) dp1[i][j] = dp2[i][j] = (1<<29);

    }
}
bool input()
{
    char A , B , C , D ;
    ll cst ;
    int x , y , i , m;
    cin >> m ;
  //  cout<<" n " << n << endl;
    if(!m ) return 0;

    while(m--)
    {
         // printf("here\n");
        //  getchar();
        cin >> A >> B >> C >> D;
        read(cst);

     //  read(A) , read(B) , read(C) , read(D) , read(cst);
       // cout<<" A " << A << B << C << D << cst << endl;
        x = C - 'A';
        y = D - 'A';

        if(A=='Y')
        {
            if( B == 'B' )
            {
                dp1[x][y] = min(dp1[x][y],cst);
                dp1[y][x] = min(dp1[y][x],cst);
            }
            else dp1[x][y] = min(dp1[x][y],cst);
        }
        else
        {
            if( B == 'B' )
            {
                dp2[x][y] = min(dp2[x][y],cst);
                dp2[y][x] = min(dp2[y][x],cst);
            }
            else dp2[x][y] = min(dp2[x][y],cst);
        }
    }
    cin >> A >> B ;
    Y = A - 'A';
    M = B - 'A';
    rep(i,n) dp1[i][i] = dp2[i][i] = 0 ;
    return 1;
}
void solve()
{
    int i , j , k ;
    rep(k,n) rep(i,n) rep(j,n)
    {
        if(dp1[i][j] > dp1[i][k] + dp1[k][j] ) dp1[i][j] = dp1[i][k] + dp1[k][j];
        if(dp2[i][j] > dp2[i][k] + dp2[k][j] ) dp2[i][j] = dp2[i][k] + dp2[k][j];


    }
    ll ans = ( 1 << 29 ) ;

        for ( i = 0 ; i < n ; i++ )
        {
             if(dp1[Y][i] == (1<<29) || dp2[M][i] == (1<<29) ) continue;
            if(ans > dp1[Y][i] + dp2[M][i])
            {
                ans = dp1[Y][i] + dp2[M][i] ;
            }
        }

    if(ans == (1<<29))
    {
            printf("You will never meet.\n");
    }
    else
    {
        cout<<ans;
        for ( i = 0 ; i < n ; i++ )
        {
            if( ans == dp1[Y][i] + dp2[M][i])
            {
                cout<<" "<< char('A'+i);

            }
        }
        cout<<endl;
    }
}
int main()
{
    // ios :: sync_with_stdio(false);
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     CLEAN();
     while(input())
     {
         solve();
         CLEAN();
     }
   return 0;
}
