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
	printf("����������%s, ���⣺%d, ��ַ��%s, ��ϵ�绰��%s\n",
		name.c_str(), price, address.c_str(), phoneNumber.c_str());
}

void Landlord::ask(){
	printf("����%s�鿴�����Ϣ��\n",name.c_str());
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
	printf("���%sѯ�ʷ�����Ϣ\n", name.c_str()); 
	(this->getMediator())->operation(this);
}

void Tenant::answer(){
	printf("���������%s\n", name.c_str());
}

int main()
{
	// �����ⷿ�н�
	Agency *mediator = new Agency();

	// ����3λ����
	Landlord *fangdong1 = new Landlord("����", 1350, "�ɶ���˫����", "1351025");
	Landlord *fangdong2 = new Landlord("����", 1500, "�ɶ��������", "1378390");
	Landlord *fangdong3 = new Landlord("�ŷ�", 1000, "�ɶ�����Ȫ��", "1881166");
	fangdong1->setMediator(mediator);
	fangdong2->setMediator(mediator);
	fangdong3->setMediator(mediator);
	// �������н鴦�Ǽ�ע�᷿Դ��Ϣ
	mediator->registerMethod(fangdong1);
	mediator->registerMethod(fangdong2);
	mediator->registerMethod(fangdong3);

	// ������λ���Jungle�ͼ�����
	Tenant *jungle = new Tenant("Jungle");
	Tenant *jianmengtu = new Tenant("������");
	jungle->setMediator(mediator);
	jianmengtu->setMediator(mediator);
	// Jungle�ͼ��������н鴦�Ǽ�������Ϣ
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