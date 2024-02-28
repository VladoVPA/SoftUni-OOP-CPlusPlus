#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include<cmath>

using namespace std;

class point {
    int x=0;
    int y=0;

public:
    point (istream & istr) {
        int X, Y;
        istr >> X >> Y;
        this->x = X;
        this->y = Y;
    };

    double calculateDistanceToPoint(point P2) {
        double dx = this->x - P2.x;
        double dy = this->y - P2.y;

        double dist = sqrt(dx * dx + dy * dy);
    
        return dist;
    };

};

int main()
{
    point Point1(cin);
    point Point2(cin);
    
    double distance = Point1.calculateDistanceToPoint(Point2);

    cout <<fixed << setprecision(3) << distance << endl;

    return 0;
}

