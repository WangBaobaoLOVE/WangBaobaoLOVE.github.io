#include "Observer.h"
#include "AllyCenter.h"

/***********   AllyCenter    ****************/
AllyCenter::AllyCenter(){
	printf("大吉大利，今晚吃鸡!\n");
}

// 加入玩家
void AllyCenter::join(Observer* player){
	if (playerList.size() == 4){
		printf("玩家已满\n");
		return;
	}
	printf("玩家 %s 加入\n", player->getName().c_str());
	playerList.push_back(player);
	if (playerList.size() == 4){
		printf("组队成功，不要怂，一起上！\n");
	}
}
// 移除玩家
void AllyCenter::remove(Observer* player){
	printf("玩家 %s 退出\n", player->getName().c_str());
	//playerList.remove(player);
}
/***********   AllyCenter    ****************/


/**********   AllyCenterController    *******/
AllyCenterController::AllyCenterController(){

}

// 实现通知方法
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
	// 创建一个战队
	AllyCenterController* controller = new AllyCenterController();

	// 创建4个玩家，并加入战队
	Player* Jungle = new Player("Jungle");
	Player* Single = new Player("Single");
	Player* Jianmengtu = new Player("贱萌兔");
	Player* SillyDog = new Player("傻子狗");
	controller->join(Jungle);
	controller->join(Single);
	controller->join(Jianmengtu);
	controller->join(SillyDog);

	printf("\n\n");

	// Jungle发现物资，呼叫队友
	Jungle->call(RESOURCE, controller);

	printf("\n\n");

	// 傻子狗遇到危险，求救队友
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