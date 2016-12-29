#include"testfield.h"
#include <iostream>



int main()
{
    std::cout << "Zadanie v TENZOR 1" << std::endl;
    TstFl::TestField Field(2);
    std::cout << Field.Calculation_Ratio() << std::endl;
    std::cout << Field.Calculation_MonteCarlo() << std::endl;
    return 0;
}
