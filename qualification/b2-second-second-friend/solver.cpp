// c++ -std=c++20 -Ofast -o solve solver.cpp
#include <cstdint>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;


typedef enum {
    PLAIN = '.',
    TREE = '^',
    STONE = '#',
} tile;


typedef struct {
    u32 y;
    u32 x;
} pos;


constexpr const u32 MAXRC = 3000;
static char S[MAXRC][MAXRC];
static char V[MAXRC][MAXRC];


static void
solve1() {
    u32 R,C;
    cin >> R >> C;

    vector<pos> fringe;
    char c;
    for (u32 y = 0; y < R; ++y) {
        for (u32 x = 0; x < C; ++x) {
            cin >> c;
            V[y][x] = S[y][x] = c;
            if (S[y][x] == PLAIN) {
                fringe.push_back({y, x});
            }
        }
    }

    u32 ans = 1;

    while (fringe.size() > 0) {
        pos p = fringe.back();
        fringe.pop_back();

        if (V[p.y][p.x] != PLAIN) { continue; }

        u32 a = 0;
        a += p.x > 0 && V[p.y][p.x-1] != STONE;
        a += p.x+1 < C && V[p.y][p.x+1] != STONE;
        a += p.y > 0 && V[p.y-1][p.x] != STONE;
        a += p.y+1 < R && V[p.y+1][p.x] != STONE;
        if (a < 2) {
            V[p.y][p.x] = STONE;
            if (p.x > 0 && V[p.y][p.x-1] == PLAIN) { fringe.push_back({p.y, p.x-1}); }
            if (p.x+1 < C && V[p.y][p.x+1] == PLAIN) { fringe.push_back({p.y, p.x+1}); }
            if (p.y > 0 && V[p.y-1][p.x] == PLAIN) { fringe.push_back({p.y-1, p.x}); }
            if (p.y+1 < R && V[p.y+1][p.x] == PLAIN) { fringe.push_back({p.y+1, p.x}); }
        }
    }

    for (u32 y = 0; y < R && ans; ++y) {
        for (u32 x = 0; x < C; ++x) {
            u8 c = V[y][x];
            if (c != STONE) {
                S[y][x] = TREE;
                u32 a = 0;
                a += x > 0 && V[y][x-1] != STONE;
                a += x+1 < C && V[y][x+1] != STONE;
                a += y > 0 && V[y-1][x] != STONE;
                a += y+1 < R && V[y+1][x] != STONE;
                if (a < 2) {
                    ans = 0;
                    break;
                }
            }
        }
    }

    if (ans) {
        cout << " Possible" << std::endl;
        for (u32 y = 0; y < R; ++y) {
            for (u32 x = 0; x < C; ++x) {
                cout << S[y][x];
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
