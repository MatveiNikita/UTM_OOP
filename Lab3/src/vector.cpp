#include"../templates/vector.hpp"
#include<iostream>

vector::vector()
{
    _capacity = 16;
    _size = 0;
    _data = new int[_capacity];
};

vector::vector(unsigned int capacity)
{
    if (capacity < 1) throw std::invalid_argument("capacity cannot be 0");
    
    _data = new int[capacity];
    _capacity = capacity;
    _size = 0;
};

vector::vector(unsigned int size, const int* value)
{
    if (value == nullptr) throw std::invalid_argument("value cannot be null");

    _capacity = size * 2;
    _size = size;
    _data = new int[_capacity];

    std::copy(value, value + size, _data);
}

vector::~vector()
{
    delete[] _data;
}

vector::vector(const vector& v)
{
    _size = v._size;
    _capacity = v._size;
    _data = new int[_capacity];

    for (size_t i = 0; i < _size; i++)
    {
        _data[i] = v.get(i);
    }
}

vector::vector(vector&& v)
{
    _data = v._data;
    _size = v._size;
    _capacity = v._capacity;

    v._data = nullptr;
    v._size = 0;
    v._capacity = 0;

}

vector& vector::operator=(const vector& v)
{
    if (this == &v)
        return *this;

    if (_capacity != v._capacity)
    {
        delete[] _data;
        _capacity = v._capacity;
        _data = new int[_capacity];
    }

    _size = v._size;

    for (size_t i = 0; i < _size; i++)
    {
        _data[i] = v.get(i);
    }

    return *this;
}

vector& vector::operator=(vector&& v)
{

    if (this == &v)
        return *this;    

    delete[] _data;
    
    _data = v._data;
    _size = v._size;
    _capacity = v._capacity;

    v._data = nullptr;
    v._size = 0;
    v._capacity = 0;
}

void vector::add(int value)
{
    if (_size >= _capacity)
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

void vector::add(unsigned int index, int value)
{
    if (index > _size) throw std::out_of_range("Index: " + std::to_string(index) + ", size: " + std::to_string(_size));

    if (_size >= _capacity)
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

void vector::addAll(const vector* v)
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


int vector::get(unsigned int index) const
{
    if (index > _size) throw std::out_of_range("Index: " + std::to_string(index) + ", size: " + std::to_string(_size));

    return _data[index];
}

unsigned int vector::size() const
{
    return _size;
}

void vector::clear()
{
    delete[] _data;

    _capacity = 16;
    _data = new int[_capacity];
    _size = 0;
}

void vector::swap(unsigned int index_x, unsigned int index_y)
{
if (index_x >= _size || index_y >= _size) 
        throw std::out_of_range("Index out of range");

    int tmp = _data[index_x];
    _data[index_x] = _data[index_y];
    _data[index_y] = tmp;
}

void vector::pop_back()
{
    _size--;
}

int vector::operator[](unsigned long int index) const
{   
    return _data[index];
}

int&  vector::operator[](unsigned long int index) 
{
    return _data[index];
}

bool operator==(const vector &lhs, const vector &rhs) //а тут friend выдает ошибку
{
    // if (lhs || rhs)   ПРОВЕРКА на NULL?? 
    // {
    // }
    
    if (lhs.size() != rhs.size())
    {
        return false;
    }

    for (size_t i = 0; i < rhs.size(); i++)
    {
        if (lhs.get(i) != rhs.get(i))
        {
            return false;
        }
        
    }
    
    return true;
}

bool operator!=(const vector &lhs, const vector &rhs) //а тут friend выдает ошибку
{   
    
    if (lhs.size() != rhs.size())
    {
        return true;
    }

    for (size_t i = 0; i < rhs.size(); i++)
    {
        if (lhs.get(i) == rhs.get(i))
        {
            return false;
        }
        
    }
    
    return true;
}

bool operator<(const vector &lhs, const vector &rhs)
{
    unsigned int min_size;

    lhs.size() <= rhs.size() ? min_size = lhs.size() : min_size = rhs.size();
    
    for (size_t i = 0; i < min_size; i++)
    {
        if (lhs.get(i) > rhs.get(i))
        {
            return false;
        }
    }
    
    return lhs.size() < rhs.size() ? true : false;
}

bool operator<=(const vector &lhs, const vector &rhs)
{   
    if (operator==(lhs, rhs)) return true;

    if (operator<(lhs, rhs))return true;
    
    return false;
}

bool operator>(const vector &lhs, const vector &rhs)
{
    unsigned int min_size;

    lhs.size() <= rhs.size() ? min_size = lhs.size() : min_size = rhs.size();

    for (size_t i = 0; i < min_size; i++)
    {
        if (lhs.get(i) < rhs.get(i))
        {
            return false;
        }
    }
    
    return lhs.size() > rhs.size() ? true : false;
}

bool operator>=(const vector &lhs, const vector &rhs)
{   
    if (operator==(lhs, rhs)) return true;

    if (operator>(lhs, rhs))return true;
    
    return false;
}