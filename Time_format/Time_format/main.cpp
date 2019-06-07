#include <iostream>

#include "Time.h"
#include "BasicTime.h"

using namespace std;
using namespace DateTime;

int main()
{
    try {
        Time t1(0, 0, 32, 1, 2019, false);
        Time t2(0, 0, 1, 1, 2019, false);
        TimeInterval ti1(0, 0, 10, 1, 1);
        TimeInterval ti2(1, 0, 10, 1, 1);
        cout << t1 << endl;
        cout << t2 << endl;
        /*t1.setEuropeanFormat(false);
        cout << t1 << endl;*/

        TimeInterval t = t1 - t2;
        //Time tt = t1 + t2;
        cout << t << endl;
        //TimeInterval ti2 = ti;
        //t = t + ti;
        //cout << (t + ti )<< endl;
    }
    catch (std::exception& e) { cout << e.what(); }



    system("pause");
}