#include <assert.h>

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

#include "../src/calculator.h"

FUZZ_TEST_SETUP() {
    // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
    // Use FuzzedDataProvider to generate random input data
    FuzzedDataProvider fuzzed_data(data, size);

    // Generate random integers and a character operator
    float num1 = fuzzed_data.ConsumeFloatingPoint<float>();
    char op = fuzzed_data.ConsumeIntegral<char>();
    float num2 = fuzzed_data.ConsumeFloatingPoint<float>();

    // Call the updated calculator function with float inputs
    calculator(num1, op, num2);
}
