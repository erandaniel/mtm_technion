#ifndef QUEUE_CPP_EX3
#define QUEUE_CPP_EX3

#include <stdio.h>

#include <iostream>

const int EMPTY_QUEUE_SIZE = 2;

template <class T>
class Queue
{
public:
    struct Node
    {
    public:
        Node(const T element);
        Node(const Node &nodeToCopy);

        explicit Node(T m_data, Node *m_next, Node *m_previous, bool m_isDummy);

        T m_data;
        Node *m_next;
        Node *m_previous;
        bool m_isDummy;
    };

    Queue();
    Queue(const Queue &queueToCopy);
    Queue<T> &operator=(const Queue &queueToCopy);
    ~Queue();

    void pushBack(const T &addedInstance);
    int size() const;
    void popFront();
    T &front() const;

    void toString();

    class EmptyQueue
    {
    };

    class Iterator;
    Iterator begin();
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

private:
    Node *m_firstNode;
    Node *m_lastNode;
    int m_size;
};

template <class T>
class Queue<T>::Iterator
{
public:
    T &operator*();
    Iterator &operator++();
    Iterator operator++(int);

    bool operator!=(const Iterator &iterator);

    Iterator(const Iterator &itertor) = default;
    Iterator &operator=(const Iterator &itertor) = default;

    class InvalidOperation
    {
    };

private:
    const Queue<T> *m_queue;
     Node *m_currentNode;
    // private constractor for encapsulation reasons.
    Iterator(const Queue<T> *queue, Node *m_currentNode);
    friend class Queue<T>;
};

template <class T>
T &Queue<T>::Iterator::operator*()
{
    if (!this->m_currentNode)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    return this->m_currentNode->m_data;
}

template <class T>
typename Queue<T>::Iterator &Queue<T>::Iterator::operator++()
{
    if (this->m_currentNode->m_previous == nullptr)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }

    this->m_currentNode = this->m_currentNode->m_previous;

    return *this;
}

template <class T>
Queue<T>::Iterator::Iterator(const Queue<T> *queue, Node *currentNode) : m_queue(queue), m_currentNode(currentNode)
{
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
{
    Iterator *previousIterator = this;
    ++*this;
    return *previousIterator;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator &iterator)
{
    return (this->m_currentNode != iterator.m_currentNode);
}

template <class T>
class Queue<T>::ConstIterator
{
public:
    const T &operator*() const;
    ConstIterator &operator++();
    ConstIterator operator++(int);

    bool operator!=(const ConstIterator &iterator) const;

    ConstIterator(const ConstIterator &itertor) = default;
    ConstIterator &operator=(const ConstIterator &itertor) = default;

    class InvalidOperation
    {
    };

private:
    const Queue<T> *m_queue;
    const Node *m_currentNode;
    // private constractor for encapsulation reasons.
    ConstIterator(const Queue<T> *queue, Node *m_currentNode);
    friend class Queue<T>;
};

template <class T, class Condition>
Queue<T> &filter(const Queue<T> &queue, Condition condition);

template <class T, class Operation>
void transform(Queue<T> &queue, Operation &operation);

template <class T>
const T &Queue<T>::ConstIterator::operator*() const
{
    if (!this->m_currentNode)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    return this->m_currentNode->m_data;
}

template <class T>
typename Queue<T>::ConstIterator &Queue<T>::ConstIterator::operator++()
{
    if (this->m_currentNode->m_previous == nullptr)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }

    this->m_currentNode = this->m_currentNode->m_previous;

    return *this;
}

