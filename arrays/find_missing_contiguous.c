//Find the missing element in a list of contiguous elements.
//O(log(n)) algorithm

#include<stdio.h>

int missing_element(int[],int,int);

void main(){
int a[]={4,5,6,7,8,9,10,11,12,14};
printf("Missing element:%d\n",missing_element(a,0,9));
}

//Similar to binary search
int missing_element(int a[],int beg,int end){
    
    int mid;
    if(beg>=end)
        return -1;

    mid=(beg+end)/2;
    
    //difference will be 2 in case the missing number at the boundary
    //>1 or ==2 will suffice for condition
    if((a[mid+1]-a[mid])>1)
        return a[mid]+1;
    if((a[mid]-a[beg])>(mid-beg))
        return missing_element(a,beg,mid);
    else
        return missing_element(a,mid+1,end);

}

