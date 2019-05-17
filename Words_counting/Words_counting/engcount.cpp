#include <vector>
#include <utility>
#include <algorithm>
#include "engcount.h"

    WordCounter::WordCounter(const char* text_path,
                             const char* stop_path,
                             const char* output_path = "output.txt",
                             std::locale locale = std::locale("English")) : m_locale(locale),
                                                                            m_apostrophe(-110)// TODO зависит от кодировки
    {
        read_stop(stop_path);
        read_text(text_path);
        write_sorted(output_path);
    }

    void WordCounter::read_text(const char* text_path)
    {
        m_counter.clear();
        m_apostrophe_words.clear();

        std::fstream text_str;

        //system("chcp 1251");
        //setlocale(LC_ALL, "Russian");
        text_str.imbue(m_locale);

        if (!text_str.is_open())
        {
            text_str.clear();
            text_str.open(text_path, std::ios::in);
            std::string word;
            while (text_str >> word)
            {
                //bool qwe = (word == "sixteen-year-old") ? true : false; // for debugging
                bool apostrophe_flag = false;
                bool end_word_flag = false;

                for (int i = 0; i < word.size(); i++)
                {
                    char sym = word.at(i);
                    if (sym == m_apostrophe)
                        apostrophe_flag = true;

                    if (!isValid(sym))
                    {
                        word.erase(word.find_first_of(sym), 1);
                        i--;
                        end_word_flag = true;
                    }
                    else if (end_word_flag == true)
                    {
                        if (i > 0)
                        {
                            std::string subword = word.substr(0, i);
                            insertion(subword, apostrophe_flag);
                            word.erase(0, i);
                            i = 0;
                            apostrophe_flag = false;
                        }
                        end_word_flag = false;
                    }
                }
                if (!word.empty())
                {
                    insertion(word, apostrophe_flag);
                }
            }
            remove_apostrophes();
            text_str.close();
        }
    }

    void WordCounter::read_stop(const char* stop_path)
    {
        m_stops.clear();
        std::fstream text_str;
        text_str.imbue(m_locale);

        if (!text_str.is_open())
        {
            text_str.clear();
            text_str.open(stop_path, std::ios::in);
            std::string word;
            while (text_str >> word)
            {
                for (int i = 0; i < word.size(); i++)
                    word[i] = std::tolower(word[i], m_locale);
                m_stops.insert(word);
            }
            text_str.close();
        }
    }


    void WordCounter::write_alphabetical(const char* output_path)
    {
        std::fstream text_str;
        text_str.imbue(m_locale);

        if (!text_str.is_open())
        {
            text_str.clear();
            text_str.open(output_path, std::ios::out);
            for (const auto& item : m_counter)
            {
                text_str << item.first << " " << item.second << '\n';
            }
            text_str.close();
        }
    }


    void WordCounter::write_sorted(const char* output_path)
    {
        using map_ptr = std::pair<const std::string, int>* ;
        std::vector<map_ptr> sorted_map;
        sorted_map.reserve(m_counter.size());
        for (auto it = m_counter.begin(); it!=m_counter.end(); it++)
        {
            sorted_map.push_back(&(*it));
        }

        sort(sorted_map.begin(), sorted_map.end(),
            [](map_ptr lhs, map_ptr rhs) {return rhs->second < lhs->second; });
        std::fstream text_str;
        text_str.imbue(m_locale);

        if (!text_str.is_open())
        {
            text_str.clear();
            text_str.open(output_path, std::ios::out);
            for (map_ptr item : sorted_map)
            {
                text_str << item->first << " " << item->second << '\n';
            }
            text_str.close();
        }
    }




    void WordCounter::set_locale(std::locale locale)
    {
        m_locale = locale;
    }


    void WordCounter::insertion(std::string& word, bool apostrophe_flag)
    {
        for (int i = 0; i < word.size(); i++)
            word[i] = std::tolower(word[i], m_locale);
        if (m_stops.find(word) == m_stops.end())
            m_counter[word]++;
        if (apostrophe_flag == true)
            m_apostrophe_words.insert(word);
    }

    void WordCounter::remove_apostrophes() //для английского языка
    {
        for (const auto& item : m_apostrophe_words)
        {
            auto pos = item.find_first_of(m_apostrophe);

            std::string prefix;
            std::string suffix;

            if (pos == 0)
                ; // ...throw ?
            else if (pos == (item.size() - 1))
            {
                //...
            }
            else
            {
                suffix = item.substr(pos + 1, item.size() - pos - 1);
                if (suffix == "t")
                {
                    suffix = "not";
                    pos--;
                }
                else if ((suffix == "re"))
                {
                    suffix = "are";
                }
                else if (suffix == "d")
                {
                    suffix = "would";
                }
                else if (suffix == "ve")
                {
                    suffix = "have";
                }
                else if (suffix == "ll")
                {
                    suffix = "will";
                }
                else if (suffix == "m")
                {
                    suffix = "am";
                }
                else if (suffix == "s")
                {
                    suffix = m_apostrophe + suffix;
                }
                else continue;

                if (m_stops.find(suffix) == m_stops.end())
                    m_counter[suffix] += m_counter[item];
            }
            prefix = item.substr(0, pos);
            if (suffix == "not")
                if (prefix == "ca")
                    prefix = "can";
                else if (prefix == "wo")
                    prefix = "will";
            if (m_stops.find(prefix) == m_stops.end())
                m_counter[prefix] += m_counter[item];
            m_counter.erase(item);
        }
    }




    bool WordCounter::isValid(char sym)
    {
        return (m_locale == std::locale("English")) ? isValid_en(sym) :
            (m_locale == std::locale("Russian")) ? isValid_ru(sym) : throw("invalid_argument");
    }

    bool WordCounter::isValid_en(char sym)
    {
        return (((sym >= 'a') && (sym <= 'z')) ||
                ((sym >= 'A') && (sym <= 'Z')) ||
                (sym == m_apostrophe) || //апостроф
                (sym == '\'') ||
                ((sym >= '0') && (sym <= '9')) /*||
                ((sym >= '#') && (sym <= '\''))||
                ((sym >= '*') && (sym <= '+')) ||
                (sym == '-')                   ||
                (sym == '/')                   ||
                ((sym >= '<') && (sym <= '>')) ||
                (sym != '@')                     */);
    }

    bool WordCounter::isValid_ru(char sym)
    {
        return (((sym >= 'а') && (sym <= 'я')) ||
                ((sym >= 'А') && (sym <= 'Я')) ||
                ((sym >= '0') && (sym <= '9')) /*||
                ((sym >= '#') && (sym <= '\''))||
                ((sym >= '*') && (sym <= '+')) ||
                (sym == '-')                   ||
                (sym == '/')                   ||
                ((sym >= '<') && (sym <= '>')) ||
                (sym != '@')                     */);
    }