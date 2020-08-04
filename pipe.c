//  Created by Nada AZ on 3/10/19.
//  Copyright © 2019 Nada AZ. All rights reserved.

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int fd[2], x, i, snt_id, rcv_id, sum=0, arr[10];
    
    pipe(fd);
    
    for (i=0;i<10;i++)
    {
        x=fork(); //fork 10 timez
        
        // [read | write]
        
        if (x==0) //child
        {
            snt_id=getpid();
            close(fd[0]); //close read
            write(fd[1],snt_id,sizeof(snt_id));
            sleep(3);
        }
        
        else //parent
        {
            close(fd[1]);
            read(fd[0],rcv_id,sizeof(rcv_id));
            arr[i]=rcv_id;
            sum+=rcv_id;
            printf("Child process id %d \n",rcv_id);
        }
    }
    printf("Sum is %d \n",sum);
    return 0;
}
