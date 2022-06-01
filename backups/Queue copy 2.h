#ifndef QUEUE_CPP_EX3
#define QUEUE_CPP_EX3

#include <stdio.h>

const int DUMMY_NODE_VALUES = nullptr;

const int INITIAL_QUEUE_SIZE = 0;
const int EMPTY_QUEUE_SIZE = 1;

/**
 *  Queue:
 *  A FIFO Data structures.
 */
template <class T>
class Queue
{
private:
    Queue<T>::QueueNode<T> *m_firstNode;
    Queue<T>::QueueNode<T> *m_lastNode;
    int m_size;

    // T m_data;
    // Queue<T> *m_next;     // if next is nullptr then this is the last node.
    // Queue<T> *m_previous; // if previous is nullptr then this is the first one.
    // int m_size;

public:
    /**
     * C'tor of Queue class.
     * Uses the defualt C'tor of the given m_data class (expected to be implemented).
     */
    Queue();

    /**
     * Copy C'tor of Queue class.
     *
     */
    Queue(const Queue<T> &queue_to_copy);

    /**
     * D'tor of Queue class.
     *
     */
    ~Queue();

    /**
     * Assignment operator  of Queue class.
     *
     */
    Queue<T> &operator=(const Queue<T> &queue_to_copy);

    /**
     * Gets iterator, the first node in the queue.
     *
     */
    Queue<T> &begin();

    /**
     * Gets iterator, the last node in the queue.
     *
     */
    Queue<T> &end();

    /**
     * Adds a new instance to the end of the queue:
     *
     * @param lastInstance - the new instance that will be added to the end of the queue.
     * @return
     *      void
     */
    void pushBack(const T &lastInstance);

    /**
     * Returns the first instance on the queue (the next instance to be poped):
     *
     * @return
     *      first instance on the queue.
     */
    T &front() const;

    /**
     * remove the first instance on the queue:
     *
     * @return
     *      void
     */
    void popFront();

    /**
     * The current number of instances on the queue:
     *
     * @return
     *      The current number of instances on the queue, 0 if the queue is empty.
     */
    int size() const;

    /**
     * EmptyQueue is an exeption, raises when the current queue is emtpy but the
     * user is trying to do an opration that is only possible on a non empty queues.
     */
    class EmptyQueue
    {
    };

    /**
     *  ConstIterator:
     *  Iterates over Queue's objects from the first node to the last node (FIFO).
     */
    template <class T>
    class ConstIterator
    {
    public:
        const T &operator*() const;
        Itrator &operator++();
        Itrator operator++(int);

        bool oprator == (const ConstIterator &itrator) const;
        bool oprator != (const ConstIterator &itrator) const;

        /**
         * Here we are explicitly telling the compiler to use the default methods.
         */
        ConstIterator(const ConstIterator &) = defualt;
        ConstIterator &operator=(const ConstIterator &) = defualt;

        /**
         * InvalidOperation is an exeption, raises when the user is trying to do an
         * illgal operation on the ConstIterator pointing on the last not of the queue.
         */
        class InvalidOperation
        {
        };

    private:
        const Queue<T> *m_node;
        int m_index;
        bool m_isFirst;
        bool m_isLast;

        // private constractor for encapsulation reasons.
        ConstIterator(const Queue<T> *queue, int index);
        freind class Queue<T>;
    }

    template <class T>
    class QueueNode
    {
        explicit QueueNode(T data, T *m_next, T *m_previous, bool m_isDummy);

    private:
        T m_data;
        T *m_next;
        T *m_previous;
        bool m_isDummy;
    }
};

/**
 * makes sure the current queue is not empty, if it is indeed empty raises an
 * EmptyQueue exeption.
 */
template <class T>
void makeSureQueueIsNotEmpty(const Queue<T> &queue)
{
    if (queue.size() == 0)
    {
        throw Queue<T>::EmptyQueue;
    }
}

/**
 * Filters a given queue by a given condition:
 *
 * @param condition on witch the queue will be filtered by.
 * @return
 *      void.
 */
