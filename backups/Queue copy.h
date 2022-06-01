

Queue<T>& filter(const Queue<T>& queue, bool (*condition)(T));


void transform(Queue<T>& queue, void (*operation)(T&));


template <class T>
Queue<T>::Queue(const Queue& other) : m_firstElement(new Node(*other.m_firstElement))
{
    m_lastElement = m_firstElement;
    try {
        Node *temp = new Node(*other.m_firstElement);
        while (temp && temp->m_next) {
            temp = temp->m_next;
            m_lastElement->m_next = new Node(*temp);
            m_lastElement = m_lastElement->m_next;
        }
    }
    catch (const std::bad_alloc& memoryAllocationError){
        delete(this);
        throw;
    }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if (this == &other){
        return *this;
    }

    Node *toDelete = m_firstElement;
    while(!isEmpty()){
        m_firstElement = m_firstElement->m_next;
        delete(toDelete);
        toDelete = m_firstElement;
    }

    try{
        m_firstElement = new Node(*other.m_firstElement);
        Node *temp = other.m_firstElement;
        while (temp && temp->m_next) {
            temp = temp->m_next;
            m_lastElement->m_next = new Node(*temp);
            m_lastElement = m_lastElement->m_next;
        }
    }
    catch (const std::bad_alloc& memoryAllocationError) {
        delete (this);
        throw;
    }
    return *this;
}





template <class T>
const T& Queue<T>::front() const {
    if (isEmpty()) {
        throw Queue<T>::EmptyQueue();
    }
    return m_firstElement->m_value;
}




template <class T>
Queue<T>& filter(const Queue<T>& queue, bool (*condition)(T))
{
    try {
        //Queue<T>* filteredQueue = new Queue<T>();
       // for (typename Queue<T>::ConstIterator currentNode = queue.begin();
          //   currentNode != queue.end(); ++currentNode) {


         //   if (condition(*currentNode)) {
                filteredQueue->pushBack(*currentNode);
       //     }
        }
       // return *filteredQueue;
    }
   // catch (std::bad_alloc& memoryAllocationError)
   // {
  //      delete (&queue);
   //     throw;
    }
}
