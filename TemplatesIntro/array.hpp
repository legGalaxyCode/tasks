#ifndef _C___ARRAY_H
#define _C___ARRAY_H

template <typename T>
class Array {
public:
    explicit Array(int sz): size_(sz) {
        buf_ = new T[size_];
    }
    explicit Array(size_t size, const T& value = T()): size_(size) {
        buf_ = new T[size_];
        std::fill(buf_, buf_ + size_, value);
    }
    Array(const Array&) {

    }
    Array& operator=(const Array&) {

    }
    ~Array() {

    }
    T& operator[](size_t sz) {
        return buf_[sz];
    }
    const T& operator[](size_t sz) const {
        return buf_[sz];
    }
    size_t size() const {
        return size_;
    }
private:
    T* buf_;
    size_t size_;
    // your code
};

#endif //_C___ARRAY_H
