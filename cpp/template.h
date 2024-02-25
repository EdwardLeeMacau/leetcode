#ifndef TEMPLATE_H_
#define TEMPLATE_H_

// Primes to cover prime check in range [0, 100'000]
static const int primes[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 
    137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 
    227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313
};

// C only sections
#ifndef __cplusplus
/**
 * @brief Frequently used divisor.
 */
#define MOD 1000000007

#define max(a, b) ({ \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; \
})

#define min(a, b) ({ \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b; \
})

#define abs(a) ({ \
    __typeof__ (a) _a = (a); \
    _a < 0 ? -_a : _a; \
})

#define swap(a, b) ({ \
    __typeof__(a) tmp = a; \
    a = b; b = tmp; \
})

#typedef long long LL;
#endif

// C++ only sections
#ifdef __cplusplus

#include <tuple>

/**
 * @brief Frequently used divisor.
 */
static const MOD = 1000000007;
using Coord = std::pair<int, int>;
using LL = long long;

#endif

#endif // TEMPLATE_H_
