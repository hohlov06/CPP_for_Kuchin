#pragma once
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>

using LLint = long long int;
using sector = std::pair<LLint, LLint>;


template <bool exception_flag = false>
class SectorContainer
{
    using IterT = std::map<LLint, LLint>::iterator;

private:
    std::map<LLint, LLint> m_cont;

public:

    SectorContainer() {}

    inline IterT begin() { return m_cont.begin(); }
    inline IterT end() { return m_cont.end(); }


    template <bool flagTrue = exception_flag>
    void throwException(const sector& sec, int line_) {}

    template <>
    void throwException<true>(const sector& sec, int line_)
    {
        throw std::domain_error(std::string("segment {") + std::to_string(sec.first) + ", " +
            std::to_string(sec.second) + "} intersection, line: " + std::to_string(line_));
    }

    //template <bool flagTrue = exception_flag>
    //void throwException(const sector& sec, int line_, typename std::enable_if<flagTrue, bool>::type = 0)
    //{
    //    throw std::domain_error(std::string("segment {") + std::to_string(sec.first) + ", " + 
    //                            std::to_string(sec.second) + "} intersection, line: " + std::to_string(line_));
    //}

    //template <bool flagTrue = exception_flag>
    //void throwException(const sector& sec, int line_, typename std::enable_if<!flagTrue, bool>::type = 0) {}

    void add(sector sec)
    {           
        if (sec.first > sec.second)
            sec = std::make_pair(sec.second, sec.first);
        // 
        if (!m_cont.empty())
        {
            if (sec.first == sec.second)
            {
                if (find(sec.first) == m_cont.end())
                {
                    // ���� ����� �� ����������� �������� ������� ���������
                    m_cont.insert(sec);
                    return;
                }
                else
                {
                    // ���� �����������, ������ �� ������ ��� ������ ����������, �.�. ������� ����� ������, ��� �����
                    throwException(sec, __LINE__);
                }
            }
            else
            {
                if ((sec.second < m_cont.begin()->first) || ((sec.first > std::prev(m_cont.end())->second)))
                {
                    m_cont.insert(sec);
                    return;
                }

                // ������ it_left � it_right, ������� ����� ���������� ����, �� ����� ���� ������������ begin()
                // � ���������� ���� it_left � it_right ����� ��� end(), ����� ������� sec ����������� ����������� � ������� ���������
                // ������ ��� ������ ������������� ��������� ����

                else
                {
                    auto it_left = m_cont.upper_bound(sec.first);
                    auto it_right = m_cont.upper_bound(sec.second);

                    // ����������� ��������� ���������� �������, ��� ������� ������� sec �� ������������ � �������:
                    // it_left == it_right. �� ����������� ���� �������, ��� ��� �� ����� ���� ������������ end() ��� begin()
                    // ������, ����� �������������� it_left-- � it_right
                    // �� ������������, ���� it_left->second < sec.first < sec.second < it_right->first

                    if (it_left == it_right)
                    {
                        it_left--;
                        if ((it_left->second < sec.first) && (sec.second < it_right->first))
                        {
                            m_cont.insert(sec);
                            return;
                            // ���� ������� add �� ����������� �� ����� �����, �� sec ����������� � ���-�� ������������
                            // ����� ������ ����������
                        }
                        else
                        {
                            //����������
                            throwException(sec, __LINE__);
                            it_right--;
                            std::pair<LLint, LLint> biggest_sec(std::min(sec.first, it_left->first),
                                                                std::max(sec.second, it_right->second));
                            // �.�. ���� it_right == it_left, �� ����������� ������ � ����� ��������
                            // ������� �� �����������, ������� ������ - ���������� �������
                            m_cont.erase(it_right);
                            m_cont.insert(biggest_sec);
                        }
                    }
                    else
                    {
                        throwException(sec, __LINE__);
                        if (it_left == m_cont.begin()) // ����� ����� sec �� ����� �������������� � �������� (it_left--), ������
                                                       // �������� ����� ����� �� ������ �����, �.�. ������ ������� ���
                                                       // ����������� ���� �������� �� ���������� �� it_right � �������� sec
                        {
                            std::pair<LLint, LLint> biggest_sec(sec.first,
                                                                std::max(sec.second, std::prev(it_right)->second));
                            m_cont.erase(m_cont.begin(), it_right); //TODO ���������
                            m_cont.insert(biggest_sec);
                        }
                        else // ����� ����� sec ����� �������������� � �������� it_left--, ������
                             // �������� ����� ����� �� ������ �����
                        {
                            if (std::prev(it_left)->second >= sec.first) // ����� ����� sec ������������� � "������� �����" ��������
                                it_left--;
                            // sec ������ ������������� � ��������� � ��������� (it_left, it_right)
                            std::pair<LLint, LLint> biggest_sec(std::min(sec.first, it_left->first),
                                                                std::max(sec.second, std::prev(it_right)->second));
                            m_cont.erase(it_left, it_right);//TODO ���������
                            m_cont.insert(biggest_sec);
                        }
                    }
                }
            }
        }
        else
            m_cont.insert(sec);
        return;
    }

    void add(std::initializer_list<LLint> sec)
    {
        if (sec.size() != 2)
            throw std::invalid_argument(std::string("argument in constructor void add(std::initializer_list<std::initializer_list<LLint>> sec)") +
                std::string("must look like add({{1,2},{3,4}, ... {5,6}}) or add({1,2})"));
        add(sector{ *sec.begin(), *std::next(sec.begin()) });
    }

    void add(const std::vector<sector>& sec)
    {
        for (const auto& item : sec)
            add(item);
    }


    void add(std::initializer_list<std::initializer_list<LLint>> sec)
    {
        for (const auto& item : sec)
            add(item);
    }

    auto find(LLint value) const
    {
        auto it = m_cont.upper_bound(value);

        if (it == m_cont.begin())
            return m_cont.end();
        else
            {
                it--;
                if ((it->first <= value) && (it->second >= value))
                    return it;
            }

        return m_cont.end();
    }


    void print()
    {
        for (auto item : m_cont)
            std::cout << "{" << item.first << " " << item.second << "} ";
        std::cout << '\n';
    }

    template <bool exFlag = false>
    void merge(const SectorContainer<exFlag>& rhs)
    {
        for (auto item : rhs.m_cont)
            m_cont.add(item);
    }


    bool empty() const
    {
        return m_cont.empty();
    }

    std::size_t size() const
    {
        return m_cont.size();
    }

    std::size_t max_size() const
    {
        return m_cont.max_size();
    }

    void clear()
    {
        m_cont.clear();
    }

    IterT erase(IterT pos)
    {
        return m_cont.erase(pos);
    }

    IterT erase(IterT first, IterT last)
    {
        return m_cont.erase(first, last);
    }

    //template<bool ExFlag>
    //bool operator==(const SectorContainer<ExFlag>& rhs) const
    //{
    //    return (m_cont == rhs.m_cont);
    //}

    template<bool ExFlag1, bool ExFlag2>
    friend bool operator==(const SectorContainer<ExFlag1>& lhs, const SectorContainer<ExFlag2>& rhs);
};

template<bool ExFlag1, bool ExFlag2>
bool operator==(const SectorContainer<ExFlag1>& lhs, const SectorContainer<ExFlag2>& rhs)
{
    return (lhs.m_cont == rhs.m_cont);
}