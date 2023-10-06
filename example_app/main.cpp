#include <iostream>
#include "src/Point/Point.h"
int main(int, char**) {
    mpf_class x, y;
    std::cout << "Enter x and y coordinates of the first point: ";
    std::cin >> x >> y;
    Point p1(x, y);
    std::cout << "Enter x and y coordinates of the second point: ";
    std::cin >> x >> y;
    Point p2(x, y);
    mpf_class distance = p1.calculateDistanceToPoint(&p2);
    gmp_printf("%.10Ff", distance.get_mpf_t());
}
