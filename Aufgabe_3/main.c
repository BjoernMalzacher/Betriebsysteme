
 #include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
 #define BUFSIZE 1024

 int main() {
 
 pipe_you(1);
 
 return 0;
 }
void pipe_you(int test ){
   int fd[2] , ret = 0;
   char output_buffer[] = "10";
   char input_buffer[BUFSIZ];
   pid_t pid;
   int status;
   // create a oneway communication channel, an unnamed pipe
   ret = pipe(fd);
   if(ret == -1){
      printf("attempt to create pipe failed");
      exit(errno);
   }
   pid = fork();

   if (pid == 0) {
   // child process:
   // close the read end of the pipe
   ret = close(fd[0]);
      if(ret == -1){
         printf("attempt to close failed");
         exit(errno);
      }
   printf("Child intiates communication by writing data to the write end of the pipe.\n");

   for (int i = 10; i >= 0; i--) {
      sprintf(output_buffer, "%d", i);
      
      
      ret =write(fd[1], output_buffer, sizeof(output_buffer));
      if(ret == -1){
         printf("attempt to write failed");
         exit(errno);
      }
      sleep(1);
   }
   } else {
   // parent process:
   // close the write end of the pipe
   ret = close(fd[1]);
   if(ret == -1){
         printf("could not close the pipe");
         exit(errno);
      }
      while (waitpid(pid, &status, WNOHANG)== 0 ){   
         
            ret = read(fd[0], input_buffer, sizeof(input_buffer));
            if(ret == -1){
               printf("attempt to write failed");
               exit(errno);
            }
         printf("The data read from parent process is: \"%s\" \n", input_buffer);
         
         
      }
   }
 
}
