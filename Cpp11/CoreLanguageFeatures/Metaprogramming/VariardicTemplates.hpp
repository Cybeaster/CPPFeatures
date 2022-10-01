

namespace CPP11
{

#pragma region Tuple

    // Begin
    template <typename... Args>
    class Tuple;

    // End
    template <>
    struct Tuple<>
    {
    };

    template <typename Head, typename... Tail>
    class Tuple<Head, Tail...> : Tuple<Tail...>
    {
        template <size_t It, typename Head, typename... Args>
        struct Getter
        {
            using ReturnType = typename Getter<It - 1, Args...>::ReturnType;
            static ReturnType Get(Tuple<Head, Args...> Tuple)
            {
                return Getter<It - 1, Args...>::Get(Tuple);
            }
        };

        template <typename Head, typename... Tail>
        struct Getter<0, Head, Tail...>
        {
            using ReturnType = typename Tuple<Head, Tail...>::ReturnType;
            static ReturnType Get(Tuple<Head, Tail...> T)
            {
                return T.Head;
            }
        };

    public:
        using BaseType = Tuple<Tail...>;
        using ValueType = Head;

        Tuple(Head _head, Tail... _tail) : head(_head), Tuple<Tail...>(_tail...) {}

        template <size_t It, typename Head, typename... Tail>
        typename Getter<It, Head, Tail...>::ReturnType Get()
        {
            return Getter<It, Head, Args...>::Get(this);
        }

    private:
        BaseType &baseType = static_cast<BaseType &>(this);
        Head head;
    };

#pragma endregion Tuple

    void Test()
    {
    }
} // namespace CPP11
