/* ������� ������� ������ "Stemmer", ����� ����������� exe ����.
* ��������� Words_Counting ������ ����� �����
*/ 

#include "engcount.h"

using namespace std;
using namespace WordCount;



int main(int argc, char** argv)
{
    try
    {
        //===============================================================================================================
        // ��������� � ������� ��� "Words_counting.exe input.txt result.txt stop_list.txt English"
        // ����������������� ���� ����, ���������������� ���������
        //if (argc != 5)
        //    throw std::invalid_argument
        //    ("wrong number of parameters of command line, correct format: *exe input.txt result.txt stop_list.txt language(russian/english)");
        //
        //const char* input = argv[1];
        //const char* result = argv[2];
        //const char* stop_list = argv[3];
        //const char* locale_str = argv[4];
        //
        ////const char* input = "input.txt";
        ////const char* result = "result.txt";
        ////const char* stop_list = "stop_list.txt";
        //
        //WordCounter count(input, stop_list, result, locale_str);
        //===============================================================================================================






         //===============================================================================================================
        // ��� ������� � visual studio ��� ���������� ��� ��������� ������

        const char* text_path_en = "texts\\en_text.txt";
        const char* stop_path_en = "texts\\en_stop.txt";
        const char* output_path_en = "texts\\en_output.txt";
        const char* text_path_ru = "texts\\ru_text.txt";
        const char* stop_path_ru = "texts\\ru_stop.txt";
        const char* output_path_ru = "texts\\ru_output.txt";
        WordCounter count(text_path_en, stop_path_en, output_path_en, "english");
        //WordCounter count(text_path_ru, stop_path_ru, output_path_ru, "russian");
        count.write("texts\\stem_test.txt", "-s-f");
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