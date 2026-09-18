mod binary_search;
mod bubble_sort;

use crate::binary_search::binary_search;
use crate::bubble_sort::bubble_sort;

// use crate::binary_search as bs;

fn main() {
    /*BINARY SEARCH */
    let int_arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
    let char_arr = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'];

    let int_item = 7;
    match binary_search(&int_arr, &int_item) {
        Some(index) => {
            assert_eq!(index, 6);
            println!(
                "(binary search) Item {} found at index {index}",
                int_arr[index]
            );
        }
        None => println!("(binary search) Int item not found"),
    }

    let char_item = 'f';
    match binary_search(&char_arr, &char_item) {
        Some(index) => {
            assert_eq!(index, 5);
            println!(
                "(binary search) Item {} found at index {index}",
                char_arr[index]
            );
        }
        None => println!("(binary search) Char item not found"),
    }

    /*BUBBLE SORT */
    let mut unsorted_list = [65, 55, 45, 35, 25, 15, 10];
    let sorted_list = bubble_sort(&mut unsorted_list);

    assert_eq!(sorted_list[0], 10);
    assert_eq!(sorted_list[1], 15);
    assert_eq!(sorted_list[2], 25);
    assert_eq!(sorted_list[3], 35);
    assert_eq!(sorted_list[4], 45);
    assert_eq!(sorted_list[5], 55);
    assert_eq!(sorted_list[6], 65);
    println!("(bubble sort) Sorted list: {sorted_list:?}");
}
