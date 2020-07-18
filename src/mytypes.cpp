#include "mytypes.h"


std::ostream& operator<<(std::ostream& out, vectorint& _vec)
{
    print_iterable(out, _vec);

    return out;
}

