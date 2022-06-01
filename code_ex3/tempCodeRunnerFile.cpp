#include "Queue.h"

int main()
{
    Queue<int> testQueue;
    testQueue.pushBack(2);
    testQueue.pushBack(9);
    testQueue.pushBack(92);

    // testQueue.popFront();
     testQueue.toString();
    std::cout << testQueue.size() << "  size \n";
    std::cout << testQueue.front() << "  front \n";

   
}