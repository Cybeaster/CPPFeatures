#include <string>

namespace
{
    long long operator"" _l(long double)
    {
    }
    std::string operator"" _w(const char16_t *va, size_t d)
    {
    }
} // namespace

void funcTest()
{
    u"1.2324"_w;

    [[expect_true]] if (true)

    {
    }
}

[[noreturn]] int32_t function()
{

    exit;
}