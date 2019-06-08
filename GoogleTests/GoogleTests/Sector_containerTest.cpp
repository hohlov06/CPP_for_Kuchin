#include "pch.h"

// Для запуска этого файла раскомментировать , если закомментировано
// Закомментировать во всех остальных cpp всё, что ниже #include "pch.h"
// либо исключить из проекта все остальные cpp
//
//#include "../../Sector_container/Sector_container/SectorContainer.h"
//
//
//#include <iostream>
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//template <bool flag>
//class TestCase
//{
//public:
//    SectorContainer<flag>& cont;
//    TestCase(SectorContainer<flag>& cont_) : cont(cont_)
//    {
//        cont.clear();
//        cont.add({ 0,5 });
//        cont.add({ 12,12 });
//        cont.add({ 6,9 });
//        cont.add({ 20,30 });
//        cont.add({40,100000});
//        cont.print();
//    }
//
//    void step_one()
//    {
//        cont.add({ -99,-90 });
//        cont.add({ -80,-70 });
//        cont.add({ -60,-50 });
//        cont.add({ -40,-30 });
//        cont.add({ -20,-10 });
//        cont.add({ -100, -20 });
//        cont.add({ -99, -21 });
//        cont.print();
//    }
//
//    void step_two()
//    {
//        cont.add({ -5,-1 });
//        cont.add({ -1,0 });
//        cont.add({ 5,6 });
//        cont.add({ 5,5 });
//        cont.add({12 , 12});
//        cont.print();
//    }
//
//    ~TestCase()
//    {
//        cont.clear();
//    }
//};
//
//
//TEST(WithExceptionTests, Exceptions)
//{
//    SectorContainer<true> cont;
//    TestCase<true> qwe(cont);
//
//    ASSERT_THROW(cont.add({0,2}), std::domain_error);
//    ASSERT_THROW(cont.add({2,2}), std::domain_error);
//    ASSERT_THROW(cont.add({12,12}), std::domain_error);
//    ASSERT_THROW(cont.add({ -1,10 }), std::domain_error);
//    ASSERT_THROW(cont.add({ 5,6 }), std::domain_error);
//    ASSERT_THROW(cont.add({ 1,2 }), std::domain_error);
//    ASSERT_THROW(cont.add({-1, 100000000}), std::domain_error);
//}
//
//TEST(WithExceptionTests, findFunction)
//{
//    SectorContainer<true> cont;
//    TestCase<true> qwe(cont);
//
//    EXPECT_EQ(sector(*cont.find(0) ), sector(0,5));
//    EXPECT_EQ(sector(*cont.find(2) ), sector(0,5));
//    EXPECT_EQ(sector(*cont.find(5) ), sector(0,5));
//    EXPECT_EQ(sector(*cont.find(6) ), sector(6,9));
//    EXPECT_EQ(sector(*cont.find(9) ), sector(6,9));
//    EXPECT_EQ(sector(*cont.find(50)), sector(40, 100000));
//    EXPECT_EQ(cont.find(-1), cont.end());
//    EXPECT_EQ(cont.find(10), cont.end());
//    EXPECT_EQ(cont.find(11), cont.end());
//    EXPECT_EQ(cont.find(15), cont.end());
//    EXPECT_EQ(cont.find(100001), cont.end());
//    EXPECT_EQ(cont.find(35), cont.end());
//}
//
//
//TEST(NoExceptionTests, mergeTest)
//{
//    SectorContainer<false> cont;
//    TestCase<false> qwe(cont);
//    qwe.step_one();
//    EXPECT_EQ(sector(*cont.begin()), sector(-100,-10));
//    
//    cont.erase(cont.begin());
//    SectorContainer<false> cont2;
//    TestCase<false> qwe2(cont2);
//    EXPECT_EQ(cont, cont2);
//}
//
//
//TEST(NoExceptionTests, findFunction)
//{
//    SectorContainer<false> cont;
//    TestCase<false> qwe(cont);
//    qwe.step_one();
//    qwe.step_two();
//
//    EXPECT_EQ(sector(*cont.find(-10)), sector(-100,-10));
//    EXPECT_EQ(sector(*cont.find(-3)), sector(-5,9));
//    EXPECT_EQ(cont.find(-7), cont.end() );
//    EXPECT_EQ(cont.find(10), cont.end() );
//    
//    auto it = cont.begin();
//    EXPECT_EQ(sector(*it), sector(-100, -10) ); 
//    it++;
//    EXPECT_EQ(sector(*it), sector(-5,9 ));
//    it++;
//    EXPECT_EQ(sector(*it), sector(12, 12));
//    it++;
//    EXPECT_EQ(sector(*it), sector(20, 30));
//    it++;
//    EXPECT_EQ(sector(*it), sector(40,100000 ));
//    it++;
//    EXPECT_EQ(it, cont.end());
//}
//
//
//
//
//int main(int argc, char** argv)
//{
//    //по умолчанию считаем пару уже упорядоченной, т.е. first <= second
//    try
//    {
//        //SimpleVector vec;
//
//        //vec.add({ 1,2 });
//        //vec.add({ 0,2 });
//        //vec.add({ 6,7 });
//        //auto val = vec.find(3);
//
//        SectorContainer<false> sect; // шаблонный параметр true - кидаются исключения при пересечении отрезков,
//                                    //                    false(по умолчанию) - слияние пересекающихся в один
//        sector a(1, 4);
//        sector b(3, 7);
//        sect.add(a);
//        sect.add(b);
//        sect.add(sector(8, 9));
//        sect.add({ 13,15 });
//        sect.add({ { 0,1 }, { 9,13 }, {16,19} });
//        std::vector<sector> vecsec({ {-9,-8}, {-6,1} });
//        sect.add(vecsec);
//
//        auto it = sect.find(16);
//
//        sect.print();
//    }
//    catch (std::exception& e)
//    {
//        cout << e.what() << endl;
//        //std::abort();
//    }
//
//
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}