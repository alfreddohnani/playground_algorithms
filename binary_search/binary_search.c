/** Binary Search */

#include <stdio.h>

#define SEARCH_SPACE (const char[]){'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'} // Search space
#define ITEM 'F'

#define LEN(arr, mem) (sizeof(arr) / sizeof(mem)) // Gets length of an array

int binary_search(const char arr[], char item, int arr_len);

int main(void)
{
    int result = binary_search(SEARCH_SPACE, ITEM, LEN(SEARCH_SPACE, char));
    if (result == -1)
        printf("Item not found\n");
    else if (SEARCH_SPACE[result] == ITEM)
        printf("Item found at index: %d\n", result);
    else
        printf("Item found at index: %d but does not equal item\n", result);
    return 0;
}

int binary_search(const char arr[], char item, int arr_len)
{
    int low = 0, high = arr_len - 1, mid;
    char guess;

    while (low <= high)
    {
        mid = (low + high) / 2;
        guess = arr[mid];
        if (guess == item)
            return mid;
        else if (item < guess)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
