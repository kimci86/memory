#include <Log.hpp>

std::ostream& log()
{
    static std::ostream s(std::cout.rdbuf());
    return s;
}

std::ostream& warn()
{
    static std::ostream s(std::cerr.rdbuf());
    return s;
}

std::ostream& err()
{
    static std::ostream s(std::cerr.rdbuf());
    return s;
}
