export function bubbleSortNonDecress(arr: number[]): number[] {
    let k = arr.length-2;

    while (k) {
        let i = 0;

        for (let k = 1; k < arr.length; k++) {
            if (arr[i] > arr[k]) {
                let reserv = arr[k]
                arr[k] = arr[i]
                arr[i] = reserv
                i++;
            }
        }
    
        k--;
    }

    return arr
}