#ifndef REPLACER_HPP
# define REPLACER_HPP
# include <iostream>
# include <string>
# include <fstream>

class Replacer
{
    public:
        Replacer();
        ~Replacer();
        
        void    replacer(std::string filename, std::string s1, std::string s2);
};

#endif