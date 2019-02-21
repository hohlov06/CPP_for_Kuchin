//#include "pch.h"
#include <iostream>
#include <exception>
#include <cmath>
#include <type_traits>
using namespace std;

template<typename Tup>
Tup NOD(Tup a, Tup b)
{
    if (b == 0)
        return a;
    else
        return NOD(b, a % b);
}

//Tup - тип числителя, беззнаковым быть не может
//Tdown - тип знаменателя, может быть беззнаковым

template <typename Tup, typename Tdown>
class Rational
{
public:
    Rational(): up(0), down(1)  {}
    Rational(Tup up_, Tdown down_)
    {
        if (down_ == 0)
            throw invalid_argument("denominator is zero");

        //следующие исключения оказались бессмысленными, 
        //т.к. ошибки для перегруженных функций генерируются при компиляции, а исключения кидаются при выполнении программы
        if (is_integral<Tup>::value == false)
            throw invalid_argument("numerator must be integral");
        if (is_integral<Tdown>::value == false)
            throw invalid_argument("denominator must be integral");
        if (is_unsigned<Tup>::value == true)
            throw invalid_argument("numerator can not be unsigned");

        // если знаменатель беззнаковый, и его значение более, чем половина диапазона, то кидается исключение
        //т.к. знаменатель в итоге приводится к типу числителя

            if (is_unsigned<Tup>::value == true)
                if (down_ > power2(sizeof(Tdown) * 4))
                    throw invalid_argument("denominator is too big");

        // Приведение к виду рациональной дроби
        Tup down_to_tup = static_cast<Tup>(down_);
        Tup nod = NOD(up_, down_to_tup);
        up = up_ / nod;
        down = down_to_tup / nod;
        if (down < 0)
        {
            up = -up;
            down = -down;
        }
    }

    template <typename N>
    Tdown power2(N n) {
        Tdown a = 2;
        while (n != 1)
        {
            a *= a;
            n = n >> 1;
        }
        return a;
    }

    Tup Up() const { return up; }

    Tup Down() const{ return down; }

    //==================================================================
    //унитарные операторы

    Rational operator+() { return *this; }

    Rational operator-() { return { -up, down }; }

    //==================================================================
    //операторы +,-,*,/

    Rational operator+(const Rational& rat)
    {
        Tup nod = NOD(down, rat.Down());
        Tup mult_first = down / nod;
        Tup mult_second = rat.Down() / nod;
        return Rational<Tup, Tdown>{up * mult_second + rat.Up() * mult_first, down * mult_second};
    }



    Rational operator-(const Rational& rat)
    {
        Tup nod = NOD(down, rat.Down());
        Tup mult_first = down / nod;
        Tup mult_second = rat.Down() / nod;
        return Rational<Tup, Tdown>{up * mult_second - rat.Up() * mult_first, down * mult_second};
    }

    Rational operator*(const Rational& rat)
    {
        return Rational<Tup, Tdown>{up * rat.Up(), down * rat.Down()};
    }

    Rational operator/(const Rational& rat) {
        if (rat.Up() == 0) 
            throw domain_error("Division by zero");
        return (*this) * Rational(rat.Down(), rat.Up());
    }

    //==================================================================
    //операторы +=,-=,*=,/=

    Rational operator+=(const Rational& rat) 
    {
        (*this) = (*this) + rat;
        return (*this); 
    }

    Rational operator-=(const Rational& rat) 
    { 
        (*this) = (*this) - rat;
        return (*this); 
    }

    Rational operator*=(const Rational& rat)
    {
        (*this) = (*this) * rat;
        return (*this); 
    }

    Rational operator/=(const Rational& rat) 
    {
        (*this) = (*this) / rat;
        return (*this); 
    }

    //==================================================================
    //операторы вида Rational = int + Rational

    template <typename T>
    friend Rational operator+(const T& lhs, const Rational& rhs)
    {
        return Rational<Tup,Tdown>{static_cast<Tup>(lhs), static_cast<Tdown>(1)} + rhs;
    }

    template <typename T>
    friend Rational operator+(const Rational& lhs, const T& rhs ){return rhs + lhs;}

    template <typename T>
    friend Rational operator-(const T& lhs, const Rational& rhs)
    {
        return Rational<Tup, Tdown>{ static_cast<Tup>(lhs), static_cast<Tdown>(1) } - rhs;
    }

