//Rotate array by k elements to right.
//For eg: if a[]={1,2,3,4,5} and k=2, o/p:a[]={4,5,1,2,3}

#include<stdio.h>

void rotate(int nums[], int n, int k); 
void reverse(int a[],int beg,int end);
void swap(int *a, int *b);

void main(){

    int a[]={1,2,3,4,5,6,7,8,9,10};
    rotate(a,10,2);

}
//Reverse n-k and k elements seperately.
//Reverse the entire list again.
//If it is to rotate to left, reverse k and n-k sepereately, and reverse the entire list.
void rotate(int nums[], int n, int k) { 
    k=k%n;
    reverse(nums,0,n-k-1);
    reverse(nums,n-k,n-1);
    reverse(nums,0,n-1);
}

void reverse(int a[],int beg,int end){

    if(beg>=end)
        return;
    swap(&a[beg],&a[end]);
    reverse(a,beg+1,end-1);
}
void swap(int *a, int *b){

    int t=*a;
    *a=*b;
    *b=t;
}
