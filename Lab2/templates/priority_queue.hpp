#ifndef TEMPLATES_PRIORITY_QUEUE_HPP
#define TEMPLATES_PRIORITY_QUEUE_HPP
#include <vector.hpp>


class priority_queue
{
public:
    vector _queue;
    unsigned int _size;
    priority_queue();
    priority_queue(const priority_queue& cpy_p_queue);  //sholow copy & deep copy
    priority_queue(priority_queue&& move_p_queue);
    ~priority_queue();

    void push(int elm);
    int pop();
    void heapify(unsigned int index);
};


#endif TEMPLATES_PRIORITY_QUEUE_HPP