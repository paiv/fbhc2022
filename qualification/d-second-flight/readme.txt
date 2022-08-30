Note: This problem has large input, so we recommend pre-downloading the
compressed zip file.

Meta Getaways is a travel agency that deals with N airports numbered 1...N, and
M flight paths. Flight path i connects airports A_i and B_i in both directions,
with two direct flights operating every morning (one in each direction), and
another two every evening (also one in each direction). Each of these four
direct flights can carry up to C_i tourists.

The first sample case is depicted above, with morning and evening flights in red
and blue.

Peak travel season is here, and will last Q days. For each day i, determine F_i,
the maximum number of tourists who could possibly fly from airport X_i to Y_i.
Each tourist may either fly directly or take one morning and one evening flight
which share an intermediate airport.

Constraints

1 ≤ T ≤ 70
1 ≤ N,M,Q ≤ 200,000
1 ≤ C_i ≤ 10^9
1 ≤ A_i,B_i ≤ N; A_i ≠ B_i
1 ≤ X_i,Y_i ≤ N; X_i ≠ Y_i

All unordered pairs (A_i, B_i) within a given test case are distinct.
The sum of Q across all test cases is at most 5,000,000.

Input Format

Input begins with a single integer T, the number of test cases. For each case,
there is first a line containing three space-separated integers N, M, and Q.
Then, M lines follow, the ith of which contains three space-separated integers
A_i, B_i, and C_i. Then, Q lines follow, the ith of which contains two
space-separated integers X_i and Y_i.

Output Format

For the ith case, print a line containing "Case #i: " followed by Q
space-separated integers F_1, ..., F_Q.
