#include <iostream>
#include <string.h>
#ifndef string
#define string
class String;
class StringIterator;

class StringIterator {
public:
    StringIterator(char* ptr) {
        m_Ptr = ptr;
    }

    StringIterator& operator++() {
        m_Ptr++;
        return *this;
    }

    StringIterator operator++(int) {
        StringIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    StringIterator& operator--() {
        m_Ptr--;
        return *this;
    }

    StringIterator operator--(int) {
        StringIterator iterator = *this;
        --(*this);
        return iterator;
    }
    
    char& operator[](int index) {
        return *(m_Ptr + index);
    }

    char* operator->() {
        return m_Ptr;
    }

    char& operator*() {
        return *m_Ptr;
    }

    bool operator ==(const StringIterator& other) {
       return m_Ptr == other.m_Ptr; 
    }

    bool operator !=(const StringIterator& other) {
        return m_Ptr != other.m_Ptr;
    }
private:
    char* m_Ptr;
};


class String {

public:
    String();
    String(char* m_arr);
    String(const String& obj);
    // String(String&& obj);
    String& operator=(String& obj);
    // String& operator=(String&& obj);
    ~String();

public:
    String operator+(String obj);
    void operator+=(String obj);
    bool operator==(String obj);
    bool operator<(String obj);
    bool operator>(String obj);
    bool operator>=(String obj);
    bool operator<=(String obj);
    char& operator[](int pos);
    String sub_string(int pos, int n);
    String sub_string(int n);
    void insert(int pos, String obj);
    void push_back(char ch);
    char pop_back();
    bool empty();
    void clear();
    int find(char ch);
    void replace(int pos, String obj);
    int get_size();
    void resize(int n);
    bool contains(String obj);
    bool contains(char ch);
    int compare(String obj);

    friend std::ostream &operator<<(std::ostream &out, const String &obj)
    {
        out << obj._arr << '\n';
        return out;
    }

    StringIterator begin() {
        return StringIterator(_arr);
    }

    StringIterator end() {
        return StringIterator(_arr + _size);
    }

private:
    char* _arr;
    int _size;
    int _cap;
};

#endif