#include "BasicTime.h"

#include <iomanip>

namespace DateTime {

    using limitType = std::array<std::pair<int, int>, 4>;

    //limitType limitInterval = { std::make_pair(0,59), std::make_pair(0,23), std::make_pair(0,30), std::make_pair(0,11) };
    //limitType limitDate = { std::make_pair(0,59), std::make_pair(0,23), std::make_pair(1,31), std::make_pair(1,12) };

    BasicTime::BasicTime() : m_field({ 0,0,0,0,0 }),
        m_pLimit(&limitInterval) { }

    BasicTime::BasicTime(const limitType* limptr) : m_field({ 0,0,1,1,2019 }),
        m_pLimit(limptr) { }

    BasicTime::BasicTime(int m, int h, int d, int mth, int y) : m_field({ m,h,d,mth,y }),
        m_pLimit(&limitInterval) {  }

    BasicTime::BasicTime(int m, int h, int d, int mth, int y, const limitType* limptr) : m_field({ m,h,d,mth,y }),
        m_pLimit(limptr) { }

    const std::array<int, 5>& BasicTime::getTime() const { return m_field; }


    void BasicTime::update()
    {
        for (int i = 0; i < 4; i++)
            updateField(i);
    }


    void BasicTime::updateField(int i)
    {
        int lowerLimit = m_pLimit->at(i).first;
        int upperLimit = m_pLimit->at(i).second - m_pLimit->at(i).first + 1;;

        if ((m_field[i] < lowerLimit) || (m_field[i] > m_pLimit->at(i).second))
        {
            int unit = m_field[i] / upperLimit;
            if (m_field[i] < lowerLimit)
                unit--;
            m_field[i] = m_field[i] - unit * upperLimit/* + lowerLimit*/;
            m_field[i + 1] += unit;
        }
    }


    const std::array<std::string, 5> BasicTime::m_fieldName = { "minutes","hours", "days", "months", "years" };


    std::ostream& operator<<(std::ostream& ostr, const BasicTime& t)
    {
        bool dotFlag = false;
        std::cout.fill('0');
        for (int i = 0; i < 4; i++)
        {
            if (dotFlag == false)
                dotFlag = true;
            else
                std::cout << ", ";
            std::cout << std::setw(2) << t.m_field[i] << " " << t.m_fieldName[i];
        }

        std::cout << ", " << t.m_field[BasicTime::YEAR] << " " << t.m_fieldName[BasicTime::YEAR];

        return ostr;
    }

}