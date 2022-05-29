#ifndef QUEUE_CPP_EX3
#define QUEUE_CPP_EX3

#include <stdio.h>

template <class T>
const T *FIRST_QUEUE_DEFUALT_VALUE = nullptr;

template <class T>
const T *NEXT_QUEUE_DEFUALT_VALUE = nullptr;

const int INITIAL_QUEUE_SIZE = 0;

/*
 *  Queue:
 *  A FIFO Data structures.
 */
template <class T>
class Queue
{
private:
    T m_data;
    Queue<T> *m_next;
    int m_size;

public:
    /*
     * C'tor of Queue class.
     * Uses the defualt C'tor of the given m_data class (expected to be implemented).
     */
    Queue();

    /*
     * Copy C'tor of Queue class.
     *
     */
    Queue(const Queue<T> &queue_to_copy);

    /*
     * D'tor of Queue class.
     *
     */
    ~Queue();

    /*
     * Assignment operator  of Queue class.
     *
     */
    Queue<T> &operator=(const Queue<T> &queue_to_copy);

    /*
     * Adds a new instance to the end of the queue:
     *
     * @param lastInstance - the new instance that will be added to the end of the queue.
     * @return
     *      void
     */
    void pushBack(const T &lastInstance);

    /*
     * Returns the first instance on the queue (the next instance to be poped):
     *
     * @return
     *      first instance on the queue.
     */
    T &front() const;

    /*
     * remove the first instance on the queue:
     *
     * @return
     *      void
     */
    void popFront();

    /*
     * The current number of instances on the queue:
     *
     * @return
     *      The current number of instances on the queue, 0 if the queue is empty.
     */
    int size() const;

    /*
     * EmptyQueue is an exeption, raises when the current queue is emtpy but the
     * user is trying to do an opration that is only possible on a non empty queues.
     */
    class EmptyQueue
    {
    };

    /*
     *  Iterator:
     *  Iterates over Queue's objects from the first node to the last node (FIFO).
     */
    template <class T>
    class Iterator
    {
    public:
        const T &operator*() const;
        Itrator &operator++();
        Itrator operator++(int);

        bool oprator == (const Iterator &itrator) const;
        bool oprator != (const Iterator &itrator) const;

        /*
         * Here we are explicitly telling the compiler to use the default methods.
         */
        Iterator(const Iterator &) = defualt;
        Iterator &operator=(const Iterator &) = defualt;

        /*
         * InvalidOperation is an exeption, raises when the user is trying to do an
         * illgal operation on the iterator pointing on the last not of the queue.
         */
        class InvalidOperation
        {
        };

    private:
        const Queue<T> *m_queue;
        int m_index;

        // private constractor for encapsulation reasons.
        Iterator(const Queue<T> *queue, int index);
        freind class Queue<T>;
    }
};

/*
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

/*
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

    for (Queue<T>::Iterator it = this.begin(); it != this.end(); ++it)
    {
        if (condition(it))
        {
            filteredQueue.pushBack(it);
        }
    }

    return &filteredQueue;
}

/*
 * Change a given queue by a given operation:
 *
 * @param operation on witch the queue will be chagned by.
 * @return
 *      a new queue, all instances on the given queue who meets with the given conditions.
 */
template <class Operaion, class T>
void transform(const Queue<T> queue, Operaion operation);

// START OF IMPLEMENTATION

template <class T>
T &Queue<T>::front() const
{
    makeSureQueueIsNotEmpty(this);

    return this->m_data;
}

template <class T>
void Queue<T>::popFront()
{
    makeSureQueueIsNotEmpty(this);

    else if (this.size() == 1)
    {
        this->m_data = FIRST_QUEUE_NODE_VALUE;
        this->m_next = NEXT_QUEUE_NDOE_VALUE;
    }
    else
    {
        delete this;
    }

    --this.m_size;
}

template <class T>
int Queue<T>::size() const
{
    return this->m_size;

    // int size = 0;
    // for (Queue<T>::Iterator it = this.begin(); it != this.end(); ++it)
    // {
    //     ++size;
    // }

    // return size;
}

template <class T>
void Queue<T>::pushBack(const T &addedInstance)
{
    if (this.size() == 0)
    {
        this->m_data = addedInstance;
        this->m_next = NEXT_QUEUE_DEFUALT_VALUE;
        ++this.m_size;
        return;
    }

    T lastNode = this.end();

    Queue<T> newLastNode = new Queue<T>;
    newLastNode->data = addedInstance;
    newLastNode->next = NEXT_QUEUE_DEFUALT_VALUE;

    lastNode->next = newLastNode;
    ++this.m_size;
}

template <class T>
Queue<T>::Queue()
{
    this->m_next = nullptr;
    this->m_data = T(); // explicitly calling T default constructor.
    this->m_size = 0;
}

template <class T>
Queue<T>::~Queue()
{
    delete this->data;
    if (this->next != NEXT_QUEUE_DEFUALT_VALUE)
    {
        delete this->next;
    }
}

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
}

// END OF IMPLEMENTATION

#endif // QUEUE_CPP_EX3
