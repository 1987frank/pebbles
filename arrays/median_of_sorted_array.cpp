/*
There are 2 sorted arrays A and B of size m and n.
Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length m+n). 
The complexity should be O(log(n))
credits: http://yucoding.blogspot.com/2013/01/leetcode-question-50-median-of-two.html
*/

#include<iostream>

using namespace std;

int getatpos(int A[],int m, int B[],int n,int k) ;
float medianofsorted(int A[],int m, int B[],int n) ;

//Driver Program
int main() {
	
	int A[]={5,6,7,8,9,10,11,12,13,14};
	int B[]={21};
	cout<<medianofsorted(A,10,B,1);	
	return 0;
	
	
}


int getatpos(int A[],int m, int B[],int n,int k) {
	
	if(m>n)
		return getatpos(B,n,A,m,k);
		
	if(m==0)
		return B[k-1];
	
	if(k==1)
		return min(A[0],B[0]);
		
	int p=min(m,k/2);
	int q=k-p;
	
	if(A[p-1]>B[q-1]) {
		
		return getatpos(A,m,B+q,n,k-q);
		
	}
	else {		
		return getatpos(A+p,m,B,n,k-p);
	}
	
}


float medianofsorted(int A[],int m, int B[],int n) {
	
	int k=(m+n)/2+1;
	if((m+n)%2==1) 
		return getatpos(A,m,B,n,k);
	else
		return (getatpos(A,m,B,n,k)+getatpos(A,m,B,n,k-1))/2.0;
	
}
