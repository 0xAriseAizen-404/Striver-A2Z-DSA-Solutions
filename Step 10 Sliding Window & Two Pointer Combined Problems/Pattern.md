10.1.1 - maximum points you can obtain from cards -> first get the left sum of K size, then traverse from end while adding like rightsum + num[sz - i] and leftsum - num[k - i], then check the max_sum, left+right

10.2.1 - longest subtring without repeating characters -> if (freq[s[right]] >= left) left = freq[s[right]] + 1;
// checking if I have seen it or not, if I have not seen it then it will be like -1 >= leftInd (wrong).
// If I seen it, then previousIndOfRight >= leftInd (right), then leftInd = previousIndOfRight + 1;
10.2.2 - maximum consective ones -> Traverse the list, keep a count of zeroes, if the limit is crossed, move left, compare max_len at every iteration
10.2.3 - Fruit into Baskets ->
10.2.4 - Longest substring with atmost k distinct chars -> keep a freq of chars, only increase count when you are first time considering, while (cnt > k) move left, if it becomes zero freq, then decrease cnt. compare max_len at every iteration
10.2.5 - longest repeating char replacement -> get max_freq, if len - max_freq > k, move left and decrase its freq, compare max_len at every iteration.
10.2.6 - Minimum Window Substring -> First have a hash_freq of string t, then get the required = t.length(), while traverse string s, if the char is in t hash_freq, reduce required cnt, while (required == 0) compare len, min_len and startInd = left; move left.
10.2.7 - Minimum Window Subsequence ->

10.3.1 -> no. of substring containing all three chars -> get lastseen of A, B, C. then get minIndex of three of them. then get cnt += (minInd + 1) -> len of the substring == that many number of substrings
10.3.2 -> binary subarrays with sum -> helper(goal) - helper(goal - 1); cnt += (right - left + 1)
10.3.3 -> count no. of nice subarrays -> helper(k) - helper(k - 1); cnt += (right - left + 1)
10.3.4 -> subarrays with k different integers -> helper(k) - helper(k - 1); cnt += (right - left + 1)

Sliding Window & Two Pointers -> Patterns need to focus on ->

1. Two Pointers + Sliding Window
2. Freq & Indexes & Cnt while traversing
3. helper(k) - helper(k-1); cnt += (right - left + 1)
