// c++ -std=c++20 -Ofast -o solve solver.cpp
#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

typedef uint8_t u8;
typedef uint32_t u32;


static void
solve1() {
    u32 R,C;
    cin >> R >> C;

    char S[R][C];
    u8 isblank = 1;
    for (u32 y = 0; y < R; ++y) {
        for (u32 x = 0; x < C; ++x) {
            cin >> S[y][x];
            if (S[y][x] != '.') {
                isblank = 0;
            }
        }
    }

    u32 ans = 1;
    if (R < 2 || C < 2) {
        ans = isblank;
    }
    if (ans) {
        cout << " Possible" << std::endl;
        for (u32 y = 0; y < R; ++y) {
            for (u32 x = 0; x < C; ++x) {
                cout << (isblank ? '.' : '^');
            }
            cout << std::endl;
        }
    }
    else {
        cout << " Impossible" << std::endl;
    }
}


int
main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    u32 T;
    cin >> T;
    for (u32 i = 0; i < T; ++i) {
        cout << "Case #" << (i + 1) << ":";
        solve1();
    }

    return 0;
}
