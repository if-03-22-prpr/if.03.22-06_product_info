/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: n/a
 *-----------------------------------------------------------------------------
 * Exercise Number: n/a
 * File:			test_product_info.cpp
 * Author(s):		P. Bauer, S. Schraml
 *-----------------------------------------------------------------------------
 * Description:
 * Test routines for product_info.
 *-----------------------------------------------------------------------------
*/
#include <string.h>
#include "product_info.h"

#include "test_product_info.h"

/**
* Testet, ob genau 4 ProductInfos gespeichert sind, welche unter den Namen
* 'A' bis 'D' abrufbar sind.
*/
TEST(test_get_all_different_product_infos)
{
	ASSERT_TRUE(get_product_info('A') != 0, "Valid product info expected");
	ASSERT_TRUE(get_product_info('B') != 0, "Valid product info expected");
	ASSERT_TRUE(get_product_info('C') != 0, "Valid product info expected");
	ASSERT_TRUE(get_product_info('D') != 0, "Valid product info expected");
	ASSERT_TRUE(get_product_info('E') == 0, "No product E expected");
}

/**
* Tested, ob Produkte A und B das Pricing Schema PACKAGE_PRICING und
* C und D das Pricing Schema QUANTITY_DISCOUNT haben.
*/
TEST(test_get_pricing_schemas)
{
	ASSERT_EQUALS(PACKAGE_PRICING, get_pricing_schema(get_product_info('A')));
	ASSERT_EQUALS(PACKAGE_PRICING, get_pricing_schema(get_product_info('B')));
	ASSERT_EQUALS(QUANTITY_DISCOUNT, get_pricing_schema(get_product_info('C')));
	ASSERT_EQUALS(QUANTITY_DISCOUNT, get_pricing_schema(get_product_info('D')));
}

/**
* Testet, Produktpreise:
* Produkt A: 10.--
* Produkt B: 5.--
* Product C: 7.50
* Product D: 3.90
*/
TEST(test_get_prices)
{
	ProductInfo p = get_product_info('A');
	ASSERT_EQUALS(10.0, get_price(p));

	p = get_product_info('B');
	ASSERT_EQUALS(5.0, get_price(p));

	p = get_product_info('C');
	ASSERT_EQUALS_TOLERANCE(7.5, get_price(p), 0.0);

	p = get_product_info('D');
	ASSERT_EQUALS_TOLERANCE(3.9, get_price(p), 0.0);
}

/**
* Tested Paketgrößen
* A: 3 Stück, B: 6 Stück. C und D haben ein Mengenrabatt-Schema, daher
* ist die Frage nach der Paketgröße unsinnig. Rückgabewert ist hier -1.
*/
TEST(test_get_package_sizes)
{
	ProductInfo p = get_product_info('A');
	ASSERT_EQUALS(3, get_package_size(p));

		p = get_product_info('B');
		ASSERT_EQUALS(6, get_package_size(p));

		p = get_product_info('C');
		ASSERT_EQUALS(-1, get_package_size(p));

		p = get_product_info('D');
		ASSERT_EQUALS(-1, get_package_size(p));
}

/**
* Tested Rabattgrenzen
* C: Ab 100 Stück 5 % Rabatt, ab 500 Stück 10 % Rabatt
* D: Ab 100 Stück 1 % Rabatt, ab 200 Stück 2 %, ... ab 1000 Stück 10% Rabatt
* A und B: Falsches Pricing Schema -> Frage unsinnig -> Rückgabewert 0
*/
TEST(test_get_discounts_fail)
{
	ProductInfo p = get_product_info('A');
	struct Discount* discounts = get_discounts(p);
	ASSERT_TRUE(discounts == 0, "No discount information expected for product A");

	p = get_product_info('B');
	discounts = get_discounts(p);
	ASSERT_TRUE(discounts == 0, "No discount information expected for product B");
}

