

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


double const EPS=3e-8;
using namespace std;



//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
int prime[100005] , idx = 0 , inp ;

bool check[1299709+5] ;

void seive()
{
    prime[idx++] = 2 ;
    int i , j ;
    for ( i = 3 ; i*i <= 1299709 ; i+=2)
    {
        if ( check[i]==0)
        {
            prime[idx++] = i ;
            for ( j = i*i ; j <= 1299709 ; j+= (2*i) ) check[j] = 1;
        }
    }
    while( i <= 1299709 )
    {
        if ( check[i]==0) prime[idx++] = i ;
        i+=2;
    }
}

int binary_search(int n)
{
    int low = 0 , high = 100000 , val  , val2 , mid;
    while ( low < high )
    {
        mid = ( low + high ) / 2 ;
        if ( prime[mid] <= n )
        {
            val = prime[mid] ;
            low = mid + 1;
        }
        if ( prime[mid] >=  n )
        {
            val2 = prime[mid] ;
            high = mid ;
        }

    }
    return val2 - val;

}

int main()
{    seive();

    while(read(inp) && inp)
    {
        printf("%d\n",binary_search(inp));
    }

   return 0;
}
