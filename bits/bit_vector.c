//Bit vector implementation

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define SET(n,pos) (n|=(1<<pos))
#define CLEAR(n,pos) (n^=(1<<pos))
#define ISSET(n,pos) !!(n&(1<<pos))


typedef struct bit_vector{
void *ptr;
int size;
}BVEC;

int init_bitvec(BVEC *vec,int size){

int bytes= (size-1)/8+1;
vec->ptr=malloc(bytes);
if(!vec->ptr)
	return -1;
memset(vec->ptr,0,bytes);
vec->size=size;
return 1;
}

int set_bitvec(BVEC *vec, int pos){

int byte;
int offset;
char val;
char *bytepos;
if(pos<=0 || pos>vec->size)
	return -1;
byte=(pos-1)/8;
offset=(pos-1)%8;
bytepos=(char*)vec->ptr+byte;
SET(*bytepos,offset);
return 1;
}

int clear_bitvec(BVEC *vec, int pos){

int byte;
int offset;
char val;
char *bytepos;
if(pos<=0 || pos>vec->size)
	return -1;
byte=(pos-1)/8;
offset=(pos-1)%8;
bytepos=(char*)vec->ptr+byte;
CLEAR(*bytepos,offset);
return 1;
}

int is_bitset(BVEC *vec, int pos){

int byte;
int offset;
char val;
char *bytepos;
if(pos<=0 || pos>vec->size)
	return -1;
byte=(pos-1)/8;
offset=(pos-1)%8;
bytepos=(char*)vec->ptr+byte;
return (ISSET(*bytepos,offset));

}

void free_bitvec(BVEC *vec){

free(vec->ptr);

}


void main(){
int i;
BVEC my_bitvector;
init_bitvec(&my_bitvector,100);

int arr[]={34,3,45,67,89,23,12,1,99,7,100};
for(i=0;i<11;++i){
set_bitvec(&my_bitvector,arr[i]);
}

for(i=0;i<my_bitvector.size;++i){
	if(is_bitset(&my_bitvector,i+1)){
		printf("%d ",i+1);
		clear_bitvec(&my_bitvector,i+1);
	}
}

printf("\n testing if bit worked\n");

for(i=0;i<my_bitvector.size;++i){
	if(is_bitset(&my_bitvector,i+1)){
		printf("%d ",i+1);
		//clear_bitvec(&my_bitvector,i+1);
	}
}

free_bitvec(&my_bitvector);
}


