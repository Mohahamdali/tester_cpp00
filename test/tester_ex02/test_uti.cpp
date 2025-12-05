#include "tester.hpp"




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
        output += buffer[i];

    return output;
}
