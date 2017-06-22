
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

const long double actualPI = 3.14159265359;

long double approximatePI(unsigned long long inCircle, unsigned long long total);
void printPercentError(const long double myPI, const long double actualPI);


int main()
{
    system("cls");

    int zeroCounter = 0;
    int currentIteration = 0;

    long double myPI = 0;

    // Test Parameters
    const int M = 50;                   // Simulations per program execution
    const int N = 20'000'000;           // Points per simulation

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

        std::cout << "Iteration: " << currentIteration + 1 << std::endl;
        std::cout << "Points in circle: " << pointsInCircle << std::endl;
        std::cout << "Total points: " << totalPoints << std::endl;


        printf("PI: %.10Le\n", approximatePI(pointsInCircle, totalPoints));
        myPI += approximatePI(overallPointsInCircle, overallTotalPoints);
        
        ++currentIteration;

        // Divide myPI every 5 iterations to put off an overflow for as long as possible
        if (zeroCounter % 5 == 0) {
            if (currentIteration == M) {
                // Do not zero out myPI
            } else {
                myPI /= 5;
                zeroCounter = 0;

                overallTotalPoints = 0;
                overallPointsInCircle = 0;
            }
        }

        printf("\n");
    }

    printf("\n\n");

    std::cout << "Points in circle overall: " << overallPointsInCircle << std::endl;
    std::cout << "Total points overall: " << overallTotalPoints << std::endl;

    //myPI = approximatePI(overallPointsInCircle, overallTotalPoints);
    printf("PI: %.10Le\n", myPI);
    printPercentError(myPI, actualPI);

    return EXIT_SUCCESS;
}


long double approximatePI(const unsigned long long inCircle, const unsigned long long total)
{
    return (((long double) inCircle / (long double) total) * 4);
}


void printPercentError(const long double myPI, const long double actualPI)
{
    printf("\n\tPercent Error: %.10Le%%\n", 100 * ((myPI - actualPI) / actualPI));
}