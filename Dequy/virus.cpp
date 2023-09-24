#include<stdio.h>

unsigned long long virus (int n){
    if(n==0)
        return 1;
    else
        return virus(n-1)*2;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",virus(n));
}