#include <thread>
namespace thread
{
    struct JoiningThread
    {

    public:
        JoiningThread() noexcept = default;

        template <typename Callable, typename... Args>
        explicit JoiningThread(Callable &&_Func, Args &&..._Args) : Thread(std::forward(Func), std::forward<Args>(_Args)...)
        {
        }

        explicit JoiningThread(std::thread Arg) noexcept : Thread(std::move(Arg))
        {
        }

        JoiningThread(JoiningThread &&Arg) noexcept : Thread(std::move(Arg.Thread))
        {
        }

        JoiningThread &operator=(JoiningThread &&Arg) noexcept
        {
            CheckableJoin();
            Thread = std::move(Arg.Thread);
            return *this;
        }

        JoiningThread &operator=(JoiningThread Arg) noexcept
        {
            CheckableJoin();
            Thread = std::move(Arg.Thread);
            return *this;
        }

        JoiningThread &operator=(std::thread Arg) noexcept
        {
            CheckableJoin();
            Thread = std::move(Arg);
            return *this;
        }

        ~JoiningThread() noexcept
        {
            CheckableJoin();
        }

        void swap(JoiningThread &Arg) noexcept
        {
            Thread.swap(Arg.Thread);
        }

        std::thread::id GetID() noexcept
        {
            return Thread.get_id();
        }

        void CheckableDetach()
        {
            if (Thread.joinable())
            {
                Thread.detach();
            }
        }

        void Detach()
        {
            Thread.detach();
        }

        bool Joinable() noexcept
        {
            return Thread.joinable();
        }

        void Join() noexcept
        {
            Thread.join();
        }

        void CheckableJoin() noexcept
        {
            if (Joinable())
            {
                Thread.join();
            }
        }

        const std::thread &GetNativeThread() const noexcept
        {
            return Thread;
        }

    private:
        std::thread Thread;
    };
} // namespace thread
