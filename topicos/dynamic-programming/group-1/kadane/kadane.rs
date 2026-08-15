pub fn kadane(nums: &[i32]) -> i32 {
    if nums.is_empty() {
        return 0;
    }

    let mut curr_max = nums[0];
    let mut global_max = nums[0];

    for &num in nums.iter().skip(1) {
        curr_max = num.max(curr_max + num);
        global_max = global_max.max(curr_max);
    }

    global_max
}