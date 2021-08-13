#include "PrototypePattern.h"

// 浅拷贝
// int main()
// {
// 	char name1[] = "Single";
// 	char workname1[] = "Single_Model";
// 	ConcreteWork *singleWork = new ConcreteWork(name1,1001,workname1);
// 	printf("\nSingle的作业：\n");
// 	singleWork->printWorkInfo();
	
// 	printf("\njungle直接抄作业……\n");
// 	ConcreteWork *jungleWork = singleWork;
// 	printf("\nJungle的作业：\n");
// 	jungleWork->printWorkInfo();

// 	//抄完改名字和学号，否则会被老师查出来
// 	printf("\njungle抄完改名字和学号，否则会被老师查出来……\n");
// 	char name2[] = "jungle";
// 	char workname2[] = "Jungle_Model";
// 	jungleWork->setName(name2);
// 	jungleWork->setIdNum(1002);
// 	WorkModel *jungleModel = new WorkModel();
// 	jungleModel->setWorkModelName(workname2);
// 	jungleWork->setModel(jungleModel);
	
// 	//检查下是否改对了
// 	printf("\nSingle的作业：\n");
// 	singleWork->printWorkInfo();
// 	printf("\nJungle的作业：\n");
// 	jungleWork->printWorkInfo();

// 	system("pause");

// 	delete singleWork;
// 	delete jungleModel;
// 	delete jungleWork;
// 	return 0;
// }

// 深拷贝
int main()
{
	char name1[] = "Single";
	char workname1[] = "Single_Model";
	ConcreteWork *singleWork = new ConcreteWork(name1, 1001, workname1);
	printf("\nSingle的作业：\n");

	ConcreteWork *jungleWork = singleWork->clone();
	printf("\nJungle的作业：\n");

	//抄完改名字和学号，否则会被老师查出来
	printf("\njungle抄完改名字和学号，否则会被老师查出来……\n");
	char name2[] = "jungle";
	char workname2[] = "Jungle_Model";
	jungleWork->setName(name2);
	jungleWork->setIdNum(1002);
	WorkModel *jungleModel = new WorkModel();
	jungleModel->setWorkModelName(workname2);
	jungleWork->setModel(jungleModel);

	//检查下是否改对了
	printf("\nSingle的作业：\n");
	singleWork->printWorkInfo();
	printf("\nJungle的作业：\n");
	jungleWork->printWorkInfo();

	system("pause");

	delete singleWork;
	delete jungleModel;
	delete jungleWork;
	return 0;
}