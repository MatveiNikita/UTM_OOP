#include"../templates/vector.hpp"
#include<iostream>

Vector::Vector()
{
    _capacity = 16;
    _size = 0;
    _data = new int[_capacity];
};

Vector::Vector(unsigned int capacity)
{
    if (capacity < 1) throw std::invalid_argument("capacity cannot be 0");
    
    _data = new int[_capacity];
    _size = 0;
};

Vector::Vector(unsigned int size, const int* value)
{
    if (value == nullptr) throw std::invalid_argument("value cannot be null");

    _capacity = size * 2;
    _size = size;
    _data = new int[_capacity];

    std::copy(value, value + size, _data);
}

Vector::~Vector()
{
    delete[] _data;
}

void Vector::add(int value)
{
    if (_size++ >= _capacity)
    {
        _capacity *= 2;
        int* __new_data = new int[_capacity];
        std::copy(_data, _data + _size, __new_data);
        delete[] _data;
        _data = __new_data;
    }

    _data[_size] = value;
    ++_size;
}

void Vector::add(unsigned int index, int value)
{
    if (index > _size) throw std::out_of_range("Index: " + std::to_string(index) + ", size: " + std::to_string(_size));

    if (_size++ >= _capacity)
    {
        _capacity *= 2;
        int* __new_data = new int[_capacity];
        std::copy(_data, _data + _size, __new_data);
        delete[] _data;
        _data = __new_data;
    }

    for(size_t i = _size; i > index; i--)
    {
        _data[i] = _data[i - 1];
    }

    _data[index] = value;
    ++_size;
}

void Vector::addAll(const Vector* v)
{
    if (v == nullptr) throw std::invalid_argument("value cannot be null");
    
    if (_size + v->_size >= _capacity)
    {
        _capacity =  _capacity * 2 + v->_size;
        int* __new_data = new int[_capacity];
        std::copy(_data, _data + _size, __new_data);
        delete[] _data;
        _data = __new_data;
    }
    
    std::copy(v->_data, v->_data + v->_size, _data + _size);
    _size += v->_size;
}

// void Vector::addAll(unsigned int index, const Vector* v)
// {
//     if (index > _size) throw std::out_of_range("Index: " + std::to_string(index) + ", size: " + std::to_string(_size));

//     if (v == nullptr) throw std::invalid_argument("value cannot be null");


//     if (_size + v->_size >= _capacity)
//     {
//         _capacity =  _capacity * 2 + v->_size;
//         int* __new_data = new int[_capacity];
//         std::copy(_data, _data + _size, __new_data);
//         delete[] _data;
//         _data = __new_data;
//     }

//     if (index == _size)
//     {
//         std::copy(v->_data, v->_data + index, _data + _size);
//         return;
//     }
    
//     int* _new_insert_data = new int[_capacity];
// }

int Vector::get(unsigned int index)
{
    if (index > _size) throw std::out_of_range("Index: " + std::to_string(index) + ", size: " + std::to_string(_size));

    return _data[index];
}

unsigned int Vector::size()
{
    return _size - 1;
}

void Vector::clear()
{
    delete[] _data;

    _capacity = 16;
    _data = new int[_capacity];
    _size = 0;
}