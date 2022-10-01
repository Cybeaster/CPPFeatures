
#include <type_traits>

namespace CPP11
{
    template <typename ... Args>
    struct MemberFunctorImpl;


    template <typename T, typename R, typename ... Args>
    struct MemberFunctorImpl<R (T::*)(Args ...)>
    {
        using FT = R(T::*FT)(Args);
        using HostType = T;

        MemberFunctorImpl(FT fn = NULL,T* obj = nullptr)
        : Fn(fn), Obj(obj){}

        FT Fn;
        T* Obj;
        
    };



    void Test()
    {
        
    }
}