template <class Condition, class T>
Queue<T> &filter(const Queue<T> queue, Condition condition)
{
    Queue<T> filteredQueue = new Queue<T>();

    for (Queue<T>::ConstIterator it = this.begin(); it != this.end(); ++it)
    {
        if (condition(it))
        {
            filteredQueue.pushBack(it);
        }
    }

    return &filteredQueue;
}

/**
 * Change a given queue by a given operation:
 *
 * @param operation on witch the queue will be chagned by.
 * @return
 *      a new queue, all instances on the given queue who meets with the given conditions.
 */
template <class Operaion, class T>
void transform(const Queue<T> queue, Operaion operation);

// START OF IMPLEMENTATION

// TODO: implement
template <class T>
T &Queue<T>::front() const
{
    makeSureQueueIsNotEmpty(this);

    return this.m_firstNode->m_data;
}

// TODO: implement
template <class T>
void Queue<T>::()
{
    makeSureQueueIsNotEmpty(this);

    else if (this.size() == 1) // remove the only node.
    {
        m_fromt =
    }

    else
    {
        delete this;
    }

    --this.m_size;
}

// TODO: implement
template <class T>
int Queue<T>::size() const
{
    return this->m_size;
}

// TODO: implement
template <class T>
void Queue<T>::pushBack(const T addedInstance)
{
    Queue<T>::QueueNode<T>::QueueNode newNode = new Queue<T>::QueueNode<T>::QueueNode(addedInstance, m_lastNode->m_next, m_lastNode);
    m_lastNode->m_previous = newNode;
    m_lastNode->m_next->m_previous = newNode;
    ++this.m_size;
}

// TODO: implement
template <class T>
Queue<T>::Queue()
{
    this->m_next = nullptr;
    this->m_data = T(); // explicitly calling T default constructor.
    this->m_size = 0;
}

// TODO: implement
template <class T>
Queue<T>::~Queue()
{
    delete this->data;
    if (this->next != nullptr)
    {
        delete this->next;
    }
}

// TODO: implement
template <class T>
Queue<T>::Queue(const Queue &queue_to_copy) : data(new T(queue_to_copy.data))
{
    try
    {
        this->m_next(queue_to_copy->m_next);
    }
    catch (…)
    {
        delete this->data;
        throw;
    }
}

// TODO: implement
template <class T>
Queue<T>::Queue<T> &begin()
{
    while (this.m_node.previos != nullptr)
    {
    }
}

// TODO: implement
template <class T>
explicit Queue<T>::QueueNode(T data, T *next, T *previous, bool isDummy)
{
    try
    {
        this.m_data = new T(data);
    }
    catch ()
    {
    }
    this.m_next = next;
    this.m_previous = previous;
    this.m_isDummy = isDummy;
}

// TODO: implement
template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &queue_to_copy)
{
    if (this == &queue_to_copy)
    {
        return *this;
    }

    T *tempData = new Queue<T>;
    try
    {
        this->m_data = queue_to_copy->m_data;

        for (int i = 0; i < nextIndex; ++i)
        {
            data[i] = s.data[i];
        }
    }
    catch (…)
    {
        delete tempData;
        throw;
    }
    delete[] data;
    data = tempData;

    return *this;
}

// TODO: implement
template <class T>
const T &Queue<T>::ConstIterator::operator*() const
{
    if (this.isLast)
    {
        throw Queue<T>::ConstIterator::InvalidOperation;
    }
    return this->m_node;
}

// TODO: implement
template <class T>
Itrator &Queue<T>::ConstIterator::operator++()
{
    if (this.m_node.next == nullptr)
    {
        throw Queue<T>::ConstIterator::InvalidOperation;
    }
    this->m_node = this->m_node.next;
    return this;
}

// TODO: implement
template <class T>
Itrator Queue<T>::ConstIterator::operator++(int) {}

template <class T>
    bool Queue<T>::ConstIterator::oprator == (const ConstIterator &itrator) const
{
    return this.m_node == itrator.m_node;
}

template <class T>
    bool Queue<T>::ConstIterator::oprator != (const ConstIterator &itrator) const
{
    return !(this.m_node == itrator.m_node);
}

// END OF IMPLEMENTATION

#endif // QUEUE_CPP_EX3
