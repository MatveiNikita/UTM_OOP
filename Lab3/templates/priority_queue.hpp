#ifndef TEMPLATES_PRIORITY_QUEUE_HPP
#define TEMPLATES_PRIORITY_QUEUE_HPP
#include <functional>
#include <vector.hpp>


class priority_queue
{
    void heapify(unsigned int index);
    vector _queue{};
    unsigned int _size{0};
public:
    priority_queue() = default;
    priority_queue(const vector& v);
    priority_queue(vector&& v);
    priority_queue(const priority_queue& cpy_p_queue);
    priority_queue(priority_queue&& move_p_queue);

    priority_queue& operator=(const priority_queue& p);
    priority_queue& operator=(priority_queue&& p);

    ~priority_queue() = default;

    void push(int elm);
    int pop();
};


#endif