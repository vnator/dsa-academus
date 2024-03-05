export function quickSort(arr: number[]): number[] {
    if (arr.length <= 1) return arr
    
    let pivot = arr[0];
    let less: number[] = [];
    let high: number[] = [];

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < pivot) {
            less.push(arr[i]);
        } else {
            high.push(arr[i]);
        }
    }

    return [...quickSort(less), pivot, ...quickSort(high)] 
}

export function quickSortPartition(arr: number[]): number[] {
    return arr;
}