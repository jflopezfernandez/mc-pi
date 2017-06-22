
/** Monte Carlo Simulation to estimate the value of PI
 *
 *  Author: Jose Lopez
 *  Date: 21-June-2017
 *  License: The Unlicense
 *
 */

#include "includes\Main.hpp"

unsigned long long totalPoints = 0;
unsigned long long pointsInCircle = 0;



int main()
{
    const int N = 10;
    
    static ::std::random_device rd;
    static std::mt19937_64 rng(rd());

    static std::uniform_real_distribution<double> uid1(-1.0,1.0);   // x
    static std::uniform_real_distribution<double> uid2(-1.0,1.0);   // y
    

    for (int i = 0; i < N; ++i) {
        Point p([&]{
            return uid1(rng);
        }(), [&]{
            return uid2(rng);
        }());
    }

    // Initialize square
    // Inscribe circle
    // Randomly populate with N dots
    // Count dots in circle
    // Multiply by 4

    return EXIT_SUCCESS;
}