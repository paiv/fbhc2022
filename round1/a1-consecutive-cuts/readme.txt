Note: The only difference between this chapter and chapter 2 is that here, all
card values are guaranteed to be distinct.

Let's cut to the chase. You have a deck of N face-up cards, each displaying a
unique integer between 1 and N. Cutting the deck once consists of taking a stack
of between 1 and N−1 cards from the top and moving it to the bottom in the same
order. For example, for the deck [5,1,2,4,3] ordered from top to bottom, cutting
2 cards from the top would yield [2,4,3,5,1]:

Initially, the ith card from the top is A_i. Is it possible to cut the deck
exactly K times to reorder the deck such that the ith card from the top is B_i
for all i?

Constraints

1 ≤ T ≤ 200
2 ≤ N ≤ 500,000
0 ≤ K ≤ 10^9
1 ≤ A_i,B_i ≤ N
A and B are each permutations of 1..N.
The sum of N across all test cases is at most 5,000,000.

Input Format

Input begins with an integer T, the number of test cases. For each test case,
there is first a line containing two space-separated integers N and K. Then,
there is a line containing N space-separated integers, A_1,...,A_N. Then, there
is a line containing N space-separated integers, B_1,...,B_N.

Output Format

For the ith test case, print "Case #i: " followed by "YES" if it's possible to
cut the deck K times to change the deck from A_i to B_i, or "NO" otherwise.

Sample Explanation

In the first case, it's possible to get to the new order with K=1 cut (cutting 2
cards from the top).

In the second case, it's impossible to change [3,1,4,2] to [1,2,3,4] with any
number of cuts.

In the third case, it's impossible for the deck to be in a different order after
K=0 cuts.
