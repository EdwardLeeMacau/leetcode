#ifndef TEMPLATE_H_
#define TEMPLATE_H_

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
