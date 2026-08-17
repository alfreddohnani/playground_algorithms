defmodule Algorithms do
  def binary_search(tup, item) do
    low = 0
    high = tuple_size(tup) - 1
    _mid = do_search(tup, item, low, high)
  end

  defp do_search(_tup, _item, :found, mid), do: mid
  defp do_search(_tup, _item, low, high) when low > high, do: -1

  defp do_search(tup, item, low, high) when low <= high do
    mid = div(low + high, 2)
    guess = elem(tup, mid)

    {low, mid} =
      cond do
        guess == item -> {:found, mid}
        item < guess -> {low, mid - 1}
        item > guess -> {mid + 1, high}
      end

    do_search(tup, item, low, mid)
  end
end
