#pragma once

#include "BasicTime.h"

namespace DateTime
{
    class TimeInterval;

    class Time : public BasicTime
    {

    public:
        //friend class TimeInterval;
        ~Time() = default;

        enum {
            JANUARY = 1, FEBRUARY = 2, MARCH = 3, APRIL, MAY, JUNE,
            JULE, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
        };

        friend std::ostream& operator<<(std::ostream& ostr, const Time& t);

        Time();

        Time(int m, int h, int d, int mth, int y, bool checkException = true, bool sumValidity = false);

        void checkArguments();

        void checkSumValidity();

        static void setEuropeanFormat(bool b);

        static bool europeanFormat();

        TimeInterval operator-(const Time& rhs);

        Time operator+(const TimeInterval& rhs);

        Time operator-(const TimeInterval& rhs);

        Time operator+(const Time& rhs) = delete;

        bool operator==(const Time& rhs) const;

    protected:

        void updateField(int i) override;

        static const std::array<int, 13> m_daysInMonth;

        static bool m_format;

    };

    std::ostream& operator<<(std::ostream& ostr, const Time& t);




    class TimeInterval : public BasicTime
    {
    public:

        friend class Time;

        TimeInterval();

        TimeInterval(int m, int h, int d, int mth, int y);

        ~TimeInterval() = default;

        TimeInterval operator+(const TimeInterval& rhs);

        TimeInterval operator-(const TimeInterval& rhs);

        bool operator==(const TimeInterval& rhs) const;

    };


}