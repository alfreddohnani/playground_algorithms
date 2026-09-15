defmodule QuickSort do
  def sort(list) when length(list) < 2, do: list

  def sort([pivot | tail]) do
    less = for x <- tail, x <= pivot, do: x
    greater = for x <- tail, x > pivot, do: x

    sort(less) ++ [pivot | sort(greater)]
  end
end

unsorted_list = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] = QuickSort.sort(unsorted_list)

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
] = QuickSort.sort(unsorted_letters)
