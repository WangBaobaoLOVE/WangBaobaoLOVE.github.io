#include "BuilderPattern.h"

int main()
{
	//��������
	AbstractBuilder *builder;
	//ָ����
	Director *director = new Director();
	//��Ʒ��House
	House *house;

	//ָ�����彨����A
	builder = new ConcreteBuilderA();
	director->setBuilder(builder);
	house = director->construct();
	house->printfHouseInfo();
	delete builder;

	//ָ�����彨����B
	builder = new ConcreteBuilderB();
	director->setBuilder(builder);
	house = director->construct();
	house->printfHouseInfo();

	system("pause");

	delete director;
	delete builder;

	return 0;
}