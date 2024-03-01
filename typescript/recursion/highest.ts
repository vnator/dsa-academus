export function highest(arr: number[], idx: number = 0, high: number = 0): number {
    high = arr[idx] > high
        ? arr[idx]
        : high;
    
    if (idx < arr.length) {

        return highest(arr, idx+1, high) 
    }


    return high;
}