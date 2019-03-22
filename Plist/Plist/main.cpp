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
    WrappedComplex c1((2.,0.)), c2((2., 4.)), c3((0., 4.)), c4((7., 6.));

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

    {
    Plist li;


    li.push_back(dptr1);
    li.push_back(iptr1);
    li.push_front(cptr1);
    li.print();

    li.add(dptr2,dptr1);
    bool has1 = li.has(dptr1);
    bool has2 = li.has(dptr3);
    li.drop(dptr2);
    li.drop(dptr3);
    li.print();
    li.clean();

    li.push_back(dptr1);
    li.push_back(iptr1);
    li.push_front(cptr1);
    li.add(dptr2, dptr1);
    has1 = li.has(dptr1);
    has2 = li.has(dptr3);
    li.drop(dptr2);
    li.drop(dptr3);

    }
    cout << "ok" << endl;
    system("pause");
    return 0;
}