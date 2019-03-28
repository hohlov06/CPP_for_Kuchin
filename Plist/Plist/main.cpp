/*
����� ��������, �� �� ���, ��� �������� ��:
1)    ���������� ������� � ������ ������� ��� ����� WrappedType �������, 
    ������� ���������� �� �������� ���� mValue, �����������, �.�. ����������� ���� � ������� ������
    � ����������� ������ ���� ����������� (double � Complex �������� �� ��������, ��������).

    �� ���� �� ������� ���������� ����������� �������� ��������� 
    (��������, bool operator==(const WrappedType* rhs)), �.�. ���������� �����-�� �������
    ������� �������� mValue, �� ������� ����� �� ����� �� ���� ����, � ������� value() ������ �������
    �����������(�� ��� � �� ���� ���).

    ��-�� ����� ������� has � drop �������� �� ���, ��� ����. ��� ���� � ������ ������� �� �� ��������, � �� ��������� �� ������.
    �.�. ������ ������ � ������ �� ���� ����������, �� � ��� �� mValue, ��� �� ������

    ������ ����� ���� - ������ ����, �����, ��������, ������� "bool has(Base* value_)" �� ��������� ��������� �� ������� �����, 
    � ���� ���������, �� ��� ���������. ��� ���� �� ��� ������ ������������ � ��������� ������ � ��� ����(� �� ������).
*/



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

    {
    


    li.push_back(dptr1);
    li.push_back(iptr1);
    li.push_front(cptr2);
    li.print();

    bool has1 = li.has(dptr1);
    bool has2 = li.has(dptr3);

    cout << "is ";
    dptr1->print();
    cout << " here: " << has1 << endl;

    cout << "is ";
    dptr3->print();
    cout << " here: " << has2 << endl;

    //drop ������� �� ���, � ������ ����������� ptr
    li.drop(dptr1);
    li.drop(dptr3);
    li.print();
    li.clean();

    li.push_back(dptr3);
    li.push_back(cptr1);
    li.push_back(dptr3);
    li.push_front(cptr3);
    li.push_back(dptr3);
    li.print();
    li.add(cptr2, li.end()->prev_ptr->prev_ptr);
    li.print();
    has1 = li.has(dptr1);
    has2 = li.has(dptr3);

    cout << "is ";
    dptr1->print();
    cout << " here: " << has1 << endl;

    cout << "is ";
    dptr3->print();
    cout << " here: " << has2 << endl;


    li.drop(dptr2);
    li.drop(dptr3);
    li.print();
    }
    cout << "ok" << endl;


    li.clean();
    cout << "ok" << endl;

    system("pause");
    return 0;
}