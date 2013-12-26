//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: uva 445 Marvelous Mazes
   Type   : Adhoc
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{  
    char str[150];
    while(gets(str))
    {       int i=0;
	    while(str[i]!=NULL)
	    {  int t=0;
	       while(str[i]>='0' && str[i]<='9') t+=(str[i++]-'0');
	       for(int j=0;j<t;j++)
	       {if(str[i]=='b') printf(" ");
	       else printf("%c",str[i]);
	       }
	       if(str[i]=='!') printf("\n");
	      i++;
	    }
     printf("\n");
    }
    return 0; 
}
 
