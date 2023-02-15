#include <iostream>

#include "reservoir.h"
#include "reverse_order.h"
int main()
{

    double east_storage;

    std::string dates[] = {"12/30/2017", "01/01/2018", "02/01/2018", "03/01/2018", "04/01/2018", "05/01/2018",
                           "06/01/2018", "07/01/2018", "08/01/2018", "09/01/2018", "10/01/2018", "10/20/2019"};

    int n = sizeof(dates) / sizeof(dates[0]);

    for (std::string date : dates)
    {

        east_storage = get_east_storage(date);

        std::cout << "Date: " << date << " East basin storage: " << east_storage << " billion gallons" << std::endl;
    }

    double x = get_min_east();
    double y = get_max_east();
    std::cout << "minimum storage in East basin: " << x << " billion gallons" << std::endl;
    std::cout << "MAXimum storage in East basin: " << y << " billion gallons" << std::endl;

    
    std::cout<<compare_basins("01/03/2018")<< "\n";

    reverse_order("01/01/18","05/01/18");

    return 0;
}