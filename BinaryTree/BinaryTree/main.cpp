#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    Tree<int, double> tree;

    //data = key + 0.5;
    tree.add(10, 10.5);
    tree.add(5, 5.5);
    tree.add(4, 4.5);
    tree.add(12, 12.5);
    tree.add(8, 8.5);
    tree.add(7, 7.5);
    tree.add(9, 9.5);
    tree.add(15, 15.5);

    cout << "tree.print()" << endl;
    tree.print();
    cout << endl << endl;

    cout << "tree.pretty_print()" << endl;
    tree.pretty_print();
    cout << endl;

    cout << "tree.GetRoot()->GetKey()" << endl;
    cout << tree.GetRoot()->GetKey() << endl << endl;

    cout << "*tree.find(7)" << endl;
    cout << *tree.find(7) << endl << endl;

    cout << "tree.MaxLayerNumber(tree.GetRoot())" << endl;
    cout << tree.MaxLayerNumber(tree.GetRoot()) << endl << endl;

    //программа обрушивается, т.к. разыменование nullptr
    //cout << *tree.find(6) << endl;

    system("pause");
}
