#include <iostream>
#include <atomic>
#include <future>
#include <thread>
std::atomic<int>flag;
void worker1(std::future<int>fut) {
    std::cout << "I am worker1 begin..." << std::endl;
    flag = 1;
    fut.get();      // block
    std::cout << "I am worker1 end..." << std::endl;
}
void worker2(std::promise<int>pro) {
    std::cout << "I am worker2 begin..." << std::endl;
    flag = 2;
    pro.set_value(100);      // will awaken
    std::cout << "I am worker2 end..." << std::endl;
}
int main() {
    std::cout << "I am main worker begin..." << std::endl;
    std::promise<int>pro;
    auto fut = pro.get_future();
    std::thread th1(worker1, std::move(fut));
    std::thread th2(worker2, std::move(pro));
    while (0 == flag.load());
    th1.detach();
    th2.detach();
    std::cout << "I am main worker end..." << std::endl;

	return 0;
}
