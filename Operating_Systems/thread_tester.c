/* YOUR NAME HERE
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
int main(int argc, char *argv[]) {
  /* YOUR CODE HERE */
}

/* Initialize t_args structure */
void t_args_init(struct t_args *args, int t_id, int num_msgs, struct bbuff * buffer) {
  /* YOUR CODE HERE */
}

/* Function for sending thread to execute */
void * send_msgs(void * args) {
  /* YOUR CODE HERE */
}

/* Function for receiving thread to execute */
void * receive_msgs(void * args) {
  /* YOUR CODE HERE */
}
