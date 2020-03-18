#ifndef MODERNCPP_UNIQUE_PTR_H
#define MODERNCPP_UNIQUE_PTR_H

template <typename T>
class unique_ptr
{
public:
    explicit unique_ptr(T *ptr = nullptr) : ptr_(ptr)
    {

    }

    ~unique_ptr()
    {
        delete ptr_;
    }


    unique_ptr(unique_ptr &other) = delete;

    unique_ptr(unique_ptr &&other)
    {
        ptr_ = other.release();
    }

    // make use of character of raw pointer
    // TODO: use dynamic_cast instead
    template <typename U>
    unique_ptr(unique_ptr<U> &&other)
    {
        ptr_ = other.release();
    }

//    better than old style "this->" assignment, which called copy-and-swap idiom
//    https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom/3279550#3279550
//    unique_ptr &operator=(unique_ptr &rhs)
//    {
//        unique_ptr(rhs).swap(*this);
//        return *this;
//    }

    // operator='s semantic depends on how the rhs construct,
    // because passing rhs as value may call copy-constructor or move-constructor
    unique_ptr &operator=(unique_ptr rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    T *get()
    {
        return ptr_;
    }

    T *release()
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(unique_ptr &rhs)
    {
        std::swap(ptr_, rhs.ptr_);
    }

    T *operator->()
    {
        return ptr_;
    }

    T &operator*()
    {
        return *ptr;
    }

    operator bool() const
    {
        return ptr_;
    }

private:
    T *ptr_;
};

#endif //MODERNCPP_UNIQUE_PTR_H
