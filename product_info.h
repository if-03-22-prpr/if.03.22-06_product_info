/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: */ <my class>; /*
 * ---------------------------------------------------------
 * Exercise Number: 
 * File:			product_info.h
 * Author:			*/ <my name>; /*
 * ----------------------------------------------------------
 * Description:
 * The function declaration of product info ADT.
 * ----------------------------------------------------------
 */
 
/* INCLUDE GUARD !! */

/* INCLUDES */


/**
 * Two different pricing schemas (see below) are supported. One for single prices and
 * price reductions for packaged goods. Another where the price gets reduced
 * with higher quantities.
 */
  /** PACKAGE_PRICING: The schema where packaged goods have a reduced price over single items. */
  /** QUANTITY_DISCOUNT :The schema where price reductions are given based on quantity gates. */


/**
 * Struct named `Discount` holding information of a quantity discount. 
 * The number of items from which the price of one item gets reduced by a certain percentage.
 */


/* The data type declaration of the ADT named `ProductInfo` */

/**
* Returns the ProductInfo of a product if the product is found, 0 otherwise
* @param product_id The character which identifies the product.
* @return The product info or 0.
*/
<type> get_product_info(<params>);

/**
* Returns the pricing schema of a product.
* @param p The ProductInfo of the desired product.
* @return The pricing schema.
*/
<type> get_pricing_schema(<params>);

/**
* Returns the regular price of a product, i.e., the price without any
* price reduction.
* @param p The product info.
* @return The regular price of the product.
*/
<type> get_price(<params>);

/**
* If the product has a pricing schema of PACKAGE_PRICING the size of the
* package is returned, otherwise -1.
* @param p The product info.
* @return The package size.
*/
<type> get_package_size(<params>);

/**
* If the product has a pricing schema of PACKAGE_PRICING the price of one piece
* it a whole package is taken is returned, otherwise -1.
* @param p The product info.
* @return The price per piece if one package is taken.
*/
<type> get_package_price(<params>);

/**
* If the product has a pricing schema of QUANTITY_DISCOUNT an array of Discount
* info is returned, otherwise 0. The array is ordered, i.e., the lower the index
* the lower is the number_of_items field.
* @param p The product info.
* @return Array of Discount structs.
*/
<type> get_discounts(<params>);

/**
* Returns the price for n pieces of a specific product reflecting all possible
* price reductions.
* @param p The product info.
* @param n The number of items taken from p.
* @return The total price of the n products after all possible price reductions are applied.
*/
<type> get_price_of_n_pieces(<params>);

