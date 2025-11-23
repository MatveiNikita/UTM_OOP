#ifndef TEMPLATES_VECTOR_HPP
#define TEMPLATES_VECTOR_HPP

#include <cstddef>
#include <initializer_list>

class vector
{
    int* _data{nullptr};
    size_t _size{0};
    size_t _capacity{0};
public:
    vector();
    vector(size_t);
    vector(const std::initializer_list<int>&);
    ~vector();
    vector(const vector&);
    vector(vector&&) noexcept;

    vector& operator=(const vector&);
    vector& operator=(vector&&) noexcept;
    vector& operator=(const std::initializer_list<int>&);

    int& operator[](size_t);
    int operator[](size_t) const;
    
    int& at(size_t);
    int at(size_t) const;

    void add(int value);
    void add(size_t, int);
    void addAll(const vector* v);
    void remove(size_t);
    int get(size_t) const;
    size_t size() const;
    bool empty() const { return !size(); }
    void clear();
    void swap(size_t, size_t) noexcept;
    void pop_back();
<<<<<<< HEAD

    friend bool operator!=(const vector &lhs,const vector &rhs);  //какого черто это не работает без friend????
    friend bool operator==(const vector &lhs, const vector &rhs);
    friend bool operator<=(const vector &lhs, const vector &rhs);
    friend bool operator<(const vector &lhs, const vector &rhs);
    friend bool operator>=(const vector &lhs, const vector &rhs);
    friend bool operator>(const vector &lhs, const vector &rhs);

=======
    void push_back(int);
    void swap(vector&) noexcept;
    friend void swap(vector&, vector&) noexcept;

    friend bool operator==(const vector&, const vector&);
    friend bool operator!=(const vector& a, const vector& b) { return !(a == b); }
    friend bool operator<(const vector&, const vector&);
    friend bool operator>(const vector& a, const vector& b) { return b < a; }
    friend bool operator<=(const vector& a, const vector& b) { return !(a > b); }
    friend bool operator>=(const vector& a, const vector& b) { return !(a < b); }

    void assign(size_t, int);
    void resize(size_t);
>>>>>>> refs/remotes/origin/main
};

#endif
