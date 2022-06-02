#include "string.h"
#include <iostream>
  
StringIterator::StringIterator(char* ptr) {
    m_Ptr = ptr;
}

StringIterator& StringIterator::operator++() {
    m_Ptr++;
    return *this;
}

StringIterator StringIterator::operator++(int) {
    StringIterator iterator = *this;
    ++(*this);
    return iterator;
}

StringIterator& StringIterator::operator--() {
    m_Ptr--;
    return *this;
}

StringIterator StringIterator::operator--(int) {
    StringIterator iterator = *this;
    --(*this);
    return iterator;
}   

char& StringIterator::operator[](int index) {
    return *(m_Ptr + index);
}

char* StringIterator::operator->() {
    return m_Ptr;
}

char& StringIterator::operator*() {
    return *m_Ptr;
}

bool StringIterator::operator==(const StringIterator& other) {
    return m_Ptr == other.m_Ptr;
}
    
bool StringIterator::operator!=(const StringIterator& other) {
    return m_Ptr != other.m_Ptr;
}

String::String() = default;

String::String(char* m_arr) {
    _arr = m_arr;
    _size = strlen(_arr);
    _cap = _size;
}

String::String(const String& obj) {
    _size = obj._size;
    _cap = obj._cap;
    _arr = new char[obj._cap];
    for(int i = 0; i < obj._size; i++) {
        _arr[i] = obj._arr[i];
    }
}

String::String(String&& obj) {
    _size = obj._size;
    _cap = obj._cap;
    _arr = obj._arr;
    obj._arr = nullptr;
}

String& String::operator=(const String& obj) {
    if(this == &obj) {
        return *this;        
    }
    _size = obj._size;
    _cap = obj._cap;
    _arr = new char[obj._cap];
    for(int i = 0; i < obj._size; i++) {
        _arr[i] = obj._arr[i];
    }
    return *this;   
}

String& String::operator=(String&& obj) {
    if(this != nullptr) {
    std::swap(_size, obj._size);
    std::swap(_cap, obj._cap);
    std::swap(_arr,obj._arr);
    } else { _size = obj._size;
            _cap = obj._cap;
            _arr = obj._arr;
    }
    return *this;
}

String String::operator+(String obj){
    char* m_arr = new char[_cap + obj._cap];
    for(int i = 0; i < _size + obj._size; i++) {
        if(i < _size) {
            m_arr[i] = _arr[i];
        } else {
            m_arr[i] = obj._arr[i - _size];
        }         
    }
    String _tmp(m_arr);
    return _tmp;
}

void String::operator+=(String obj) {
    if(_size + obj._size >= _cap) {
        _cap*=2;
    }
    for(int i = _size; i < _size + obj._size; i++) {
        _arr[i] = obj._arr[i - _size];
    }
}

bool String::operator<=(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] <= obj._arr[i]) {
            continue;
        } else {
            return false;
        }
    }
    return false;
}

bool String::operator>=(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] >= obj._arr[i]) {
            continue;
        } else {
            return false;
        }
    }
    return false;
}

bool String::operator==(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] == obj._arr[i]) {
            continue;
        } else {
            return false;
        }
    }
    return false;
}

bool String::operator<(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] < obj._arr[i]) {
            continue;
        } else {
            return false;
        }
    }
    return false;
}

bool String::operator>(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] > obj._arr[i]) {
            continue;
        } else {
            return false;
        }
    }
    return false;
}

String::~String(){
    delete[] _arr;
    _arr = nullptr;
}

String String::sub_string(StringIterator pos, int n) {
    String _tmp;
    int i = 0;
    for(StringIterator it = pos; it != this->end(); it++){
        _tmp._arr[i] = *it;
        i++;
    }
    return _tmp;
}

String String::sub_string(int n) {
     String _tmp;
    _tmp._cap = _cap;
    for(int i = 0; i < _size - n; i++) {
        _tmp._arr[i] = _arr[i];
        _tmp._size++;  
    }
    return _tmp;
}   
    
void String::insert(int pos, String obj) {
    if(obj._size + _size >= _cap) {
        _cap*=2;
    }
    char* m_arr = new char[_cap];
    for(int i = 0; i < _size + obj._size; i++) {
        if(i == pos) {
            m_arr[i] = obj._arr[i];
        } else if(i < pos) {
            m_arr[i] = _arr[i];
        }   else {
            m_arr[i] = _arr[i - obj._size];
        }
    }
    *_arr = *m_arr;
    delete[] m_arr;
    m_arr = nullptr; 
}

void String::insert(int pos, char ch) {
    if(_size == _cap) {
        _cap = _cap * 2;
    }
    char* m_arr = new char[_size+1];
    for(int i = 0; i < _size + 1; i++) {
        if(i < pos) {
            m_arr[i] = _arr[i];
        }
        if(i == pos) {
            m_arr[i] = ch;
        } else {
            m_arr[i+1] = _arr[i];
        }
        }
        *_arr = *m_arr;
        delete[] m_arr;
        m_arr = nullptr;
    }

void String::push_back(char ch) {
    if( _size == _cap) {
        _cap*=2;
    } 
    _arr[_size] = ch;
    _arr[_size+1] = '\0';
}

void String::pop_back() {
    _size--;
    _arr[_size] = '\0';
}

StringIterator String::find(char ch) {
    for(int i = 0; i < _size; i++) {
        if(_arr[i] == ch) {
            return StringIterator(_arr+i);
        }
    }
    return StringIterator(_arr + _size);
}

bool String::empty() const{
    if(this->_size == 0) { return true; }
    return false;
}

void String::clear() {
    delete[] _arr;
    _arr = nullptr;
    _arr = new char[0];
    _arr[0] = '\0';
}

void String::replace(int pos, String obj) {
    for(int i = pos; i < pos + obj._size; i++) {
        _arr[i] = obj._arr[i - pos];
    }
}

int String::get_size() {
    return _size;
}

StringIterator String::operator[](int pos) {
    return StringIterator(_arr + pos);
}

void String::resize(int n) {
    char* m_arr = new char[n];
    for(int i = 0; i < _size; i++) {
        m_arr[i] = _arr[i];
    }
    *_arr = *m_arr;
    m_arr = nullptr;
    delete[] m_arr;
}

bool String::contains(String obj) {
    bool check = false;
    for(int i = 0; i < _size; i++) {
        if(check == true && _arr[i] != obj._arr[i]) {
            return false;
        }
        if(_arr[i] == obj._arr[i]) {
            return true;
        }
    }
    return false;
}

int String::compare(String obj){
    if(obj._size < _size) {
        return 1;
    }
    if(obj._size > _size) {
        return -1;
    } return 0; 
}

