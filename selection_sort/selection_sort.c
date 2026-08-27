/** This file contains the selection sort algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

typedef int (*ComparFunc)(void *a, void *b);
typedef unsigned char Byte;

int compar_char(void *a, void *b);
int compar_int(void *a, void *b);
Byte *find_smallest(void *first,
                    size_t member_size,
                    size_t array_len,
                    ComparFunc compar);
void *selection_sort(void *array,
                     size_t member_size,
                     size_t array_length,
                     ComparFunc compar);
void *drop_p(void *p);
void print_array(void *a, size_t member_size, size_t arr_len, char *conversion_spec);
void assert_p(void *p);

int main(void)
{
    char unsorted_char_list[] = {'J', 'F', 'G', 'O', 'K', 'E'};
    int unsorted_num_list[] = {8, 3, 4, 6, 2, 1, 9, 7, 5, 0};

    size_t mem_size = sizeof(char);
    size_t array_len = sizeof(unsorted_char_list) / mem_size;

    return 0;
}

Byte *find_smallest(void *array,
                    size_t member_size,
                    size_t array_len,
                    ComparFunc compar)
{
    Byte *first = (Byte *)array;
    Byte *smallest = first;
    Byte *last = first + (member_size * array_len);

    for (Byte *current = first + member_size;
         current < last;
         current += member_size)
    {

        int result = compar(smallest, current);
        if (result < 1)
            smallest = current;
        // printf("Smallest: %c, Current: %c\n", *(char *)smallest, *(char *)current);
    }
    return smallest;
}

int compar_char(void *a, void *b)
{
    char *smallest = (char *)a;
    char *current = (char *)b;
    if (*current < *smallest)
        return -1;
    else if (*current == *smallest)
        return 0;
    else
        return 1;
}
int compar_int(void *a, void *b)
{
    int *smallest = (int *)a;
    int *current = (int *)b;
    if (*current < *smallest)
        return -1;
    else if (*current == *smallest)
        return 0;
    else
        return 1;
}

void *drop_p(void *p)
{
    if (p != NULL)
    {

        free(p);
        p = NULL;
    }
    return p;
}

void print_array(void *a, size_t member_size, size_t arr_len, char *conversion_spec)
{
    Byte *end_p = a + member_size * arr_len;
    for (Byte *curr_p = a;
         curr_p < end_p;
         curr_p += member_size)
    {
        printf(conversion_spec, *curr_p);
    }
    printf("\n");
}

void assert_p(void *p)
{
    assert(p != NULL);
}
