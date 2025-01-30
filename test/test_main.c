#include "main.h"

#include "mock_ft_printf.h"
#include "mock_mlx.h"

#include "unity.h"

void	setUp(void){};
void	tearDown(void){};

void	test_summer(void)
{
	TEST_ASSERT_EQUAL_INT(3, summ(1, 2));
	TEST_ASSERT_EQUAL_INT(5, summ(2, 3));
	TEST_ASSERT_EQUAL_INT(7, summ(3, 4));
	TEST_ASSERT_EQUAL_INT(9, summ(4, 5));
	TEST_ASSERT_EQUAL_INT(11, summ(5, 6));
}
