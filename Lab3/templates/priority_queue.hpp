#ifndef TEMPLATES_PRIORITY_QUEUE_HPP
#define TEMPLATES_PRIORITY_QUEUE_HPP
#include <functional>
#include <vector.hpp>


class priority_queue
{
<<<<<<< HEAD
    void heapify(unsigned int index);
    vector _queue;
    unsigned int _size{0};
=======
    void heapify(unsigned int);
    vector _queue{};
>>>>>>> refs/remotes/origin/main
public:
    priority_queue() : priority_queue(vector()) {}
    priority_queue(const vector&);
    priority_queue(vector&&) noexcept;
    priority_queue(const priority_queue&) = default;
    priority_queue(priority_queue&&) noexcept = default;

    priority_queue& operator=(const priority_queue&) = default;
    priority_queue& operator=(priority_queue&&) noexcept = default;

    ~priority_queue() = default;

    void push(int);
    int pop();
    int top() const;
    size_t size() const { return _queue.size(); }
    bool empty() const { return !size(); }
    void swap(priority_queue&) noexcept;
    friend void swap(priority_queue&, priority_queue&) noexcept;
};


#endif
