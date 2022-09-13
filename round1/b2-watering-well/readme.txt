Note: The only difference between this chapter and chapter 1 is that here,
coordinates may be up to 10^9.

Boss Rob just planted N happy little trees in his yard, which can be represented
on a Cartesian plane. The ith tree is located at coordinates t_i=(A_i,B_i). Now,
he's looking for the best spot to build a well in order to provide water to
them. He considers the inconvenience of a potential well location p to be the
sum of the squared Euclidean distances to every tree: ∑∥p−t_i∥^2

Rob wants to pick a location for his well, well... well. Help him determine the
inconvenience for Q different potential well locations, (X_1,Y_1),...,(X_Q,Y_Q).
To reduce output size, please print the sum of inconveniences for all potential
well locations, modulo 1,000,000,007.

Constraints

1 ≤ T ≤ 50
1 ≤ N,Q ≤ 500,000
0 ≤ A_i,B_i,X_i,Y_i ≤ 10^9
All (A_i,B_i) are distinct within a given test case.
All (X_i,Y_i) are distinct within a given test case.
The total sum of N and Q across all test cases is at most 3,000,000.

Input Format

Input begins with a single integer T, the number of test cases. For each case,
there is first a line containing a single integer N. Then, N lines follow, the
ith of which contains two space-separated integers A_i and B_i. Then there is a
line containing a single integer Q. Then, Q lines follow, the ith of which
contains two space-separated integers X_i and Y_i.

Output Format

For the ith test case, print a line containing "Case #i: ", followed by a single
integer, the sum of inconveniences for all Q well locations, modulo
1,000,000,007.

Sample Explanation

The first two sample cases are depicted below:

In the first case, the total inconvenience is 18+34=52:
For the well at (2,5), the inconvenience is the sum of the squared Euclidean
distance to both trees, which is 3^2+3^2=18.
For the well at (6,6), the inconvenience is 32+2=34.

In the second case, the total inconvenience is 47+31+53=131:
For the well at (3,1), the inconvenience is 4+5+13+25=47.
For the well at (5,2), the inconvenience is 17+2+2+10=31.
For the well at (6,5), the inconvenience is 41+8+4+0=53.
