#ifndef _C___ARRAY_H
#define _C___ARRAY_H

template <typename T>
class Array {
public:
    explicit Array(int sz) {}
    explicit Array(size_t size, const T& value = T()) {}
    Array(const Array&) {}
    Array& operator=(const Array&) {}
    ~Array() {}

    T& operator[](size_t sz) {}
    const T& operator[](size_t sz) const {}

    size_t Size() const {}
private:
    // your code goes here
};

#endif //_C___ARRAY_H
