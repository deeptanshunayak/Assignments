#include <stdio.h>
#include<stdbool.h>
bool checkyear(int year);
int main()
{
    int year;
    
    printf("enter the year:");
    
    scanf("%d",&year);
    
    if(checkyear(year)){
        printf("the year is a leap year");
    }
    else{
    printf("the year is not a leap year");
    }
    return 0;
}

bool checkyear(int year){
    
    
    if(year%100==0){
        
        if(year%400==0){
            
            return true;
        }
        else{
            
            return false;
        }
        
    }
    
    else{
        
        if(year%4==0){
            
            return true;
        }
        
        else{
            
            return false;
        }
    }
    
    
    return false;
    
}
