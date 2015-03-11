/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
*/

#include<stdio.h>
int majorityElement(int a[],int n);

void main(){
int a[]={2,3,4,3,4,3,2,3,3,9,0,3,3,3,4};
printf("Maj element:%d\n",majorityElement(a,15));
}

int majorityElement(int num[], int n) {
    int i;
    int maj;
    int count=0;
    for(i=0;i<n;++i){    

    if(count==0){
        maj=num[i];
        count=1;
    }
    else if(num[i]==maj){
        count++;
    }
    else{
        count--;
    }
    }
    return maj;
 }
