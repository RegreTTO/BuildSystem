#include "Point.h"
#include "../../cfg/globals.cpp"

Point::Point(const mpf_class& x, const mpf_class& y) {
    this->x = x;
    this->y = y;
}
mpf_class Point::calculateDistanceToPoint(const Point* p) {
    mpf_class result = sqrt((this->x - p->x) * (this->x - p->x) +
                            (this->y - p->y) * (this->y - p->y));
    return result;
}