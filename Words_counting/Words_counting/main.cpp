#include "engcount.h"


using namespace std;
using namespace WordCount;

int main()
{
    const char* text_path_en = R"foo(texts/en_text.txt)foo";
    const char* stop_path_en = R"foo(texts/en_stop.txt)foo";
    const char* output_path_en = R"foo(texts/en_output.txt)foo";
    const char* text_path_ru = R"foo(texts/ru_text.txt)foo";
    const char* stop_path_ru = R"foo(texts/ru_stop.txt)foo";
    const char* output_path_ru = R"foo(texts/ru_output.txt)foo";
    WordCounter count(text_path_en, stop_path_en, output_path_en, std::locale("English"));
    //WordCounter count(text_path_ru, stop_path_ru, output_path_ru, std::locale("Russian"));
    //system("pause");
}