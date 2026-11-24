#include <exception>
#include <print>

template <typename T, const size_t Size>
class dummy_array {
    T data[Size] = {};

    public:
        const T& GetAt(const size_t index) const {
            if (index < Size) {
                return data[index];
            }
            throw std::out_of_range("index out of range");
        }

        void SetAt(const size_t index, const T& value) {
            if (index < Size) {
                data[index] = value;
            } else {
                throw std::out_of_range("index out of range");
            }
        }

        size_t GetSize() const { return Size; }
};

template <typename T, typename C, const size_t Size>
class dummy_array_iterator_type {
    public:
        dummy_array_iterator_type(C& collection, const size_t index) : index(index), collection(collection) { }

        bool operator!=(const dummy_array_iterator_type& other) const {
            return index != other.index;
        }

        const T& operator*() const {
            return collection.GetAt(index);
        }

        dummy_array_iterator_type& operator++() {
            ++index;
            return *this;
        }

        dummy_array_iterator_type operator++(int) {
            auto temp = *this;
            ++*this;
            return temp;
        }

        private:
            size_t index;
            C& collection;
};

template <typename T, const size_t Size>
using dummy_array_iterator = dummy_array_iterator_type<T, dummy_array<T, Size>, Size>;

template <typename T, const size_t Size>
using dummy_array_const_iterator = dummy_array_iterator_type<T, const dummy_array<T, Size>, Size>;

template <typename T, const size_t Size>
inline dummy_array_iterator<T, Size> begin(dummy_array<T, Size>& collection) {
    return dummy_array_iterator<T, Size>(collection, 0);
}

template <typename T, const size_t Size>
inline dummy_array_iterator<T, Size> end(dummy_array<T, Size>& collection) {
    return dummy_array_iterator<T, Size>(collection, collection.GetSize());
}

template <typename T, const size_t Size>
inline dummy_array_const_iterator<T, Size> begin(const dummy_array<T, Size>& collection) {
    return dummy_array_const_iterator<T, Size>(collection, 0);
}

template <typename T, const size_t Size>
inline dummy_array_const_iterator<T, Size> end(const dummy_array<T, Size>& collection) {
    return dummy_array_const_iterator<T, Size>(collection, collection.GetSize());
}

template <typename T>
class MyVec {
    public:
        MyVec(size_t size, T default_data) : size(size) {
            data = new T[size];

            for (auto i{0uz}; i < size; ++i) {
                data[i] = default_data;
            }
        }
    
        class iterator {
            public:
                iterator(T* ptr) : ptr(ptr) { }
                
                iterator& operator++() {
                    ++ptr;
                    return *this;
                }

                const T& operator*() {
                    return *ptr;
                }

                bool operator!=(const iterator& other) {
                    return ptr != other.ptr;
                }
                
                T* ptr;
        };

        iterator begin() const {
            return iterator(data);
        }

        iterator end() const {
            return iterator(data + size);
        }

    private:
        size_t size;
        T* data;
};


int main(int argc, char* argv[]) {
    // dummy_array<int, 3> arr;
    // arr.SetAt(0, 1);
    // arr.SetAt(1, 2);
    // arr.SetAt(2, 3);
    // for (auto&& e: arr) {
    //     std::println("{}", e);
    // }
    const auto myvec {MyVec{10, 20}};
    for (const auto& val: myvec) {
        std::println("{}", val);
    }
    return 0;
}
