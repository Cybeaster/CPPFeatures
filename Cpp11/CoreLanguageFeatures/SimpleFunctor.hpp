

namespace cpp11
{
    template <typename... Ts>
    struct FunctorImpl;

    template <typename ReturnType, typename... Args>
    struct FunctorImpl<ReturnType(Args...)>
    {
        using FuncType = ReturnType(Args...);
        FunctorImpl(FuncType Func) : Function(Func) {}

        __forceinline ReturnType operator()(Args... args)
        {
            return Function(args...);
        }

        FuncType Function;
    };

    template <typename FT>
    struct Functor : public FunctorImpl<FT>
    {
        Functor() : FunctorImpl<FT>(NULL) {}
        Functor(FT fn) : FunctorImpl<FT>(fn) {}
    };

} // namespace CPP11
