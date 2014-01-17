//uva 11220,decode message
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int main()
{  int test;
   scanf("%d",&test);
   getchar();
   getchar();
   for(int kase=1;kase<=test;kase++)
   {  string str;
	  if(kase>1) printf("\n");
	  printf("Case #%d:\n",kase);
	  while(getline(cin,str) && str!="")
	  {  
         stringstream ss;
	     ss<<str;
	     int indx=1;
	     while(ss>>str)
		 {  if(str.size()>=indx)
		 {  cout<<str[indx-1];
		    indx+=1;
		 } 
		 }
	   printf("\n");
	  }
 
   }
 return 0;
}
 
