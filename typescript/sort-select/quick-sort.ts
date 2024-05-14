export function quickSort(arr: number[]): number[] {
  if (arr.length <= 1) return arr;

  const pivot = arr[0];
  const less: number[] = [];
  const high: number[] = [];

  for (let i = 1; i < arr.length; i++) {
    if (arr[i] < pivot) {
      less.push(arr[i]);
    } else {
      high.push(arr[i]);
    }
  }

  return [...quickSort(less), pivot, ...quickSort(high)];
}
