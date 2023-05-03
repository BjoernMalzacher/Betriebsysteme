#include <stdio.h>
#include <unistd.h>

 int createforks(int n){
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if(pid == 0){
                printf("this is chuldprocess %d\n",i+1);
            break;
        }
    }
   
 }

 int main(int arcg, char *argv[])
 {
      scanf("%d");
    createforks();
 }