#!/usr/bin/env python
import random


def main(N):
    Q = N
    ps = [(x,y) for y in range(3001) for x in range(3001)]
    s = random.sample(ps, N + Q)
    ts = s[:N]
    qs = s[N:]
    print('1')
    print(N)
    for (x, y) in ts:
        print(f'{x} {y}')
    print(Q)
    for (x, y) in qs:
        print(f'{x} {y}')


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('N', type=int, nargs='?', default=500000)
    args = parser.parse_args()
    main(args.N)
