#include <iostream>
#include <sys/types.h>

union endy {
    uint16_t num;
    uint8_t c[2];
};

int main()
{
    endy m;

    m.num = 42;

    std::cout << "M: "<<static_cast<unsigned short>(m.c[0])<< " L: " << static_cast<unsigned short>(m.c[1]) << std::endl;


}