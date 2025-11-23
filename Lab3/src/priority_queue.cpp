#include <utility>

#include "../templates/priority_queue.hpp"


priority_queue::priority_queue(const vector& v)
{
    _queue = v;
    for (size_t i = 0; i < v.size(); i++)
    {
        _queue[i] = v.get(i);
    }
}

priority_queue::priority_queue(vector&& v) noexcept
{
    _queue = std::move(v);
}

void priority_queue::push(int elm)
{
    _queue.add(elm);
    
    for (int i = size() / 2 - 1; i >= 0; i--)
        heapify(0);
}

int priority_queue::pop()
{
    if (size() == 0) {
        return 0; 
    }

    int root = _queue[0];

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
    auto _size = size();

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
