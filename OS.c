Implementation for  POSIX thread :

#include <stdio.h>
#inlcude <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *ethread ( void *arg ) ;

char ret_status [10] [100];

int main (int argc,char **argv)
{
  pthread_t tid [10];
  int i ,r;
  void*status ;
  char Buffer [128];

  int thread_no [10];
  for ( i =0 : i < 10 : i++ )
       thread_no [i] = i;
    {
      if (( r = pthread_create(&tid [i] , NUll ,ethread , (void *) &thread_no
          strerror_ r(r , buffer , sizeof(buffer));
           fprintf(stderr, "Error = %d (%s)/n ",r , buffer) ; exit ( 1); 
      }
}
if ((r = pthread_cancel (tid [9])) != 0) {
        strerror_r (r, buffer, sizeof (buffer));
        fprintf (stderr, "Error = %d (%s)\n", r, buffer); exit (1);
    }
    
    for (i = 0; i < 10; i++) {
        if ((r = pthread_join (tid [i], &status)) != 0) {
            strerror_r (r, buffer, sizeof (buffer));
            fprintf (stderr, "Error = %d (%s)\n", r, buffer); exit (1);
        }

        if (status == PTHREAD_CANCELED)
            printf ("i = %d, status = CANCELED\n", i);
        else
            printf ("i = %d, status = %s\n", i, (char *) status);
    }
    exit (0);
}
void *ethread (void *arg)
{
    int my_id = *((int *) arg);

    // Take a nap
    sleep (1);

    // say hello and terminate
    printf ("Thread %d: Hello World!\n", my_id);

    sprintf (ret_status [my_id], "Thread %d: %d", my_id, my_id + 10);

    if (my_id == 9) sleep (10);

    // pass your id to the thread waiting for you to terminate
    // using pthread_join.
    pthread_exit (ret_status [my_id]);
}

This is the code for Posix thread in which main thread creates ten threads also waiting for the threads to terminate ,printing status by each thread. The threads which are recorded in output is leading to cancellation status.ss