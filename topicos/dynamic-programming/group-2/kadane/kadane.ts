export function kadake(nums: number[]) {
    if (!nums.length) return 0;


    let currMax = nums[0];
    let globalMax = nums[0];

    for (let i = 1; i < nums.length; i++) {
        currMax = Math.max(nums[i], currMax+nums[i])
        
        if (currMax > globalMax) {
            globalMax = currMax;
        }
    }

    return globalMax;
}