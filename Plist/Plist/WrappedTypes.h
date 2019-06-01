#pragma once

#include <complex>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <type_traits>

#include "Structs.h"


// Классы-обертки типов ниже: WrappedType, WrappedDouble, WrappedInt, WrappedComplex


class WrappedType
{
public:
    //WrappedType(){}
    //virtual ~WrappedType() {}

    virtual void print() const = 0;

    virtual E_typeOfValue typeOfValue() const /*= 0; */ { return E_typeOfValue::ABSTRACT; }

//protected:
};

class WrappedDouble : public WrappedType
{
protected:

    double m_value;

public:

    WrappedDouble(double value_ = 0.) : m_value(value_) {}

    WrappedDouble(const WrappedDouble& rhs)  
    {
        m_value = rhs.m_value;
    }

    WrappedDouble& operator=(const WrappedDouble& rhs)
    {
        if (&rhs == this)
            return *this;
        m_value = rhs.m_value;
        return *this;
    }

    //~WrappedDouble() { }

    virtual E_typeOfValue typeOfValue() const override { return E_typeOfValue::DOUBLE; }

    inline double value() const { return m_value; }

    void print() const override
    {
        std::cout << m_value;
    }

    //===================================================================================================
    //Арифметика
    WrappedDouble operator+(const WrappedDouble& rhs) { return WrappedDouble(m_value + rhs.m_value); }
    WrappedDouble operator-(const WrappedDouble& rhs) { return WrappedDouble(m_value - rhs.m_value); }
    WrappedDouble operator*(const WrappedDouble& rhs) { return WrappedDouble(m_value * rhs.m_value); }
    WrappedDouble operator/(const WrappedDouble& rhs)
    {
        if ((rhs.m_value < 2e-15) && (rhs.m_value > -2e-15))
            throw std::domain_error("Division by zero");
        return WrappedDouble(m_value / (rhs.m_value));
    }

    //bool operator<(const WrappedDouble& rhs) { return  m_value < rhs.m_value; }
    //bool operator>(const WrappedDouble& rhs) { return  m_value > rhs.m_value; }
    //bool operator==(const WrappedDouble& rhs) { return m_value == rhs.m_value; }

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






class WrappedInt : public WrappedType
{
protected:

    int m_value;

public:

    WrappedInt(int value_ = 0.) : m_value(value_) {}

    WrappedInt(const WrappedInt& rhs)
    {
        m_value = rhs.m_value;;
    }

    WrappedInt& operator=(const WrappedInt& rhs)
    {
        if (&rhs == this)
            return *this;
        m_value = rhs.m_value;
        return *this;
    }

    //~WrappedInt() {}

    virtual E_typeOfValue typeOfValue() const override { return E_typeOfValue::INT; }

    inline int value() const { return m_value; }

    void print() const override
    {
        std::cout << m_value;
    }

};




class WrappedComplex : public WrappedType
{
protected:

    Complex m_value;

public:

    WrappedComplex(Complex value_ = 0.) : m_value(value_) {}

    WrappedComplex(const WrappedComplex& rhs)
    {
        m_value = rhs.m_value;
    }

    WrappedComplex& operator=(const WrappedComplex& rhs)
    {
        if (&rhs == this)
            return *this;
        m_value = rhs.m_value;
        return *this;
    }

    //~WrappedComplex() {}

    virtual E_typeOfValue typeOfValue() const override { return E_typeOfValue::COMPLEX; }

    const Complex& value() const { return m_value; }

    void print() const override
    {
        std::cout << m_value;
    }
};




//=============================================================================================

// Операторы для сравнения между собой наследников WrappedType

bool operator==(const WrappedType& lhs, const WrappedType& rhs);

bool operator!=(const WrappedType& lhs, const WrappedType& rhs);

template <typename T>
bool compareWithCast(WrappedType* lhs, T rhs)
{
    bool ret;
    switch (lhs->typeOfValue())
    {
    case E_typeOfValue::DOUBLE:
        ret = (rhs == dynamic_cast<WrappedDouble*>(lhs)->value());
        break;
    case E_typeOfValue::INT:
        ret = (rhs == static_cast<double>(dynamic_cast<WrappedInt*>(lhs)->value()));
        break;
    case E_typeOfValue::COMPLEX:
        ret = (rhs == dynamic_cast<WrappedComplex*>(lhs)->value());
        break;
    default:
        ret = false;
        break;
    }

    return ret;
}


//inline std::ostream& operator<<(std::ostream& stre, const WrappedType& a)
//{
//    return stre;
//}

//inline std::ostream& operator<<(std::ostream& stre, const WrappedDouble& a)
//{
//    std::cout << a.value();
//    return stre;
//}

//inline std::ostream& operator<<(std::ostream& stre, const WrappedInt& a)
//{
//    std::cout << a.value();
//    return stre;
//}

//
//inline std::ostream& operator<<(std::ostream& stre, const WrappedComplex& a)
//{
//    std::cout << a.value();
//    return stre;
//}

