#include "contact.h"
// ����������ʾ
void menu()
{
	printf("                        ************************************                    \n");
	printf("                  ****1.add**************2.del********                        \n");
	printf("                   ****3.search***********4.modify*****                     \n");
	printf("                ****5.show*************6.sort*******                          \n");
	printf("                  **************0.quit****************                          \n");
	printf("                     ************************************                        \n");
}
int main()
{
	int intput = 0;
	// ����contact�ı���con
	struct Contact con;
	InitContact(&con);
	// dowhile��switch����γɹ���ѡ��ͬʱ �ڲ�case����������ö�ٶ��� �ɶ�������
	do
	{
		menu();
		printf("������ѡ��:>\n");
		scanf("%d", &intput);
		switch (intput)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			printf("�˳�\n");
			break;
		default:
			printf("������ѡ��:>\n");
			break;
		}
	} while (intput);
	return 0;
}