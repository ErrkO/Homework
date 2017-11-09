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

  msg->t_id = t_id;
  
  msg->m_id = m_id;

}

/* Copy the source message to the destination message */
void bb_copy_msg(struct bb_msg * source, struct bb_msg * destination) 
{

  destination->t_id = source->t_id;
  destination->m_id = source->m_id;

}

/* Display the contents of a message along with the id of the receiver */
void bb_display_msg(struct bb_msg *msg, int receiver) 
{

  printf("[sending thread: %d, message %d, receiving thread: %d]",msg->t_id,msg->m_id,receiver);
  printf("\n");

}

/* Initialize the bounded buffer */
void bb_init(struct bbuff * buffer) 
{

  /* initizilize bounded buffer, in and out varaibles are set to zero */
	buffer->in = 0;
	buffer->out = 0;
	pthread_mutex_init(&buffer->lock,NULL);

}

/* Send a message to a bounded buffer */
void bb_send(struct bbuff * buffer, struct bb_msg * message) 
{

	/* Acquire buffer lock */
	pthread_mutex_lock(&buffer->lock);
  
	/* While buffer is full, release the lock, then acquere it again so the receiving thread can access buffer*/
  	while(buffer->in - buffer->out >= BUFFER_SIZE)
  	{

  		pthread_mutex_unlock(&buffer->lock);

  		pthread_mutex_lock(&buffer->lock);

  		bb_copy_msg(message,buffer->messages);

  		buffer->in++;

  	}
  
  	pthread_mutex_unlock(&buffer->lock);

}

/* Receive a message from a bounded buffer */
void bb_receive(struct bbuff *buffer, struct bb_msg * message) 
{

	pthread_mutex_lock(&buffer->lock);

  	while(buffer->in == buffer->out)
  	{

  		pthread_mutex_unlock(&buffer->lock);

  		pthread_mutex_lock(&buffer->lock);

  		bb_copy_msg(message,buffer->messages);

  		buffer->out++;

  	}

  	pthread_mutex_unlock(&buffer->lock);

}