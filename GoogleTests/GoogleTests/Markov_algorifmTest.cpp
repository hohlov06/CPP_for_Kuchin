#include "pch.h"

// Для запуска этого файла раскомментировать , если закомментировано
// Закомментировать во всех остальных cpp всё, что ниже #include "pch.h"
// либо исключить из проекта все остальные cpp
//
//#include "../../Markov_algorifm/Markov_algorifm/MarkovString.h"
//
//#include <iostream>
//#include <list>
//
//using namespace std;
//
//Markov<char> mark;
//Markov<char> mark2;
//Markov<int> mark3;
//
//TEST(resultTest, charT)
//{
//    EXPECT_EQ(mark.getData(), std::string("Я купил килограмм апельсинов в том ларьке"));
//    EXPECT_EQ(mark2.getData(), std::string("|||||"));
//}
//
//TEST(resultTest, intT)
//{
//    EXPECT_EQ(mark3.getData(), std::list<int>({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}));
//}
//
//
//
//template <typename T>
//ostream& operator<<(ostream& stre, const std::list<T>& a) {
//    for (auto item : a)
//        stre << item << " ";
//    stre << "\n";
//    return stre;
//}
//
//
//int main(int argc, char** argv)
//{
//    std::list<int> a;
//    auto b = a.begin();
//    setlocale(LC_ALL, "Russian");
//
//
//
//
//    mark.setData("Я купил кг Аов в Т М");
//
//    mark.addRule("А", "апельсин", false);
//    mark.addRule("кг", "килограмм", false);
//    mark.addRule("М", "магазинчике", false);
//    mark.addRule("Т", "том", false);
//    mark.addRule("магазинчике", "ларьке", true);
//    mark.addRule("в том ларьке", "на том рынке", false);
//
//
//    cout << mark.getData() << endl;
//
//    while (mark.isTerminated() != true)
//    {
//        mark.step();
//        cout << mark.getData() << endl;
//    }
//
//    //mark.run();
//    //cout << mark.getData() << endl;
//
//    cout << "===================================================" << endl;
//
//
//
//    mark2.setData("101");
//    mark2.addRule("1", "0|", false);
//    mark2.addRule("|0", "0||", false);
//    mark2.addRule("0", "", false);
//
//    cout << mark2.getData() << endl;
//    while (mark2.isTerminated() != true)
//    {
//        mark2.step();
//        cout << mark2.getData() << endl;
//    }
//
//    //mark2.run();
//        //cout << mark2.getData() << endl;
//
//
//    cout << "===================================================" << endl;
//
//
//    mark3.setData({ 5 });
//    mark3.addRule({ 5 }, { 4, 4 }, false);
//    mark3.addRule({ 4 }, { 3, 3 }, false);
//    mark3.addRule({ 3 }, { 2, 2 }, false);
//    mark3.addRule({ 2 }, { 1, 1 }, false);
//
//    cout << mark3.getData() << endl;
//    while (mark3.isTerminated() != true)
//    {
//        mark3.step();
//        cout << mark3.getData() << endl;
//    }
//
//    //mark3.run();
//    //cout << mark3.getData() << endl;
//
//    cout << "===================================================" << endl;
//    cout << "ok" << endl;
//    //system("Pause");
//
//
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}