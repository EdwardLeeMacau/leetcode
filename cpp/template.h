#ifndef TEMPLATE_H_
#define TEMPLATE_H_

// C only sections
#ifndef __cplusplus
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

#typedef long long LL;
#endif

// C++ only sections
#ifdef __cplusplus

#include <tuple>
using Coord = std::pair<int, int>;
using LL = long long;

#endif

#endif // TEMPLATE_H_
