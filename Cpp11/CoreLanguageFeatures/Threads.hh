#include <tuple>
#include <string>
namespace cpp11
{
    namespace thread
    {
        struct Threads
        {
            char a;
            int b : 5;
        };

    
        template <typename ... Args>
        std::tuple<Args...> printArgs(Args ... arg);

        template <typename Arg>
        std::tuple<Arg> printArgs(Arg arg)
        {
            std::cout << arg << std::endl;
            return {arg};
        }

        template <typename Arg, typename... Args>
        std::tuple<Arg, Args...> printArgs(Arg arg, Args... args)
        {
            std::cout << arg << std::endl;
            printArgs<Args...>(args...);
            return std::tuple<Arg, Args...>(arg,args...);
        }

        void fun()
        {
            auto &[FirstVal, SecondVal, ThirdString] = printArgs<int, int, std::string>(32, 32, "dfd");
        }

    } // namespace thread

} // namespace cpp11
