#include <stdio.h>

int n=0;

int cal(int* a){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

int main(){
    int a[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",cal(a));
    return 0;
}