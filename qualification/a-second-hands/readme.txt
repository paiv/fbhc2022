Sandy's store has N pre-owned clock parts for sale, where the ith part is of
style S_i. The store also has two display cases, each capable of holding at most
K parts. To maximize the aesthetics of Sandy's secondhand second hands, she'd
like to put each of the N parts into one of the two cases so that neither case
ends up with two different parts of the same style, and neither case has more
than K parts total. Can you determine if this is possible?

Constraints

1 ≤ T ≤ 90
1 ≤ N,K,S_i ≤ 100

Input Format

Input begins with an integer T, the number of test cases. For each test case,
there is first a line containing 2 space-separated integers, N and K. Then,
there is a line containing N space-separated integers, S_1, ..., S_N.

Output Format

For the ith test case, print "Case #i: " followed by "YES" if it's possible to
arrange the N parts into two cases satisfying the description above, or "NO"
otherwise.

Sample Explanation

In the first test case, there are 3 parts of styles 1, 2, and 2, with the
display cases having capacity 2. One solution, depicted below, is to put the
first and third parts in one display case, and the second part in the other.

In the second test case, there are 5 parts of styles 1, 2, 3, 3, 1, with
the display cases having capacity 3. One solution, depicted below, is to put
the first three parts in one display case, and the last two in the other.

In the third test case, there are 5 parts, but the display cases can each only
hold 2. Therefore, there is no solution.

In the fourth test case, style 1 will always be duplicated in some display case
for any given arrangement. Therefore, there is no solution.
