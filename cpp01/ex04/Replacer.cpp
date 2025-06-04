#include "Replacer.hpp"

Replacer::Replacer()
{
}

Replacer::~Replacer()
{
}

void    Replacer::replacer(std::string filename, std::string s1, std::string s2)
{   
    std::ifstream myFile(filename);
    if (!myFile)
    {
        std::cerr << "Error: could not open file <" << filename << ">!" << std::endl;
        return ;
    }
    std::string newFileName = filename + ".replace";
    std::ofstream newFile(newFileName);
    if (!newFile)
    {
        std::cerr << "Error: could not create file <" << newFileName << ">!" << std::endl;
        return ;
    }
    std::string line;
    std::size_t found;

    while (std::getline(myFile, line))
    {
        if (s1 != "")
        {
            found = line.find(s1);
            while (found != std::string::npos)
            {
                line.erase(found, s1.length());
                line.insert(found, s2);
                found = line.find(s1);
            }
        }
        newFile << line << std::endl;
    }
}