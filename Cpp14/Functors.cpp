
#pragma region SimpleFunctor
template <typename ... Ts>
struct SimpleFunctorImpl;


template <typename R, typename ... Args>
struct SimpleFunctorImpl<R (Args ...)>
{
    typedef R(FT)(Args ...);
    SimpleFunctorImpl(FT fn) : m_fn(fn){}

    __forceinline R operator() (Args ... args)
    {return m_fn(args ...);}

    FT m_fn;
};


template <typename FT>
struct SimpleFunctor : public SimpleFunctorImpl<FT>
{
    SimpleFunctor() : SimpleFunctorImpl<FT>(NULL){}
    SimpleFunctor(FT fn) : SimpleFunctorImpl<FT>(fn){}
};

int&& plus_fn(int a,int b) {return a + b;}

void test()
{
    SimpleFunctor<int&& (int,int)> plus(plus_fn);
}
#pragma endregion SimpleFunctor


#pragma region MemberFunctor
template <typename ... Args>
struct MemberFunctorImpl;


template <typename T, typename R, typename ... Args>
struct MemberFunctorImpl<R (T::*)(Args ...)>
{
    using FT = R(T::*FT)(Args);
    using HostType = T;

    MemberFunctorImpl(FT fn = NULL,T* obj = nullptr)
    : m_fn(fn), m_obj(obj){}

    FT m_fn;
    T* m_obj;
    
};


#pragma endregion MemberFunctor