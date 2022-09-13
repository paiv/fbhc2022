// c++ -std=c++20 -O2 -o solve solver.cpp
#include <cstdint>
#include <iostream>
#include <limits>

using std::cin;
using std::clog;
using std::cout;
using std::endl;

typedef uint8_t u8;
typedef uint32_t u32;
static constexpr const u32 u32_max = std::numeric_limits<u32>::max();


constexpr const u32 MAXN = 500000;
static u32 A[MAXN];
static u32 B[MAXN];


static u32
search(const u32* A, const u32* B, u32 N) {
    static u32 S[MAXN * 3 + 1];
    static u32 T[MAXN * 3 + 1];

    const u32 N11 = N + 1;
    const u32 N21 = N * 2 + 1;
    const u32 N31 = N * 3 + 1;
    for (u32 i = 0; i < N; ++i) {
        S[i] = B[i];
        S[i+N11] = A[i];
        S[i+N21] = A[i];
    }
    S[N] = 0;

    for (u32 i = 1, l = 0, r = 0; i < N21; ++i) {
        if (i > r) {
            l = r = i;
            while (r < N31 && S[r-l] == S[r]) {
                ++r;
            }
            T[i] = r-- - l;
        }
        else {
            u32 k = i - l;
            if (T[k] < r + 1 - i) {
                T[i] = T[k];
            }
            else {
                l = i;
                while (r < N31 && S[r-l] == S[r]) {
                    ++r;
                }
                T[i] = r-- - l;
            }
        }
        if (T[i] == N) {
            return (i - N11);
        }
    }

    return u32_max;
}


static void
solve1() {
    u32 N,K;
    cin >> N >> K;

    for (u32 i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (u32 i = 0; i < N; ++i) {
        cin >> B[i];
    }

    u8 ans = 0;
    if (K == 0) {
        ans = 1;
        for (u32 i = 0; i < N; ++i) {
            if (A[i] != B[i]) {
                ans = 0;
                break;
            }
        }
    }
    else {
        u32 off = search(A, B, N);
        if (off != u32_max) {
            if (K == 1) {
                ans = (off != 0);
            }
            else if (N == 2) {
                ans = (B[0] == B[1]) || ((K % N) == off);
            }
            else {
                ans = 1;
            }
        }
    }
    cout << " " << (ans ? "YES" : "NO");
}


int
main(int argc, char const *argv[]) {
    u32 T;
    cin >> T;
    for (u32 i = 0; i < T; ++i) {
        cout << "Case #" << (i + 1) << ":";
        solve1();
        cout << std::endl;
    }

    return 0;
}
