#include<stdio.h>

void main(){
    int arr[5];
    int x;
    int i = 0;
    while (i <5)
    {
        scanf("%d",&x);
         arr[i] =x;
        i++;

        /* code */
    }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    
}