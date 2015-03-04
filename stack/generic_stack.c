/*
A Generic Stack Implemenation.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct my_stack{
	
	void *ptr;
	int size;
	int elem_size;
	int top;	
	
}STACK;

int push(STACK *st, void* val) {	
	
	if(st->top==st->size) {
		
		void *temp=realloc(st->ptr,2*st->size*st->elem_size);
		if(!temp) {
			
			return 0;
		}
		st->ptr=temp;
		st->size*=2;		
	}
	void *loc=st->ptr+(st->elem_size*st->top);
	memcpy(loc,val,st->elem_size);	
	st->top++;	
	return 1;
}

int init_stack(STACK* st, int size, int elem_size) {
	
	st->ptr=malloc(size*elem_size);
	if(!st->ptr) {
		return 0;
	}
	st->size=size;
	st->elem_size=elem_size;
	st->top=0;
	return 1;	
}

void *pop(STACK* st) {
	
	void *val;
	if(st->top==0)
		return NULL;
	
	st->top--;	
	val= st->top*st->elem_size+st->ptr;
	return val;	
}

void main() {
	
	int i;
	float *v, val[]={1.23,1.44,4.56,8.99,9.04,9,9,7.0};
	STACK k;
	init_stack(&k,3,sizeof(float));	
	
	for(i=0;i<8;i++) {
		
		push(&k,(void*)&val[i]);
		
	}

	for(i=0;i<=7;i++) {
		
		v=(float*)pop(&k);
		if(!v)
			printf("Empty!\n");
		else
			printf("%f\n",*v);
		
	}
	/*
	for(i=0;i<5;i++) {
		
		push(&k,(void*)&val[i]);
		
	}
	
	for(i=0;i<=7;i++) {
		
		v=(float*)pop(&k);
		if(!v)
			printf("Empty!\n");
		else
			printf("%f\n",*v);
		
	}	*/
	
}
