#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <iterator>
#include <cstring>

class StringIterator {
public:
    StringIterator(char* ptr);
    StringIterator& operator++();
    StringIterator operator++(int) ;
    StringIterator& operator--();
    StringIterator operator--(int);
    char& operator[](int index);
    char* operator->();
    char& operator*();
    bool operator ==(const StringIterator& other);
    bool operator !=(const StringIterator& other);
private:
    char* m_Ptr;
};

class String {
public: //Constructors
    String();
    String(char* m_arr);
    String(const String& obj);
    String(String&& obj);
    String& operator=(const String& obj);
    String& operator=(String&& obj);
    ~String();

public: //Functions
    String operator+(String obj);
    String operator+(char ch);
    void operator+=(String obj);
    bool operator==(String obj);
    bool operator<(String obj);
    bool operator>(String obj);
    bool operator>=(String obj);
    bool operator<=(String obj);
    StringIterator operator[](int pos);
    String sub_string(StringIterator pos, int n);
    String sub_string(int n);
    void insert(int pos, String obj);
    void insert(int pos, char ch);
    void push_back(char ch);
    void pop_back();
    bool empty() const;
    void clear();
    StringIterator find(char ch);
    void replace(int pos, String obj);
    int get_size();
    void resize(int n);
    bool contains(String obj);
    bool contains(char ch);
    int compare(String obj);
    StringIterator end() {
        return StringIterator(_arr +_size);
    }
    StringIterator begin(){
         return StringIterator(_arr);
    }

    friend std::ostream &operator<<(std::ostream &out, const String &obj)
    {
        out << obj._arr << '\n';
        return out;
    }

private:
    char* _arr;
    int _size;
    int _cap;
};

#endif //STRING_H

