#include "../templates/priority_queue.hpp"

priority_queue::priority_queue(){
    _queue = new Vector();
    _size = _queue->size();
}

priority_queue::priority_queue(const priority_queue& cpy_p_queue)
{
    _queue = new Vector();

    for (unsigned int i = 0; i < cpy_p_queue._size; i++)
    {
        _queue->_data[i] = cpy_p_queue._queue->_data[i];
    }

    _size = cpy_p_queue._size;
}

priority_queue::priority_queue(priority_queue&& move_p_queue)
{
    _queue = move_p_queue._queue;
    _size = move_p_queue._size;

    move_p_queue._queue = nullptr;
    move_p_queue._queue->~Vector();
}

priority_queue::~priority_queue()
{
    _queue->~Vector();
    _size = 0;
}