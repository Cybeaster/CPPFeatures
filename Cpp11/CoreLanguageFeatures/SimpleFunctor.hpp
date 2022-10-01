

namespace CPP11
{
    template <typename... Ts>
    struct SimpleFunctorImpl;

    template <typename R, typename... Args>
    struct SimpleFunctorImpl<R(Args...)>
    {
        typedef R(FT)(Args...);
        SimpleFunctorImpl(FT fn) : m_fn(fn) {}

        __forceinline R operator()(Args... args)
        {
            return m_fn(args...);
        }

        FT m_fn;
    };

    template <typename FT>
    struct SimpleFunctor : public SimpleFunctorImpl<FT>
    {
        SimpleFunctor() : SimpleFunctorImpl<FT>(NULL) {}
        SimpleFunctor(FT fn) : SimpleFunctorImpl<FT>(fn) {}
    };

    int &&PlusFN(int a, int b) { return a + b; }

    void Test_1()
    {
        SimpleFunctor<int && (int, int)> plus(PlusFN);
    }
} // namespace CPP11
