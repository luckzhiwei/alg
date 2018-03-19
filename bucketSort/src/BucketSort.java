import java.util.ArrayList;
import java.util.Collections;

/**
 * Created by zhiwei on 2018/3/19.
 */
public class BucketSort {


    public void bucketSort(int[] nums) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[i]);
        }
        //分桶的思想
        int bucketNumber = ((max - min) / nums.length) + 1;

        ArrayList<ArrayList<Integer>> bucketArr = new ArrayList<>();
        for (int i = 0; i < bucketNumber; i++)
            bucketArr.add(new ArrayList<>());

        for (int i = 0; i < nums.length; i++) {
            int index = (nums[i] - min) / nums.length;
            bucketArr.get(index).add(nums[i]);
        }

        for (int i = 0; i < bucketNumber; i++) {
            Collections.sort(bucketArr.get(i));
        }

        int i = 0;
        for (ArrayList<Integer> oneBucket : bucketArr) {
            for (int number : oneBucket) {
                nums[i++] = number;
            }
        }
    }

    public static void main(String[] args) {
        BucketSort sorter = new BucketSort();
        int nums[] = {1, 3, 10, 5, 8};
        sorter.bucketSort(nums);
        for (int number : nums) {
            System.out.println(number);
        }
    }
}