TEST(test_get_discounts)
{
	ProductInfo p = get_product_info('C');
	struct Discount* discounts = get_discounts(p);
	ASSERT_EQUALS(100, discounts[0].number_of_items);
	ASSERT_EQUALS(5, discounts[0].discount);
	ASSERT_EQUALS(500, discounts[1].number_of_items);
	ASSERT_EQUALS(10, discounts[1].discount);
	ASSERT_EQUALS(0, discounts[2].number_of_items);
	ASSERT_EQUALS(0, discounts[2].discount);

	p = get_product_info('D');
	discounts = get_discounts(p);
	ASSERT_EQUALS(100, discounts[0].number_of_items);
	ASSERT_EQUALS(1, discounts[0].discount);
	ASSERT_EQUALS(200, discounts[1].number_of_items);
	ASSERT_EQUALS(2, discounts[1].discount);
	ASSERT_EQUALS(300, discounts[2].number_of_items);
	ASSERT_EQUALS(3, discounts[2].discount);
	ASSERT_EQUALS(400, discounts[3].number_of_items);
	ASSERT_EQUALS(4, discounts[3].discount);
	ASSERT_EQUALS(500, discounts[4].number_of_items);
	ASSERT_EQUALS(5, discounts[4].discount);
	ASSERT_EQUALS(0, discounts[5].number_of_items);
	ASSERT_EQUALS(0, discounts[5].discount);
}

/**
* Tested Paketpreise
* A: 5,-- / Stück im Paket
* B: 4.50 / Stück im Paket
* C und D: Wird nicht im Paket verkauft -> Anfrage unsinnig -> -1,-- / Paket
*/
TEST(test_get_package_prices)
{
	ProductInfo p = get_product_info('A');
	ASSERT_EQUALS(5.0, get_package_price(p));

	p = get_product_info('B');
	ASSERT_EQUALS_TOLERANCE(4.5, get_package_price(p), 0.0);

	p = get_product_info('C');
	ASSERT_EQUALS(-1, get_package_price(p));

	p = get_product_info('D');
	ASSERT_EQUALS(-1, get_package_price(p));
}

/**
* Tested ob Preise für A korrekt ermittelt werden
*/
TEST(test_get_price_of_n_pieces_of_A)
{
	ProductInfo p = get_product_info('A');
	// Einzelpreis für ein Stück
	ASSERT_EQUALS(10.0, get_price_of_n_pieces(p, 1));
	// Einzelpreis für zwei Stücke
	ASSERT_EQUALS(20.0, get_price_of_n_pieces(p, 2));
	// Paketpreis für ein Paket bei 3 Stücken
	ASSERT_EQUALS(15.0, get_price_of_n_pieces(p, 3));
	// Paketpreis für ein Paket und ein Einzelpreis
	ASSERT_EQUALS(25.0, get_price_of_n_pieces(p, 4));
	// Paketpreis für ein Paket und zwei Einzelpreise
	ASSERT_EQUALS(35.0, get_price_of_n_pieces(p, 5));
	// Paketpreis für zwei Pakete
	ASSERT_EQUALS(30.0, get_price_of_n_pieces(p, 6));
}

/**
* Tested ob Preise für B korrekt ermittelt werden
*/
TEST(test_get_price_of_n_pieces_of_B)
{
	ProductInfo p = get_product_info('B');
	// Stückpreis
	ASSERT_EQUALS(5.0, get_price_of_n_pieces(p, 1));
	// Stückpreis
	ASSERT_EQUALS(10.0, get_price_of_n_pieces(p, 2));
	// Stückpreis
	ASSERT_EQUALS(25.0, get_price_of_n_pieces(p, 5));
	// Paketpreis
	ASSERT_EQUALS(27.0, get_price_of_n_pieces(p, 6));
	// Paketpreis und Stückpreis
	ASSERT_EQUALS(32.0, get_price_of_n_pieces(p, 7));
	// Paketpreis und Stückpreis
	ASSERT_EQUALS(37.0, get_price_of_n_pieces(p, 8));
}

/**
* Tested Produkt C (Mengenrabatt), ob Preise für Mengen
* unter der ersten Rabattstufe korrekt ermittelt werden.
*/
TEST(test_get_price_of_n_pieces_of_C_without_discount)
{
	ProductInfo p = get_product_info('C');
	// 1 Stück
	ASSERT_EQUALS_TOLERANCE(7.5, get_price_of_n_pieces(p, 1), 0.0);

	// Max. Anzahl von Stück ohne Rabatt
	double price_for_99 = get_price(p) * 99;
	ASSERT_EQUALS_TOLERANCE(price_for_99, get_price_of_n_pieces(p, 99), 0.0);
}

