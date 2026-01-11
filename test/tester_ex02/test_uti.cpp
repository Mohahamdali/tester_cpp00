#include "tester.hpp"


void clean_date (std::string &output_date)
{
    size_t pos = output_date.find("]");
    if (pos != std::string::npos)
    {
        output_date.erase(0, pos + 1);
    }
}


std::string  file_log ()
{

    std::ifstream file_read(LOG_FILE_PATH);
    if (!file_read.is_open())
    {
        std::cout << "DEBUG: Failed to open file!" << std::endl;
        std::cout << "DEBUG: Current directory: ";
        system("pwd");
        return "ERROR OPEN FILE\n";
    }
    std::string line;

   std::vector <std::string> container;
    while (getline(file_read,line))
    {
        container.push_back(line + "\n");
    }

    std::string output ;
    std::string clean;
    for (unsigned int i = 0; i < container.size(); i++ )
    {
        clean_date(container[i]);
        output += container[i];
    }
    return output;
}




std::string RUN_PROGRAME(const std::string &cmd)
{
    std::vector<std::string> buffer;
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe)
        return "Error";

    char tmp[4096];
    while (fgets(tmp, sizeof(tmp), pipe))
        buffer.push_back(std::string(tmp));

    pclose(pipe);

    std::string output;
    for (unsigned int i = 0; i < buffer.size(); i++)
    {
        clean_date(buffer[i]);
        output += buffer[i];
    }

    return output;
}
