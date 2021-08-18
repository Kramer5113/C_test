#include "contact.h"
// �Զ��庯�������static �˹���ֻ�ڴ��ļ���Ч ��ֹ�����ļ�ʧ������ const���ֽṹ�岻�� 
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	// ����ѭ�����ӵ�һλ�������в���
	for (i = 0; i < ps->size; i++)
	{
		// ����strcmp���� ѭ�����е�ĳһ�׶�ʱ ��������name�����ڲ��ҵ���ͬ����0
		if (0 == strcmp(ps->data[i].name, name))
		{
			// ���˲�ѯ����i����
			return i;
		}
	}
	// ������ȫ����ѯ���ʱ ��δ�ҵ�����-1
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
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
	Checkcap(ps);
	
	
		// �������������� ps�ṹ��ָ��ṹ������data ͬʱ���ô�ʱsize��λ�� ָ����洢λ�� �� .xxxx ���嵽������һ��
		printf("����: \n");
		scanf("%s", ps->data[ps->size].name);
		printf("����: \n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�Ա�: \n");
		scanf("%s", ps->data[ps->size].sex);
		printf("�绰: \n");
		scanf("%s", ps->data[ps->size].tele);
		printf("��ַ: \n");
		scanf("%s", ps->data[ps->size].adr);
		//ÿ���һ�κ�size+1 ��ʵ�ֽ���ÿ�ε����붼���д洢
		ps->size++;
		printf("add success\n");
	
}

void ShowContact(struct Contact* ps)
{
	// ����if��� ��ʱsizeΪ0 ˵�������� else ��ӡ������ ����ѭ�� ��ʱsize�����˼��� �ʹ���add��������Ϣ �Դ˽�������Ϣ���
	if (ps->size == 0)
	{
		printf("�����ݲ�ѯ\n");
	}
	else
	{
		int i = 0;
		// ����-����������� \xxt �����Ƽ��
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", "����", "����", "�Ա�", "�绰", "��ͥסַ");
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
	printf("������Ҫɾ��������\n");
	scanf("%s", name);
	// ���ô�ַ���� ʵ�ֺ��������� �������� ������������Ϊint 
	int pos = FindByName(ps, name);
	if (pos==-1)
	{
		printf("���޴���\n");
	}
	else
	{
		//  ����ɾ����ʽʹ�õ��Ǹ��� ����ѭ�� ����һ��j ����=i ͨ������һλ���ݸ��ǵ�ǰһλ�ķ�ʽ������ɾ��
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		// �ڽ��д˲����� ��ʹ������+1 Ҳ����size-1
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�����\n");
	scanf("%s", name);
	// ͬdelcontact
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		// ͬshowcontact
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", "����", "����", "�Ա�", "�绰", "��ͥסַ");
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
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s", name);
	// ͬ��
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		// ͬaddcontact ͨ����������ķ�ʽ ���޸���Ϣ
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