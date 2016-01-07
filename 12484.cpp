#include <iostream>
using namespace std;

long long a[10003];
long long dp[2][10002];
int n;

int main(){
        while(cin>>n){
                for(int i=1;i<=n;i++){
                        cin>>a[i];
                        dp[1][i]=a[i];
                        a[i]+=a[i-1];
                }
                for(int l=2;l<=n;l++){
                        for(int s=1;s+l-1<=n;s++){
                                {  // printf("l::%d s::%d  s+l-1::%d a[s+l-1]::%d  a[s-1]::%d dp[1-l%2][s] %d dp[1-l%2][s+1] :%d \n",l,s,s+l-1,a[s+l-1],a[s-1],dp[1-l%2][s],dp[1-l%2][s+1]);
                                    dp[l%2][s]=a[s+l-1]-a[s-1]-min(dp[1-l%2][s],dp[1-l%2][s+1]);

                                }
                        }
                }
                cout<<dp[n%2][1]<<endl;
        }
}







