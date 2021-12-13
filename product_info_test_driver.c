/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: n/a
 *-----------------------------------------------------------------------------
 * Exercise Number: n/a
 * File:			product_info_test_driver.c
 * Author(s):		P. Bauer, S. Schraml
 *-----------------------------------------------------------------------------
 * Description:
 * Tests product info functionality
 *-----------------------------------------------------------------------------
*/
#include "shortcut.h"

#include "test_product_info.h"

int main(int arg, char *argv[])
{
	ADD_TEST(test_get_all_different_product_infos);
	ADD_TEST(test_get_pricing_schemas);
	ADD_TEST(test_get_prices);
	ADD_TEST(test_get_package_sizes);
	ADD_TEST(test_get_package_prices);
	ADD_TEST(test_get_discounts);
	ADD_TEST(test_get_discounts_fail);
	ADD_TEST(test_get_price_of_n_pieces_of_A);
	ADD_TEST(test_get_price_of_n_pieces_of_B);
	ADD_TEST(test_get_price_of_n_pieces_of_C_without_discount);
	ADD_TEST(test_get_price_of_n_pieces_of_C_with_first_discount_level);
	ADD_TEST(test_get_price_of_n_pieces_of_C_with_second_discount_level);
	ADD_TEST(test_get_price_of_n_pieces_of_D);
	
	run_tests();

	return 0;
}
