#include "contact.h"
// 程序界面的显示
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
	// 创建contact的变量con
	struct Contact con;
	InitContact(&con);
	// dowhile与switch结合形成功能选项同时 内部case的名称利用枚举定义 可读性增加
	do
	{
		menu();
		printf("请输入选择:>\n");
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
			printf("退出\n");
			break;
		default:
			printf("请重新选择:>\n");
			break;
		}
	} while (intput);
	return 0;
}