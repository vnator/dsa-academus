export function binarySearch(
    arr: number[],
    target: number,
    start: number = 0,
    end: number = 0
): number {
    if (end < start) return -1;

    end = end ? end : arr.length-1;    

    let middle = start == end
        ? start
        : Math.floor((start+end)/2);
    
    let midVal = arr[middle]
    
    if (midVal != target) {
        if (midVal < target) start = middle+1
        else end = middle-1
        
        middle = binarySearch(arr, target, start, end)
    }

    return middle;
}