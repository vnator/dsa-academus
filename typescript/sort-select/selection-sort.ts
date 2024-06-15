export function selectionSortNonDecress(arr: number[]): number[] {
  for (let i = 0; i < arr.length - 2; i++) {
    let lessN = [arr[i + 1], i + 1];
    for (let j = i + 2; j < arr.length; j++) {
      if (arr[j] < lessN[0]) lessN = [arr[j], j];
    }

    if (lessN[0] < arr[i]) {
      const reserv = arr[i];
      arr[i] = lessN[0];
      arr[lessN[1]] = reserv;
    }
  }

  return arr;
}

