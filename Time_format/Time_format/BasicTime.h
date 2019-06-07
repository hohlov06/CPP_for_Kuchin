#pragma once

#include <array>
#include <string>
#include <utility>
#include <iostream>

// считаем, что для временного интервала в каждом месяце по 31 дню
// для даты количество дней зависит от месяца и от того, високосный год или нет
namespace DateTime {

    using limitType = std::array<std::pair<int, int>, 4>;

    const limitType limitInterval = { std::make_pair(0,59), std::make_pair(0,23), std::make_pair(0,30), std::make_pair(0,11) };
    const limitType limitDate = { std::make_pair(0,59), std::make_pair(0,23), std::make_pair(1,31), std::make_pair(1,12) };

    class BasicTime
    {

    public:

        enum { MINUTE, HOUR, DAY, MONTH, YEAR };

    protected:

        std::array<int, 5> m_field;

        const limitType* const m_pLimit;

        static const std::array<std::string, 5> m_fieldName;

    public:

        BasicTime();

        BasicTime(const limitType* limptr);

        BasicTime(int m, int h, int d, int mth, int y);

        BasicTime(int m, int h, int d, int mth, int y, const limitType* limptr);

        //BasicTime(const BasicTime&) = default;
        //BasicTime& operator=(const BasicTime&) = default;
        //BasicTime(BasicTime&&) = default;
        //BasicTime& operator=(BasicTime&&) = default;
        virtual ~BasicTime() = default;

        friend std::ostream& operator<<(std::ostream& ostr, const BasicTime& t);

    public:

        const std::array<int, 5>& getTime() const;

        const inline int minute() const     { return m_field.at(0); }
        const inline int hour()   const     { return m_field.at(1); }
        const inline int day()    const     { return m_field.at(2); }
        const inline int month()  const     { return m_field.at(3); }
        const inline int year()   const     { return m_field.at(4); }
        const inline int field(int i) const { return m_field.at(i); }

        virtual void update();

    protected:

        virtual void updateField(int i);

    };

    std::ostream& operator<<(std::ostream& ostr, const BasicTime& t);
}