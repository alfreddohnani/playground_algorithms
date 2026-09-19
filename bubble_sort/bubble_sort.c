#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum ordering { LESS = -1, EQUAL = 0, GREATER = 1 } ordering;
typedef ordering (*cmp_func)(const void* a, const void* b);

void* bubble_sort(void* arr, const size_t elem_size, const size_t arr_len,
                  cmp_func cmp) {

  size_t unsorted_until_index = arr_len - 1;
  bool sorted = false;

  const char* start = (const char*)arr;

  while (!sorted) {
    sorted = true;

    for (size_t left_index = 0; left_index < unsorted_until_index;
         left_index++) {
      const void* left_ptr = start + (left_index * elem_size);
      const void* right_ptr = left_ptr + elem_size;
      if (cmp(left_ptr, right_ptr) == GREATER) {

        void* tmp_right_object =
            malloc(elem_size); // allocate temporary buffer to keep the
                               // right element object.
        if (tmp_right_object == NULL) {
          printf("Out of memory!\n");
          exit(EXIT_FAILURE);
        }

        memcpy(tmp_right_object, right_ptr,
               elem_size); // copy right element object to temporary buffer

        // swap values
        memcpy((void*)right_ptr, left_ptr, elem_size);
        memcpy((void*)left_ptr, tmp_right_object, elem_size);

        free(tmp_right_object);

        sorted = false;
      }
    }

    if (unsorted_until_index > 0) {
      unsorted_until_index -= 1;
    }
  }

  return arr;
}

ordering cmp_int(const void* a, const void* b) {
  const int int_a = *(int*)a;
  const int int_b = *(int*)b;

  if (int_a > int_b) {
    return GREATER;
  } else if (int_a < int_b) {
    return LESS;
  } else {
    return EQUAL;
  }
}

ordering cmp_char(const void* a, const void* b) {
  const char char_a = *(char*)a;
  const char char_b = *(char*)b;

  if (char_a > char_b) {
    return GREATER;
  } else if (char_a < char_b) {
    return LESS;
  } else {
    return EQUAL;
  }
}

int main(void) {

  int int_arr[] = {65, 55, 45, 35, 25, 15, 10};
  int arr_len = sizeof(int_arr) / sizeof(int);

  bubble_sort(int_arr, sizeof(int), arr_len, cmp_int);

  printf("[");
  for (int i = 0; i < arr_len; i++) {
    printf("%d,", int_arr[i]);
  }
  printf("]\n");

  assert(int_arr[0] == 10);
  assert(int_arr[1] == 15);
  assert(int_arr[2] == 25);
  assert(int_arr[3] == 35);
  assert(int_arr[4] == 45);
  assert(int_arr[5] == 55);
  assert(int_arr[6] == 65);

  return EXIT_SUCCESS;
}
