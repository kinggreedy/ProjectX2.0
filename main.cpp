#include "src/calculator.h"
#include <cassert>
#include <cfloat>
#include <cmath>
#include <iostream>


using namespace std;


int main() {
    // Basic operations
    assert(calculator(3.0f, '+', 76.2f) == 79.2f);
    assert(calculator(2.4f, '-', 3445.0f) == -3442.6f);
    assert(calculator(2.0f, '*', 2.0f) == 4.0f);
    assert(calculator(-5.0f, '*', 4.0f) == -20.0f);
    assert(calculator(10.0f, '/', 2.0f) == 5.0f);

    // Edge cases
    assert(calculator(1.0f, '/', 0.0f) == 1);  // Division by zero
    assert(calculator(1.0f, '/', -0.0f) == 1);  // Division by negative zero
    assert(calculator(0.0f, 'x', 0.01f) == 1);  // Invalid operator

    float largeNum = FLT_MAX;
    assert(isinf(calculator(largeNum, '+', largeNum)));
    assert(isinf(calculator(largeNum, '*', largeNum)));
    assert(isinf(calculator(largeNum, '+', 1.0e32f)));  // FLT_MAX + small number triggers overflow

    // Underflow checks
    assert(fpclassify(calculator(FLT_MIN, '*', 0.5f)) == FP_SUBNORMAL);
    assert(calculator(FLT_MIN, '*', FLT_MIN) == 0);

    // Additional tests
    assert(fabs(calculator(0.1f, '+', 0.2f) - 0.3f) < 0.00001f); // Floating-point precision
    assert(fabs(calculator(1.0e20f, '+', 1.0e20f) - 2.0e20f) < 1.0e15f); // Large numbers

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
