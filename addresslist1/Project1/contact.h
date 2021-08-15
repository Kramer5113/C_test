// ������ȫ�Ծ���
#define _CRT_SECURE_NO_WARNINGS
// ������ֵ�Ա�ȫ��ʹ��
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADR 30

#include <stdio.h>
#include <string.h>

// ����ö�������ӿɶ���
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
// ����ͨѶ¼������������ֵ
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char adr[MAX_ADR];
};
// �����ṹ�� ���peoinfo�������ı���data ���ýṹ��������ʽ���������� size������λ�õļ�¼
struct Contact
{
	struct PeoInfo data[MAX];
	int size;
};
// ��ʼ��con ͬʱ��con��ַ���� ��Ϊ������Ҫ�޸�
void InitContact(struct Contact* ps);
// Ϊcon�������� ͬʱ��con��ַ���� ��Ϊ������Ҫ�޸�
void AddContact(struct Contact* ps);
// ��ʾcon���� ͬʱ��con��ַ���� ��Ϊ����ʹ���ڴ��ʹ��ʹ�����и�˳��
void ShowContact(struct Contact* ps);
// Ϊcon�������� ͬʱ��con��ַ���� ��Ϊ������Ҫ�޸�
void DelContact(struct Contact* ps);
// ����con���� ͬʱ��con��ַ���� ��Ϊ����ʹ���ڴ��ʹ��ʹ�����и�˳��
void SearchContact(const struct Contact* ps);
// Ϊcon�޸����� ͬʱ��con��ַ���� ��Ϊ������Ҫ�޸�
void ModifyContact(struct Contact* ps);

