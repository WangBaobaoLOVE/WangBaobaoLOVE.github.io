#include "PrototypePattern.h"

// ǳ����
// int main()
// {
// 	char name1[] = "Single";
// 	char workname1[] = "Single_Model";
// 	ConcreteWork *singleWork = new ConcreteWork(name1,1001,workname1);
// 	printf("\nSingle����ҵ��\n");
// 	singleWork->printWorkInfo();
	
// 	printf("\njungleֱ�ӳ���ҵ����\n");
// 	ConcreteWork *jungleWork = singleWork;
// 	printf("\nJungle����ҵ��\n");
// 	jungleWork->printWorkInfo();

// 	//��������ֺ�ѧ�ţ�����ᱻ��ʦ�����
// 	printf("\njungle��������ֺ�ѧ�ţ�����ᱻ��ʦ���������\n");
// 	char name2[] = "jungle";
// 	char workname2[] = "Jungle_Model";
// 	jungleWork->setName(name2);
// 	jungleWork->setIdNum(1002);
// 	WorkModel *jungleModel = new WorkModel();
// 	jungleModel->setWorkModelName(workname2);
// 	jungleWork->setModel(jungleModel);
	
// 	//������Ƿ�Ķ���
// 	printf("\nSingle����ҵ��\n");
// 	singleWork->printWorkInfo();
// 	printf("\nJungle����ҵ��\n");
// 	jungleWork->printWorkInfo();

// 	system("pause");

// 	delete singleWork;
// 	delete jungleModel;
// 	delete jungleWork;
// 	return 0;
// }

// ���
int main()
{
	char name1[] = "Single";
	char workname1[] = "Single_Model";
	ConcreteWork *singleWork = new ConcreteWork(name1, 1001, workname1);
	printf("\nSingle����ҵ��\n");

	ConcreteWork *jungleWork = singleWork->clone();
	printf("\nJungle����ҵ��\n");

	//��������ֺ�ѧ�ţ�����ᱻ��ʦ�����
	printf("\njungle��������ֺ�ѧ�ţ�����ᱻ��ʦ���������\n");
	char name2[] = "jungle";
	char workname2[] = "Jungle_Model";
	jungleWork->setName(name2);
	jungleWork->setIdNum(1002);
	WorkModel *jungleModel = new WorkModel();
	jungleModel->setWorkModelName(workname2);
	jungleWork->setModel(jungleModel);

	//������Ƿ�Ķ���
	printf("\nSingle����ҵ��\n");
	singleWork->printWorkInfo();
	printf("\nJungle����ҵ��\n");
	jungleWork->printWorkInfo();

	system("pause");

	delete singleWork;
	delete jungleModel;
	delete jungleWork;
	return 0;
}