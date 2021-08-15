#include <iostream>
#include "Mediator.h"
#include "Colleague.h"

Landlord::Landlord(){
	name = "none";
	price = 0;
	address = "none";
	phoneNumber = "none";
	setPersonType(NONE_PERSON);
}

Landlord::Landlord(string iName, int iPrice, 
	string iAddress, string iPhoneNum){
	name = iName;
	price = iPrice;
	address = iAddress;
	phoneNumber = iPhoneNum;
	setPersonType(LANDLORD);
}

void Landlord::answer(){
	printf("房东姓名：%s, 房租：%d, 地址：%s, 联系电话：%s\n",
		name.c_str(), price, address.c_str(), phoneNumber.c_str());
}

void Landlord::ask(){
	printf("房东%s查看租客信息：\n",name.c_str());
	(this->getMediator())->operation(this);
}

Tenant::Tenant(){
	name = "none";
	setPersonType(NONE_PERSON);
}

Tenant::Tenant(string iName){
	name = iName;
	setPersonType(TENANT);
}

void Tenant::ask(){
	printf("租客%s询问房东信息\n", name.c_str()); 
	(this->getMediator())->operation(this);
}

void Tenant::answer(){
	printf("租客姓名：%s\n", name.c_str());
}

int main()
{
	// 创建租房中介
	Agency *mediator = new Agency();

	// 创建3位房东
	Landlord *fangdong1 = new Landlord("刘备", 1350, "成都市双流区", "1351025");
	Landlord *fangdong2 = new Landlord("关羽", 1500, "成都市武侯区", "1378390");
	Landlord *fangdong3 = new Landlord("张飞", 1000, "成都市龙泉驿", "1881166");
	fangdong1->setMediator(mediator);
	fangdong2->setMediator(mediator);
	fangdong3->setMediator(mediator);
	// 房东在中介处登记注册房源信息
	mediator->registerMethod(fangdong1);
	mediator->registerMethod(fangdong2);
	mediator->registerMethod(fangdong3);

	// 创建两位租客Jungle和贱萌兔
	Tenant *jungle = new Tenant("Jungle");
	Tenant *jianmengtu = new Tenant("贱萌兔");
	jungle->setMediator(mediator);
	jianmengtu->setMediator(mediator);
	// Jungle和贱萌兔在中介处登记求租信息
	mediator->registerMethod(jungle);
	mediator->registerMethod(jianmengtu);

	jungle->ask();
	printf("\n\n");
	fangdong1->ask();

	printf("\n\n");
	system("pause");

	delete mediator;
	delete fangdong1;
	delete fangdong2;
	delete fangdong3;
	delete jungle;
	delete jianmengtu;

	return 0;
}