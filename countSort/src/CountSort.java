/**
 * Created by zhiwei on 2018/3/19.
 */
public class CountSort {


    public void countSort(int nums[]) {
        int B[] = new int[nums.length];
        int max = Integer.MIN_VALUE;
        for (int number : nums) {
            max = Math.max(max, number);
        }
        int C[] = new int[max + 1];
        for (int number : nums) {
            C[number] += 1;
        }
        for (int i = 1; i < C.length; i++) {
            C[i] += C[i - 1];
        }
        for (int number : nums) {
            int pos = --C[number];
            B[pos] = number;
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = B[i];
        }
    }

    public static void main(String[] args) {
        CountSort sorter = new CountSort();
        int nums[] = {2, 5, 3, 0, 2, 3, 0, 3};
        sorter.countSort(nums);
        for (int numbers : nums) {
            System.out.println(numbers);
        }
    }


}
