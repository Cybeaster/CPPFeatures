#pragma once
#include "main.hpp"

#define TO_STRING(x) #x
#define CONCAT(x, y, z) x##y##z

#define assert(x) \
    if (!x)       \
        debugBreak();

#define debugBreak()

namespace cpp11
{
    namespace Preprocessor
    {

#define mul(a, b) (a * b)

        void fun()
        {
        }

    } // namespace Preprocessor

} // namespace cpp11
