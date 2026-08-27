defmodule SelectionSort do
  def find_smallest([]), do: nil

  def find_smallest([head | tail]) do
    do_find_smallest(tail, head)
  end

  defp do_find_smallest([], smallest), do: smallest

  defp do_find_smallest([element | tail], smallest) do
    new_smallest = if element < smallest, do: element, else: smallest
    do_find_smallest(tail, new_smallest)
  end

  def sort([]), do: []

  def sort(list) do
    do_sort(list, [])
  end

  defp do_sort([], sorted_list), do: Enum.reverse(sorted_list)

  defp do_sort(unsorted_list, sorted_list) do
    smallest = find_smallest(unsorted_list)
    unsorted_list = List.delete(unsorted_list, smallest)
    sorted_list = [smallest | sorted_list]
    do_sort(unsorted_list, sorted_list)
  end
end

unsorted_list = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] = SelectionSort.sort(unsorted_list)

unsorted_letters = [
  "c",
  "a",
  "j",
  "i",
  "r",
  "o",
  "i",
  "n",
  "a",
  "r",
  "e",
  "o",
  "i",
  "u"
]

[
  "a",
  "a",
  "c",
  "e",
  "i",
  "i",
  "i",
  "j",
  "n",
  "o",
  "o",
  "r",
  "r",
  "u"
] = SelectionSort.sort(unsorted_letters)
