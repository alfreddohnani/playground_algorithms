function findSmallest(arr = []) {
  let smallestTuple = [arr.at(0), 0];
  for (let i = 1; i < arr.length; i++) {
    const element = arr.at(i);
    if (element < smallestTuple[0]) {
      smallestTuple = [element, i];
    }
  }

  return smallestTuple;
}

function selectionSort(arr = []) {
  let arrClone = arr.slice();
  let arrSorted = [];
  while (arrClone.length > 0) {
    const [smallest, index] = findSmallest(arrClone);
    arrSorted.push(smallest);
    arrClone.splice(index, 1);
  }
  return arrSorted;
}

const arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
const letters = [
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
  "u",
];
const sortedList = selectionSort(arr);

console.assert(findSmallest(arr).at(0) == 1, "Smallest == 1");
console.assert(findSmallest(arr).at(1) == 9, "Smallest index == 9");

console.assert(sortedList[0] == 1, "Sorted list [0] == 1");
console.assert(sortedList[1] == 2, "Sorted list [1] == 2");
console.assert(sortedList[9] == 10, "Sorted list [9] == 10");
console.log("Sorted list", sortedList);
const sortedLetters = selectionSort(letters);
console.assert(sortedLetters.at(0) == "a", "Sorted letters [0] == a");
console.assert(
  sortedLetters.at(letters.length - 1) == "u",
  "Sorted letters [last] == u",
);
console.log("Sorted letters", sortedLetters);
