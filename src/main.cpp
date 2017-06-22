
/** Monte Carlo Simulation to estimate the value of PI
 *
 *  Author: Jose Lopez
 *  Date: 21-June-2017
 *  License: The Unlicense
 *
 */

unsigned long long totalPoints = 0;
unsigned long long pointsInCircle = 0;

unsigned long long overallTotalPoints = 0;
unsigned long long overallPointsInCircle = 0;

#include "includes\Main.hpp"

long double approximatePI(unsigned long long inCircle, unsigned long long total);


int main()
{
    system("cls");
    
    const int M = 20;           // Simulations per program execution
    const int N = 100'000;        // Points per simulation

    for (int i = 0; i < M; ++i) {    
        totalPoints = 0;
        pointsInCircle = 0;

        srand(time(NULL));

        static ::std::random_device rd;
        //static std::mt19937_64 rng(rd());
        static std::mt19937_64 rng(rand());

        static std::uniform_real_distribution<double> uid1(-1.0,1.0);   // x
        static std::uniform_real_distribution<double> uid2(-1.0,1.0);   // y
        

        for (int j = 0; j < N; ++j) {
            Point p([&]{
                return uid1(rng);
            }(), [&]{
                return uid2(rng);
            }());
        }

        std::cout << "Points in circle: " << pointsInCircle << std::endl;
        std::cout << "Total points: " << totalPoints << std::endl;


        printf("PI: %.10Le\n", approximatePI(pointsInCircle, totalPoints));
    }

    printf("\n\n");

    std::cout << "Points in circle overall: " << overallPointsInCircle << std::endl;
    std::cout << "Total points overall: " << overallTotalPoints << std::endl;

    printf("PI: %.10Le\n", approximatePI(overallPointsInCircle, overallTotalPoints));

    return EXIT_SUCCESS;
}


long double approximatePI(unsigned long long inCircle, unsigned long long total)
{
    return (((long double) inCircle / (long double) total) * 4);
}