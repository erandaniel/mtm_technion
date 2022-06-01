#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <cstdio>
#include <vector>
#include "HealthPoints.h"
#include "Queue.h"


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ostringstream;

static const std::string FILE_PATH = "../testOutputs";
int counter = 0;

#define ASSERT_TEST(expr)                                                         \
     do {                                                                          \
         if (!(expr)) {                                                            \
             printf("\nAssertion failed at line:%d",__LINE__); \
             result = false;                                                       \
         }                                                                         \
     } while (0);

#define RUN_TEST(test, name)                  \
    do {                                 \
        cout << "+ Running " << (name) << "...";  \
        if (test()) {                   \
            counter++;                    \
            cout << "[OK]\n" << endl;         \
        } else {                         \
            cout << "[Failed]\n" << endl;       \
        }                                \
    } while (0);

#define ASSERT(expr) ASSERT_TEST(expr)

#define OPEN_FILE(streamName, name) std::string fileName = name;\
std::ofstream streamName(fileName, std::ofstream::trunc | std::ofstream::in);\
if(!(streamName).is_open()){\
throw FileFailed();\
}

class FileFailed: std::exception {
public:
    FileFailed() = default;
    ~FileFailed() = default;
};

bool matchFiles(const std::string& out, const std::string& exp) {
    ifstream output(out);
    if (!output) {
        cout << "can't open file" << endl;
    }
    ifstream expOutput(exp);
    if (!expOutput) {
        cout << "can't open file" << endl;
    }
    while (!output.eof()) {
        char c;
        output >> std::noskipws >> c;
        char ex;
        expOutput >> std::noskipws >> ex;
        if (ex != c) {
            return false;
        }
    }
    return true;
}

template <class T> void print(const T& x, ofstream& stream) { stream << x << endl; }
///////////////////////////////////////////////////////////////////////////////////
//                          The tests Starts here                                //
//                                GOOD LUCK                                      //
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
//                               Help function                                   //
///////////////////////////////////////////////////////////////////////////////////

static bool checkHealthPointsValues(const HealthPoints& healthPoints, int current, int max)
{
	ostringstream expected;
	expected << current << '(' << max << ')';
	ostringstream result;
	result << healthPoints;
	return (expected.str() == result.str());
}

static bool isEven(int n){
	return (n % 2) == 0;
}

static bool smallerThan300(HealthPoints n){
	return (n < 300);
}

static bool noOne(HealthPoints n){
	return (n > 400);
}

static bool diffFrom200(HealthPoints n){
	return (n != 200);
}

static void setFortyTwo(int& n){
	n = 42;
}

static void biggerThan200(HealthPoints& n){
	if(n > 200){
        n -= 100; 
    }
}

static void zeroAll(HealthPoints& n){
	n -= 1000;
}

static void maxAll(HealthPoints& n){
	n += 1000;
}

///////////////////////////////////////////////////////////////////////////////////
//                            HealthPoints tests                                 //
///////////////////////////////////////////////////////////////////////////////////

