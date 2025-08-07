#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat Markku("Markku", 1);
    
    std::cout << Markku.getName() << std::endl;
    std::cout << Markku.getGrade() << std::endl;
    std::cout << Markku << std::endl;
    Markku.upGrade();
    std::cout << Markku << std::endl; 
    Markku.downGrade();
    std::cout << Markku << std::endl;
    Markku.downGrade();

    return 0;
}