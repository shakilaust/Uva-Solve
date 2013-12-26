#include <stdio.h>
int next_col[8]={1,1,1,-1,-1,-1,0,0};
int next_row[8]={1,0,-1,1,0,-1,1,-1};
char grid[105][105];
int main()
{
    int row,col,i,j,k;
    while(scanf("%d %d",&row,&col)==2)
    {       getchar();
	    if(row==0 && col==0) break;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++) scanf("%c",&grid[i][j]);
		getchar();
        }
        int count=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
               if(grid[i][j]=='*')
                  {   bool check=true;
                      for(k=0;k<8;k++)
                         if(((i+next_row[k])>-1 && (i+next_row[k])<row) && ((j+next_col[k])>-1 && (j+next_col[k]<col)))
                              if(grid[i+next_row[k]][j+next_col[k]]=='*') check=false;
                        if(check) count+=1;
                  }
        }
        printf("%d\n",count);
    }
    return 0;
}
 
