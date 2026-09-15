/** Binary Search */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SEARCH_SPACE                                                           \
  (const char[]){'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}             \
  // Search space

#define LEN(arr) (sizeof(arr) / sizeof(arr[0])) // Gets length of an array

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef u_int8_t u8;
typedef u_int16_t u16;
typedef u_int32_t u32;
typedef u_int64_t u64;

// N.B Array must be ordered
int generic_binary_search(i32 arr_len, const void* arr, size_t elem_size,
                          const void* item,
                          i32 (*cmp)(const void* a, const void* b)) {
  i64 low = 0, high = arr_len - 1, mid;
  const char* start = (const char*)arr;

  while (low <= high) {
    mid = (low + high) / 2;
    const void* guess_ptr = start + (elem_size * mid);

    i64 result = cmp(item, guess_ptr);
    if (result == 0) {
      return mid;
    } else if (result < 0) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

i32 cmp_int(const void* a, const void* b) {
  const int* int_a = (int*)a;
  const int* int_b = (int*)b;
  return *int_a - *int_b;
}

i32 cmp_char(const void* a, const void* b) {
  const char* char_a = (char*)a;
  const char* char_b = (char*)b;
  return *char_a - *char_b;
}

int main(void) {
  const char char_arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  const char char_item = 'F';

  i32 char_result = generic_binary_search(
      LEN(char_arr), char_arr, sizeof(char_arr[0]), &char_item, cmp_char);

  if (char_result == -1)
    printf("Item not found\n");
  else if (char_arr[char_result] == char_item)
    printf("Item: %c found at index: %d\n", char_arr[char_result], char_result);
  else
    printf("Item found at index: %d but does not equal item\n", char_result);

  const i32 int_arr[] = {0, 1, 2, 3, 5, 7, 8, 9};
  const i32 int_item = 9;

  i32 int_result = generic_binary_search(
      LEN(int_arr), int_arr, sizeof(int_arr[0]), &int_item, cmp_int);

  if (int_result == -1)
    printf("Item not found\n");
  else if (int_arr[int_result] == int_item)
    printf("Item: %d found at index: %d\n", int_arr[int_result], int_result);
  else
    printf("Item found at index: %d but does not equal item\n", int_result);

  return EXIT_SUCCESS;
}
