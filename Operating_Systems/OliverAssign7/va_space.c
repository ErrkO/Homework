/* Nicholas Coleman
 * CSCI 4100
 * Assignment 7
 * Source file for virtual address space simulation
 */

#include "va_space.h"
#include <stdio.h>

/* Error codes */
const int ERR_PAGE_NOT_ALLOCATED = -1;
const int ERR_PAGE_NOT_PRESENT = -2;
const int ERR_PERMISSION_DENIED = -3;

/* Bits for page table entries */
const pt_bits PT_ALLOC = 0x80, PT_DIRTY = 0x40, PT_ACCESSED = 0x20, PT_PRESENT = 0x10,
    PT_KERNEL = 0x08, PT_READ = 0x04, PT_WRITE = 0x02, PT_EXECUTE = 0x01;

/* Initialize an empty page table */
void pt_init(page_table table) 
{

    for (int i=0;i<PT_SIZE;i++)
    {

        table[i]=0;

    }

}

/* Add a page table entry */
void pt_map(page_table table, pt_index page_num, pt_index frame_num, pt_bits perm_page) 
{

    table[page_num] = frame_num;
    table[page_num] = table[page_num] << 8;
    table[page_num] = table[page_num] | perm_page;
    table[page_num] = table[page_num] | PT_ALLOC;
    table[page_num] = table[page_num] | PT_PRESENT;

}

/* Remove a page table entry */
void pt_unmap(page_table table, pt_index page_num) 
{

    table[page_num] = 0;

}

/* Set and clear bits */
void pt_set_dirty(page_table table, pt_index page_num)
{

    table[page_num] = table[page_num] | PT_DIRTY;

}

void pt_set_accessed(page_table table, pt_index page_num)
{

    table[page_num] = table[page_num] | PT_ACCESSED;

}

void pt_set_present(page_table table, pt_index page_num)
{

    table[page_num] = table[page_num] | PT_PRESENT;

}

void pt_clear_dirty(page_table table, pt_index page_num)
{

    table[page_num] = table[page_num] & ~ PT_DIRTY;

}

void pt_clear_accessed(page_table table, pt_index page_num)
{

    table[page_num] = table[page_num] & ~ PT_ACCESSED;

}

void pt_clear_present(page_table table, pt_index page_num)
{

    table[page_num] = table[page_num] & ~ PT_PRESENT;

}

/* Test bits */
int pt_allocated(page_table table, pt_index page_num) 
{

    if (table[page_num] & (0x0000 | PT_ALLOC) == PT_ALLOC)
    {

        return 1;

    }

    return 0;

}

int pt_dirty(page_table table, pt_index page_num) 
{

    if (table[page_num] & (0x0000 | PT_DIRTY) == PT_DIRTY)
    {

        return 1;

    }

    return 0;

}

int pt_accessed(page_table table, pt_index page_num) 
{

    if (table[page_num] & (0x0000 | PT_ACCESSED) == PT_ACCESSED)
    {

        return 1;

    }

    return 0;

}

int pt_present(page_table table, pt_index page_num) 
{

    if (table[page_num] & (0x0000 | PT_PRESENT) == PT_PRESENT)
    {

        return 1;

    }

    return 0;

}

/* Test permissions */
int pt_not_permitted(page_table table, pt_index page_num, pt_bits perm_needed) 
{

    if (table[page_num] & (0x0000 | perm_needed) == perm_needed)
    {

        return 0;

    }

    return 1;

}

/* Translate a virtual address to a physical address */
int pt_translate(page_table table, pt_address virtual_address, pt_bits perm_needed) 
{

    int page_num, offset;

    pt_entry physcal_address;

    page_num = virtual_address >> 8;

    offset = virtual_address & 0x00ff;

    if (pt_not_permitted(table,page_num,perm_needed) == 1)
    {

        return ERR_PERMISSION_DENIED;

    }

    else if (pt_present(table,page_num) == 0)
    {

        return ERR_PAGE_NOT_PRESENT;
    
    }

    else if (pt_allocated(table,page_num) == 0)
    {

        return ERR_PAGE_NOT_ALLOCATED;

    }

    else
    {

        physcal_address = table[page_num] & 0xff00;

        physcal_address = physcal_address & offset;

        return physcal_address;

    }

}

/* Display page table */
void pt_display(page_table table) 
{

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
        printf("%04x  ", table[row * 16 + col]);
        puts("");
    
    }

}

/* Display page table entry */
void pt_display_entry(page_table table, pt_index page_num) 
{

    printf("%02x: 0x%04x\n", page_num, table[page_num]);

}

/* Display address */
void pt_display_address(const char *label, pt_address address) 
{

    printf("%s: 0x%04x\n", label, address);

}


