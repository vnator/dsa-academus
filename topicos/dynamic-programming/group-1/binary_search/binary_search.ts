 export function binarySearch(nums: number[], x: number): number {
    let left = 0;
    let right = nums.length-1;

    let mid = Math.round(right/2);

    while (left <= right) {
        let mid = Math.round(left+(right-right) >>> 1);

        if (nums[mid] == x) return mid;
        
        if (nums[mid] > x) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
}