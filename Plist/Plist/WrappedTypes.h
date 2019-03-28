#pragma once

#include <complex>
#include <stdexcept>
#include <iostream>
#include <memory>

using Complex = std::complex<double>;



class WrappedType
{
public:
    //WrappedType(){}
    virtual ~WrappedType() {}

    virtual void print() = 0;
    /*virtual bool operator==(std::shared_ptr<WrappedType> rhs) = 0;*/
    //virtual Complex value() const = 0;
//protected:
};

//inline std::ostream& operator<<(std::ostream& stre, const WrappedType& a)
//{
//    return stre;
//}

class WrappedDouble : public WrappedType
{
protected:

    double mValue;

public:

    WrappedDouble(double value_ = 0.) : mValue(value_) {}

    WrappedDouble(const WrappedDouble& rhs)
    {
        mValue = rhs.mValue;
    }

    WrappedDouble& operator=(const WrappedDouble& rhs)
    {
        if (&rhs == this)
            return *this;
        mValue = rhs.mValue;
        return *this;
    }

    ~WrappedDouble() { }
    inline double value() const { return mValue; }

    /*bool operator==(const WrappedType& rhs) { return mValue==rhs.mValue; }*/
    void print() override
    {
        std::cout << mValue;
    }

    //===================================================================================================
    //Арифметика
    WrappedDouble operator+(const WrappedDouble& rhs) { return WrappedDouble(mValue + rhs.mValue); }
    WrappedDouble operator-(const WrappedDouble& rhs) { return WrappedDouble(mValue - rhs.mValue); }
    WrappedDouble operator*(const WrappedDouble& rhs) { return WrappedDouble(mValue * rhs.mValue); }
    WrappedDouble operator/(const WrappedDouble& rhs)
    {
        if ((rhs.mValue < 2e-15) && (rhs.mValue > -2e-15))
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

//inline std::ostream& operator<<(std::ostream& stre, const WrappedDouble& a)
//{
//    std::cout << a.value();
//    return stre;
//}




class WrappedInt : public WrappedType
{
protected:

    int mValue;

public:

    WrappedInt(int value_ = 0.) : mValue(value_) {}

    WrappedInt(const WrappedInt& rhs)
    {
        mValue = rhs.mValue;;
    }

    WrappedInt& operator=(const WrappedInt& rhs)
    {
        if (&rhs == this)
            return *this;
        mValue = rhs.mValue;
        return *this;
    }

    ~WrappedInt() {}
    inline int value() const { return mValue; }

    void print() override
    {
        std::cout << mValue;
    }

};

//inline std::ostream& operator<<(std::ostream& stre, const WrappedInt& a)
//{
//    std::cout << a.value();
//    return stre;
//}


class WrappedComplex : public WrappedType
{
protected:

    Complex mValue;

public:

    WrappedComplex(Complex value_ = 0.) : mValue(value_) {}

    WrappedComplex(const WrappedComplex& rhs)
    {
        mValue = rhs.mValue;
    }

    WrappedComplex& operator=(const WrappedComplex& rhs)
    {
        if (&rhs == this)
            return *this;
        mValue = rhs.mValue;
        return *this;
    }

    ~WrappedComplex() {}
    inline Complex value() const { return mValue; }

    void print() override
    {
        std::cout << mValue;
    }
};

//
//inline std::ostream& operator<<(std::ostream& stre, const WrappedComplex& a)
//{
//    std::cout << a.value();
//    return stre;
//}