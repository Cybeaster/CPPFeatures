

namespace MetaProgramming
{

    template <typename T>
    bool compare(const T &Var1, const T &Var2)
    {
        return Var1 == Var2;
    }

    template <typename FirstType, typename... Rest>
    bool compare(const FirstType &Var1, FirstType &Var2, Rest... Args)
    {
        return Var1 == Var2 && compare(Args);
    }

} // namespace MetaProgramming
