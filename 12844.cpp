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
int freq[405] , inp[15] ,a[6] , b[6]  , ans[10];
bool vis[15] ;
bool possible( )
{
    ms(vis,0);
    int i , j , k , x ;

    for ( i = 0 ; i < 5 ; i++ )
    {
      //  printf(" %d :: %d\n",i , b[i]);
        for ( j = i + 1 ; j < 5 ; j++ )
        {
            x = b[i] + b[j] ;
          //  printf(" x :: %d\n",x);
            bool fls = 1 ;
            for ( k = 0 ; k < 10 ; k++ )
            {
                if( vis[k] ) continue ;
                if ( x == inp[k] )
                {
                    vis[k] = 1 ;
                    fls = 0 ;
                  //  printf("x :: %d inp[k] :: %d\n",x,inp[k]);
                    break;

                }
            }
            if( fls) return 0 ;
        }
    }
    return 1 ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs , t , i , j , k , l , m , x;
   t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {

       int sum = 0 ;

       for ( i = 0 ; i < 10 ; i++ )
       {
           inp[i] = II ;


       }

      for ( i = 1 ; i <= 399 ; i++ )
      {
          b[0] = i ;
          b[1] = inp[0] - b[0];
          b[2] = inp[1] - b[0] ;
          b[4] = inp[8] - b[2] ;
          b[3] = inp[9] - b[4] ;

          bool fls = 1 ;
          for ( j = 1 ; j < 5 ; j++ )
          {
              if( b[j-1] > b[j] )
              {
                  fls = 0 ;
                  break ;
              }
          }
          if( fls && possible() ) break;

      }


       printf("Case %d:",cs);
       for( i = 0 ; i < 5 ; i++ ) printf(" %d",b[i]);
       printf("\n");

   }


    return 0;
}
/*
1
114 116 118 120 121 122 123 124 125 129
*/
