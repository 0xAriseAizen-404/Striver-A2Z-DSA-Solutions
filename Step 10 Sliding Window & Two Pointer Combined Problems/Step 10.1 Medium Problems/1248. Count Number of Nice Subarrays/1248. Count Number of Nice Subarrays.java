import java.util.HashMap;

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int oddCount = 0;
        int resCount = 0;
        for (int x : nums) {
            if ((x & 1) == 1)
                oddCount++;
            if (oddCount == k)
                resCount++;
            if (map.containsKey(oddCount - k)) {
                resCount += map.get(oddCount - k);
            }
            map.put(oddCount, map.getOrDefault(oddCount, 0) + 1);
        }
        return resCount;
    }
}