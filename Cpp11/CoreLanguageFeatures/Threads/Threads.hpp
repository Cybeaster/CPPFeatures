#include "ThreadHeader.hpp"

namespace thread
{

    void TestFunc1(int &data)
    {
    }

    void Test1() {}
    void Test2() {}
    void TestThread()
    {
        int val = 1;
        // wont work! :: std::thread thread1(test1, val);
        std::thread thread1(TestFunc1, std::ref(val)); // ok
    }

    void TestThread1()
    {
        class x
        {
        public:
            void doSmth(){

            };
        };

        x local_x;

        std::thread thread(&x::doSmth, &local_x);
    }

    void DynamicObjectMove(std::unique_ptr<int> value)
    {
        
    }
    void DynamicThreadTest()
    {
        std::unique_ptr<int> some_value(new int());
        *some_value = 10;
        std::thread thread(DynamicObjectMove, std::move(some_value));
    }

    void MoveThreadTest()
    {
        std::mutex mutex;
        MutexGuard guard(mutex);
    }

} // namespace thread
