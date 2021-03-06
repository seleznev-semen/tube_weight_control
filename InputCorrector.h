#pragma once

#include <iostream>
#include <regex>
#include <string>

/**
*����� - ������� ��������� ������ �����
*���������� ������� �������� ��� ����� ���������� �����
*���� ��������� ������ �� �������, ������ �������� ������ ������ ��������
*�������� ������ � ��������������� � double ����
*/
class InputCorrector
{
private:
    /**
    *������������ ���������� ������ ����� ��������� ������,
    *�������� ������ � ����, ���������� � ����������� ��������� stod(str)
    *��������, ������������� ������ 3,14 � ������ 3.14 ��� 3?14 � 3.14
    *���������� true, ���� ��������������� ������ ������� (����� ������� ������ ������������� �������)
    */
    bool CorrectMisinput(std::string & input);
public:
    InputCorrector() = default;
    /**
    *������������ ������������ ������� CorrectMisinput ������ � double
    *���� ������ ��������������� �� �������, ����������� ��������� ���� ������
    * ���������� ���������������� �������� double
    */
    double ConvertToDigit(std::string &input);
};

