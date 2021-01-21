#include "Logger.h"

std::string Logger::SetLogPath()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    return "C://tube_logs/" + std::to_string(st.wDay) + "_" + std::to_string(st.wMonth) + "_" + std::to_string(st.wYear) + ".txt";
}

void Logger::CreateLogFile()
{
    this->LogPath = SetLogPath();
    fout.open(LogPath, std::ios::app);
    fout.close();
}

void Logger::WriteDefectLog(Tube &tube, int i)
{
    fout.open(LogPath,std::ios::app);
    fout << tube.ReportDefect(i);
    fout.close();
}
