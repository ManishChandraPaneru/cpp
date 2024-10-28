#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int x=1;
    if(fork()==0){
        printf("Child has %d\n",++x);
    }
    else {
        printf("Parent has %d\n",--x);
    }   
    return 0;
}
