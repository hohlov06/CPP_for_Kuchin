#include <stdexcept>
#include <iomanip>

#include "Time.h"

namespace DateTime {

    Time::Time() : BasicTime(&limitDate) { }

    Time::Time(int m, int h, int d, int mth, int y, bool checkException, bool sumValidity) : BasicTime(m, h, d, mth, y, &limitDate)
    {
        if (checkException == true)
        {
            if (sumValidity == false)
                checkArguments();
            else
                checkSumValidity();
        }
        update();
    }

    void Time::checkArguments()
    {
        for (int i = 0; i < 4; i++)
            if ((m_field[i] > limitDate[i].second) ||
                (m_field[i] < limitDate[i].first))
                throw std::domain_error("arguments is out of limits, field: "
                    + m_fieldName[i] + " = " + std::to_string(m_field[i]) + '\n');
        if (m_field[DAY] > m_daysInMonth[m_field[MONTH] - 1])
            throw std::domain_error("arguments is out of limits, field: "
                + m_fieldName[DAY] + " = " + std::to_string(m_field[DAY]) + '\n');
    }

    void Time::checkSumValidity()
    {
        for (int i = 0; i < 4; i++)
            if ((m_field[i] > (limitDate[i].second + limitInterval[i].second)) ||
                (m_field[i] < (limitDate[i].first - limitInterval[i].second)))
                throw std::domain_error("result of Time+TimeInterval is out of limits, field: "
                    + m_fieldName[i] + " = " + std::to_string(m_field[i]) + '\n');
    }


    void Time::updateField(int i)
    {
        int lowerLimit = m_pLimit->at(i).first;
        int upperLimit;

        if (i != DAY)
            upperLimit = m_pLimit->at(i).second - m_pLimit->at(i).first + 1;
        else
        {
            updateField(MONTH);
            if (m_field[i] < lowerLimit)
            {
                switch (m_field[MONTH])
                {
                case(MARCH):
                    upperLimit = (m_field[YEAR] % 4 == 0) ? 29 : 28;
                    break;
                case(JANUARY):
                    upperLimit = m_daysInMonth[DECEMBER - 1];
                    break;
                default:
                    upperLimit = m_daysInMonth[m_field[MONTH] - 1];
                    break;
                }
            }
            else //(m_field[i] >= lowerLimit)
            {
                if (m_field[MONTH] == FEBRUARY)
                    upperLimit = (m_field[YEAR] % 4 == 0) ? 29 : 28;
                else
                    upperLimit = m_daysInMonth[m_field[MONTH] - 1];
            }
        }

        if ((m_field[i] < lowerLimit) || (m_field[i] > upperLimit))
        {
            int unit = (m_field[i] < lowerLimit) ? -1 : 1;
            m_field[i] = m_field[i] - unit * upperLimit;
            m_field[i + 1] += unit;

            if ((m_field[i] < lowerLimit) || (m_field[i] > upperLimit))
                updateField(DAY);
        }
    }


    void Time::setEuropeanFormat(bool b) { m_format = b; }

    bool Time::europeanFormat() { return m_format; }


    TimeInterval Time::operator-(const Time& rhs)
    {
        return TimeInterval{ m_field[0] - rhs.m_field.at(0),
                             m_field[1] - rhs.m_field.at(1),
                             m_field[2] - rhs.m_field.at(2),
                             m_field[3] - rhs.m_field.at(3),
                             m_field[4] - rhs.m_field.at(4) };
    }

    Time Time::operator+(const TimeInterval& rhs)
    {
        return Time{ m_field[0] + rhs.m_field.at(0),
                     m_field[1] + rhs.m_field.at(1),
                     m_field[2] + rhs.m_field.at(2),
                     m_field[3] + rhs.m_field.at(3),
                     m_field[4] + rhs.m_field.at(4),
                     true, true };
    }

    Time Time::operator-(const TimeInterval& rhs)
    {
        return Time{ m_field[0] - rhs.m_field.at(0),
                     m_field[1] - rhs.m_field.at(1),
                     m_field[2] - rhs.m_field.at(2),
                     m_field[3] - rhs.m_field.at(3),
                     m_field[4] - rhs.m_field.at(4),
                     true, true };
    }


    bool Time::m_format = true;

    const std::array<int, 12> Time::m_daysInMonth = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };



    //=====================================================================

    TimeInterval::TimeInterval() : BasicTime() { }

    TimeInterval::TimeInterval(int m, int h, int d, int mth, int y) : BasicTime(m, h, d, mth, y) { update(); }

    TimeInterval TimeInterval::operator+(const TimeInterval& rhs)
    {
        return TimeInterval{ m_field[0] + rhs.m_field.at(0),
                             m_field[1] + rhs.m_field.at(1),
                             m_field[2] + rhs.m_field.at(2),
                             m_field[3] + rhs.m_field.at(3),
                             m_field[4] + rhs.m_field.at(4) };
    }

    TimeInterval TimeInterval::operator-(const TimeInterval& rhs)
    {
        return TimeInterval{ m_field[0] - rhs.m_field.at(0),
                             m_field[1] - rhs.m_field.at(1),
                             m_field[2] - rhs.m_field.at(2),
                             m_field[3] - rhs.m_field.at(3),
                             m_field[4] - rhs.m_field.at(4) };
    }


    std::ostream& operator<<(std::ostream& ostr, const Time& t)
    {
        if (t.europeanFormat() == true)
        {
            std::cout.fill('0');
            std::cout << std::setw(2) << t.m_field[Time::HOUR] << ":"
                << std::setw(2) << t.m_field[Time::MINUTE] << " "
                << std::setw(2) << t.m_field[Time::DAY] << "/"
                << std::setw(2) << t.m_field[Time::MONTH] << "/"
                << t.m_field[Time::YEAR];
        }
        else
        {
            bool pm = (t.m_field[Time::HOUR] > 12) ? true : false;
            std::cout.fill('0');
            if (t.m_field[Time::HOUR] <= 12)
            {
                std::cout << t.m_field[Time::HOUR] << ":"
                    << std::setw(2) << t.m_field[Time::MINUTE] << " AM ";
            }
            else
            {
                std::cout << (t.m_field[Time::HOUR] - 12) << ":"
                    << std::setw(2) << t.m_field[Time::MINUTE] << " PM ";
            }

            std::cout << std::setw(2) << t.m_field[Time::MONTH] << "/"
                << std::setw(2) << t.m_field[Time::DAY] << "/"
                << t.m_field[Time::YEAR];
        }

        return ostr;
    }

}