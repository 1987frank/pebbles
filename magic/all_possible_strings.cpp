/*
Generate all possible strings from given set of characters.
Repetitions allowed.
*/

#include<stdio.h>

int size;

void strgen(int n, char *, char*);

void main() {
	
	char str[]={'x','y','z'};
	char gen[3];
	size=3;
	strgen(0,str,gen);
	
}

void strgen(int n, char *str, char* gen){
	
	
	if(n==size) {
		int i;	
		for(i=0;i<size;++i) 
			printf("%c",gen[i]);
		printf("\n");
		
	}
	else {
		int i;
		for(i=0;i<size;++i) {
			
			gen[n]=str[i];
			strgen(n+1,str,gen);
		}
		
	}	
}
