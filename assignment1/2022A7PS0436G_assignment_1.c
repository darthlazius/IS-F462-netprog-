/*
TODO: he parent process creates a child process. (2 marks)
The parent prints its PID and its role (parent, child, or grandchild). (2 mark)
The child prints its PID and its role (parent, child,  grandchild). (2 mark)
The child process creates a grandchild process. (2 marks)
The grandchild prints its PID and its role (parent, child,  grandchild). (2 mark)
The grandchild exits after its execution. (2 mark)
When the grandchild exits, the child prints that the grandchild has exited. It prints the grandchild's PID and role. (2 marks)
The child process exits. (2 mark)
When the child exits, the parent prints that the child has exited. It prints the child's PID and role. (2 marks)
The parent process prints its PID and its role. It exits. (2 marks)
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


void ChildProcess(){
    pid_t pid2 = fork();

     if (pid2 == -1){
        perror("Fork Unsuccesfull");
        exit(-1);
    }
    else if (pid2 == 0){
        printf("I am a grandchild Process with PID :%d\n",getpid());
        exit(0);
    }
    else {
        printf("I am a child Process with PID:%d\n",getpid());
        waitpid(pid2,NULL,0);
        printf("The GrandChild process has exited it's PID was :%d\n",pid2);
        exit(0);
    }

}

int main(){
    pid_t pid = fork();
    if (pid == -1){
        perror("Fork Unsuccesfull");
        exit(-1);
    }
    else if (pid == 0){
        ChildProcess();
    }
    else {
        printf("I am a parent Process with PID:%d\n",getpid());
        waitpid(pid,NULL,0);
        printf("The child process has exited it's PID was :%d\n",pid);
        exit(0);
    }
}
