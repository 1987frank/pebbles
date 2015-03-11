/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, 
otherwise return 0.
*/
#include<stdio.h>
#include<string.h>

int compareVersion(char *version1, char *version2);

void main(){
char v1[]="1";
char v2[]="2";
printf("op:%d\n",compareVersion(v1,v2));
}

int compareVersion(char *version1, char *version2){

    char *pos1,*pos2;
    char *val1,*val2;
    int v1,v2;
    val1=strtok_r(version1,".",&pos1);
    val2=strtok_r(version2,".",&pos2);    

    while(val1 || val2) {
        //printf("%s..%s\n",val1,val2);
	v1=val1?atoi(val1):0;
        v2=val2?atoi(val2):0;
        //printf("%d..%d\n",v1,v2);
	if(v1==v2){
            val1=strtok_r(NULL,".",&pos1);
            val2=strtok_r(NULL,".",&pos2);
        }
        else{
            return (v1>v2?1:-1);
        }
    }     
    return 0;
  }