bool testHpBySegel(){
    bool result = true;
	HealthPoints healthPoints1; /* has 100 points out of 100 */
	HealthPoints healthPoints2(150); /* has 150 points out of 150 */
	bool exceptionThrown = false;
	try {
		HealthPoints healthPoints3(-100);
	}
	catch (HealthPoints::InvalidArgument& e) {
		exceptionThrown = true;
	}
    ASSERT(result && exceptionThrown)
	ASSERT(result && checkHealthPointsValues(healthPoints1, 100, 100))

	healthPoints1 -= 20; /* now has 80 points out of 100 */
	ASSERT(result && checkHealthPointsValues(healthPoints1, 80, 100))

	healthPoints1 += 100; /* now has 100 points out of 100 */
	ASSERT(result && checkHealthPointsValues(healthPoints1, 100, 100))

	healthPoints1 -= 150; /* now has 0 points out of 100 */
	ASSERT(result && checkHealthPointsValues(healthPoints1, 0, 100))

	healthPoints2 = healthPoints2 - 160; /* now has 0 points out of 150 */
	ASSERT(checkHealthPointsValues(healthPoints2, 0, 150))

	healthPoints2 = 160 + healthPoints1; /* now has 100 out of 100 */
	ASSERT(checkHealthPointsValues(healthPoints2, 100, 100))

	HealthPoints healthPoints3 = HealthPoints(100); /* has 100 points out of 100 */
	HealthPoints healthPoints4 = 100; /* has 100 points out of 100 */

	ASSERT(healthPoints3 == healthPoints4)

	healthPoints3 = HealthPoints(150); /* has 150 points out of 150 */

	ASSERT(!(healthPoints3 == healthPoints4))

	healthPoints3 -= 50; /* now has 100 points out of 150 */
	ASSERT(healthPoints3 == healthPoints4) /* returns true */

	ASSERT(!(healthPoints3 < healthPoints4)) /* returns false */

	healthPoints3 -= 50; /* now has 50 points out of 100 */
	ASSERT(healthPoints3 < healthPoints4); /* returns true */

	ostringstream stream;

	HealthPoints healthPoints5 = HealthPoints(100); /* has 100 points out of 100 */
	healthPoints5 -= 50; /* now has 50 points out of 100 */
	stream << healthPoints5; /* stream content is "50(100)" */
	ASSERT((stream.str() == "50(100)"))

	HealthPoints healthPoints6 = HealthPoints(150); /* has 1500 points out of 150 */
	healthPoints6 -= 50; /* now has 100 points out of 150 */
	stream << ", " << healthPoints6; /* stream content is "50(100), 100(150)" */
	ASSERT((stream.str() == "50(100), 100(150)"))
    return result;
}

bool testConstructorHp(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testConstructorHp.txt"))
    HealthPoints hp1(400);
    HealthPoints hp2;
    try{
        HealthPoints hp3(0);
    }
    catch(HealthPoints::InvalidArgument& hp) {
        out << "InvalidArgument" << endl;
    }
    try{
        HealthPoints hp4(-1);
    }
    catch(HealthPoints::InvalidArgument& hp) {
        out << "InvalidArgument" << endl;
    }
    print(hp1, out);
    print(hp2, out);
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testConstructorHp.txt")))
    return result;
}

bool testBooleanOperatorsHp()
{
    bool result = true;
    HealthPoints hp1(100);
    HealthPoints hp2(150);
    HealthPoints hp3(170);
    HealthPoints hp4(170);
    ASSERT(hp1 < hp2)
    ASSERT(hp2 > hp1)
    ASSERT(hp3 == hp4)
    ASSERT(hp1 <= hp1)
    ASSERT(hp1 <= hp2)
    ASSERT(hp2 >= hp1)
    ASSERT(hp3 >= hp4)
    ASSERT(hp1 != hp2)
    return result;
}

bool testArithmeticOperatorsHp() 
{
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testArithmeticOperatorsHp.txt"))
    HealthPoints hp1(100);
    HealthPoints hp2(150);
    HealthPoints hp3(170);
    HealthPoints hp4(200);
    hp1 -= 200;
    hp1 += 50;
    hp2 = hp2 - 100;
    hp2 = hp2 + 25;
    hp2 = 25 + hp2;
    hp3 -= 20;
    hp4 = hp4 - 10;
    hp4 = (-10) + hp4;
    hp3 += -60;
    hp3 -= -10;
    hp4 = hp4 + (-80);
    hp4 += 360;
    print(hp1, out);
    print(hp2, out);
    print(hp3, out);
    print(hp4, out);
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testArithmeticOperatorsHp.txt")))
    return result;
}

///////////////////////////////////////////////////////////////////////////////////
//                              Queue tests                                      //
///////////////////////////////////////////////////////////////////////////////////

bool testQueueMethodsBySegel(){
	bool result = true;

	Queue<int> queue1;
	queue1.pushBack(1);
	queue1.pushBack(2);
	int front1 = queue1.front();
	ASSERT(front1 == 1)

	queue1.front() = 3;
	front1 = queue1.front();
	ASSERT(front1 == 3)

	queue1.popFront();
	front1 = queue1.front();
	ASSERT(front1 == 2)

	int size1 = queue1.size();
	ASSERT(size1 == 1)

	return result;
}

