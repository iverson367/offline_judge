#include <cstdlib>
#include <string>
#include <sstream>
#include <filesystem>
#include <iostream>

int main(int argc, char **argv)
{
    auto currentDir = std::filesystem::absolute(argv[0]).parent_path().string();
    auto problemInput = currentDir + "/problem_input.txt";
    auto problemOutput = currentDir + "/problem_output.txt";
    auto contestOutput = currentDir + "/contest_output.txt";
    //generate test input data
    {
        std::stringstream ss;
        ss << currentDir << "/ProblemInput_" << argv[1] << " > " << problemInput;
        auto command = ss.str();
        std::cout << "input txt:" << command << " ";
        int flag = system(command.c_str());
        std::cout << flag << std::endl;
    }
    //run target code and generate reference output data
    {
        std::stringstream ss;
        ss << currentDir << "/Problem_" << argv[1] << " < " << problemInput << " > " << problemOutput;
        auto command = ss.str();
        std::cout << "reference problem:" << command << std::endl;
        system(command.c_str());
    }
    //run our code and generate out ouput data
    {
        std::stringstream ss;
        ss << currentDir << "/Contest_" << argv[1] << " < " << problemInput << " > " << contestOutput;
        auto command = ss.str();
        std::cout << "test :" << command << std::endl;
        system(command.c_str());
    }
    //compare reference output data and our output data
    {
        std::stringstream ss;
        ss << "diff -w " << problemOutput << " " << contestOutput;
        auto command = ss.str();
        std::cout << "compare :" << command << std::endl;
        int flag = system(command.c_str());
        std::cout << flag << std::endl;
    }
    return 0;
}