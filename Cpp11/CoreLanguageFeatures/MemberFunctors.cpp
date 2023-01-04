
#include <type_traits>

namespace cpp11
{
    template <typename... Args>
    struct MemberFunctorImpl;

    template <typename T, typename ReturnType, typename... Args>
    struct MemberFunctorImpl<ReturnType (T::*)(Args...)>
    {
        using FT = ReturnType (T::*FT)(Args);
        using HostType = T;

        MemberFunctorImpl(FT fn = NULL, T *obj = nullptr)
            : Fn(fn), Obj(obj) {}

        FT Fn;
        T *Obj;
    };

    void Test()
    {
    }
}