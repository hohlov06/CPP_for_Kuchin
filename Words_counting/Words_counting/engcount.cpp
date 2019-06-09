#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include "engcount.h"
#include <experimental/filesystem>


namespace WordCount {

#ifdef GOOGLE_TEST_DEBUG
    std::string projPath = std::experimental::filesystem::current_path().parent_path().parent_path().string()
        + "\\Words_counting\\Words_counting\\";
    std::string exePath = std::experimental::filesystem::current_path().parent_path().parent_path().string()
        + "\\Words_counting\\Debug\\";
#else
    std::string projPath = std::experimental::filesystem::current_path().string() + "\\";
    std::string exePath = std::experimental::filesystem::current_path().parent_path().string() + "\\Debug\\";
#endif 


    WordCounter::WordCounter(const char* text_path,
        const char* stop_path,
        const char* output_path = "output.txt",
        std::string locale_str = "english") : m_apostrophe(-110), m_locale_str(locale_str)// TODO зависит от кодировки
    {
        set_locale(locale_str);
        count(text_path, stop_path);
        stem_count();
        write(output_path, "-w-f");
    }

    void WordCounter::read(const char* text_path, char c = 't')
    {
        std::fstream text_str;
        text_str.imbue(m_locale);

        if (!text_str.is_open())
        {
            text_str.clear();


            if (c == 't') // text
            {
                text_str.open(projPath + text_path, std::ios::in);
                read_text(text_str);
            }
            else if (c == 'c') // stop words
            {
                text_str.open(projPath + text_path, std::ios::in);
                read_stop(text_str);
            }
            else if (c == 's') // stemmed
            {
                text_str.open(projPath + text_path, std::ios::in);
                read_stemmed(text_str);
            }
            else
                throw std::invalid_argument("argument for read must be t, c, s");

            text_str.close();
        }
    }


    void WordCounter::read_text(std::fstream& text_str)
    {
        m_counter.clear();
        m_apostrophe_words.clear();
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
    }

    void WordCounter::read_stop(std::fstream& text_str)
    {
        m_stops.clear();
        std::string word;
        while (text_str >> word)
        {
            for (int i = 0; i < word.size(); i++)
                word[i] = std::tolower(word[i], m_locale);
            m_stops.insert(word);
        }
    }

    void WordCounter::read_stemmed(std::fstream& text_str)
    {
        m_stemmed.clear();
        std::string word;
        auto it = m_counter.begin();
        while (text_str >> word)
        {
            //for (int i = 0; i < word.size(); i++)
            //    word[i] = std::tolower(word[i], m_locale);
            m_stemmed[word] += it->second;
            it++;
        }
    }

    void WordCounter::sort(std::unordered_map<std::string, int>& counter,
        std::vector<map_ptr>& sorted_alphabet,
        std::vector<map_ptr>& sorted_frequent)
    {
        sorted_frequent.clear();
        sorted_alphabet.clear();


        m_sorted_frequent.reserve(counter.size());
        m_sorted_alphabet.reserve(counter.size());
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            sorted_frequent.push_back(&(*it));
            sorted_alphabet.push_back(&(*it));
        }


        std::sort(sorted_frequent.begin(), sorted_frequent.end(),
            [](map_ptr lhs, map_ptr rhs) {return rhs->second < lhs->second; });

