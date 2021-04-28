#include <iostream>
#include "FactoryMethod.h"

int main()
{
	printf("��������ģʽ\n");
	
	//���幤�������Ͳ�Ʒ�����
	AbstractFactory *fac = NULL;
	AbstractSportProduct *product = NULL;

	fac = new BasketballFactory();
	product = fac->getSportProduct();
	if (fac)
	{
		delete fac;
	}
	if (product) {
		delete product;
	}

	fac = new FootballFactory();
	product = fac->getSportProduct();
	if (fac)
	{
		delete fac;
	}
	if (product) {
		delete product;
	}

	fac = new VolleyballFactory();
	product = fac->getSportProduct();	
	if (fac)
	{
		delete fac;
	}
	if (product) {
		delete product;
	}

	system("pause");
	return 0;
}