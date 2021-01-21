#include <iostream>
#include <string>
#include "Tube.h"
#include "InputCorrector.h"
#include "Logger.h"
using namespace std;

Tube current_tube;
InputCorrector ic;
Logger logger;
double ethalone_weight = 0;

/**
*вспомогательная функция для ввода, корректировки ввода и подчистки памяти
*/
void input_and_convert(string & in_str, double & out_digit)
{
    cin >> in_str;
    out_digit = ic.ConvertToDigit(in_str);
    in_str.clear();
}

/**
*Функция для ввода требуемых параметров трубы
*/
void input_params(double & D, double & S, double & L, string & s_D,  string & s_S,  string & s_L)
{
    cout << "\n\tD: ";
    input_and_convert(s_D, D);
    cout << "\tS: ";
    input_and_convert(s_S, S);
    cout << "\tL: ";
    input_and_convert(s_L, L);
}

/**
*Функция для предустановки глобальных параметров:
*создаёт (либо открывает-закрывает) лог-файл
*запрашивает номер партии
*вычисляет вес "эталонной трубы"
*/
void setup()
{
    logger.CreateLogFile(); //сюда можно (нужно!) прикрутить проверку открытия файла

    Tube::SetBatch();

    string s_D, s_S, s_L;
    double D, S, L;
    cout << "Введите номинальные параметры труб из ТС и УнП \nD - наружный диаметр (мм), \nS - толщина стенки (мм), \nL - длина (мм или м).";
    input_params(D, S, L, s_D, s_S, s_L);
    current_tube.ChangeParams(D, S, L);
    ethalone_weight = current_tube.GetWeight();
    cout << "\tВес базовой трубы:\t" << ethalone_weight << " кг\n\n";
}

/**
*функция для считывания параметров и определения пригодности фактических труб партии
*если трубы несоответствующие, функция записывает номер трубы время обнаружения и параметры трубы в дефект-лог
*/
void input()
{
    string s_D, s_S, s_L;
    double D, S, L;
    for (size_t i = 1; ;++i)
    {
        cout << "Введите параметры трубы #" << i << ": ";
        input_params(D, S, L, s_D, s_S, s_L);
        current_tube.ChangeParams(D, S, L);

        cout << "\tВес трубы #" << i << ":\t" << current_tube.GetWeight() << " кг\n\n";
        if (current_tube.GetWeight() < 0.95 * ethalone_weight)
        {
            cout << "\tВНИМАНИЕ! Недостаточно металла в заготовке.\n\tНа трубу #" << i << " нужно выписать ЛИСТ НЕСООТВЕТСТВИЯ\n\n";
            logger.WriteDefectLog(current_tube, i);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC,"eng");
    setup();
    input();
    return 0;
}
