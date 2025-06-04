# [Lexicographic rank of a String](https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/)

1.   [Naive Approach] Generating all permutations
Execute [ex_01.cpp](ex_01.cpp)
Time Complexity: O(n!), for generating all permutations
Auxiliary Space: O(n)

2.  Count Smaller Strings - O(n^3) Time
Execute [ex_02.cpp](ex_02.cpp)
Time Complexity : O(n^3)
Auxiliary Space : O(1)

3.  Optimized Approach - Reducing Repeated Computations - O(n^2) Time
Execute [ex_03.cpp](ex_03.cpp)
Time Complexity: O(n2)
Auxiliary Space: O(1)

4.  Further Optimized - Using Frequency Array - O(n) Time
Execute [ex_04.cpp](ex_04.cpp)
Time Complexity: O(n)
Auxiliary Space: O(1) as we are using an array of size 256