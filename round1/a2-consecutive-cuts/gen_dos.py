#!/usr/bin/env python
def main(N):
    K = 1
    A = [1] * (N - 1) + [2]
    B = [1] * (N // 2) + [2] + [1] * (N - N // 2 - 1)
    print('1')
    print(f'{N} {K}')
    print(' '.join(map(str, A)))
    print(' '.join(map(str, B)))


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('N', type=int, nargs='?', default=500000)
    args = parser.parse_args()
    main(args.N)
