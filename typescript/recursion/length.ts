export function length(arr: number[], idx: number = 0): number {
    if (typeof arr[idx] == 'number') return length(arr, idx+1)
    return idx;
}