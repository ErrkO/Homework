/* Eric Oliver
 * CSCI 4100
 * Assignment 6
 * This program tests a bounded buffer by creating multiple sending and
 * receiving threads
 */

#include <stdio.h>
#include <stdlib.h>
#include "bbuff.h"

/* Structure to hold thread arguments */
struct t_args {

    /* Thread ID */
    int t_id;

    /* Number of messages to send/receive */
    int num_msgs;

    /* Bounded buffer to use */
    struct bbuff * buffer;
};

/* Initialize t_args structure */
void t_args_init(struct t_args *args, int t_id, int num_msgs, struct bbuff * buffer);

/* Function for sending thread to execute */
void * send_msgs(void * args);

/* Function for receiving thread to execute */
void * receive_msgs(void * args);

/* Main function */
int main(int argc, char *argv[]) 
{

    // Sending threads
    pthread_t st1;
    pthread_t st2;
    pthread_t st3;

    // Receiving threads
    pthread_t rt1;
    pthread_t rt2;
    pthread_t rt3;
    pthread_t rt4;

    struct bbuff buffer;

    bb_init(&buffer);

    // Sending args
    struct t_args sa1;
    struct t_args sa2;
    struct t_args sa3;

    // Receiving args
    struct t_args ra1;
    struct t_args ra2;
    struct t_args ra3;
    struct t_args ra4;

    t_args_init(&sa1,0,4,&buffer);

    t_args_init(&sa2,1,4,&buffer);

    t_args_init(&sa3,2,4,&buffer);

    t_args_init(&ra1,0,4,&buffer);

    t_args_init(&ra2,1,4,&buffer);

    t_args_init(&ra3,2,4,&buffer);

    t_args_init(&ra4,3,4,&buffer);

    pthread_create(&st1,NULL,send_msgs,&sa1);

    pthread_create(&st2,NULL,send_msgs,&sa2);

    pthread_create(&st3,NULL,send_msgs,&sa3);

    pthread_create(&rt1,NULL,receive_msgs,&ra1);

    pthread_create(&rt2,NULL,receive_msgs,&ra2);

    pthread_create(&rt3,NULL,receive_msgs,&ra3);

    pthread_create(&rt4,NULL,receive_msgs,&ra4);

    pthread_join(st1,NULL);

    pthread_join(st2,NULL);

    pthread_join(st3,NULL);

    pthread_join(rt1,NULL);

    pthread_join(rt2,NULL);

    pthread_join(rt3,NULL);

    pthread_join(rt4,NULL);

}

/* Initialize t_args structure */
void t_args_init(struct t_args *args, int t_id, int num_msgs, struct bbuff * buffer) 
{

    args->t_id = t_id;
    args->num_msgs = num_msgs;
    args->buffer = buffer;

}

/* Function for sending thread to execute */
void * send_msgs(void * args) 
{

    struct t_args * real_args = ( struct t_args *) args ;

    struct bb_msg newmsg;

    bb_init_msg(&newmsg,0,0);

    bb_send(real_args->buffer,&newmsg);

    bb_init_msg(&newmsg,1,1);

    bb_send(real_args->buffer,&newmsg);

    bb_init_msg(&newmsg,2,2);

    bb_send(real_args->buffer,&newmsg);

    bb_init_msg(&newmsg,3,3);

    bb_send(real_args->buffer,&newmsg);

    return NULL;

}

/* Function for receiving thread to execute */
void * receive_msgs(void * args) 
{

    struct t_args * real_args = ( struct t_args *) args ;

    struct bb_msg newmsg;

    bb_receive(real_args->buffer,&newmsg);

    bb_display_msg(&newmsg,0);

    bb_receive(real_args->buffer,&newmsg);

    bb_display_msg(&newmsg,1);

    bb_receive(real_args->buffer,&newmsg);

    bb_display_msg(&newmsg,2);

    bb_receive(real_args->buffer,&newmsg);

    bb_display_msg(&newmsg,3);

    return NULL;

}
