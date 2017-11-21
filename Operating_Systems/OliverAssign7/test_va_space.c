/* Eric Oliver
 * CSCI 4100
 * Assignment 7
 * Source file for virtual address space simulation
 */

#include "va_space.h"
#include <stdio.h>

 void InttoBool(int num);

int main(int argc, char *argv[])
{

	/* Variable delcarations */
	pt_bits c0,c1,c2,c4,c8,c16,c32,c64,c128,c256;

	pt_index page_num, frame_num;

	pt_entry virtual_address,physical_address;

	int address[PT_SIZE];

	int flag, permneeded;

	permneeded = PT_READ | PT_WRITE;

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

	/* setting up the table */
	pt_init(table);

	pt_display(table);

	/* Mapping our test entries */
	pt_map(table,0,20,permneeded);

	pt_map(table,1,12,permneeded);

	pt_map(table,2,30,permneeded);

	pt_display_entry(table,0);

	pt_display_entry(table,1);

	pt_display_entry(table,2);

	puts("");



	puts("Testing for dirty bit");

	InttoBool(pt_dirty(table,0));

	flag = pt_dirty(table,0);

	printf("flag = %01x \n", flag);

	puts("Setting the dirty bit");

	pt_set_dirty(table,0);

	pt_display_entry(table,0);

	puts("Testing for dirty bit");

	flag = pt_dirty(table,0);

	printf("flag = %01x \n", flag);

	InttoBool(pt_dirty(table,0));

	puts("Clearing the dirty bit");

	pt_clear_dirty(table,0);

	pt_display_entry(table,0);

	puts("");



	puts("Testing for accessed bit");

	InttoBool(pt_accessed(table,1));

	puts("Setting the accessed bit");

	pt_set_accessed(table,1);

	pt_display_entry(table,1);

	puts("Testing for accessed bit");

	InttoBool(pt_accessed(table,1));

	puts("Clearing the accessed bit");

	pt_clear_accessed(table,1);

	pt_display_entry(table,1);

	puts("");



	puts("Testing for present bit");

	InttoBool(pt_present(table,2));

	puts("Setting present bit");

	pt_set_present(table,2);

	pt_display_entry(table,2);

	puts("Testing for present bit");

	InttoBool(pt_present(table,2));

	puts("Clearing the present bit");

	pt_clear_present(table,2);

	pt_display_entry(table,2);

	puts("");



	puts("Testing for allocated bit");

	InttoBool(pt_allocated(table,0));

	puts("");


	puts("Testing the translate function");

	virtual_address = 0x0021;

	pt_display_address("virtual address",virtual_address);

	physical_address = pt_translate(table,virtual_address,permneeded);

	pt_display_address("Physical Address",physical_address);

	puts("");



	puts("Testing the unmap function");

	pt_display_entry(table,1);

	pt_unmap(table,1);

	pt_display_entry(table,1);

	return 0;

}

void InttoBool(int num)
{

	if (num > 0)
	{

		puts("True");

	}

	else if (num == -1)
	{

		puts("Error");

	}

	else if (num == -1)
	{

		puts("Error");

	}

	else if (num == -1)
	{

		puts("Error");

	}

	else
	{

		puts("False");

	}

}