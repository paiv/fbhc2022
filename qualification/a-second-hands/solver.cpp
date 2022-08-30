// c++ -std=c++20 -Ofast -o solve solver.cpp
#include <algorithm>
#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

typedef uint32_t u32;


static void
solve1() {
    u32 K,N;
    cin >> N >> K;

    u32 S[N];
    for (u32 i = 0; i < N; ++i) {
        cin >> S[i];
    }

    u32 ans = 0;
    if (N <= 2 * K) {
        std::sort(&S[0], &S[N]);
        ans = 1;
        for (u32 i = 2; i < N; ++i) {
            if (S[i] == S[i-2]) {
                ans = 0;
                break;
            }
        }
    }

    cout << (ans ? " YES" : " NO");
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
