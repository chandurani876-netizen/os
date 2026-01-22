#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
    int arr[30],key1 ,key2, status;
    pid_t p1,p2;

    srand(time(NULL));
    for (int i=0; i<30; i++){
        arr[i]=rand() %50+1;
        printf("%d",arr[i]);
    }
    printf("\n\n Enter key1 and key2:");
    scanf("%d %d",& key1,&key2);
     p1=fork();
     if(p1==0){
        int count1=0;
        for(int i=0; i<30; i++){
            count1++;
        }
        printf("\nChild 1: key1(%d)%d times mila\n",key1,count1);
        exit(count1);
     }
     waitpid(p1,&status,0);
     int res1=WEXITSTATUS (status);
     printf("Parent:Child 1 ka result=%d\n",res1);

     p2=fork();
     if(p2==0){
        int count2=0;
        for (int i=0; i<30; i++){
            if (arr[i]==key2)
            count2++;
        }
        printf("\nChild2: key2(%d)%d times mila\n",key2,count2);
        exit(count2);
     }
     waitpid (p2,&status,0);
     int res2 =WEXITSTATUS (status);
     printf("Parent:Child 2 ka result=%d\n",res2);

     return 0;
    }