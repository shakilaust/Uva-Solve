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

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
char str1[30] , str2[30];
double win[1005] , lose[1005]  ;
int n , k ;
bool CanDef( char iam , char youare )
{
    if( iam == 'r' && youare == 's' ) return 1 ;
    if( iam == 's' && youare == 'p' ) return 1 ;
    if( iam == 'p' && youare == 'r' ) return 1 ;

    return 0 ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    bool sp = 0 ;
    while(scanf("%d",&n) && n )
    {
        if(sp) puts("");
        sp = 1 ;
        k = II ;
        For(i,n) win[i] = lose[i] = 0.0 ;
        k *= (( n * (n-1))/2);
        rep(i,k)
        {
            int x = II ;
            scanf("%s",str1);
            int y = II ;
            scanf("%s",str2);
            if( !strcmp(str1,str2)) continue ;
            if( CanDef(str1[0],str2[0]))
            {
                win[x]++;
                lose[y]++;
            }
            else
            {
                win[y]++;
                lose[x]++;
            }
        }
        For( i , n )
        {
            if( win[i] + lose[i] == 0 ) puts("-");
            else printf("%.3lf\n",win[i]/(win[i]+lose[i]));
        }
    }
    return 0;
}
/*
2
17
9 3 5 2 6 6 3 0 8 6 0 4 4 8 7 2 1
1 2 3 3 3 1 2 1 1 3 1 3 3 2 1 3 1
12
4 6 9 0 2 7 3 0 9 6 8 1
2 3 1 1 1 3 2 1 3 3 2 3
*/
