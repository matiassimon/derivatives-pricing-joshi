#ifndef WRAPPER_HPP
#define WRAPPER_HPP

template <class T> class wrapper
{
public:
  wrapper () { data_ = 0; }

  wrapper (const T &inner) { data_ = inner.clone (); }

  ~wrapper ()
  {
    if (data_ != 0)
      delete data_;
  }

  wrapper (const wrapper<T> &original)
  {
    if (original.data_ != 0)
      data_ = original.data_->clone ();
    else
      data_ = 0;
  }

  wrapper &
  operator= (const wrapper<T> &original)
  {
    if (this != &original)
      {
        if (data_ != 0)
          delete data_;

        data_ = original.data_ != 0 ? original.data_->clone () : 0;
      }

    return *this;
  }

  T &
  operator* ()
  {
    return *data_;
  }

  const T &
  operator* () const
  {
    return *data_;
  }

  const T *const
  operator->() const
  {
    return data_;
  }

  T *
  operator->()
  {
    return data_;
  }

private:
  T *data_;
};

#endif