#ifndef TASKS_ARRAY_H
#define TASKS_ARRAY_H

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

    size_t size() const {}
private:
    // your code goes here
};

#endif //TASKS_ARRAY_H
