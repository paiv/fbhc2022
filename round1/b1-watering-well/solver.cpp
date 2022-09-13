// c++ -std=c++20 -O2 -o solve solver.cpp
#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <iostream>

using std::abs;
using std::cin;
using std::clog;
using std::cout;
using std::endl;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t i32;
typedef int64_t i64;


typedef struct {
    u32 x, y;
} point;


constexpr const u32 MAXN = 500000;
static point AB[MAXN];
static point XY[MAXN];


static void
solve1() {
    constexpr const u64 MOD = 1000000007;
    u32 N,Q;
    cin >> N;
    for (u32 i = 0; i < N; ++i) {
        cin >> AB[i].x >> AB[i].y;
    }
    cin >> Q;
    for (u32 i = 0; i < Q; ++i) {
        cin >> XY[i].x >> XY[i].y;
    }

#if 0
    u64 ans = 0;
    for (u32 k = 0; k < Q; ++k) {
        auto& q = XY[k];
        for (u32 i = 0; i < N; ++i) {
            auto& t = AB[i];
            u64 dx = abs(i32(t.x) - i32(q.x));
            u64 dy = abs(i32(t.y) - i32(q.y));
            ans = ((ans + dx * dx) % MOD + dy * dy) % MOD;
        }
    }
#endif

#if 1
    u64 sx = 0, sx2 = 0, sy = 0, sy2 = 0;
    for (u32 i = 0; i < N; ++i) {
        auto& t = AB[i];
        sx = (sx + t.x);
        sy = (sy + t.y);
        sx2 = (sx2 + t.x * t.x);
        sy2 = (sy2 + t.y * t.y);
    }
    u64 rx = 0, ry = 0;
    for (u32 k = 0; k < Q; ++k) {
        auto& q = XY[k];
        rx = (rx + sx2);
        ry = (ry + sy2);
        rx = (rx + u64(N) * (q.x * q.x));
        ry = (ry + u64(N) * (q.y * q.y));
        rx = (rx - (2 * sx * q.x) % MOD) % MOD;
        ry = (ry - (2 * sy * q.y) % MOD) % MOD;
    }
    u64 ans = (rx + ry) % MOD;
#endif

    cout << " " << ans;
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
