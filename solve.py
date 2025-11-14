#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10000)

def phi(n):
    result = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1 if p == 2 else 2
    if n > 1:
        result -= result // n
    return result

# helper that computes small tower value and indicates if it reached/exceeded limit
def tower_check(k, limit):
    # returns (value, reached_limit_boolean)
    if limit <= 1:
        # anything >=1 is "reached"
        return (1, True)
    if k == 1:
        return (1, 1 >= limit)
    val, big = tower_check(k-1, limit)
    # compute k**val but stop early if >= limit
    res = 1
    for _ in range(val):
        res *= k
        if res >= limit:
            return (res, True)
    return (res, res >= limit)

def tower_mod(n, m):
    # compute n^( (n-1)^(...^(2^1))) mod m
    if m == 1:
        return 0
    if n == 1:
        return 1 % m
    ph = phi(m)
    # compute exponent = tower(n-1) mod ph, but if actual tower >= ph, add ph
    exp_mod = tower_mod(n-1, ph)
    _, is_large = tower_check(n-1, ph)
    if is_large:
        exp = exp_mod + ph
    else:
        exp = exp_mod
    return pow(n % m, exp, m)

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    a = int(data[0]); m = int(data[1])
    print(tower_mod(a, m))

if __name__ == '__main__':
    main()