#include <stdio.h>
#include <math.h>


int main(){
    double x;
    double y;
    if((scanf("%lf",&x)!=1)||(x==0)){
        printf("n/a\n");
        return -1;
    }
    y=7*pow(10,-3)*pow(x,4)+((22.8*cbrt(x)-pow(10,3))*x+3)/(x*x/2)-x*pow(10+x,2/x)-1.01;
    printf("%.1lf\n",y);
    return 0;
}