function bubble_sort(list) {
  let unsorted_until_index = list.length - 1;
  let sorted = false;

  while (!sorted) {
    sorted = true;
    for (let left_index = 0; left_index < unsorted_until_index; left_index++) {
      const left_value = list[left_index];
      const right_value = list[left_index + 1];

      if (left_value > right_value) {
        list[left_index + 1] = left_value;
        list[left_index] = right_value;
        sorted = false;
      }
    }
    if (unsorted_until_index > 0) {
      unsorted_until_index -= 1;
    }
  }

  return list;
}

const sorted_list = bubble_sort([65, 55, 45, 35, 25, 15, 10]);

console.log(`sorted list: ${sorted_list}`);
[10, 15, 25, 35, 45, 55, 65].forEach((v, i) => {
  console.assert(v == sorted_list[i]);
});
