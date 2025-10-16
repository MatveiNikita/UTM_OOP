#ifndef TEMPLATES_PRIORITY_QUEUE_HPP
#define TEMPLATES_PRIORITY_QUEUE_HPP
#include <vector.hpp>


class priority_queue
{
public:
    Vector c;
    unsigned int size;
    priority_queue();
    priority_queue(const priority_queue& cpy_p_queue);  //sholow copy & deep copy
    priority_queue(const priority_queue&& move_p_queue);
    ~priority_queue();
};


#endif TEMPLATES_PRIORITY_QUEUE_HPP