export function insertionSortNonDecress(arr: number[]): number[] {
    let i, j;
    for (i = 1; i < arr.length; i++) {
        let val = arr[i];

        for (j=i; j > 0 && (val < arr[j-1]); j--) {
            arr[j] = arr[j-1]
        }

        arr[j] = val
    }


    return arr;
}