    template <typename T>
    friend Rational operator-(const Rational& lhs, const T& rhs) { return -(rhs - lhs); }


    template <typename T>
    friend Rational operator*(const T& lhs, const Rational& rhs)
    {
        return Rational<Tup, Tdown>{ static_cast<Tup>(lhs), static_cast<Tdown>(1) } * rhs;
    }

    template <typename T>
    friend Rational operator*(const Rational& lhs, const T& rhs) { return rhs * lhs; }

    template <typename T>
    friend Rational operator/(const T& lhs, const Rational& rhs)
    {
        return Rational<Tup, Tdown>{ static_cast<Tup>(lhs), static_cast<Tdown>(1) } / rhs;
    }

    template <typename T>
    friend Rational operator/(const Rational& lhs, const T& rhs) { return rhs / lhs; }

    //==================================================================
    //...
private:
    Tup up;
    Tup down;

};

template <typename Tup, typename Tdown>
Rational <Tup, Tdown> make_rational(Tup up, Tdown down)
{
    return Rational<Tup, Tdown>(up, down);
}



template <typename Tup, typename Tdown>
ostream& operator<<(ostream& stre, const Rational<Tup, Tdown> &a) {
    if (a.Up() != 0)
        stre << a.Up() << "/" << a.Down();
    else
        stre << 0;
    return stre;
}

//ниже перегрузка оператора сложения элементов класса с разными шаблонными типами
//компилятор выдает ошибку на такую перегрузку, т.к. ждет от оператора, чтоб он вернул объект с типом, стоящим слева от оператора+
//
//возможно ли перегрузить оператор так, чтобы сложить классы с разными шаблонными типами и
//и вернуть класс с шаблонными типами элемента класса справа от оператора?

//template <typename Tup1, typename Tdown1, typename Tup2, typename Tdown2>
//auto operator+(const Rational<Tup1, Tdown1>& lhs, const Rational<Tup2, Tdown2>& rhs)
//{
//    if (sizeof(Tup1) >= sizeof(Tup2))
//    {
//        Tup1 nod = NOD(lhs.Down(), static_cast<Tup1>(rhs.Down()));
//        Tup1 mult_first = lhs.Down() / nod;
//        Tup1 mult_second = static_cast<Tup1>(rhs.Down()) / nod;
//        return Rational<Tup1, Tdown1>{lhs.Up() * mult_second + static_cast<Tup1>(rhs.Up()) * mult_first, static_cast<Tdown1>(lhs.Down() * mult_second)};
//    }
//    else
//    {
//        Tup2 nod = NOD(rhs.Down(), static_cast<Tup2>(lhs.Down()));
//        Tup2 mult_first = static_cast<Tup2>(lhs.Down()) / nod;
//        Tup2 mult_second = rhs.Down() / nod;
//        return Rational<Tup2, Tdown2>{static_cast<Tup2>(lhs.Up()) * mult_second + rhs.Up() * mult_first, static_cast<Tdown2>(rhs.Down() * mult_first)};
//    }
//}

int main() {

    try
    {
        auto a = make_rational(2, 5); 
        auto b = make_rational(4, -6);
        auto c = 1 + a;
        auto d = make_rational(0,5);
        auto e = make_rational(static_cast<int64_t>(9), static_cast<uint64_t>(15));

        cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << " e=" << e << endl; 

        cout << "+a=" << +a << " -a=" << -a << endl;

        cout << "a+b=" << a+b << " a-b=" << a-b << " a*b=" << a*b << " a/b=" << a/b << endl;

        cout << "a+2=" << a + 2 << " 2+a=" << 2 + a << " a-2=" << a - 2 << " 2-a=" << 2-a << endl;

        d *= a;
        c /= a;

        cout << "d*=a => d= " << d << " c/=a => c=" << c << endl;

        
       // cout << c << endl;

        //проверка на ноль в знаменателе, бросает исключение
        //auto f = make_rational(2,0);
        //нельзя делить на ноль, бросает исключение
        //cout << b/d << endl;

        //a и e сложить нельзя, ошибка компиляции
        //cout << a+e << endl;

    }
    catch (exception &ex)
    {
        cerr << ex.what() << "\n";
        //exit(0);
    }
    return 0;
}
