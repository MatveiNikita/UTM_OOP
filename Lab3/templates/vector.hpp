#ifndef TEMPLATES_VECTOR_HPP
#define TEMPLATES_VECTOR_HPP

class vector
{
    int* _data;
    unsigned int _size;
    unsigned int _capacity;
public:
    vector();
    vector(unsigned int capacity);
    vector(unsigned int size, const int* value);
    ~vector();
    vector(const vector& v);
    vector(vector&& v);

    vector& operator=(const vector& v);
    vector& operator=(vector&& v);

    int& operator[](unsigned long int index);
    int operator[](unsigned long int index) const;

    void add(int value);
    void add(unsigned int index, int value);
    void addAll(const vector* v);
    void remove(unsigned int index);
    int get(unsigned int index) const;
    unsigned int size() const;
    void clear();
    void swap(unsigned int x, unsigned int y);
    void pop_back();

    friend bool operator!=(const vector &lhs,const vector &rhs);  //какого черто это не работает без friend????
    friend bool operator==(const vector &lhs, const vector &rhs);
    friend bool operator<=(const vector &lhs, const vector &rhs);
    friend bool operator<(const vector &lhs, const vector &rhs);
    friend bool operator>=(const vector &lhs, const vector &rhs);
    friend bool operator>(const vector &lhs, const vector &rhs);

};


#endif