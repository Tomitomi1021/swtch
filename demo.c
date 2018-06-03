#include<stdio.h>
#include"swtch.h"

struct context *Cmain,*Ctest;

void test(){
	int i=0;
	while(1){
		printf("test:%d\n",i);
		i++;
		swtch(&Ctest,Cmain);
	}
}

int main(){
	int i=0;
	char stack[0x1000];

	Ctest  = mkcontext(test,stack,0x1000);

	while(1){
		printf("main:%d\n",i);
		i++;
		swtch(&Cmain,Ctest);
	}
	return 0;
}
