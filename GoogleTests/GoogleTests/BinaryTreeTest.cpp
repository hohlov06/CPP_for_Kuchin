#include "pch.h"

// Для запуска этого файла раскомментировать , если закомментировано
// Закомментировать во всех остальных cpp всё, что ниже #include "pch.h"
// либо исключить из проекта все остальные cpp
//
//#include <iostream>
//#include "../../BinaryTree/BinaryTree/BinaryTree.h"
//
//using namespace std;
//
//
//Tree<int, double> tree;
//
//class FillTree
//{
//public:
//    FillTree()
//    {
//        tree.add(10, 10.5);
//        tree.add(5, 5.5);
//        tree.add(4, 4.5);
//        tree.add(12, 12.5);
//        tree.add(8, 8.5);
//        tree.add(7, 7.5);
//        tree.add(9, 9.5);
//        tree.add(15, 15.5);
//    }
//    ~FillTree()
//    { 
//        tree.destruct(tree.GetRoot()); 
//    }
//};
//
//TEST(RootNullptr, first)
//{
//    EXPECT_EQ(tree.GetRoot(), nullptr);
//}
//
//TEST(CorrectLocation, TreeTraversal)
//{
//    FillTree qwe;
//    auto node = tree.GetRoot();
//    EXPECT_EQ(*node->GetData(), 10.5) ;
//    EXPECT_EQ(node->GetKey(), 10) ;
//    node = node->GetLeft();
//    EXPECT_EQ(*node->GetData(),5.5);
//    node = node->GetLeft();
//    EXPECT_EQ(*node->GetData(), 4.5);
//    EXPECT_EQ(node->GetLeft(), nullptr);
//    EXPECT_EQ(node->GetRight(), nullptr);
//    node = node->GetUp();
//    EXPECT_EQ(*node->GetData(), 5.5);
//    node = node->GetRight();
//    EXPECT_EQ(*node->GetData(), 8.5);
//    node = node->GetLeft();
//    EXPECT_EQ(*node->GetData(), 7.5);
//    EXPECT_EQ(node->GetLeft(), nullptr);
//    EXPECT_EQ(node->GetRight(), nullptr);
//    node = node->GetUp();
//    EXPECT_EQ(*node->GetData(), 8.5);
//    node = node->GetRight();
//    EXPECT_EQ(*node->GetData(), 9.5);
//    EXPECT_EQ(node->GetLeft(), nullptr);
//    EXPECT_EQ(node->GetRight(), nullptr);
//    node = node->GetUp();
//    EXPECT_EQ(*node->GetData(), 8.5);
//    node = node->GetUp();
//    EXPECT_EQ(*node->GetData(), 5.5);
//    node = node->GetUp();
//    EXPECT_EQ(*node->GetData(), 10.5);
//    node = node->GetRight();
//    EXPECT_EQ(*node->GetData(), 12.5);
//    EXPECT_EQ(node->GetLeft(), nullptr);
//    node = node->GetRight();
//    EXPECT_EQ(*node->GetData(), 15.5);
//    EXPECT_EQ(node->GetLeft(), nullptr);
//    EXPECT_EQ(node->GetRight(), nullptr);
//    node = node->GetUp();
//    EXPECT_EQ(*node->GetData(), 12.5);
//    node = node->GetUp();
//    EXPECT_EQ(*node->GetData(), 10.5);
//}
//
//TEST(RootNullptr, second)
//{
//    EXPECT_EQ(tree.GetRoot(), nullptr);
//}
//
//TEST(TestFind, TestFind)
//{
//    FillTree qwe;
//    EXPECT_EQ(*tree.find(7), 7.5);
//    EXPECT_EQ(*tree.find(9), 9.5);
//    EXPECT_EQ(*tree.find(8), 8.5);
//    EXPECT_EQ(*tree.find(5), 5.5);
//    EXPECT_EQ(*tree.find(4), 4.5);
//    EXPECT_EQ(*tree.find(10),10.5);
//    EXPECT_EQ(*tree.find(12),12.5);
//    EXPECT_EQ(*tree.find(15),15.5);
//    EXPECT_EQ(tree.find(0), nullptr);
//    EXPECT_EQ(tree.find(20),nullptr);
//    EXPECT_EQ(tree.find(6), nullptr);
//    EXPECT_EQ(tree.find(3), nullptr);
//
//}
//
//
//int main(int argc, char** argv)
//{
//    FillTree qwe;
//
//    cout << "tree.print()" << endl;
//    tree.print();
//    cout << endl << endl;
//
//    cout << "tree.pretty_print()" << endl;
//    tree.pretty_print();
//    cout << endl;
//
//    cout << "tree.GetRoot()->GetKey()" << endl;
//    cout << tree.GetRoot()->GetKey() << endl << endl;
//
//    cout << "*tree.find(7)" << endl;
//    cout << *tree.find(7) << endl << endl;
//
//    cout << "tree.MaxLayerNumber(tree.GetRoot())" << endl;
//    cout << tree.MaxLayerNumber(tree.GetRoot()) << endl << endl;
//
//    //программа обрушивается, т.к. разыменование nullptr
//    //cout << *tree.find(6) << endl;
//
//    tree.destruct(tree.GetRoot());
//
//    cout << "ok" << endl;
//
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}