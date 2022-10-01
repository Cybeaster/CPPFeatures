

namespace cpp11
{
    template <class T>
    void swap(T &a, T &b) noexcept
    {
        static_assert(std::is_copy_constructible_v<T>,
                      "Swap requires copying");
        static_assert(std::is_nothrow_copy_constructible_v<T> &&
                          std::is_nothrow_copy_assignable_v<T>,
                      "Swap requires nothrow copy/assign");
        auto c = b;
        b = a;
        a = c;
    }

} // namespace cpp11
