#pragma once
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <locale>

//#define GOOGLE_TEST_DEBUG

#ifdef GOOGLE_TEST_DEBUG
class TestCase;
#endif // GOOGLE_TEST_DEBUG

namespace WordCount{

    namespace WordConstants{
        //constexpr std::array<const char*, 2> encoding_array = { "en_US.UTF8", "ru_RU.UTF8" };

        const std::locale loc_en = std::locale("English");
        const std::locale loc_ru = std::locale("Russian"); //rus_rus.866 //Russian_Russia.866
    };


class WordCounter 
{
    using map_ptr = std::pair<const std::string, int>*;

public:

    #ifdef GOOGLE_TEST_DEBUG
    friend TestCase;
    #endif // GOOGLE_TEST_DEBUG

    //WordCounter() {}

    WordCounter(const char* text_path,
                const char* stop_path,
                const char* output_path /*= "output.txt"*/,
                std::string locale_str /*= "english"*/);

    void read(const char* text_path, char);

    void count(const char* text_path,
               const char* stop_path);

    void stem_count();

    void write(const char* output_path, std::string);

    void set_locale(std::string locale_str);

    //inline void set_text_path(char* p)  {m_text_path = p;}
    //inline void set_stop_path(char* p)  {m_stop_path = p;}
    //inline void set_output_path(char* p){m_output_path = p;}


private:

    void sort(std::unordered_map<std::string, int>& counter,
              std::vector<map_ptr>& sorted_alphabet,
              std::vector<map_ptr>& sorted_frequent);

    void read_text(std::fstream& text_str);

    void read_stop(std::fstream& text_str);

    void read_stemmed(std::fstream& text_str);

    void insertion(std::string& word, bool apostrophe_flag);

    void remove_apostrophes();

    inline bool isValid(char sym);

    inline bool isValid_en(char sym);

    bool isValid_ru(char sym);


    //inline bool isPunct(char sym)
    //{
    //    return (m_locale_str == "english") ? isPunct_en(sym) :
    //           (m_locale_str == "russian") ? isPunct_ru(sym) : throw std::invalid_argument("locale" + m_locale_str + "isn't supported");
    //}

    //inline bool isPunct_en(char sym)
    //{
    //    return ((sym == '.') || (sym == ',') || (sym == '!')  || (sym == '?') ||
    //            (sym == 150) || (sym == 151) || (sym == '\"') || (sym == '(') || /*150,151 - тире*/
    //            (sym == ')') || (sym == ':') || (sym == ';')  || (sym == '[') || 
    //            (sym == ']') || (sym == '{') || (sym == '}')                    ); 
    //}

    //inline bool isPunct_ru(char sym)
    //{
    //    return (isPunct_en(sym) || (sym == '\'')); //TODO apostrphe
    //}

private:
    std::unordered_map<std::string, int> m_counter;
    std::unordered_map<std::string, int> m_stemmed;
    std::unordered_set<std::string> m_stops;
    std::unordered_set<std::string> m_apostrophe_words;
    std::vector<map_ptr> m_sorted_alphabet;
    std::vector<map_ptr> m_sorted_frequent;
    std::vector<map_ptr> m_sorted_stemmed_alphabet;
    std::vector<map_ptr> m_sorted_stemmed_frequent;
    std::locale m_locale;
    std::string m_locale_str;
    char m_apostrophe; //TODO зависит от кодировки
};

};