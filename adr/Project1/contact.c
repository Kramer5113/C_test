#include "contact.h"
// 自定义函数添加了static 此功能只在此文件有效 防止其他文件失误引用 const保持结构体不变 
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	// 利用循环来从第一位到最后进行查找
	for (i = 0; i < ps->size; i++)
	{
		// 利用strcmp函数 循环进行到某一阶段时 当所输入name与其内查找的相同返回0
		if (0 == strcmp(ps->data[i].name, name))
		{
			// 将此查询到的i返回
			return i;
		}
	}
	// 当数据全部查询完毕时 还未找到返回-1
	return -1;
}

void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*) malloc(DEF_size * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->cap = DEF_size;
	LoadContact(ps);
}

void Checkcap(struct Contact *ps)
{
	if (ps->size == ps->cap)
	{
		struct Contact *ptr=realloc(ps->data, (ps->cap + 2)*sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->cap += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

void LoadContact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("L:%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
	{
		Checkcap(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

void AddContact(struct Contact* ps)
{
	Checkcap(ps);
	
	
		// 输入数据向数组 ps结构体指向结构体数组data 同时利用此时size的位置 指定其存储位置 再 .xxxx 具体到输入哪一项
		printf("姓名: \n");
		scanf("%s", ps->data[ps->size].name);
		printf("年龄: \n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("性别: \n");
		scanf("%s", ps->data[ps->size].sex);
		printf("电话: \n");
		scanf("%s", ps->data[ps->size].tele);
		printf("地址: \n");
		scanf("%s", ps->data[ps->size].adr);
		//每添加一次后size+1 以实现将其每次的输入都进行存储
		ps->size++;
		printf("add success\n");
	
}

void ShowContact(struct Contact* ps)
{
	// 利用if语句 此时size为0 说明无数据 else 打印属性名 进入循环 此时size增加了几次 就代表add了所有信息 以此将所有信息输出
	if (ps->size == 0)
	{
		printf("无数据查询\n");
	}
	else
	{
		int i = 0;
		// 加上-来进行左对齐 \xxt 来限制间隔
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", "姓名", "年龄", "性别", "电话", "家庭住址");
		printf("\n");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].adr);
		}
		printf("\n");
	}
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的名字\n");
	scanf("%s", name);
	// 利用传址调用 实现函数的利用 减少冗余 返回类型设置为int 
	int pos = FindByName(ps, name);
	if (pos==-1)
	{
		printf("查无此人\n");
	}
	else
	{
		//  这里删除方式使用的是覆盖 利用循环 定义一个j 令其=i 通过将后一位内容覆盖到前一位的方式来进行删除
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		// 在进行此操作后 可使用内容+1 也即是size-1
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的名字\n");
	scanf("%s", name);
	// 同delcontact
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		// 同showcontact
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", "姓名", "年龄", "性别", "电话", "家庭住址");
		printf("\n");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].adr);
	}		
	printf("\n");
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改的名字\n");
	scanf("%s", name);
	// 同上
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		// 同addcontact 通过重新输入的方式 来修改信息
		printf("name: \n");
		scanf("%s", ps->data[pos].name);
		printf("age: \n");
		scanf("%d", &(ps->data[pos].age));
		printf("sex: \n");
		scanf("%s", ps->data[pos].sex);
		printf("tele: \n");
		scanf("%s", ps->data[pos].tele);
		printf("adr: \n");
		scanf("%s", ps->data[pos].adr);
	}
}

void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("S:%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL; 
}