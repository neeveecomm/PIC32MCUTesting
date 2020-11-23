#include "unity.h"
#include "main.h"
#include "initialization.h"
#include "peripheral/gpio/plib_gpio.h"
#include "peripheral/clk/plib_clk.h"
#include "peripheral/evic/plib_evic.h"
#include <stdbool.h>
#include "mock_system.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_gpio_test(void)
{
	SYS_Initialize(NULL);
	TEST_ASSERT_EQUAL(1, SWITCH_Get());
}

void test_gpio_bittest(void)
{
	SYS_Initialize(NULL);
	TEST_ASSERT_BIT_HIGH(SWITCH_Get(), 1);
}

void test_main_function_should_return_when_ShouldAbortApp_returns_true(void)
{
    // Setup expected call chain
    ShouldAbortApp_ExpectAndReturn(true);
    // Call function under test
    test_main();
}

void test_test_main_should_call_LED_State_for_each_LED_on_and_then_off(void)
{
    // Setup expected call chain
    ShouldAbortApp_ExpectAndReturn(false);  // Don't abort so we can see the other functions get called.

    ShouldAbortApp_ExpectAndReturn(true);   // Abort since we have validated the call chain
    // Call function under test
    test_main();
}
