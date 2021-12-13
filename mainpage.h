/** @file mainpage.h
* @brief Description of product_info.
*/
/** @mainpage product_info -- Implement a supermarket pricing scheme
*
* @author P. Bauer, S. Schraml
*
* This week we are implementing a supermarket check out system. @ref english.
*
* Diese Woche implementieren wir ein Kassasystem für einen Supermarkt. @ref german.
*
* @page english English Version
* @section intro Introduction
* A supermarket checkout system has to implement pretty complex pricing
* schemas such as "three for a dollar," "$1.99 per pound", "buy two, get one free",
* etc.
*
* This week, let's implement the code for a supermarket checkout that calculates
* the total price of a number of items. In a normal supermarket, things are
* identified using unique numbers encoded in some EAN system. In our store, we'll use
* individual letters of the alphabet (A, B, C, and so on).
*
* We support two different pricing schemas which will be described in the sequel.
* One schema is where our goods are
* priced individually. In addition, some items are multipriced: if you buy a
* package of n items one item will have a lower price. For example, item 'A' is
* packaged in numbers of 3. One 'A' costs 10 € individually, but the price of
* one package is € 15 (3 times € 5.--). If we buy 4 'A's, which is a package
* of 3 and one individual 'A' the price would be € 25.--. In fact our prices are:
*
* <pre>
 Item   Unit      Package    Package
        Price      Size       Price
 ------------------------------------
    A   10.--         3         5.--
    B    5.--         6         4.50
* </pre>
*
* Furthermore we shall support a quantity discount, i.e., the price gets reduced
* the quantity of bought goods. As an example the prices could be like
* a price reduction of 5 % when selling a quantity of at least 100 pieces and
* of 10 % when selling a quantity of at least 500 pieces.
* Both variants (packaged pricing above and quantity
* discount) are determined by the PricingSchema.
*
* We will create an abstract data type ProductInfo, which encapsulates the
* pricing info and adds a convenience function which gives us the total price
* for a specific number of items.
*
* @section assignment Assignment
* Implement the given the library such that all unit tests given pass successfully.
*
* @page german Deutsche Version
* @section intro Einführung
* Preisschemata in einem Supermarkt können manchmal durchaus komplex werden,
* wie zum Beispiel Drei Stück für einen Euro, "1.99 / kg",
* "Kaufe zwei, eines ist gratis", etc.
*
* Wir wollen heute eine Library implementieren, welche den Gesamtpreis einer
* bestimmten Anzahl von Waren berechnet. Normalerweise werden Waren in einem
* Supermarkt über EAN Codes identifiziert. Zur Vereinfachung werden Waren in
* unserem System mittels Buchstaben aus dem Alphabet bezeichnet (A, B, C, ...).
*
* Unsere Library soll zwei grundsätzliche Preis-Schemata unterstützen: Einerseits
* das sog. Package Pricing und andererseits Mengenrabatte. Beim Package Pricing
* sind die Waren mit Einzelpreisen ausgezeichnet. Zusätzlich gibt es
* Waren mit Spezialpreisen. Beispielsweise ist A in Packeten von 3 Stück
* verpackt. Ein einzelnes 'A' kostet 10 € aber der Paketpreis ist nur 5 € / Stück.
* Wenn man 4 'A's kauft, was ein Packet von 3 und ein einzelnes 'A' ist, kostet
* das € 25,--.
* Unser Preisangebot ist:
*
* <pre>
Item   Unit      Package    Package
       Price      Size       Price
------------------------------------
   A   10.--         3         5.--
   B    5.--         6         4.50
* </pre>
*
* Bei den Mengenrabatten werden ab einer Abnahme einer bestimmten Menge eine
* Preisreduktion auf den Stückpreis gewährt. Je höher die Abnahmemenge, desto
* größer ist normalerweise die Reduktion.
* In den unit tests sind die Produkte C und D Beispiele für Produkte mit
* Mengenrabatt. Bei C wird ein Rabatt ab 100 Stück von 5 % und ab 500 Stück
* in Rabatt von 10 % gewährt. Produkt D ist stärker gestaffelt und bietet einen
* Rabatt von 1 % ab 100 Stück, 2 % ab 200 Stück, ... bis 5 % ab 500 Stück.
*
* Es soll ein abstrakter Datentyp implementiert werden, der die Preisinformation
* kapselt und eine Funktion zur bequemen Berechnung des Gesamtpreises einer bestimmten
* Anzahl eines Produkts.
**
* @section assignment Aufgabe
* Implementieren Sie das Interface der Library product_info, sodass die unit tests
* erfolgreich durchlaufen.
*/
