defmodule BubbleSort do
  def sort(list) when is_tuple(list) and tuple_size(list) < 2, do: list

  def sort(list) when is_tuple(list) do
    unsorted_until_index = tuple_size(list) - 1
    sorted = false

    do_sort(list, sorted, unsorted_until_index)
  end

  defp do_sort(list, true, _), do: list
  defp do_sort(list, _sorted, unsorted_until_index) when unsorted_until_index <= 0, do: list

  defp do_sort(list, _sorted, unsorted_until_index) do
    {sorted_partially, sorted} =
      Enum.reduce(
        0..(unsorted_until_index - 1),
        {list, true},
        fn left_index, {current_list, sorted_flag} ->
          left_value = elem(current_list, left_index)
          right_value = elem(current_list, left_index + 1)

          if left_value > right_value do
            sorted_partially =
              current_list
              |> put_elem(left_index + 1, left_value)
              |> put_elem(left_index, right_value)

            {sorted_partially, false}
          else
            {current_list, sorted_flag}
          end
        end
      )

    do_sort(
      sorted_partially,
      sorted,
      unsorted_until_index - 1
    )
  end
end

sorted_list = BubbleSort.sort({65, 55, 45, 35, 25, 15, 10})
IO.puts("sorted list: #{inspect(sorted_list)}")
{10, 15, 25, 35, 45, 55, 65} = sorted_list
