#pragma once

#include <complex>
#include <stdexcept>
#include <iostream>
#include <memory>

using Complex = std::complex<double>;



class WrappedType
{
public:
    WrappedType() : next_ptr(nullptr), prev_ptr(nullptr) {}
	virtual ~WrappedType() {}
    //virtual Complex value() const = 0;
//    inline WrappedType* next_ptr() { return mNextPtr; }
//    inline WrappedType* prev_ptr() { return mPrevPtr; }
//protected:
    std::shared_ptr <WrappedType> next_ptr;
    std::shared_ptr <WrappedType> prev_ptr;
};

inline std::ostream& operator<<(std::ostream& stre, const WrappedType& a)
{
    return stre;
}

class WrappedDouble : public WrappedType
{
protected:

    double mValue;

public:

    WrappedDouble(double value_ = 0.) : WrappedType(), mValue(value_) {}

    WrappedDouble(const WrappedDouble& rhs)
    {
        mValue = rhs.mValue;
        next_ptr = rhs.next_ptr;
        prev_ptr = rhs.prev_ptr;
    }

    WrappedDouble& operator=(const WrappedDouble& rhs)
    {
        if (&rhs == this)
            return *this;
        mValue = rhs.mValue;
        next_ptr = rhs.next_ptr;
        prev_ptr = rhs.prev_ptr;
        return *this;
    }

    ~WrappedDouble() { }
    inline double value() const { return mValue; }


    //===================================================================================================
    //Арифметика
    WrappedDouble operator+(const WrappedDouble& rhs) { return WrappedDouble(mValue + rhs.mValue); }
    WrappedDouble operator-(const WrappedDouble& rhs) { return WrappedDouble(mValue - rhs.mValue); }
    WrappedDouble operator*(const WrappedDouble& rhs) { return WrappedDouble(mValue * rhs.mValue); }
    WrappedDouble operator/(const WrappedDouble& rhs) 
    {   
        if (rhs.mValue < 2e-15)
            throw std::domain_error("Division by zero");
        return WrappedDouble(mValue / (rhs.mValue)); 
    }

    bool operator<(const WrappedDouble& rhs) { return  mValue < rhs.mValue; }
    bool operator>(const WrappedDouble& rhs) { return  mValue > rhs.mValue; }
    bool operator==(const WrappedDouble& rhs) { return mValue == rhs.mValue; }

    template <typename T>
    WrappedDouble operator+(const T rhs) { return WrappedDouble((*this) + WrappedDouble(rhs)); }
    template <typename T>
    WrappedDouble operator-(const T rhs) { return WrappedDouble((*this) - WrappedDouble(rhs)); }
    template <typename T>
    WrappedDouble operator*(const T rhs) { return WrappedDouble((*this) * WrappedDouble(rhs)); }
    template <typename T>
    WrappedDouble operator/(const T rhs) { return WrappedDouble((*this) / WrappedDouble(rhs)); }

    //и так далее
    //===================================================================================================
};

inline std::ostream& operator<<(std::ostream& stre, const WrappedDouble& a)
{
    std::cout << a.value();
    return stre;
}




class WrappedInt : public WrappedType
{
protected:

    int mValue;

public:

    WrappedInt(int value_ = 0.) : WrappedType(), mValue(value_) {}

    WrappedInt(const WrappedInt& rhs)
    {
        mValue = rhs.mValue;
        next_ptr = rhs.next_ptr;
        prev_ptr = rhs.prev_ptr;
    }

    WrappedInt& operator=(const WrappedInt& rhs)
    {
        if (&rhs == this)
            return *this;
        mValue = rhs.mValue;
        next_ptr = rhs.next_ptr;
        prev_ptr = rhs.prev_ptr;
        return *this;
    }

    ~WrappedInt() {}
    inline int value() const { return mValue; }

};

inline std::ostream& operator<<(std::ostream& stre, const WrappedInt& a)
{
    std::cout << a.value();
    return stre;
}


class WrappedComplex : public WrappedType
{
protected:

    Complex mValue;

public:

    WrappedComplex(Complex value_ = 0.) : WrappedType(), mValue(value_) {}

    WrappedComplex(const WrappedComplex& rhs)
    {
        mValue = rhs.mValue;
        next_ptr = rhs.next_ptr;
        prev_ptr = rhs.prev_ptr;
    }

    WrappedComplex& operator=(const WrappedComplex& rhs)
    {
        if (&rhs == this)
            return *this;
        mValue = rhs.mValue;
        next_ptr = rhs.next_ptr;
        prev_ptr = rhs.prev_ptr;
        return *this;
    }

    ~WrappedComplex() {}
    inline Complex value() const { return mValue; }
};


inline std::ostream& operator<<(std::ostream& stre, const WrappedComplex& a)
{
    std::cout << a.value();
    return stre;
}