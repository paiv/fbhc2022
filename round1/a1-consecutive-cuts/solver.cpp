// c++ -std=c++20 -O2 -o solve solver.cpp
#include <algorithm>
#include <cstdint>
#include <iostream>

using std::cin;
using std::clog;
using std::cout;
using std::endl;

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;


constexpr const u32 MAXN = 500000;
static u32 A[MAXN];
static u32 B[MAXN];


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
    u32* pos = std::find(A, A + N, B[0]);
    if (pos != A + N) {
        u32 off = pos - A;
        ans = 1;
        for (u32 i = 1; i < N; ++i) {
            pos += 1;
            if (pos == A + N) { pos = A; }
            if (B[i] != *pos) {
                ans = 0;
                break;
            }
        }
        if (ans) {
            if (K == 0) {
                ans = (off == 0);
            }
            else if (K == 1) {
                ans = (off != 0);
            }
            else if (N == 2) {
                ans = (K % N) == off;
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
