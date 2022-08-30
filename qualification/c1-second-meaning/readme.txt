Note: The only difference between this problem and problem C2 is that here, the
length of each output codeword may be at most 200.

Morse code is a classic way to send messages, where each letter in an alphabet
is substituted with a codeword: a unique sequence of dots and dashes. However,
ignoring spaces, it's possible for a coded message to have multiple meanings.

For example, ".....--.-.-.-..-.-.-...-.--." can be interpreted as either "HACKER
CUP" or "SEE META RENT A VAN":

Beyond Morse code, a general set of codewords is an unambiguous encoding if any
possible sequence of dots and dashes corresponds to either zero or exactly one
sequence of codewords.

Given one codeword C_1 from a set of N distinct codewords, your task is to
generate another N−1 codewords C_2, ..., C_N to yield an unambiguous encoding.
It can be shown that an answer always exists. If there are multiple answers, you
may print any one of them.

Constraints

1 ≤ T ≤ 100
2 ≤ N ≤ 100
The length of C_1 is between 1 and 100, inclusive.
The length of each C_2, ..., C_N must be between 1 and 200, inclusive.

Input Format

Input begins with an integer T, the number of test cases. For each case, there
is first a line containing a single integer N. Then, there is a line containing
the codeword C_1.

Output Format

For the ith case, output a line containing only "Case #i:", followed by N−1
lines, the codewords C_2, ..., C_N, one per line.

Sample Explanation

In the first case, it can be shown that the codewords {".-.", "...", "---"} are
an unambiguous encoding. Any sequence of dots and dashes can be interpreted if
and only if it has a length that's a multiple of 3, and can be broken up into
instances of the three length-3 codewords.

In the second case, it can be shown that the codewords {"-", "...", ".-", "..-"}
are an unambiguous encoding. For instance, ".." has no possible interpretation,
and ".-...--" can only be interpreted as ".- ... - -".

In the third case, it can be shown that the codewords {"..", "-", ".-"} are an
unambiguous encoding. For any sequence of dots and dashes: every odd group of
dots followed by a dash can only be interpreted as repeated ".."s followed by a
final ".-" every even group of dots followed by a dash can only be interpreted
as repeated ".."s followed by a final "-" every group of dots not followed by a
dash (i.e. at the end of the sequence), is interpretable if and only if there is
an even number of dots this leaves only groups of dashes, interpreted only as
repeated "-"s
