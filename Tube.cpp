#include "Tube.h"

std::string Tube::Batch = "";

Tube::Tube (double D, double S, double L) : D(D), S(S), L(L)
{
    if (this->L < 20)
        this->L *= 1000;
    M = floor(0.01413 * S * (D - S) * L  / 10) / 100;       //
}

void Tube::ChangeParams(double D, double S, double L)
{
    this->D = D;
    this->S = S;
    if (L < 20)
           L *= 1000;
    this->L = L;
    this->M = floor(0.01413 * S * (D - S) * L / 10) / 100;
}

const double & Tube::GetWeight()
{
    return this->M;
}

std::string Tube::GetCurrentTime()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    return std::to_string(st.wHour + 5) + ":" + std::to_string(st.wMinute) + ":" + std::to_string(st.wSecond);
}

std::string Tube::GetBatch()
{
    return Batch ;
}

std::string Tube::PrintTubeInfo()
{
    return "D: " + std::to_string(D) + " S: " + std::to_string(S) + " L: " + std::to_string(L);
}

std::string Tube::ReportDefect(int i)
{
   return GetCurrentTime() + " - batch: #" + GetBatch() + " tube: #" + std::to_string(i) + '\t' + PrintTubeInfo() + '\n';
}

void Tube::SetBatch()
{
    std::cout << "¬ведите номер партии: ";
    std::cin >> Batch;
}
