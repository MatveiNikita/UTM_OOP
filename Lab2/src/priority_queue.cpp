#include "../templates/priority_queue.hpp"

priority_queue::priority_queue(){
    _queue = vector();
    _size = _queue.size();
}

priority_queue::priority_queue(const priority_queue& cpy_p_queue)
{
    _queue = vector();

    for (unsigned int i = 0; i < cpy_p_queue._size; i++) //
    {
        _queue[i] = cpy_p_queue._queue[i];
    }

    _size = cpy_p_queue._size;
}

priority_queue::priority_queue(priority_queue&& move_p_queue)
{
    _queue = move_p_queue._queue;
    _size = move_p_queue._size;
}

void priority_queue::push(int elm)
{
    _queue.add(elm);
    _size++;
    
    for (int i = _size / 2 - 1; i >= 0; i--)
        heapify(0);
}

int priority_queue::pop()
{
    if (_size == 0) {
        return 0; 
    }

    int root = _queue[0];

    _size--;
    _queue.swap(0, _size);

    _queue.pop_back(); 

    heapify(0);

    return root;
}

void priority_queue::heapify(unsigned int index)
{
    unsigned int largest = index;
    unsigned int l = 2 * index + 1;
    unsigned int r = 2 * index + 2;

    if (l < _size && _queue[l] > _queue[largest]) largest = l;

    if (r < _size && _queue[r] > _queue[largest]) largest = r;

    if (largest != index)
    {
        _queue.swap(index, largest);   
        heapify(largest);
    }
    
}