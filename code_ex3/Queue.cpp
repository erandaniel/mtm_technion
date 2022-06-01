#include "Queue.h"

static bool isEven(int n) { return (n % 2) == 0; }
static void setFortyTwo(int &n) { n *= 2; }
int main()
{
    Queue<int> testQueue;
    testQueue.pushBack(2);
    testQueue.pushBack(9);
    testQueue.pushBack(92);

    // testQueue.popFront();
    testQueue.toString();
    std::cout << "  size \n";

    transform(testQueue, setFortyTwo);
    
    std::cout << " filterd\n";
    testQueue.toString();
}