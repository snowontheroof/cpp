#include "Harl.hpp"

int   main(int argc, char **argv)
{
    Harl    letsHarl;

    if (argc == 2)
        letsHarl.complain(argv[1]);
    return (0);
}