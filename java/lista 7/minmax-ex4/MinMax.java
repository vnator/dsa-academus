public class MinMax {
  public static void main (String[] args) {
    int[] nums = { 99, -10, 100, 19, 977, -562, 463, -9, 287, 49 };
    int min, max;
    min = max = nums[0];
    
    for(int num : nums) {
      if(num < min)
        min = num;
      if(num > max)
        max = num;
    }
    
    System.out.println("Min e Max: " + min + " " + max);
  }
}
