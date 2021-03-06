#pragma once
#include<string>
#include<fstream>
#include "Tube.h"

/**
*����� ��� �������� ���-������ � ����������� ����������� ��������������
*��� ������� ��������� ������ ���-���� �� ������ C:/tube_logs/
*��� ����� ������������� ���� ������� ���������
*��� ��������� ���������������� ����, � ���-���� ������������ ������ � �����������:
*[�����_�����������] - [������]: [�����_�����]: [�������]: [�������_������]: [�����]:
*����� �������� ���������� LogPath, � ������� ������������ ���� � ����� � ����������� �����.
*/
class Logger
{
private:
    //���� � ���-�����
    std::string LogPath;

    //������ ��� �������������� � �������
    std::ofstream fout;

    /**
    *������ ���� ��� ���-�����
    *���������� ��� ���-�����, ��������������� ������� ����,
    *��������� ���-���� �� ������ C:/tube_logs/
    */
    std::string SetLogPath();

public:
    //�-��� �� ���������
    Logger() = default;

    /**
    *����� ������� ������� ���-����,
    *���� ���-���� ��� ������ ������ ��������� � ��������� ����
    */
    void CreateLogFile();

    /**
    *��������� ����� ������ � ���-���� � ������ ��������� �������
    *�������� i ������������� ������ ������� �������������� �����
    */
    void WriteDefectLog(Tube &tube, int i);
};