bool testModuleFunctionsBySegel(){
	bool result = true;

	Queue<int> queue3;
	for (int i = 1; i <= 10; i++) {
		queue3.pushBack(i);
	}
	Queue<int> queue4 = filter(queue3, isEven);
	for (int i = 2; i <= 10; i+=2) {
		int front4 = queue4.front();
		ASSERT(front4 == i)
		queue4.popFront();
	}


	Queue<int> queue5;
	for (int i = 1; i <= 5; i++) {
		queue5.pushBack(i);
	}
	transform(queue5, setFortyTwo);
	for (Queue<int>::Iterator i = queue5.begin(); i != queue5.end(); ++i) {
		ASSERT(*i == 42)
	}

	return result;
}

bool testExceptionsBySegel()
{
	bool result = true;

	bool exceptionThrown = false;
	Queue<int> queue6;
	try {
		queue6.front();
	}
	catch (Queue<int>::EmptyQueue& e) {
		exceptionThrown = true;
	}
	ASSERT(exceptionThrown)

	exceptionThrown = false;
	Queue<int>::Iterator endIterator = queue6.end();
	try {
		++endIterator;
	}
	catch (Queue<int>::Iterator::InvalidOperation& e) {
		exceptionThrown = true;
	}
	ASSERT(exceptionThrown)

	return result;
}

bool testConstQueueBySegel()
{
	bool result = true;

	Queue<int> queue5;
	for (int i = 1; i <= 5; i++) {
		queue5.pushBack(42);
	}

	const Queue<int> constQueue = queue5;
	for (Queue<int>::ConstIterator i = constQueue.begin(); i != constQueue.end(); ++i) {
		ASSERT(*i == 42)
	}
	bool exceptionThrown = false;
	Queue<int>::ConstIterator endConstIterator = constQueue.end();
	try {
		++endConstIterator;
	}
	catch (Queue<int>::ConstIterator::InvalidOperation& e) {
		exceptionThrown = true;
	}
	ASSERT(exceptionThrown)

	return result;
}

