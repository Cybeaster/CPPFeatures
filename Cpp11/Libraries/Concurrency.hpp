#include <thread>
#include <iostream>

void doWork()
{
    using namespace std::literals::chrono_literals;
    while (true)
    {
        std::cout<<"Working..."<<std::endl;
        std::this_thread::sleep_for(1s);
    }
    
 
}

void CuncurrentMain()
{
    std::thread worker(doWork);

    worker.join();
}