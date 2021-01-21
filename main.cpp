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
*��������������� ������� ��� �����, ������������� ����� � ��������� ������
*/
void input_and_convert(string & in_str, double & out_digit)
{
    cin >> in_str;
    out_digit = ic.ConvertToDigit(in_str);
    in_str.clear();
}

/**
*������� ��� ����� ��������� ���������� �����
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
*������� ��� ������������� ���������� ����������:
*������ (���� ���������-���������) ���-����
*����������� ����� ������
*��������� ��� "��������� �����"
*/
void setup()
{
    logger.CreateLogFile(); //���� ����� (�����!) ���������� �������� �������� �����

    Tube::SetBatch();

    string s_D, s_S, s_L;
    double D, S, L;
    cout << "������� ����������� ��������� ���� �� �� � ��� \nD - �������� ������� (��), \nS - ������� ������ (��), \nL - ����� (�� ��� �).";
    input_params(D, S, L, s_D, s_S, s_L);
    current_tube.ChangeParams(D, S, L);
    ethalone_weight = current_tube.GetWeight();
    cout << "\t��� ������� �����:\t" << ethalone_weight << " ��\n\n";
}

/**
*������� ��� ���������� ���������� � ����������� ����������� ����������� ���� ������
*���� ����� �����������������, ������� ���������� ����� ����� ����� ����������� � ��������� ����� � ������-���
*/
void input()
{
    string s_D, s_S, s_L;
    double D, S, L;
    for (size_t i = 1; ;++i)
    {
        cout << "������� ��������� ����� #" << i << ": ";
        input_params(D, S, L, s_D, s_S, s_L);
        current_tube.ChangeParams(D, S, L);

        cout << "\t��� ����� #" << i << ":\t" << current_tube.GetWeight() << " ��\n\n";
        if (current_tube.GetWeight() < 0.95 * ethalone_weight)
        {
            cout << "\t��������! ������������ ������� � ���������.\n\t�� ����� #" << i << " ����� �������� ���� ��������������\n\n";
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
