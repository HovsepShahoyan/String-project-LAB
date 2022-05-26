#include <iostream>
#include "string.h"

String::String() {}

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

String& String::operator=(String& obj) {
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
    std::swap(_size, obj._size);
    std::swap(_cap, obj._cap);
    std::swap(_arr,obj._arr);
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
    String _return(m_arr);
    return _return;
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
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool String::operator>=(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] >= obj._arr[i]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool String::operator==(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] == obj._arr[i]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool String::operator<(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] < obj._arr[i]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool String::operator>(String obj) {
    for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
        if (_arr[i] > obj._arr[i]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

String::~String(){
    delete[] _arr;
}

String String::sub_string(int pos, int n) {
    char* m_arr = new char[_cap];
    for(int i = pos; i < _size - pos - n; i++) {
        m_arr[i - pos] = _arr[i];  
    }
    String _return(m_arr);
    return _return;
}

String String::sub_string(int n) {
    char* m_arr = new char[_cap];
    for(int i = 0; i < n; i++) {
        m_arr[i] = _arr[i];  
    }
    String _return(m_arr);  
    return _return; 
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

void String::push_back(char ch) {
    if( _size == _cap) {
        _cap*=2;
    } 
    _arr[_size] = ch;
}

char String::pop_back() {
    char _return = _arr[_size - 1];
    _arr[_size - 1] = '\0';
    return _return;
    
}

int String::find(char ch) {
    for(int i = 0; i < _size; i++) {
        if(_arr[i] == ch) {
            return i;
        }
    }
    return -1;
}

bool String::empty() {
    if(this->_size = 0) {return true;}
    return false;
}

void String::clear() {
    _arr = nullptr;
    _arr = new char[0];
}

void String::replace(int pos, String obj) {
    for(int i = pos; i < pos + obj._size; i++) {
        _arr[i] = obj._arr[i - pos];
    }
}

int String::get_size() {
    return _size;
}

char& String::operator[](int pos) {
    return _arr[pos];
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
            check = false;
        }
        if(_arr[i] == obj._arr[i]) {
            check = true;
        }
    }
    return check;
}

int String::compare(String obj){
    if(obj._size < _size) {
        return 1;
    }
    else if(obj._size > _size) {
        return -1;
    } else {
        return 0;
    }
}