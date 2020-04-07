#ifndef MODERNCPP_SHARED_PTR_H
#define MODERNCPP_SHARED_PTR_H

#include <utility>

class shared_count
{
public:
    shared_count() noexcept
    : count_(1){}
    void add_count() noexcept
    {
        ++count_;
    }
    long reduce_count() noexcept
    {
        return --count_;
    }
    long get_count() const noexcept
    {
        return count_;
    }
private:
    long count_;
};

template <typename T>
class shared_ptr
{
public:
    template <typename U>
    friend class shared_ptr;

    explicit shared_ptr(T *ptr = nullptr) : ptr_(ptr)
    {
        if(ptr_)
        {
            shared_count_ = new shared_count();
        }
    }

    ~shared_ptr()
    {
        if(ptr_ && !shared_count_->reduce_count())
        {
            delete ptr_;
            delete shared_count_;
        }

    }

    // for dynamic_pointer_cast use
    template <typename U>
    shared_ptr(const shared_ptr<U> &other, T *ptr) noexcept
    {
        ptr_ = ptr;
        if(ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename T, typename U>
    shared_ptr<T> dynamic_pointer_cast(const shared_ptr<T> &other) noexcept
    {
        T *ptr = dynamic_cast<T*>(other.get());
        return shared_ptr<T>(other, ptr);
    }

    shared_ptr(shared_ptr &other)
    {
        ptr_ = other.ptr_;
        other.shared_count_->add_count();
        shared_count_ = other.shared_count_;
    }

    template <typename U>
    shared_ptr(const shared_ptr<U> &other) noexcept
    {
        ptr_ = other.ptr_;
        if(ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    shared_ptr(shared_ptr &&other) noexcept
    {
        ptr_ = other.ptr_;
        if(ptr)
        {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }

    // make use of character of raw pointer
    template <typename U>
    shared_ptr(shared_ptr<U> &&other)
    {
        ptr_ = other.release();
    }

    // operator='s semantic depends on how the rhs construct,
    // because passing rhs as value may call copy-constructor or move-constructor
    shared_ptr &operator=(shared_ptr rhs) noexcept
    {
        rhs.swap(*this);
        return *this;
    }

    long use_count() const noexcept
    {
        if(ptr_)
            return shared_count_->get_count();
        else
            return 0;
    }

    T *get() noexcept
    {
        return ptr_;
    }

    T *release()
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(shared_ptr &rhs) noexcept
    {
        std::swap(ptr_, rhs.ptr_);
        std::swap(shared_count_, rhs.shared_count_);
    }

    T *operator->() const noexcept
    {
        return ptr_;
    }

    T &operator*() const noexcept
    {
        return *ptr_;
    }

    operator bool() const noexcept
    {
        return ptr_;
    }


private:
    T *ptr_;
    shared_count *shared_count_;
};


#endif //MODERNCPP_SHARED_PTR_H
