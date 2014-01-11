//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 11057
   Type   : Adhoc
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{  int n;
   while(scanf("%d",&n)!=EOF)
   {  vector<int> arr;
      int total,prize,min,max=-1;
      while(n--)
      {  cin>>prize;
         arr.push_back(prize);
      }
      cin>>total;
      cin.ignore(100,'\n');
      stable_sort(arr.begin(),arr.end());
      for(int i=0,sz=arr.size();i<sz-1;i++)
	    for(int j=i+1;j<sz;j++) 
	       if(arr[i]+arr[j]==total) {if(max<arr[i]) { max=arr[i]; min=arr[j];} }
     printf("Peter should buy books whose prices are %d and %d.\n\n",max,min);
 
   }
 return 0;
}
 