bool testQueue(){
    bool result = true;
    OPEN_FILE(out, FILE_PATH + std::string("/your_outputs/testQueue.txt"))
    Queue<double> queue1;
    ASSERT(queue1.size() == 0)
    for(int i = 1; i <= 1000; i++){
        queue1.pushBack(i+0.1);
    }
    ASSERT(queue1.size() == 1000)

    out << "front & popFront check:" << endl << endl;

    for(int i = 1; i <= 9; i++){
        out << queue1.front() << " , ";
        out << (queue1.front() = queue1.front()*2.0) << endl;
        queue1.popFront();
    }
    ASSERT(queue1.size() == 991)
    const Queue<double> constQueue1 = queue1;
    ASSERT(constQueue1.size() == 991)
    ASSERT(constQueue1.front() == 10.1)
    for(int i = 1; i <= 995; i++){
        try{
            queue1.popFront();
        }
        catch(Queue<double>::EmptyQueue& e) {
            out << "EmptyQueue" << endl;
        }
    }
    ASSERT(queue1.size() == 0)
    try{
        queue1.front();
    }
    catch(Queue<double>::EmptyQueue& e) {
        out << "EmptyQueue" << endl;
    }
    try{
        queue1.front() = 5;
    }
    catch(Queue<double>::EmptyQueue& e) {
        out << "EmptyQueue" << endl;
    }
    queue1 = constQueue1;
    for(int i = 1; i <= 981; i++){
        queue1.popFront();
    }
    ASSERT(queue1.front() == 991.1)

    out << endl << "Queue<HealthPoints> check:" << endl << endl;
    Queue<HealthPoints> queue2;
    for(int i = -1; i <= 5; i++){
        try{
            HealthPoints hp1(i*100);
            queue2.pushBack(hp1);
        }
        catch(HealthPoints::InvalidArgument& hp) {
            out << "InvalidArgument" << endl;
        }
    }
    const Queue<HealthPoints> constQueue2 = queue2;
    ASSERT(constQueue2.front() == queue2.front())
    for(int i = 7; i >= 1; i--){
        try{
            out << queue2.front() << " , ";
            HealthPoints hp2(i*100);
            out << (queue2.front() = hp2) << endl;
            queue2.popFront();
        }
        catch(Queue<HealthPoints>::EmptyQueue& e){
            out << "EmptyQueue" << endl;
        }
    }
    ASSERT(constQueue2.front() == 100)
    for(Queue<HealthPoints>::ConstIterator i = constQueue2.begin(); i != constQueue2.end(); ++i) {
        out << *i << " , ";
    }
    out << endl;
    queue2 = constQueue2;
    for(Queue<HealthPoints>::Iterator i = queue2.begin(); i != queue2.end(); ++i) {
        out << *i << " , ";
    }
    out << endl;
    transform(queue2, biggerThan200);
    for(Queue<HealthPoints>::Iterator i = queue2.begin(); i != queue2.end(); ++i) {
        out << *i << " , ";
    }
    out << endl;
    transform(queue2, zeroAll);
    for(Queue<HealthPoints>::Iterator i = queue2.begin(); i != queue2.end(); ++i) {
        out << *i << " , ";
    }
    out << endl;
    transform(queue2, maxAll);
    for(Queue<HealthPoints>::Iterator i = queue2.begin(); i != queue2.end(); ++i) {
        out << *i << " , ";
    }
    out << endl;
    transform(queue2, biggerThan200);
    Queue<HealthPoints> queue3 = filter(queue2, smallerThan300);
    for(Queue<HealthPoints>::Iterator i = queue3.begin(); i != queue3.end(); ++i) {
        out << *i << " , ";
    }
    out << endl;
    Queue<HealthPoints> queue4 = filter(queue2, noOne);
    for(Queue<HealthPoints>::Iterator i = queue4.begin(); i != queue4.end(); ++i) {
        out << *i << " , ";
    }
    out << endl;
    Queue<HealthPoints> queue5 = filter(queue2, diffFrom200);
    for(Queue<HealthPoints>::Iterator i = queue5.begin(); i != queue5.end(); ++i) {
        out << *i << " , ";
    }
    out.close();
    ASSERT(matchFiles(fileName, FILE_PATH + std::string("/expected/testQueue.txt")))
    return result;
}

///////////////////////////////////////////////////////////////////////////////////
//                                  Main                                         //
///////////////////////////////////////////////////////////////////////////////////

#define NUMBER_OF_TESTS 9

#define TEST_NAMES \
    X(testHpBySegel) \
    X(testConstructorHp) \
    X(testBooleanOperatorsHp) \
    X(testArithmeticOperatorsHp) \
    X(testQueueMethodsBySegel) \
    X(testModuleFunctionsBySegel) \
    X(testExceptionsBySegel) \
    X(testConstQueueBySegel) \
    X(testQueue)
    
const char* testNames[] = {
    #define X(name) #name,
        TEST_NAMES
    #undef X
};

bool (*tests[])(void) = {
    #define X(test_name) test_name,
        TEST_NAMES
    #undef X
};

int main(int argc, char* argv[]) {
    cout << "\nRUNNING IDAN'S TESTS... GOOD LUCK =]\n" << endl;
    if (argc < 2) {
        for (int i = 0; i < NUMBER_OF_TESTS; i++) {
            RUN_TEST(tests[i], testNames[i])
        }
    }
    else if (argc > 2) {
        std::cout << "invalid arguments" << std::endl;
    }
    else {
        int i = std::atoi(argv[1]);
        tests[i - 1]();
    }
    if(counter == NUMBER_OF_TESTS){
        cout << "Congratulations!! You passed all the tests successfully =]" << endl;
    }else{
        cout << "Sorry buddy, you failed some of the tests =[" << endl;
    }
    return 0;
}
