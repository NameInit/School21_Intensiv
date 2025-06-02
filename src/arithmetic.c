#include <stdio.h>


int main(){
    int num1;
    int num2;
    if(scanf("%d%d",&num1,&num2)!=2){
        printf("n/a\n");
        return -1;
    }
    printf("%d %d %d ",num1+num2,num1-num2,num1*num2);
    (num2 == 0) ? printf("n/a\n") : printf("%d\n",num1/num2);
    return 0;
}