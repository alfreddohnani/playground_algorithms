mod binary_search;
use crate::binary_search::binary_search;

// use crate::binary_search as bs;

fn main() {
    let int_arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
    let char_arr = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'];

    let int_item = 7;
    match binary_search(&int_arr, &int_item) {
        Some(index) => {
            assert_eq!(index, 6);
            println!("Item {} found at index {index}", int_arr[index]);
        }
        None => println!("Int item not found"),
    }

    let char_item = 'f';
    match binary_search(&char_arr, &char_item) {
        Some(index) => {
            assert_eq!(index, 5);
            println!("Item {} found at index {index}", char_arr[index]);
        }
        None => println!("Char item not found"),
    }
}
