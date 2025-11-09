#include "../templates/priority_queue.hpp"

priority_queue::priority_queue(const vector& v)
{
    _queue = v;
    _size = v.size();

    for (size_t i = 0; i < _size; i++)
    {
        _queue[i] = v.get(i);
    }
}

priority_queue::priority_queue(vector&& v)
{
    _queue = v;
    _size = v.size();
}

priority_queue::priority_queue(const priority_queue& cpy_p_queue)
{
    _size = cpy_p_queue._size;
    _queue = vector();

    for (unsigned int i = 0; i < cpy_p_queue._size; i++)
    {
        _queue.add(cpy_p_queue._queue[i]);
    }
}

priority_queue::priority_queue(priority_queue&& move_p_queue)
{
    _queue = move_p_queue._queue;
    _size = move_p_queue._size;
}


priority_queue& priority_queue::operator=(const priority_queue& cpy_p_queue)
{
    if (this != &cpy_p_queue)
    {
        _queue = cpy_p_queue._queue; 
        _size = cpy_p_queue._size;
    }
    
    return *this;
}

priority_queue& priority_queue::operator=(priority_queue&& cpy_p_queue)
{
    if (this != &cpy_p_queue)
    {
        _queue = std::move(cpy_p_queue._queue); 
        _size = cpy_p_queue._size;

        cpy_p_queue._size = 0;
    }
    
    return *this;
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

    auto t = _queue[0];
    _queue[0] = _queue[_queue.size() - 1];
    _queue[_queue.size() - 1] = t;

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
        auto t = _queue[0];
        _queue[0] = _queue[_queue.size() - 1];
        _queue[_queue.size() - 1] = t; 
        
        heapify(largest);
    }
}