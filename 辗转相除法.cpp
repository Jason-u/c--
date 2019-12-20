#include<stdio.h>
int main(void)  
{
    int a,b,t,c,sum;
    scanf("%d %d",&a,&b);
    sum=a*b;
    printf("%d %d",a,a);
else{ 
    if(a>b){ 
    while(a%b!=
    if(a==b)0){ 
    c=b;
    b=a%b;
    a=c;
    } 
    t=sum/b;
    printf("%d %d",b,t);//t为最小公倍数  b为最大公因数。 
    }
    else
   {
    while(b%a!=0)
    {
        c=a;
        a=b%a;
        b=c;
        
    }
    t=sum/a;
    printf("%d %d",a,t);}}
    return 0;

}
