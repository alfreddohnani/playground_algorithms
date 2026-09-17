pub fn binary_search<T: Ord>(arr: &[T], item: &T) -> Option<usize> {
    let mut low = 0;
    let mut high = arr.len() - 1;

    while low <= high {
        let mid = low + (high - low) / 2;
        let guess = &arr[mid];
        if *guess == *item {
            return Some(mid);
        }
        if *item < *guess {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    None
}
