//#include "pch.h"
#include <iostream>
#include <exception>
#include <cmath>
#include <type_traits>

#include "Rational.h"


using namespace std;


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

    system("pause");
    return 0;
}
