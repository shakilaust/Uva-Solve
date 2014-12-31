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
const int MX = 205 ;
int tree[MX][MX];
void update(int x , int y , int val )
{
    int i , j ;
    for ( i = x ; i < MX ; i += (i & -i ) )
    {
        for ( j = y ; j < MX ; j += ( j & -j ) )
        {
            tree[i][j] += val ;
        }
        //printf("i :: j :: %d %d\n",i,j);
    }
}
int sum(int x , int y)
{
    int ret = 0 ;
    int i , j ;
    for ( i = x ; i > 0 ; i -= ( i &-i) )
    {
        for ( j = y ; j > 0 ; j -= ( j & -j) )
           {
               ret += tree[i][j];

           }

    }
    return ret ;
}
int total(int x1 , int y1 , int x2 , int y2)
{
    int ans = sum(x1-1,y1-1);
    ans += sum(x2,y2);
    ans -= sum(x1-1,y2);
    ans -= sum(x2,y1-1);
    return ans ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   //FI ;
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       ms(tree,0);
       int n = II ;
       int Ans = 0 ;
       rep(i,n)
       {
           int x = II , y = II ;
           x += 101 ;
           y += 101 ;
           int x1 = II , y1 = II ;
           x1 += 100 ;
           y1 += 100 ;
           if( total(x,y,x1,y1)==0)
           {
               //printf(" x :: %d x1 :: %d\n",x,x1);
               int i , j ;
               for ( i = x ; i <= x1 ; i++ )
               {
                   for ( j = y ; j <=y1 ; j++ )
                   {
                       Ans++;
                       update(i,j,1);
                   }
               }
           }
       }
       printf("Case %d: %d\n",cs,Ans);
   }

    return 0;
}
/*

*/
