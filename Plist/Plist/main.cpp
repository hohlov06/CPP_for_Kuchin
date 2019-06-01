#include <iostream>

//#include <vector>
//#include <list>
//#include "../../Rational/Rational.h"

//#include "WrappedTypes.h"
#include "Plist.h"

using namespace std;


int main()
{

    WrappedDouble d1(2.), d2(4.), d3(15.);
    WrappedInt i1(4), i2(6), i3(9), i4(9);
    WrappedComplex c1(Complex(2.,0.)), c2(Complex(2., 4.)), c3(Complex(0., 4.)), c4(Complex(7., 6.));

    auto dptr1 = make_shared<WrappedDouble>(d1);
    auto dptr2 = make_shared<WrappedDouble>(d2);
    auto dptr3 = make_shared<WrappedDouble>(d3);

    auto iptr1 = make_shared<WrappedInt>(i1);
    auto iptr2 = make_shared<WrappedInt>(i2);
    auto iptr3 = make_shared<WrappedInt>(i3);
    auto iptr4 = make_shared<WrappedInt>(i4);

    auto cptr1 = make_shared<WrappedComplex>(c1);
    auto cptr2 = make_shared<WrappedComplex>(c2);
    auto cptr3 = make_shared<WrappedComplex>(c3);
    auto cptr4 = make_shared<WrappedComplex>(c4);

    Plist li;

    

    li.push_back(dptr1); //2.
    li.push_back(iptr1); //4
    li.push_front(cptr2); //<2, 4>
    li.print();

    cout << "is ";
    cptr1->print(); // <2, 0> 
    cout << " here: " << li.has(cptr1) << endl; //true

    cout << "is ";
    dptr3->print(); //15.
    cout << " here: " << li.has(dptr3) << endl; //false

    cout << "is ";
    dptr2->print(); //4.
    cout << " here: " << li.has(dptr2) << endl; //true

    //drop удаляет не все, а первый встреченный ptr

    li.drop(dptr1); //2.
    li.drop(dptr3); //15.
    li.print();
    li.clean();


    li.push_back(dptr3); //15.
    li.push_back(cptr1); //<2,0>
    li.push_back(dptr3); // 15.
    li.push_front(cptr3);// <0, 4>
    li.push_back(dptr3); // 15.
    li.print();
    li.add(cptr2, li.end()->prev_ptr->prev_ptr); //<2,4>
    li.print();

    cout << "is ";
    dptr1->print(); //2.
    cout << " here: " << li.has(dptr1) << endl;

    cout << "is ";
    dptr3->print(); //15.
    cout << " here: " << li.has(dptr3) << endl;


    li.drop(dptr2); //4.
    li.drop(dptr3); //15.
    li.print();
    
    cout << "ok" << endl;


    li.clean();
    cout << "ok" << endl;

    li.print();

    system("pause");
    return 0;
}




//
//void test_function(WrappedType* base)
//{
//    auto derived = dynamic_cast<WrappedDouble*>(base);
//    //cout << base->typeOfValue() << " " << derived->typeOfValue();
//    cout << is_same<decltype(*base), decltype(*derived)>::value << endl;
//    cout << is_same<decltype(*base), WrappedType&>::value << endl;
//    cout << is_same<WrappedDouble&, decltype(*derived)>::value << endl;
//    cout << is_same<WrappedDouble, WrappedDouble>::value << endl;
//    cout << "======" << endl;
//    cout << derived->value() << endl;
//    cout << "ok!" << endl;
//    cout << "======" << endl;
//}

//void test_function_sptr(S_ptr base)
//{
//    auto derived = dynamic_pointer_cast<WrappedDouble>(base);
//    //cout << base->typeOfValue() << " " << derived->typeOfValue();
//    cout << is_same<decltype(*base), decltype(*derived)>::value << endl;
//    cout << is_same<decltype(*base), WrappedType&>::value << endl;
//    cout << is_same<WrappedDouble&, decltype(*derived)>::value << endl;
//    cout << is_same<WrappedDouble, WrappedDouble>::value << endl;
//    cout << "======" << endl;
//    cout << derived->value() << endl;
//    cout << "ok!" << endl;
//}