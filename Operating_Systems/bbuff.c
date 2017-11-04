/* Eric Oliver
 * CSCI 4100
 * Assignment 6
 * Source file for bounded buffer implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include "bbuff.h"

/* Initiailze a message structure */
void bb_init_msg(struct bb_msg *msg, int t_id, int m_id) 
{

  msg.t_id = t_id;
  
  msg.m_id = m_id;

}

/* Copy the source message to the destination message */
void bb_copy_msg(struct bb_msg * source, struct bb_msg * destination) 
{

  stpcpy(destination.m_id,source.m_id);

}

/* Display the contents of a message along with the id of the receiver */
void bb_display_msg(struct bb_msg *msg, int receiver) 
{

  printf("[sending thread: %d, message %d, receiving thread: %d]",

}

/* Initialize the bounded buffer */
void bb_init(struct bbuff * buffer) 
{

  /* initizilize bounded buffer, in and out varaibles are set to zero */

}

/* Send a message to a bounded buffer */
void bb_send(struct bbuff * buffer, struct bb_msg * message) 
{

  /* Acquire buffer lock */
  
  
  /* While buffer is full, release the lock, then acquere it again so the receiving thread can access buffer*/
  
  
  /* 

}

/* Receive a message from a bounded buffer */
void bb_receive(struct bbuff *buffer, struct bb_msg * message) 
{

  /* YOUR CODE HERE */

}


void * pthread_fun(void * fun)
{
	
	
	
}