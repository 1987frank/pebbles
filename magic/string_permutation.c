/*
All possible permuatation of a string.
*/

#include<stdio.h>

void swap(char *a, char *b);
void permute(int k,int n, char str[]) ;

void main() {
	
	char a[5]="ABCD";
	permute(0,4,a);
	
}

void swap(char *a, char *b) {
	
	char ch=*a;
	*a=*b;
	*b=ch;	
}

void permute(int k,int n, char str[]) {
	
	if(k==n) {
		
		printf("%s\n",str);
				
	}
	else {
		int i;
		for(i=k;i<n;++i) {
			
			swap(str+i,str+k);
			permute(k+1,n,str);
			swap(str+k,str+i);			
		}
		
	}
	
}
