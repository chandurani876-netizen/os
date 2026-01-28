#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
int main()
{
int fd;
char buffer[100];
fd=open("data.text",O_CREAT|O_WRONLY|O_TRUNC,0644);//parent 
printf("Enter text to write into file:");
fgets(buffer,sizeof (buffer),stdin);
write(fd,buffer,strlen(buffer));//child 
close(fd);
pid_t pid=fork();
//child process
if (pid==0){
fd=open("data.text",O_RDONLY);
read(fd,buffer,strlen(buffer));
printf("\n%s",buffer);
close(fd);
}
return 0;
}