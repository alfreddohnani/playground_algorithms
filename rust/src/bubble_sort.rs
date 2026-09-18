pub fn bubble_sort<T: Ord>(list: &mut [T]) -> &[T] {
    if list.len() < 2 {
        return list;
    }
    let mut unsorted_until_index = list.len() - 1;
    let mut sorted = false;

    while !sorted {
        sorted = true; // assume list is sorted until otherwise indicated

        for left_index in 0..unsorted_until_index {
            //range is upperbound exclusive(i.e 0..N -> exclusive range; 0..=N -> inclusive range)
            if list[left_index] > list[left_index + 1] {
                list.swap(left_index, left_index + 1); //indexing borrows the entire container(list), not just the individual slot, hence this approach

                sorted = false; // we indicate here that we made at least one swap during this pass-through so we need to conduct another one
            }
        }
        if unsorted_until_index > 0 {
            unsorted_until_index -= 1;
        }
    }

    list
}