template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T> *queue, Node *cuurentNode) : m_queue(queue), m_currentNode(cuurentNode)
{
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
{
    ConstIterator *previousIterator = this;
    ++*this;
    return *previousIterator;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator &iterator) const
{
    return (this->m_currentNode != iterator.m_currentNode);
}

template <class T>
T &Queue<T>::front() const
{
    if (this->m_size == EMPTY_QUEUE_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }

    return this->m_firstNode->m_previous->m_data;
}

template <class T>
int Queue<T>::size() const
{
    return this->m_size - EMPTY_QUEUE_SIZE;
}

template <class T>
Queue<T>::Node::Node(T m_data, Node *next, Node *previous, bool isDummy) : m_data(m_data)
{
    this->m_next = next;
    this->m_previous = previous;
    this->m_isDummy = isDummy;
};

template <class T>
Queue<T>::Node::Node(T m_data) : m_data(m_data){};

template <class T>
Queue<T>::Node::Node(const Node &nodeToCopy)
{
    try
    {
        this->m_data = T(nodeToCopy->m_data);
    }
    catch (const std::bad_alloc &memoryExeption)
    {
        delete *this;
        throw;
    }

    this->m_isDummy = nodeToCopy->m_isDummy;
    this->m_next = nodeToCopy->m_next;
    this->m_previous = nodeToCopy->m_next;
};

template <class T>
void Queue<T>::popFront()
{
    if (this->m_size == EMPTY_QUEUE_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }

    Node *popedNode = this->m_firstNode->m_previous;

    this->m_firstNode->m_previous = popedNode->m_previous;
    popedNode->m_previous->m_next = this->m_firstNode;

    delete popedNode;

    --this->m_size;
}

template <class T>
void Queue<T>::pushBack(const T &addedInstance)
{
    Node *newNode = nullptr;

    try
    {
        newNode = new Node(addedInstance, m_lastNode->m_next, m_lastNode, false);
        newNode->m_next = m_lastNode->m_next;
        newNode->m_previous = m_lastNode;
    }
    catch (const std::bad_alloc &memoryExeption)
    {
        delete this;
        throw;
    }

    m_lastNode->m_next->m_previous = newNode; // the real last node points back at new.
    m_lastNode->m_next = newNode;             // dummy last node points to new.
    ++this->m_size;
}

template <class T>
Queue<T>::Queue()
{
    Node *firstNode = new Node(T(), nullptr, nullptr, true);
    Node *lastNode = new Node(T(), nullptr, nullptr, true);

    lastNode->m_next = firstNode;
    firstNode->m_previous = lastNode;

    m_firstNode = firstNode;
    m_lastNode = lastNode;

    m_size = EMPTY_QUEUE_SIZE;
}

template <class T>
Queue<T>::~Queue()
{
    Node *nodeToDelete = this->m_firstNode;

    while (nodeToDelete != this->m_lastNode)
    {
        this->m_firstNode = this->m_firstNode->m_previous;
        delete nodeToDelete;
        nodeToDelete = this->m_firstNode;
    }

    delete this->m_lastNode;
}

template <class T>
void Queue<T>::toString()
{
    Queue<T>::Iterator i = this->begin();
    Queue<T>::Iterator end = this->end();
    for (i; i != end; ++i)
    {
        std::cout << i.m_currentNode->m_data << "\n";
    }

    return;

    Node *nodeToPrint = this->m_firstNode->m_previous;

    while (nodeToPrint != this->m_lastNode)
    {
        std::cout << nodeToPrint->m_data << '\n';
        nodeToPrint = nodeToPrint->m_previous;
    }
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return ConstIterator(this, this->m_firstNode->m_next);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(this, this->m_lastNode);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    return Iterator(this, this->m_firstNode->m_previous);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(this, this->m_lastNode);
}

template <class T>
Queue<T>::Queue(const Queue &queueToCopy)
{
    try
    {
        *this = Queue();

        for (typename Queue<T>::ConstIterator it = queueToCopy.begin(); it != queueToCopy.end(); ++it)
        {
            this->pushBack(it.m_currentNode->m_data);
        }
    }
    catch (const std::bad_alloc &memoryExeption)
    {
        delete this;
        throw;
    }
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue &queueToCopy)
{

    if (this == &queueToCopy)
    {
        return *this;
    }

    Queue<T> *tempQueue = new Queue<T>();

    if (this->size() >= queueToCopy.size())
    {
        int extraNodes = this->size() - queueToCopy.size();
        for (int i = extraNodes; i <= 0; --i)
        {
            this->popFront();
        }
    }

    if (this->size() < queueToCopy.size())
    {
        int missingNodes = queueToCopy.size() - this->size();
        for (int i = missingNodes; i <= 0; --i)
        {
            try
            {
                Node *dummyNode = new Node(T(), nullptr, nullptr, true);
                this->pushBack(T());
            }
            catch (const std::bad_alloc &memoryExeption)
            {
                delete &queueToCopy;
                throw;
            }
        }
    }

    Queue<T>::Iterator thisIterator = this->begin();
    Queue<T>::ConstIterator otherIterator = queueToCopy.begin();
    for (int i = 0; i < this->size(); i++)
    {
        *thisIterator = *otherIterator;
        ++thisIterator;
        ++otherIterator;
    }

    return *this;
}

template <class T, class Condition>
Queue<T> &filter(const Queue<T> &queue, Condition condition)
{
    try
    {
        Queue<T> *filteredQueue = new Queue<T>();

        for (typename Queue<T>::ConstIterator i = queue.begin(); i != queue.end(); ++i)
        {
            if (condition(*i))
            {
                filteredQueue->pushBack(*i);
            }
        }

        return *filteredQueue;
    }
    catch (const std::bad_alloc &memoryExeption)
    {
        throw;
    }
}

template <class T, class Operation>
void transform(Queue<T> &queue, Operation &operation)
{
    int size = queue.size();
    while (size > 0) // > true or >= false
    {
        operation(queue.front());      // a3tked hen 4lt
        queue.pushBack(queue.front()); // athen sa7 hkol lazm for(int i=0 ; i<size ; i++)
        queue.popFront();              // { operation(m_data[i])} sa3etha lazm frined
        size--;                        // aw lazm Queue<T> tmp = queue; ......
    }

    // for (typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it)
    // {
    //     operation(*it);
    // }
}

#endif // QUEUE_CPP_EX3
