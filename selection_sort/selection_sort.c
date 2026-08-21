/** This file contains the selection sort algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

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

int main(void)
{
    char unsorted_char_list[] = {'J', 'F', 'G', 'O', 'K', 'E'};
    int unsorted_num_list[] = {8, 3, 4, 6, 2, 1, 9, 7, 5, 0};

    // size_t mem_size = sizeof(char);
    // size_t array_len = sizeof(unsorted_char_list) / mem_size;

    // char *sorted_char_list = selection_sort(unsorted_char_list, mem_size, array_len, compar);

    // printf("Sorted list: \n");
    // for (char *current = sorted_char_list;
    //      current <= (current + (mem_size * array_len));
    //      current += mem_size)
    // {
    //     printf("%c ", *current);
    // }
    // printf("\n");

    // char *smallest_char = (char *)find_smallest(
    //     unsorted_char_list,
    //     sizeof(char),
    //     sizeof(unsorted_char_list) / sizeof(char),
    //     compar_char);

    // printf("Smallest is: %c\n", *smallest_char);
    // assert(*smallest_char == 'E');

    int *smallest_num = (int *)find_smallest(
        unsorted_num_list,
        sizeof(int),
        sizeof(unsorted_num_list) / sizeof(int),
        compar_int);
    printf("Smallest num: %d\n", *smallest_num);
    assert(*smallest_num == 0);

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

void *selection_sort(void *array,
                     size_t member_size,
                     size_t array_length,
                     ComparFunc compar)
{

    void *sorted_list = malloc(member_size * array_length);
    assert(sorted_list != NULL);
    void *current_sorted_mem = sorted_list;

    // push everything into unsorted list first; this will
    // then be reduced to the next unsorted elements after each
    // find_smallest iteration
    size_t unsorted_list_rem = array_length;
    size_t unsorted_list_rem_size = member_size * unsorted_list_rem;
    void *unsorted_list = malloc(unsorted_list_rem_size);
    assert(unsorted_list != NULL);
    memcpy(unsorted_list, array, unsorted_list_rem_size);

    while (unsorted_list_rem != 0)
    {

        void *smallest = find_smallest(unsorted_list,
                                       member_size,
                                       unsorted_list_rem,
                                       compar);

        // put smallest into sorted_list
        memcpy(current_sorted_mem, smallest, member_size);
        current_sorted_mem += member_size;

        // push everything into unsorted array except smallest
        unsorted_list_rem -= 1;
        unsorted_list_rem_size = member_size * unsorted_list_rem;

        void *temp_unsorted_list = malloc(unsorted_list_rem_size);
        assert(temp_unsorted_list != NULL);

        for (void *current = unsorted_list;
             current <= (current + unsorted_list_rem_size);
             current += member_size)
            if (current != smallest)
                memcpy(temp_unsorted_list, current, member_size);

        // free current unsorted list memory
        free(unsorted_list);
        unsorted_list = NULL;

        // temp_unsorted_list is the new unsorted_list
        unsorted_list = temp_unsorted_list;
    }
    // free the last memory of unsorted_list
    free(unsorted_list);
    unsorted_list = NULL;

    return sorted_list;
}
