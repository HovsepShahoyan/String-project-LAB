#include <iostream>
#include <stdexcept>
#include "string.h"

String::Iterator::Iterator(char* ptr) { m_ptr = ptr; }

String::Iterator& String::Iterator::operator++() {
   m_ptr++;
   return *this;
}

String::Iterator& String::Iterator::operator++(int) {
   ++m_ptr;
   return *this;
}

String::Iterator& String::Iterator::operator--() {
   m_ptr--;
   return *this;
}

String::Iterator& String::Iterator::operator--(int) {
   --m_ptr;
   return *this;
}

char* String::Iterator::operator->() { return m_ptr; }

char& String::Iterator::operator*() { return *m_ptr; }

bool String::Iterator::operator==(const Iterator& other) {
   return m_ptr == other.m_ptr;
}

bool String::Iterator::operator!=(const Iterator& other) {
   return m_ptr != other.m_ptr;
}

String::String(char* m_arr) {
   _size = strlen(m_arr);
   _cap = _size;
   _arr = new char[_cap];
   for (int i = 0; i < _size; i++) {
      _arr[i] = m_arr[i];
   }
}

String::String(const String& obj) {
   _size = obj._size;
   _cap = obj._cap;
   _arr = new char[obj._cap];
   for (int i = 0; i < obj._size; i++) {
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
   if (this == &obj) {
      return *this;
   }
   _size = obj._size;
   _cap = obj._cap;
   delete[] _arr;
   _arr = nullptr;
   _arr = new char[obj._cap];
   for (int i = 0; i < obj._size; i++) {
      _arr[i] = obj._arr[i];
   }
   return *this;
}

String& String::operator=(String&& obj) {
   delete[] _arr;
   _arr = nullptr;
   std::swap(_size, obj._size);
   std::swap(_cap, obj._cap);
   _arr = new char[_cap];
   for (int i = 0; i < _size; i++) {
      _arr[i] = obj._arr[i];
   }
   return *this;
}

String String::operator+(String obj) {
   String tmp;
   tmp._arr = new char[_cap + obj._cap];
   tmp._size = obj._size + _size;
   for (int i = 0; i < _size + obj._size; i++) {
      if (i < _size) {
         tmp._arr[i] = _arr[i];
      } else {
         tmp._arr[i] = obj._arr[i - _size];
      }
   }
   return tmp;
}

void String::operator+=(String obj) {
   if (_size + obj._size >= _cap) {
      _cap *= 2;
      char* m_arr = new char[_cap];
      for (int i = 0; i < _size; i++) {
         m_arr[i] = _arr[i];
      }
      delete[] _arr;
      _arr = new char[_cap];
      for (int i = 0; i < _size; i++) {
         _arr[i] = m_arr[i];
      }
      m_arr = nullptr;
   }
   int size_copy = _size;
   for (int i = size_copy; i < size_copy + obj._size; i++) {
      _arr[i] = obj._arr[i - size_copy];
      _size++;
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
   return true;
}

bool String::operator>=(String obj) {
   for (int i = 0, j = 0; i < _size && j < obj._size; i++, j++) {
      if (_arr[i] >= obj._arr[i]) {
         continue;
      } else {
         return false;
      }
   }
   return true;
}

bool String::operator==(String obj) {
   if (_size != obj._size) {
      return false;
   }
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
         return true;
      }
      if (_arr[i] == obj._arr[i]) {
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
         return true;
      } else if (_arr[i] == obj._arr[i]) {
         continue;
      } else {
         return false;
      }
   }
   return false;
}

String::~String() {
   if (_arr != nullptr) {
      delete[] _arr;
      _arr = nullptr;
   }
}

String::Iterator String::at(int pos) const {
   if (pos > _size) {
      throw std::out_of_range("Out of range Exception");
   }
   return Iterator(_arr + pos);
}

String String::sub_string(Iterator pos, int n) {
   String _tmp;
   _tmp._cap = _cap;
   _tmp._size = n;
   _tmp._arr = new char[n];
   Iterator it = this->end();
   for (int i = 0; pos != it; ++pos, ++i) {
      _tmp._arr[i] = *pos;
      if (i == n - 1) {
         break;
      }
   }
   return _tmp;
}

String String::sub_string(int n) {
   String _tmp;
   _tmp._cap = _cap;
   _tmp._size = n;
   _tmp._arr = new char[_cap];
   for (int i = 0; i < n; i++) {
      _tmp._arr[i] = _arr[i];
   }
   return _tmp;
}