        std::sort(sorted_alphabet.begin(), sorted_alphabet.end(),
            [](map_ptr lhs, map_ptr rhs) {return rhs->first > lhs->first; });
    }


    void WordCounter::write(const char* output_path, std::string s = "-w-f")
    {
        std::fstream text_str;
        text_str.imbue(m_locale);

        if (!text_str.is_open())
        {
            text_str.clear();
            text_str.open(projPath + output_path, std::ios::out);

            if (s == "-w-f") // frequency counter
            {
                for (map_ptr item : m_sorted_frequent)
                {
                    text_str << item->first << " " << item->second << '\n';
                }
            }
            else if (s == "-w-a") // alphabetical counter
            {
                for (map_ptr item : m_sorted_alphabet)
                {
                    text_str << item->first << " " << item->second << '\n';
                }
            }
            else if (s == "-w-c") // chronological counter
            {
                for (const auto& item : m_counter)
                {
                    text_str << item.first << " " << item.second << '\n';
                }
            }
            else if (s == "-w-o") //only words
            {
                for (const auto& item : m_counter)
                {
                    text_str << item.first << '\n';
                }
            }
            else if (s == "-s-f") // stemmed by frequence
            {
                for (const auto& item : m_sorted_stemmed_frequent)
                {
                    text_str << item->first << " " << item->second << '\n';
                }
            }
            else if (s == "-s-a") // stemmed alphabetical
            {
                for (const auto& item : m_sorted_stemmed_alphabet)
                {
                    text_str << item->first << " " << item->second << '\n';
                }
            }
            else if (s == "-s-c") // stemmed chronological
            {
                for (const auto& item : m_stemmed)
                {
                    text_str << item.first << " " << item.second << '\n';
                }
            }
            else if (s == "-s-o") // stemmed words only
            {
                for (const auto& item : m_stemmed)
                {
                    text_str << item.first << '\n';
                }
            }
            else
                throw std::invalid_argument("parameter for write must be -(1)-(2), where 1=w/c, 2 = c/o/a/f. For example, -w-f");

            text_str.close();
        }
    }

    void WordCounter::count(const char* text_path,
        const char* stop_path)
    {
        read(stop_path, 'c');
        read(text_path, 't');
        sort(m_counter, m_sorted_alphabet, m_sorted_frequent);
    }

    class TempFileGuaranteedRemoval
    {
        char* m_file;
    public:
        TempFileGuaranteedRemoval(char* c_file) : m_file(c_file) {}
        ~TempFileGuaranteedRemoval()
        {
            std::remove(m_file);
        }
    };
	
	class StringToChar
    {
    public:
        char* c_str;
        StringToChar(const std::string& str): c_str(new char[str.size() + 1])
        {
            std::copy(str.begin(), str.end(), c_str);
            c_str[str.size()] = '\0';
        }
        ~StringToChar()
        {
            delete[] c_str;
        }
    };

    void WordCounter::stem_count()
    {
        write(R"foo(../Debug/temp_file_for_stem.txt)foo", "-w-o");

        StringToChar cmd_input(exePath + "temp_file_for_stem.txt");
        TempFileGuaranteedRemoval inp( cmd_input.c_str);
        StringToChar cmd_output(exePath + "temp_file_result.txt");
        TempFileGuaranteedRemoval outp(cmd_output.c_str);

        StringToChar cmd_params(exePath + "Stemmer.exe" + " -l " + m_locale_str +
            " -i " + exePath + "temp_file_for_stem.txt" + " -o " + exePath + "temp_file_result.txt");

        system(cmd_params.c_str);

        read(R"foo(../Debug/temp_file_result.txt)foo", 's');
        sort(m_stemmed, m_sorted_stemmed_alphabet, m_sorted_stemmed_frequent);
    }

    void WordCounter::set_locale(std::string locale_str)
    {
        m_locale_str = locale_str;
        if ((locale_str == "english") || (locale_str == "eng") || (locale_str == "en"))
            m_locale == WordConstants::loc_en;
        else if ((locale_str == "russian") || (locale_str == "rus") || (locale_str == "ru"))
            m_locale == WordConstants::loc_ru;
        else
            throw std::invalid_argument("locale isn't supported");
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
        if ((m_locale_str == "english") || (m_locale_str == "eng") || (m_locale_str == "en"))
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
    }




    bool WordCounter::isValid(char sym)
    {
        return ((m_locale_str == "english") || (m_locale_str == "eng") || (m_locale_str == "en")) ? isValid_en(sym) :
            ((m_locale_str == "russian") || (m_locale_str == "rus") || (m_locale_str == "ru")) ? isValid_ru(sym) :
            throw std::invalid_argument("locale" + m_locale_str + "isn't supported");
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


};