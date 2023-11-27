#include <iostream>
#include "names.h"


//using shape::SIDE;
//using namespace shape;
//using namespace rect;

using namespace mka;
using namespace st_3;
int main()
{
    std::cout << shape::areaSquare(shape::SIDE) << std::endl;
    std::cout << shape::rect::area(shape::SIDE,15) << std::endl;
    
    mka::Student mka("Masha", 12);
    mka.print();

    st_3::Student st("Oleg", 25);
    st.print();
}

