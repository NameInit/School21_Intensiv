#include <stdio.h>


int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int main(){
    int num1;
    int num2;
    if(scanf("%d%d",&num1,&num2)!=2){
        printf("n/a\n");
        return -1;
    }
    printf("%d\n",max(num1,num2));
    return 0;
}