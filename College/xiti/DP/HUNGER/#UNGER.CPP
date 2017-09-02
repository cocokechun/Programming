#include<stdio.h>
#include<stdlib.h>

int n;

typedef struct
{
        int start;
        int end;
}cow;

int f[1500]={0};
cow c[1500]={0};



int main(void)
{
    freopen("hunger.in","r",stdin);
    freopen("hunger.out","w",stdout);
    int i,j;
    int max=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d%d",&c[i].start,&c[i].end);
    for( i=1;i<=n-1;i++)
         for( j=i+1;j<=n;j++)
         {
              if( c[i].end > c[j].end ) 
              {
                  c[i].end^=c[j].end^=c[i].end^=c[j].end;
                  c[i].start^=c[j].start^=c[i].start^=c[j].start;
              }
         }
    for( i=1;i<=n;i++)
    {
         for( j=1;j<i;j++)
         {
              if( c[j].end < c[i].start && f[j] > f[i] )
                  f[i]=f[j];
         }
         f[i]+=c[j].end-c[i].start+1;
    }
    for( i=1;i<=n;i++) if(f[0]<f[