String& String::insert(Iterator pos, String& obj) {
   char* m_arr = new char[_size + obj._size];
   _cap = _cap + obj._cap;
   _size = _size + obj._size;
   int i = 0;
   for (Iterator it = this->begin(); it != pos; ++it) {
      m_arr[i] = *it;
      i++;
   }
   for (Iterator it = obj.begin(); it != obj.end(); ++it) {
      m_arr[i] = *it;
      i++;
   }
   for (Iterator it = pos; it != this->end(); ++it) {
      m_arr[i] = *it;
      i++;
   }
   delete[] _arr;
   _arr = m_arr;
   m_arr = nullptr;
   return *this;
}

String& String::insert(Iterator pos, char ch) {
   char* m_arr = new char[_size + 1];
   _cap = _cap + 1;
   _size = _size + 1;
   int i = 0;
   for (Iterator it = this->begin(); it != this->end(); ++it) {
      m_arr[i] = *it;
      i++;
      if (it == pos) {
         m_arr[i] = ch;
         i++;
         continue;
      }
   }
   delete[] _arr;
   _arr = m_arr;
   m_arr = nullptr;
   return *this;
}

String::Iterator String::insert(int pos, String& obj) {
   char* m_arr = new char[_size + obj._size];
   _cap = _cap + obj._cap;
   _size = _size + obj._size;
   for (int i = 0; i < _size; i++) {
      if (i < pos) {
         m_arr[i] = _arr[i];
         continue;
      }
      if (i > pos + obj._size - 1) {
         m_arr[i] = _arr[i - obj._size];
         continue;
      }
      m_arr[i] = obj._arr[i - pos];
   }
   delete[] _arr;
   _arr = m_arr;
   m_arr = nullptr;
   return Iterator(_arr + pos);
}

void String::push_back(char ch) {
   if (_size == _cap) {
      _cap *= 2;
      char* m_arr = new char[_cap];
      for (int i = 0; i < _size; i++) {
         m_arr[i] = _arr[i];
      }
      delete[] _arr;
      _arr = m_arr;
      m_arr = nullptr;
   }
   _arr[_size + 1] = _arr[_size];
   _arr[_size] = ch;
   _size++;
}

void String::pop_back() {
   _arr[_size - 1] = _arr[_size];
   _size--;
}

String::Iterator String::find(char ch) const {
   for (int i = 0; i < _size; i++) {
      if (_arr[i] == ch) {
         return Iterator(_arr + i);
      }
   }
   return Iterator(_arr + _size);
}

bool String::empty() const { return this->_size == 0; }

void String::clear() {
   delete[] _arr;
   _arr = nullptr;
   _arr = new char[0];
   _arr[0] = '\0';
}

String String::replace(int pos, String& obj) {
   String tmp;
   tmp._cap = obj._cap + _cap;
   tmp._size = obj._size + _size;
   tmp._arr = new char[tmp._size];
   for (int i = 0; i < tmp._size; i++) {
      if (i < pos) {
         tmp._arr[i] = _arr[i];
      } else if (i < pos + obj._size) {
         tmp._arr[i] = obj._arr[i - pos];
      } else {
         tmp._arr[i] = _arr[i - obj._size];
      }
   }
   return tmp;
}

String String::replace(Iterator first, Iterator last, String& obj) {
   String tmp;
   tmp._size = _size;
   tmp._cap = _cap;
   tmp._arr = new char[_size];
   int i = 0;
   for (Iterator it = this->begin(); it != first; ++it) {
      tmp._arr[i] = *it;
      i++;
   }
   for (Iterator it = obj.begin(); it != obj.end(); ++it) {
      tmp._arr[i] = *it;
      i++;
   }
   for (Iterator it = last; it != this->end(); ++it) {
      tmp._arr[i] = *it;
      i++;
   }
   return tmp;
}

int String::get_size() const { return _size; }

String::Iterator String::operator[](int pos) const {
   return Iterator(_arr + pos);
}

void String::resize(int n) {
   char* m_arr = new char[n];
   for (int i = 0; i < _size; i++) {
      m_arr[i] = _arr[i];
   }
   *_arr = *m_arr;
   delete m_arr;
   m_arr = nullptr;
}

bool String::contains(String obj) const {
   bool check = false;
   if (_size > obj._size) {
      return false;
   }
   for (int i = 0; i < _size; i++) {
      if (_arr[i] == obj._arr[0]) {
         for (int j = i; j < i + obj._size; j++) {
            if (_arr[j] == obj._arr[j - i]) {
               check = true;
            } else {
               check = false;
            }
         }
         if (check == true) {
            return true;
         }
      }
   }
   return false;
}

bool String::contains(char ch) const {
   for (int i = 0; i < _size; i++) {
      if (_arr[i] == ch) {
         return true;
      }
   }
   return false;
}

int String::compare(String obj) {
   if (obj < *this) {
      return 1;
   }
   if (obj > *this) {
      return -1;
   }
   return 0;
}

String::Iterator String::end() { return Iterator(_arr + _size); }

String::Iterator String::begin() { return Iterator(_arr + 0); }