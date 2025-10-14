#ifndef TEMPLATES_VECTOR_HPP
#define TEMPLATES_VECTOR_HPP

class Vector
{
public:
    int* _data;
    unsigned int _size;
    unsigned int _capacity;

    Vector();
    Vector(unsigned int capacity);
    Vector(unsigned int size, const int* value);
    ~Vector();

    void add(int value);
    void add(unsigned int index, int value);
    void addAll(const Vector* v);
    // void addAll(unsigned int index, const Vector* v);
    int get(unsigned int index);
    unsigned int size();
    void clear();
};


#endif //TEMPLATES_VECTOR_HPP