#include <gmpxx.h>
struct Point {
    mpf_class x, y;
    Point();
    Point(const mpf_class& x, const mpf_class& y);
    mpf_class calculateDistanceToPoint(const Point* p);
};