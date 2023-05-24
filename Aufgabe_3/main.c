
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
 #define BUFSIZE 1024

 int main() {
 int fd[2] , ret = 0;
 char output_buffer[] = "10";
char input_buffer[BUFSIZ];
pid_t pid;
int status;
 // create a oneway communication channel, an unnamed pipe
pipe(fd);

 pid = fork();

 if (pid == 0) {
 // child process:
 // close the read end of the pipe
 close(fd[0]);
 printf("Child intiates communication by writing data to the write end of the pipe.\n");
 for (int i = 10; i >= 0; i--) {
    sprintf(output_buffer, "%d", i);
    write(fd[1], output_buffer, sizeof(output_buffer));
    
    sleep(1);
 }
 } else {
 // parent process:
 // close the write end of the pipe
 close(fd[1]);
    while (waitpid(pid, &status, WNOHANG)== 0){   
       
        ret = read(fd[0], input_buffer, sizeof(input_buffer));
        printf("The data read from parent process is: \"%s\" \n", input_buffer);
        
        
    }
 }
 
 return 0;
 }
