/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * File:			test_product_info.h
 * Author:			P. Bauer, S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Headers of test routines
 * ----------------------------------------------------------
 */
#ifndef ___TEST_PRODUCT_INFO_H
#define ___TEST_PRODUCT_INFO_H

#include "shortcut.h"

TEST(test_get_all_different_product_infos);
TEST(test_get_pricing_schemas);
TEST(test_get_prices);
TEST(test_get_package_sizes);
TEST(test_get_package_prices);
TEST(test_get_discounts_fail);
TEST(test_get_discounts);
TEST(test_get_price_of_n_pieces_of_A);
TEST(test_get_price_of_n_pieces_of_B);
TEST(test_get_price_of_n_pieces_of_C_without_discount);
TEST(test_get_price_of_n_pieces_of_C_with_first_discount_level);
TEST(test_get_price_of_n_pieces_of_C_with_second_discount_level);
TEST(test_get_price_of_n_pieces_of_D);

#endif
