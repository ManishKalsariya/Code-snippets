/*
=========================================
POWER OF 2 CHECK (Bit Manipulation)
=========================================

Condition:
    (n & (n - 1)) == 0

Meaning:
    n is a power of 2 (for n > 0)

Why?
    Power of 2 has exactly one set bit.

Examples:

    n = 8

    8     = 1000
    8 - 1 = 0111

    1000
  & 0111
    ----
    0000

    => Result = 0

Non-Power of 2:

    n = 12

    12     = 1100
    12 - 1 = 1011

    1100
  & 1011
    ----
    1000

    => Result != 0

Useful Applications:

1. Check if n is power of 2

    if (n > 0 && (n & (n - 1)) == 0)

2. CF 1475A / Odd Divisor

    Observation:
    - Every number = (power of 2) × (odd part)
    - Odd divisor > 1 exists iff n is NOT a power of 2

    if ((n & (n - 1)) == 0)
        cout << "NO";
    else
        cout << "YES";

Common Powers of 2:

    1, 2, 4, 8, 16, 32, 64, 128, ...

Time Complexity:
    O(1)

=========================================
*/