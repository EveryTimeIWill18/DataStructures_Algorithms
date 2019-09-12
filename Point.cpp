//
// Created by wmurphy on 9/12/2019.
//

#include "Point.h"
#include <iostream>
#include <sstream>
#include <math.h>

namespace WMurphy {
    Point::Point()=default;

    Point::Point(double x, double y) : m_x(x), m_y(y) {}
    double Point::getX() const {
        return this->m_x;
    }
    double Point::getY() const {
        return this->m_y;
    }

    Point::Point(const WMurphy::Point &source) {
        this->m_x = source.m_x;
        this->m_y = source.m_y;
    }

    Point::~Point() {
        std::cout << "Destroying Point ... " << std::endl;
    }

    void Point::setX(double x) {
        this->m_x = x;
    }

    void Point::setY(double y) {
        this->m_y = y;
    }

    std::string Point::toString() const {
        std::stringstream ssx;
        std::stringstream ssy;

        ssx << this->m_x;
        ssy << this->m_y;

        std::string output;

        output = "(" + ssx.str() + "," + ssy.str() + ")";
        return output;
    }

    double Point::distance(const WMurphy::Point &point) const {
        double  _dist;
        _dist = sqrt(pow(this->m_x - point.getX(), 2) + pow(this->m_y - point.getY(), 2));

        return _dist;
    }

    Point Point::operator-() const {
        return Point(-this->m_x, -this->m_y);
    }

    Point Point::operator*(double factor) const {
        return Point(factor*this->m_x, factor*this->m_y);
    }

    Point Point::operator+(const WMurphy::Point *p) const {
        return Point(this->m_x + p->getX(), this->m_y + p->getY());
    }

    bool Point::operator==(const WMurphy::Point &p) const {
        return (this->m_x == p.getX() && this->m_y == p.getY());
    }

    Point& Point::operator=(const WMurphy::Point &source) {
        if (this == &source)
            return *this;

        this->m_x = source.m_x;
        this->m_y = source.m_y;

        return *this;
    }

    Point& Point::operator*=(double factor) {
        this->m_x = this->m_x*factor;
        this->m_y = this->m_y*factor;

        return *this;
    }
}