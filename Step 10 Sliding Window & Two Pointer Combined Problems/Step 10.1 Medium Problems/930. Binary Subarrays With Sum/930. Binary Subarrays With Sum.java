class Solution {
    public int numSubarraysWithSum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int sum = 0;
        int count = 0;
        for(int x: nums) {
            sum += x;
            if(sum==k)  count++;
            if(map.containsKey(sum-k)){
                count+= map.get(sum-k);
            }
            map.put(sum,map.getOrDefault(sum,0)+1);
        }
        return count;
    }
}