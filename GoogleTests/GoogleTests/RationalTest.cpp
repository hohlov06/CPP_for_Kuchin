#include "pch.h"

// Для запуска этого файла раскомментировать , если закомментировано
// Закомментировать во всех остальных cpp всё, что ниже #include "pch.h"
// либо исключить из проекта все остальные cpp

#include "../../Rational/Rational/Rational.h"
using namespace std;

auto a = make_rational(2, 5);
auto b = make_rational(4, -6);
auto c = 1 + a;
auto d = make_rational(0, 5);
auto e = make_rational(static_cast<int64_t>(9), static_cast<uint64_t>(15));

TEST(Exceptions, ZeroDenominator)
{
    ASSERT_THROW(make_rational(1,0), invalid_argument);
}


TEST(Exceptions, DivisionByZero)
{
    ASSERT_THROW(b/d, domain_error);
}

TEST(ReductionToMinimumForm, test) 
{
    EXPECT_EQ(b, make_rational(-2,3)) ;
    EXPECT_EQ(d, make_rational(0, 1)) ;
    EXPECT_EQ(e, make_rational(3, 5)) ;
}


TEST(Arithmetic, WithRational)
{
    EXPECT_EQ(a + b, make_rational(-4,15));
    EXPECT_EQ(a - b, make_rational(16,15));
    EXPECT_EQ(a * b, make_rational(-4,15));
    EXPECT_EQ(a / b, make_rational(-3,5));
}

TEST(Arithmetic, WithInteger)
{
    EXPECT_EQ(a + 2, make_rational(12,5));
    EXPECT_EQ(2 + a, make_rational(12,5));
    EXPECT_EQ(a - 2, make_rational(-8,5));
    EXPECT_EQ(2 - a, make_rational(8,5));
}

TEST(Arithmetic, OperatorPlusEqual)
{
    d *= a;
    c /= a;
    EXPECT_EQ(d, make_rational(0,1));
    EXPECT_EQ(c, make_rational(7,2));
}


int main(int argc, char** argv)
{

    //cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << " e=" << e << endl;

    //cout << "+a=" << +a << " -a=" << -a << endl;

    //cout << "a+b=" << a + b << " a-b=" << a - b << " a*b=" << a * b << " a/b=" << a / b << endl;

    //cout << "a+2=" << a + 2 << " 2+a=" << 2 + a << " a-2=" << a - 2 << " 2-a=" << 2 - a << endl;

    //d *= a;
    //c /= a;

    //cout << "d*=a => d= " << d << " c/=a => c=" << c << endl;


    //// cout << c << endl;

    // //проверка на ноль в знаменателе, бросает исключение
    // //auto f = make_rational(2,0);
    // //нельзя делить на ноль, бросает исключение
    // //cout << b/d << endl;

    // //a и e сложить нельзя, ошибка компиляции
    // //cout << a+e << endl;




    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}