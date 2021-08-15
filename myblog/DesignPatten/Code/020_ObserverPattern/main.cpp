#include "Observer.h"
#include "AllyCenter.h"

/***********   AllyCenter    ****************/
AllyCenter::AllyCenter(){
	printf("�󼪴���������Լ�!\n");
}

// �������
void AllyCenter::join(Observer* player){
	if (playerList.size() == 4){
		printf("�������\n");
		return;
	}
	printf("��� %s ����\n", player->getName().c_str());
	playerList.push_back(player);
	if (playerList.size() == 4){
		printf("��ӳɹ�����Ҫ�ˣ�һ���ϣ�\n");
	}
}
// �Ƴ����
void AllyCenter::remove(Observer* player){
	printf("��� %s �˳�\n", player->getName().c_str());
	//playerList.remove(player);
}
/***********   AllyCenter    ****************/


/**********   AllyCenterController    *******/
AllyCenterController::AllyCenterController(){

}

// ʵ��֪ͨ����
void AllyCenterController::notify(INFO_TYPE infoType, std::string name){
	switch (infoType){
	case RESOURCE:
		for (Observer* obs : playerList){
			if (obs->getName() != name){
				((Player*)obs)->come();
			}
		}
		break;
	case HELP:
		for (Observer* obs : playerList){
			if (obs->getName() != name){
				((Player*)obs)->help();
			}
		}
		break;
	default:
		printf("Nothing\n");
	}
}
/**********   AllyCenterController    *******/

int main()
{
	// ����һ��ս��
	AllyCenterController* controller = new AllyCenterController();

	// ����4����ң�������ս��
	Player* Jungle = new Player("Jungle");
	Player* Single = new Player("Single");
	Player* Jianmengtu = new Player("������");
	Player* SillyDog = new Player("ɵ�ӹ�");
	controller->join(Jungle);
	controller->join(Single);
	controller->join(Jianmengtu);
	controller->join(SillyDog);

	printf("\n\n");

	// Jungle�������ʣ����ж���
	Jungle->call(RESOURCE, controller);

	printf("\n\n");

	// ɵ�ӹ�����Σ�գ���ȶ���
	SillyDog->call(HELP, controller);

	printf("\n\n");
	system("pause");

	delete controller;
	delete Jungle;
	delete Single;
	delete Jianmengtu;
	delete SillyDog;

	return 0;
}