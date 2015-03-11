/*
Given an array of integers which is initially increasing and then decreasing, find the maximum value in the array.
*/
#include<stdio.h>
int getmax(int a[],int n);
void main(){
//int a[]={1,2,3,4,5,6,7,8,9,10,9,8,7,6,5};
int arr[] = {1, 3, 50, 10, 9, 7, 6};
printf("%d",getmax(arr,7));
}

int getmax(int a[],int n){

int mid=0;
if(n==1)
	return a[0];
mid=n/2;

if(a[mid-1]>a[mid])
	return getmax(a,mid);
else
	return getmax(a+mid,n-mid);
}
