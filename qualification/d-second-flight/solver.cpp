// c++ -std=c++20 -Ofast -o solve solver.cpp
#include <cstdint>
#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::min;
using std::unordered_map;

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;


constexpr const u32 MAXN = 200000;
static unordered_map<u32,u64> direct[MAXN];
static unordered_map<u32,u64> indirect[MAXN];


static void
solve1() {
    u32 N,M,Q;
    cin >> N >> M >> Q;

    for (u32 i = 0; i < MAXN; ++i) {
        direct[i].clear();
        indirect[i].clear();
    }

    for (u32 i = 0; i < M; ++i) {
        u32 a, b, c;
        cin >> a >> b >> c;
        a -= 1;
        b -= 1;
        direct[a][b] = c;
        direct[b][a] = c;
    }

    const u32 bi = sqrt(M);

    for (u32 x = 0; x < N; ++x) {
        if (direct[x].size() < bi) { continue; }
        for (auto const &[z, c1] : direct[x]) {
            for (auto const &[y, c2] : direct[z]) {
                u64 c = min(c1, c2);
                indirect[x][y] += c;
            }
        }
    }

    u64 ans[Q];

    for (u32 i = 0; i < Q; ++i) {
        u32 x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        if (direct[x].size() < direct[y].size()) {
            std::swap(x, y);
        }
        u64 res = 0;
        if (direct[x].count(y)) {
            res += direct[x][y] * 2;
        }
        if (direct[x].size() >= bi) {
            res += indirect[x][y];
        }
        else {
            for (auto const &[z, c1] : direct[x]) {
                if (direct[z].count(y)) {
                    u64 c2 = direct[z][y];
                    u64 c = min(c1, c2);
                    res += c;
                }
            }
        }
        cout << " " << res;
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
        cout << std::endl;
    }

    return 0;
}
