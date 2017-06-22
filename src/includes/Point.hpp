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
                printf("%llu - Point created (%0.2f,%0.2f)\n", ++totalPoints, x, y);
                
            }
        
        bool isInCircle()
        {
            return true;
        }

};



#endif /* _POINT_HPP */