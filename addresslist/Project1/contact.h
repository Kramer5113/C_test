// 消除安全性警告
#define _CRT_SECURE_NO_WARNINGS
// 定义数值以便全局使用
//#define MAX 100
#define DEF_size 3

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 利用枚举来增加可读性
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
// 定义通讯录所需内容数据值
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char adr[MAX_ADR];
};

struct Contact
{
	struct PeoInfo *data;
	int size;
	int cap; // 记录当前最大容量
};
// 初始化con 同时将con地址传入 因为内容需要修改
void InitContact(struct Contact* ps);
// 为con增加内容 同时将con地址传入 因为内容需要修改
void AddContact(struct Contact* ps);
// 显示con内容 同时将con地址传入 因为这样使用内存的使用使得运行更顺畅
void ShowContact(struct Contact* ps);
// 为con减少内容 同时将con地址传入 因为内容需要修改
void DelContact(struct Contact* ps);
// 搜索con内容 同时将con地址传入 因为这样使用内存的使用使得运行更顺畅
void SearchContact(const struct Contact* ps);
// 为con修改内容 同时将con地址传入 因为内容需要修改
void ModifyContact(struct Contact* ps);
// 释放内存
void DestroyContact(struct Contact* ps);