/**
* Tested ob Preise für Produkt C bei Mengen in der ersten Rabattstufe
* korrekt ermittelt werden.
*/
TEST(test_get_price_of_n_pieces_of_C_with_first_discount_level)
{
	ProductInfo p = get_product_info('C');
	struct Discount* d = get_discounts(p);
	int discount_rate = d[0].discount;
	double price_for_100 = get_price(p) * (100 - discount_rate)/100;
	ASSERT_EQUALS_TOLERANCE(price_for_100 * 100, get_price_of_n_pieces(p, 100), 0.001);
	ASSERT_EQUALS_TOLERANCE(price_for_100 * 499, get_price_of_n_pieces(p, 499), 0.001);
}

/**
* Tested ob Preise für Produkt C bei Mengen in der zweiten Rabattstufe
* korrekt ermittelt werden.
*/
TEST(test_get_price_of_n_pieces_of_C_with_second_discount_level)
{
	ProductInfo p = get_product_info('C');
	int discount_rate = get_discounts(p)[1].discount;
	double price_for_500 = get_price(p) * (100 - discount_rate)/100;
	ASSERT_EQUALS_TOLERANCE(price_for_500 * 500, get_price_of_n_pieces(p, 500), 0.001);
	ASSERT_EQUALS_TOLERANCE(price_for_500 * 5000, get_price_of_n_pieces(p, 5000), 0.001);
}

/**
* Tested, ob für Produkt D der korrekte Preis ermittelt wird.
*/
TEST(test_get_price_of_n_pieces_of_D)
{
	ProductInfo p = get_product_info('D');

	// Regulärer Preis für Stückzahlen unter 100
	double price = get_price(p);
	ASSERT_EQUALS_TOLERANCE(price * 99, get_price_of_n_pieces(p, 99), 0.0);

	// Rabatt für Stückzahlen unter 200
	int discount_rate = get_discounts(p)[0].discount;
	price = get_price(p) * (100 - discount_rate) / 100;
	ASSERT_EQUALS_TOLERANCE(price * 100, get_price_of_n_pieces(p, 100), 0.001);
	ASSERT_EQUALS_TOLERANCE(price * 199, get_price_of_n_pieces(p, 199), 0.001);

	// Rabatt für Stückzahlen unter 300
	discount_rate = get_discounts(p)[1].discount;
	price = get_price(p) * (100 - discount_rate) / 100;
	ASSERT_EQUALS_TOLERANCE(price * 200, get_price_of_n_pieces(p, 200), 0.001);
	ASSERT_EQUALS_TOLERANCE(price * 299, get_price_of_n_pieces(p, 299), 0.001);

	// Rabatt für Stückzahlen unter 400
	discount_rate = get_discounts(p)[2].discount;
	price = get_price(p) * (100 - discount_rate) / 100;
	ASSERT_EQUALS_TOLERANCE(price * 300, get_price_of_n_pieces(p, 300), 0.001);
	ASSERT_EQUALS_TOLERANCE(price * 399, get_price_of_n_pieces(p, 399), 0.001);

	// Rabatt für Stückzahlen unter 500
	discount_rate = get_discounts(p)[3].discount;
	price = get_price(p) * (100 - discount_rate) / 100;
	ASSERT_EQUALS_TOLERANCE(price * 400, get_price_of_n_pieces(p, 400), 0.001);
	ASSERT_EQUALS_TOLERANCE(price * 499, get_price_of_n_pieces(p, 499), 0.001);

	// Rabatt für Stückzahlen über 500
	discount_rate = get_discounts(p)[4].discount;
	price = get_price(p) * (100 - discount_rate) / 100;
	ASSERT_EQUALS_TOLERANCE(price * 500, get_price_of_n_pieces(p, 500), 0.001);
	ASSERT_EQUALS_TOLERANCE(price * 10000, get_price_of_n_pieces(p, 10000), 0.001);

}
