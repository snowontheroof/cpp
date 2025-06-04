#include "Replacer.hpp"

int main(void)
{
    Replacer thisguy;
    std::string filename = "testfile";

    thisguy.replacer(filename, "testing", "_TRYING_");
    thisguy.replacer("anothertest", "", "HELLOO");
    thisguy.replacer("thirdtest", "s", "j");
    thisguy.replacer("fourthtest", "11", "");
    return (0);
}