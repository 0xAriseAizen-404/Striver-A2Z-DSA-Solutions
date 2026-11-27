9.1.1 - Check the i-th bit set or not -> n & (1 << i)
9.1.2 - check if n is odd or even -> n & 1
9.1.3 - check if n is power of 2 -> n & (n-1) == 0
9.1.4 - no. of set bits -> while (n) n & (n - 1), cnt++
9.1.5 - set the rightmost unset bit -> n | (n + 1)
9.1.6 - swap two numbers -> a = a ^ b, b = a ^ b, a = a ^ b

9.2.1 - min bits flips to convert -> required = num ^ target, count the set bits
9.2.2 - single number -> Xor of all numbers
9.2.3 - don't know
9.2.4 - don't know
9.2.5 - don't know
9.2.6 - Powerset - use maksed bits traversal
9.2.7 - xor of given range in 1 to n -> xor(l-1) ^ xor(r) -> (1 ^ 2 ^ 3) ^ (1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7) = xor of 4 to 7., mod = num % 4, mod == 0 -> num, 1 -> 1, 2 -> num + 1, 3 -> 0.