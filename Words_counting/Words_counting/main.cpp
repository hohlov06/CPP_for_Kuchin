/* Сначала собрать проект "Stemmer", чтобы образовался exe файл.
* Запускать Words_Counting только после этого
*/ 

#include "engcount.h"

using namespace std;
using namespace WordCount;



int main(int argc, char** argv)
{
    try
    {
        //===============================================================================================================
        // Запускать к консоли как "Words_counting.exe input.txt result.txt stop_list.txt English"
        // Раскомментировать этот блок, закомментировать следующий
        //if (argc != 5)
        //    throw std::invalid_argument
        //    ("wrong number of parameters of command line, correct format: *exe input.txt result.txt stop_list.txt language(russian/english)");
        //
        //const char* input = argv[1];
        //const char* result = argv[2];
        //const char* stop_list = argv[3];
        //const char* locale_str = argv[4];
        //
        ////const char* input = R"foo(input.txt)foo";
        ////const char* result = R"foo(result.txt)foo";
        ////const char* stop_list = R"foo(stop_list.txt)foo";
        //
        //WordCounter count(input, stop_list, result, locale_str);
        //===============================================================================================================






         //===============================================================================================================
        // Для запуска в visual studio без параметров для командной строки

        const char* text_path_en = R"foo(texts/en_text.txt)foo";
        const char* stop_path_en = R"foo(texts/en_stop.txt)foo";
        const char* output_path_en = R"foo(texts/en_output.txt)foo";
        const char* text_path_ru = R"foo(texts/ru_text.txt)foo";
        const char* stop_path_ru = R"foo(texts/ru_stop.txt)foo";
        const char* output_path_ru = R"foo(texts/ru_output.txt)foo";
        WordCounter count(text_path_en, stop_path_en, output_path_en, "english");
        //WordCounter count(text_path_ru, stop_path_ru, output_path_ru, "russian");
        count.write(R"foo(texts/stem_test.txt)foo", "-s-f");
         //===============================================================================================================
    }
    catch (std::exception& e)
    {
        std::fstream text_str;
        if (!text_str.is_open())
        {
            text_str.clear();
            text_str.open("log.txt", std::ios::out);
            text_str << e.what() << '\n';
            text_str.close();
        }
        std::abort();
    }
    //system("pause");
}