#ifndef _POINT_HPP
#define _POINT_HPP


class Point {
    public:
        //static int pointCount;
        double x;
        double y;

        Point()
        {
            std::cout << "Default point constructor has been called. " << std::endl;
        }

        Point(double a, double b)
            : x(a), y(b)
            { 
                ++totalPoints;
                ++overallTotalPoints;
                isInCircle();
            }
        
        bool isInCircle()
        {
            double value = sqrt(1 - pow(x, 2));
            if (value <= std::abs(y)) {
                // Do not increase counter
                return false;
            } else {
                ++pointsInCircle;
                ++overallPointsInCircle;
                return true;
            }
        }

};



#endif /* _POINT_HPP */