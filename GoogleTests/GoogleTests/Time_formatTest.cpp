#include "pch.h"

// Для запуска этого файла раскомментировать , если закомментировано
// Закомментировать во всех остальных cpp всё, что ниже #include "pch.h"
// либо исключить из проекта все остальные cpp
//
//#include "../../Time_format/Time_format/Time.h"
//#include <iostream>
//
//using namespace std;
//using namespace DateTime;
//
//
//TEST(TimeTest, CheckExceptionsDate)
//{
//    ASSERT_THROW(Time(0,0,32,1,1), std::domain_error);
//    ASSERT_THROW(Time(61,1,1,1,1), std::domain_error);
//    ASSERT_THROW(Time(1,-1,1,1,1), std::domain_error);
//    ASSERT_THROW(Time(0,0,1,13,1), std::domain_error);
//    ASSERT_THROW(Time(0,0,31,4,2), std::domain_error);
//    ASSERT_THROW(Time(0,0,29,2,2019), std::domain_error);
//    ASSERT_THROW(Time(0,0,30,2,2020), std::domain_error);
//    ASSERT_THROW(Time(0,0,31,11,2010), std::domain_error);
//    ASSERT_THROW(Time(0,0,31,9,2010), std::domain_error);
//}
//
//TEST(TimeTest, CheckExceptionsSum)
//{
//    ASSERT_THROW(Time(0, 0, 62, 1, 1, true, true), std::domain_error);
//    ASSERT_THROW(Time(0, 0, 1, 24, 1, true, true), std::domain_error);
//    ASSERT_THROW(Time(0, 0, -30, 1, 1, true, true), std::domain_error);
//}
//
//TEST(Constructors, TimeIntervalTest)
//{
//    EXPECT_EQ(TimeInterval(60, 0, 0, 0, 0), TimeInterval(0, 1, 0, 0, 0));
//    EXPECT_EQ(TimeInterval(-1, 0, 0, 0, 0), TimeInterval(59, 23, 30, 11, -1));
//    EXPECT_EQ(TimeInterval(0, 24, 0, 0, 0), TimeInterval(0, 0, 1, 0, 0));
//    EXPECT_EQ(TimeInterval(0, 0, 31, 0, 0), TimeInterval(0, 0, 0, 1, 0));
//    EXPECT_EQ(TimeInterval(0, 0, 0, 12, 0), TimeInterval(0, 0, 0, 0, 1));
//    EXPECT_EQ(TimeInterval(185, 0, 0, 0, 0), TimeInterval(5, 3, 0, 0, 0));
//    EXPECT_EQ(TimeInterval(-121, 0, 0, 0, 0), TimeInterval(59, 21, 30, 11, -1));
//    EXPECT_EQ(TimeInterval(0, 0, 0, 0, 0), TimeInterval(0, 0, 0, 0, 0));
//}
//
//TEST(Constructors, TimeTest)
//{
//    EXPECT_EQ(Time(0, 0, 0, 1, 1, false), Time(0, 0, 31, 12, 0, false));
//    EXPECT_EQ(Time(0, 0, 32, 12, 1, false), Time(0, 0, 1, 1, 2, false));
//    EXPECT_EQ(Time(0, 0, 29, 2, 2020, false), Time(0, 0, 29, 2, 2020, false));
//    EXPECT_EQ(Time(0, 0, 29, 2, 2019, false), Time(0, 0, 1, 3, 2019, false));
//    EXPECT_EQ(Time(0, 0, 0, 3, 2020, false), Time(0, 0, 29, 2, 2020, false));
//    EXPECT_EQ(Time(0, 0, 0, 3, 2019, false), Time(0, 0, 28, 2, 2019, false));
//    EXPECT_EQ(Time(0, 0, 32, 3, 1, false), Time(0, 0, 1, 4, 1, false));
//    EXPECT_EQ(Time(0, 0, 31, 4, 1, false), Time(0, 0, 1, 5, 1, false));
//    EXPECT_EQ(Time(0, 0, 31, 8, 1, false), Time(0, 0, 31, 8, 1, false));
//    EXPECT_EQ(Time(0, 0, 0, 10, 1, false), Time(0, 0, 30, 9, 1, false));
//}
//
//
//
//TEST(Operators, T_plus_TI)
//{
//    EXPECT_EQ(Time(30, 12, 15, 6, 0) + TimeInterval(1, 1, 1, 1, 1) , Time(31, 13, 16, 7, 1));
//    EXPECT_EQ(Time(30, 12, 15, 6, 0) + TimeInterval(40, 13, 20, 10, 1) , Time(10, 2, 6, 5, 2));
//}
//
//TEST(Operators, T_minus_TI)
//{
//    EXPECT_EQ(Time(30, 12, 15, 6, 0) - TimeInterval(1, 1, 1, 1, 1), Time(29, 11, 14, 5, -1));
//    EXPECT_EQ(Time(30, 12, 15, 6, 2) - TimeInterval(40, 13, 20, 10, 1), Time(50, 22, 25, 7, 0));
//}
//
//TEST(Operators, T_minus_T)
//{
//    EXPECT_EQ(Time(30, 12, 15, 6, 0) - Time(1, 1, 1, 1, 1), TimeInterval(29, 11, 14, 5, -1));
//    EXPECT_EQ(Time(30, 12, 15, 6, 2) - Time(40, 13, 20, 10, 1), TimeInterval(50, 22, 25, 7, 0));
//}
//
//TEST(Operators, TI_plus_TI)
//{
//    EXPECT_EQ(TimeInterval(30, 12, 15, 6, 0) + TimeInterval(1, 1, 1, 1, 1), TimeInterval(31, 13, 16, 7, 1));
//    EXPECT_EQ(TimeInterval(30, 12, 15, 6, 0) + TimeInterval(40, 13, 20, 10, 1), TimeInterval(10, 2, 5, 5, 2));
//}
//
//TEST(Operators, TI_minus_TI)
//{
//    EXPECT_EQ(TimeInterval(30, 12, 15, 6, 0) - TimeInterval(1, 1, 1, 1, 1), TimeInterval(29, 11, 14, 5, -1));
//    EXPECT_EQ(TimeInterval(30, 12, 15, 6, 2) - TimeInterval(40, 13, 20, 10, 1), TimeInterval(50, 22, 25, 7, 0));
//}
//
//
//
//int main(int argc, char** argv)
//{
//
//    try {
//        cout << TimeInterval(30, 12, 15, 6, 0) + TimeInterval(1, 1, 1, 1, 1) << endl;
//        cout << TimeInterval(30, 12, 15, 6, 0) + TimeInterval(40, 13, 20, 10, 1) << endl;
//        Time t1(0, 0, 32, 1, 2019, false);
//        Time t2(0, 0, 1, 1, 2019, false);
//        TimeInterval ti1(0, 0, 10, 1, 1);
//        TimeInterval ti2(1, 0, 10, 1, 1);
//        cout << t1 << endl;
//        cout << t2 << endl;
//        /*t1.setEuropeanFormat(false);
//        cout << t1 << endl;*/
//
//        TimeInterval t = t1 - t2;
//        //Time tt = t1 + t2;
//        cout << t << endl;
//        //TimeInterval ti2 = ti;
//        //t = t + ti;
//        //cout << (t + ti )<< endl;
//    }
//    catch (std::exception& e) { cout << e.what(); }
//
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}