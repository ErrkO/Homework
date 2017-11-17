/* Eric Oliver
 * CSCI 4100
 * Assignment 7
 * Source file for virtual address space simulation
 */

#include "va_space.h"
#include <stdio.h>

int main(int argc, char *argv[])
{

	pt_bits c0,c1,c2,c4,c8,c16,c32,c64,c128,c256;

	pt_index page_num, frame_num;

	pt_entry virtual_address,physical_address;

	int address[PT_SIZE];

	c0 = 0b000000000;
	c1 = 0b000000001;
	c2 = 0b00000010;
	c4 = 0b00000100;
	c8 = 0b00001000;
	c16 = 0b00010000;
	c32 = 0b00100000;
	c64 = 0b01000000;
	c128 = 0b10000000;
	c256 = 0b11111111;

	page_table table;

	pt_init(table);

	pt_display(table);

	for (int i = 0; i < PT_SIZE; i++)
	{

		if (i < 20)
		{

			pt_map(table,i,i,c0);

		}

		else if (i < 40)
		{

			pt_map(table,i,i,c1);

		}

		else if (i < 60)
		{

			pt_map(table,i,i,c2);

		}

		else if (i < 80)
		{

			pt_map(table,i,i,c4);

		}

		else if (i < 100)
		{

			pt_map(table,i,i,c8);

		}

		else if (i < 120)
		{

			pt_map(table,i,i,c16);

		}

		else if (i < 140)
		{

			pt_map(table,i,i,c32);

		}

		else if (i < 160)
		{

			pt_map(table,i,i,c64);

		}

		else if (i < 180)
		{

			pt_map(table,i,i,c128);

		}

		else
		{

			pt_map(table,i,i,c256);

		}

		

	}

	int row, col;
    const int ROWS = 16, COLS = 16;
    printf("   ");
    for(col = 0; col < COLS; col++)
        printf(" %x    ", col);
    puts("");
    for(row = 0; row < ROWS; row++) 
    {



        printf("%x  ", row);
        for(col = 0; col < COLS; col++)
        printf("%16x  ", pt_display_address(table[row * 16 + col]);
        puts("");
    
    }

	pt_display(table);

}