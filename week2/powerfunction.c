#include<stdio.h>
float power(int x,int y);
int main()
{
    int x,y;
    float result;
    printf("enter the number:");
    
    scanf("%d",&x);
    
    printf("enter the power:");
    scanf("%d",&y);
    result=power(x,y);
    printf("the value of %d ^ %d is %f",x,y,result);

    return 0;
}
float power(int x,int y){
    
    int value=1;
    float next;
    if(y<0){
        y=-y;
        
        for(int i=0;i<y;i++){
        value=value*x;
        }
        
    next=1.0/value;    
    }
    else{
    for(int i=0;i<y;i++){
        value=value*x;
        }
        next=value;
    }
    
    return next;
}
