There's a famous saying about what to do when life gives you lemons. As a
traveling lemonade salesman who's never been given any lemons, you sadly can't
relate. You must shamefully concoct your lemonade from store-bought powder with
your back turned to the world, lest someone see your dirty secret.

Your sales route can be mapped out on a Cartesian plane with N houses, the ith
of which is at coordinates (X_i,Y_i). Your journey starts at house 1, the
leftmost house, and ends at house N, the rightmost house. Along the way, you
may stop at zero or more other houses to sell lemonade.

You may only stop at a house h if:
there is a direction you can face in which all other houses would be strictly
more behind you than they are in front of you (formally, if there exists a
half-plane containing only house h), and
house h is at most Euclidean distance D from the previous house you were at.

Your brand image is hurt if you go too long without selling lemonade. The brand
damage incurred by traveling from one house to another is the larger of K and
the squared Euclidean distance between them. Formally, if your journey consists
of M (2≤M≤N) houses with the ith being house H_i (H_1=1,H_M=N), the total brand
damage is:

\sum_{i=1}^{M-1} \max(K, (X_{H_i} - X_{H_{i + 1}})^2 + (Y_{H_i} - Y_{H_{i + 1}})^2)

Is it possible to make the journey? If so, what is the minimum possible total
brand damage to do so? Note that the answer may be large, but will fit in a
64-bit integer.

Constraints

1 ≤ T ≤ 90
2 ≤ N ≤ 1,000,000
0 ≤ K,D ≤ 10^9
0 ≤ X_i,Y_i ≤ 1,000,000
X_1 is strictly less than all other X_i.
X_N is strictly greater than all other X_i.
All (X_i,Y_i) are distinct within a given test case.
The sum of N across all test cases is at most 4,000,000.
There are at most 15 test cases in which N > 5,000.

Input Format

Input begins with a single integer T, the number of test cases. For each test
case, there is first a line containing three space-separated integers N, K, and
D. Then, N lines follow, the ith of which contains two space-separated integers
X_i and Y_i.

Output Format

For the ith test case, print a line containing "Case #i: " followed a single
integer, the minimum total brand damage that must be incurred to make the
journey, or −1 if it's impossible to do so.

Sample Explanation

The first three sample cases are depicted below, with the optimal paths given in
blue.

In the first case, going from one house to another takes at least K=25 brand
damage and must not exceed a distance of D=8. The total brand damage is
25+50+40=115. Note that you cannot stop at house (6,7) because there is no
direction you could face from there in which your back is at least slightly
facing both house (1,6) and (11,8).

In the second case, you can stop at house (4,1) because for instance, the line
y=0.3x−0.2 contains only (4,1), and the half-plane below it contains no other
houses.

In the third case, you cannot stop at house (4,1). There are no other houses
within D=7 units of your starting house, so it is not possible to reach the
house at (8,2).
