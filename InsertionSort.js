function InsertionSort(Arr){
  let length = Arr.length;

  for (let i = 1; i < length; i++) {
    let temp = Arr[i];
    let j = i - 1;
    while (j >= 0 && Arr[j] > temp) {
      Arr[j + 1] = Arr[j];
      j = j - 1;
    }
    Arr[j + 1] = temp;
  }
  return Arr;
}

var Arr = [2, 5, 3, 10, 11, 2, 1, 1, 125, 5, 7, 10];
console.log(InsertionSort(Arr));