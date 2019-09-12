//
// Created by wmurphy on 9/12/2019.
//

#ifndef DATASTRCTURES_ALGORITHMS_POINT_H
#define DATASTRCTURES_ALGORITHMS_POINT_H

#include <string>


namespace WMurphy {
    class Point {
    private:
        double m_x{0.0};
        double m_y{0.0};
    public:
        Point();
        explicit Point(double x, double y);
        Point(const Point& source);
        ~Point();

        double getX() const;
        double getY() const;
        void setX(double x);
        void setY(double y);
        std::string toString() const;

        double distance(const Point& point) const;
        Point operator-() const;
        Point operator*(double factor) const;
        Point operator+ (const Point* p) const;
        bool operator== (const Point& p) const;
        Point& operator =(const Point& source);
        Point&operator *=(double factor);
    };
}


#endif //DATASTRCTURES_ALGORITHMS_POINT_H
