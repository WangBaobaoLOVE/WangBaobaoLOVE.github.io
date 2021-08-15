#include "Element.h"
#include "Visitor.h"
#include "ShoppingCart.h"
#include <Windows.h>

int main()
{
	Apple *apple1 = new Apple("�츻ʿƻ��", 7);
	Apple *apple2 = new Apple("��ţƻ��", 5);
	Book *book1 = new Book("��¥��", 129);
	Book *book2 = new Book("�ս���", 49);

	Cashier* cashier = new Cashier();
	Customer* jungle = new Customer("Jungle");
	jungle->setNum(apple1, 2);
	jungle->setNum(apple2, 4);
	jungle->setNum(book1, 1);
	jungle->setNum(book2, 3);

	ShoppingCart* shoppingCart = new ShoppingCart();
	shoppingCart->addElement(apple1);
	shoppingCart->addElement(apple2);
	shoppingCart->addElement(book1);
	shoppingCart->addElement(book2);

	printf("\n\n");
	shoppingCart->accept(jungle);

	printf("\n\n");
	shoppingCart->accept(cashier);

	printf("\n\n");
	system("pause");

	delete apple1;
	delete apple2;
	delete book1;
	delete book2;
	delete cashier;
	delete jungle;
	delete shoppingCart;

	return 0;
}