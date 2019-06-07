#include "pch.h"

// Для запуска этого файла раскомментировать , если закомментировано
// Закомментировать во всех остальных cpp всё, что ниже #include "pch.h"
// либо исключить из проекта все остальные cpp
//
//#include "../../Plist/Plist/Plist.h"
//
//using namespace std;
//
//
//WrappedDouble d1(2.), d2(4.), d3(15.);
//WrappedInt i1(4), i2(6), i3(9), i4(9);
//WrappedComplex c1(Complex(2., 0.)), c2(Complex(2., 4.)), c3(Complex(0., 4.)), c4(Complex(7., 6.));
//
//auto dptr1 = make_shared<WrappedDouble>(d1);
//auto dptr2 = make_shared<WrappedDouble>(d2);
//auto dptr3 = make_shared<WrappedDouble>(d3);
//
//auto iptr1 = make_shared<WrappedInt>(i1);
//auto iptr2 = make_shared<WrappedInt>(i2);
//auto iptr3 = make_shared<WrappedInt>(i3);
//auto iptr4 = make_shared<WrappedInt>(i4);
//
//auto cptr1 = make_shared<WrappedComplex>(c1);
//auto cptr2 = make_shared<WrappedComplex>(c2);
//auto cptr3 = make_shared<WrappedComplex>(c3);
//auto cptr4 = make_shared<WrappedComplex>(c4);
//
//Plist li;
//
//class FillPlist_1
//{
//public:
//
//    FillPlist_1()
//    {
//        li.push_back(dptr1); //2.
//        li.push_back(iptr1); //4
//        li.push_front(cptr2); //<2, 4>
//    }
//
//    void step_1()
//    {
//        li.drop(dptr1); //2.
//        li.drop(dptr3); //15.
//    }
//
//
//    ~FillPlist_1()
//    {
//        li.clean();
//    }
//};
//
//
//class FillPlist_2
//{
//public:
//
//    FillPlist_2()
//    {
//        li.push_back(dptr3); //15.
//        li.push_back(cptr1); //<2,0>
//        li.push_back(dptr3); // 15.
//        li.push_front(cptr3);// <0, 4>
//        li.push_back(dptr3); // 15.
//    }
//
//    void step_1()
//    {
//        li.add(cptr2, li.end()->prev_ptr->prev_ptr); //<2,4>
//    }
//
//    void step_2()
//    {
//        li.drop(dptr2); //4.
//        li.drop(dptr3); //15.
//    }
//
//    ~FillPlist_2()
//    {
//        li.clean();
//    }
//};
//
//
//TEST(HasFunction, first)
//{
//    FillPlist_1 qwe;
//
//    EXPECT_EQ(li.has(cptr1), true);
//    EXPECT_EQ(li.has(dptr3), false);
//    EXPECT_EQ(li.has(dptr2), true);
//
//    qwe.step_1();
//
//    EXPECT_EQ(li.has(dptr1), false);
//}
//
//TEST(HasFunction, second)
//{
//    FillPlist_2 qwe;
//
//    EXPECT_EQ(li.has(dptr1), true);
//    EXPECT_EQ(li.has(dptr3), true);
//
//    qwe.step_1();
//
//    EXPECT_EQ(li.has(cptr2), true);
//
//    qwe.step_2();
//
//    EXPECT_EQ(li.has(dptr3), true);
//    EXPECT_EQ(li.has(cptr4), false);
//}
//
//
//
//int main(int argc, char** argv)
//{
//
//
//
//
//
//    li.push_back(dptr1); //2.
//    li.push_back(iptr1); //4
//    li.push_front(cptr2); //<2, 4>
//    li.print();
//
//    cout << "is ";
//    cptr1->print(); // <2, 0> 
//    cout << " here: " << li.has(cptr1) << endl; //true
//
//    cout << "is ";
//    dptr3->print(); //15.
//    cout << " here: " << li.has(dptr3) << endl; //false
//
//    cout << "is ";
//    dptr2->print(); //4.
//    cout << " here: " << li.has(dptr2) << endl; //true
//
//    //drop удаляет не все, а первый встреченный ptr
//
//    li.drop(dptr1); //2.
//    li.drop(dptr3); //15.
//    li.print();
//    li.clean();
//
//
//    li.push_back(dptr3); //15.
//    li.push_back(cptr1); //<2,0>
//    li.push_back(dptr3); // 15.
//    li.push_front(cptr3);// <0, 4>
//    li.push_back(dptr3); // 15.
//    li.print();
//    li.add(cptr2, li.end()->prev_ptr->prev_ptr); //<2,4>
//    li.print();
//
//    cout << "is ";
//    dptr1->print(); //2.
//    cout << " here: " << li.has(dptr1) << endl;
//
//    cout << "is ";
//    dptr3->print(); //15.
//    cout << " here: " << li.has(dptr3) << endl;
//
//
//    li.drop(dptr2); //4.
//    li.drop(dptr3); //15.
//    li.print();
//
//    cout << "ok" << endl;
//
//
//    li.clean();
//    cout << "ok" << endl;
//
//    li.print();
//
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}