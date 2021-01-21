#include "InputCorrector.h"

bool InputCorrector::CorrectMisinput(std::string & input)
{
    static const std::regex r_double(R"(\d*\D?\d+)");
    static const std::regex r_not_digit(R"(\D)");
    std::string tmp = "";
    if (regex_match(input, r_double) )
    {
        for (size_t i = 0; i < input.length(); ++i)
        {
            tmp = "";
            tmp+=input[i];
            if(regex_match(tmp, r_not_digit))
            {
                input[i] = '.';
                break;
            }
        }
        return true;
    }
    else
        return false;
}

double InputCorrector::ConvertToDigit(std::string &input)
{
    while(true)
    {
        if(CorrectMisinput(input))
        {
            return stod(input);
        }
        else
        {
            std::cout << "Некорректный ввод. Введите параметр заново\n\t :";
            std::cin >> input;
        }
    }

}


