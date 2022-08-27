import java.util.*;

public class Aug0827 {
}

class Solution61 { // 和最小的k个数对
    public static void main(String[] args) {
        int[] v1 = new int[]{1, 7, 11};
        int[] v2 = new int[]{2, 4, 6};
        int k = 3;
        List<List<Integer>> res = new Solution61().kSmallestPairs(v1, v2, k); // [1,2] [1,4] [1,6]
    }

    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        Queue<int[]> minHeap = new PriorityQueue<>((p1, p2) ->
                (nums1[p1[0]] + nums2[p1[1]]) - (nums1[p2[0]] + nums2[p2[1]]));

        for (int i = 0; i < Math.min(k, nums1.length); ++i) {
            minHeap.offer(new int[]{i, 0});
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < k && !minHeap.isEmpty(); ++i) {
            int[] ids = minHeap.poll();
            result.add(Arrays.asList(nums1[ids[0]], nums2[ids[1]]));

            if (ids[1] + 1 < nums2.length) {
                minHeap.offer(new int[]{ids[0], ids[1] + 1});
            }
        }
        return result;
    }
}


class Solution60 { // 出现频率最高的K个数字
    public static void main(String[] args) {
        int[] v = new int[]{1, 1, 1, 2, 2, 3};
        int k = 2;
        int[] result = new Solution60().topKFrequent(v, k); // [1, 2]
    }

    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> numToCount = new HashMap<>();
        for (int num : nums) {
            numToCount.put(num, numToCount.getOrDefault(num, 0) + 1);
        }

        Queue<Map.Entry<Integer, Integer>> minHeap = new PriorityQueue<>(
                (e1, e2) -> e1.getValue() - e2.getValue());

        for (Map.Entry<Integer, Integer> entry : numToCount.entrySet()) {
            if (minHeap.size() < k) {
                minHeap.offer(entry);
            } else if (entry.getValue() > minHeap.peek().getValue()) {
                minHeap.poll();
                minHeap.offer(entry);
            }
        }

        int i = 0;
        int[] result = new int[k];
        for (Map.Entry<Integer, Integer> entry : minHeap) {
            result[i++] = entry.getKey().intValue();
        }
        return result;
    }
}