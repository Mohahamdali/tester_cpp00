
#include "tester.hpp"


std::string RUN_PROGRAM(const std::string &cmd, const std::string &input)
{
    int in_fd[2], out_fd[2];
    pipe(in_fd);
    pipe(out_fd);

    pid_t pid = fork();
    if (pid == -1) 
        return "ERROR: fork failed";

    if (pid == 0)
    {
        dup2(in_fd[0], STDIN_FILENO);
        dup2(out_fd[1], STDOUT_FILENO);
        close(in_fd[1]);
        close(out_fd[0]);

        char *argv[] = {(char *)cmd.c_str(), NULL};
        char *env[] = {NULL};
        execve(cmd.c_str(), argv, env);

        exit(1);  
    }

    close(in_fd[0]);
    close(out_fd[1]);

    write(in_fd[1], input.c_str(), input.size());
    close(in_fd[1]);  

    char buffer[4096];
    std::string output;
    ssize_t n;
    while ((n = read(out_fd[0], buffer, sizeof(buffer))) > 0)
        output.append(buffer, n);

    close(out_fd[0]);

    int status;
    waitpid(pid, &status, 0);

    return output;
}

std::string remove_ansi(const std::string &s)
{
    std::regex ansi("\033\\[[0-9;]*m");
    return std::regex_replace(s, ansi, "");
}

std::string RUN_AND_CLEAN(const std::string &cmd, const std::string &input)
{
    return remove_ansi(RUN_PROGRAM(cmd, input));
}



bool check_error_message(std::string &output)
{
    std::string fake_output = output;
    std::transform(fake_output.begin(), fake_output.end(), fake_output.begin(), ::tolower);

    std::vector<std::string> keywords = {
     
        "error", "invalid", "fail", "failed", "failure",
        "exception", "critical", "fatal", "unexpected",

        "command not found", "not found", "unknown command",
        "unrecognized option", "unsupported", "invalid argument",
        "invalid input", "missing argument", "not enough arguments",


        "file not found", "no such file", "no such directory",
        "cannot open file", "could not read",
        "permission denied", "access denied",


        "runtime error", "logic error", "syntax error",
        "segmentation fault", "segfault", "crash", "abort",
        "timeout", "overflow", "underflow",
        "out of range", "out of memory",

        "warning", "deprecated", "notice"
    };

    for (const auto &kw : keywords) {
        if (fake_output.find(kw) != std::string::npos) {
            return true;
        }
    }
    return false;
}


