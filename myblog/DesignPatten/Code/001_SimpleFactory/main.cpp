#include <iostream>
#include "SimpleFactory.h"

int main()
{
	cout << "简单工厂模式" << endl;
	cout << "王波波";
	//定义工厂类对象
	Factory *fac = new Factory();
	AbstractSportProduct *product = NULL;

	product = fac->getSportProduct("Basketball");
	if (product) {
		delete product;
	}

	product = fac->getSportProduct("Football");
	if (product) {
		delete product;
	}

	product = fac->getSportProduct("Volleyball");	
	if (product) {
		delete product;
	}

	delete fac;
	system("pause");
	return 0;
}