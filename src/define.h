#ifndef define_h
#define define_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
//#include <malloc.h>

typedef int status;

#define OK 1
#define ERROR 0
#define Untrue -1

//ȫ�ֱ��� 
int wordnumber, formulanumber;//����������ʽ�� 
int *variate;//�����б����ֵ���ֵ 
int i;//����ѭ��
int temp;//�м���� 
int WAY;//����ѡ����ⷽʽ 

//�洢�ṹ
struct Literal{
    struct Literal * next;
    int value;//����ֵ 
};

struct Clause{
    struct Clause * next;
    struct Literal * head;
};

//���ڱ������� 
struct Qipan{
	int flag;//���ڱ���Ƿ�Ϊ��ʼ������ȷ����λ�� 
	int num;
};
struct Qipan qipan[36];//���ڱ���6��������Ϣ

char filename_setcnf[15];//���ڱ�������ת��cnf�ļ��� 

/*------------------------CNF�ļ�����------------------------*/

/*��������ʼ������*/

/*�½��Ӿ�*/ 
struct Clause * createClause();
/*�½�����*/ 
struct Literal * createLiteral();
/*cnf�ļ���ȡ*/
struct Clause * Readfile(char * filename);
/*�������CNF�ļ���ʽ*/ 
void Traversefile(struct Clause * root);
/*CNF�ļ�����*/ 
status Savefile(struct Clause * root);

/*------------------------DPLL�㷨------------------------*/

/*�����������ж�����*/ 
int judgesign(int a);
/*�жϵ��Ӿ䣬���ص��Ӿ��������*/ 
int isUnitClause(struct Clause * root);
/*�������Ӿ�*/ 
status removeClause(struct Clause * root);
/*�ж�ֻ��һ�ֳ�����ʽ������*/
int isPureLiteral(struct Clause * root);
/*����ֻ��һ�ֳ�����ʽ������*/ 
status removePureLiteral(struct Clause * root);
/*ѡȡ������ֵ����*/ 
int chooseLiteral(struct Clause *root);
/*��¡�Ӿ�*/
struct Clause * cloneClause(struct Clause * headp);
/*��¡ȫ���ṹ����ѡȡ��������Ϊ���Ӿ����洢�ṹ��*/ 
struct Clause * cloneAll(int a, struct Clause * root);
/*���ٴ洢�ṹ*/ 
void destoryClauses(struct Clause * root);
/*�ж��Ƿ����־�Ϊ��ֵ*/ 
status isAllPureLiteral(struct Clause * root);
/*�ж��Ƿ���ڿ��Ӿ�*/ 
status isEmptyClause(struct Clause * root);
/*��鵱ǰ�Ƿ�����*/ 
status check(struct Clause * root);
/*dpll�㷨*/ 
status dpll(struct Clause * root);
/*�����д��ͬ���ļ�*/ 
void writeResult(char * filename, int flag, int time);

/*------------------------SuDoKu------------------------*/

/*��ȡ�����ļ�*/
void Readqipan(char *filename);
/*��ʼ������*/
void Resetqipan(struct Qipan qipan[]);
/*�����ǰ����*/
void Showqipan(struct Qipan qipan[]);
/*��������*/
void PlaySuDoKu(struct Qipan qipan[]);
/*��������Ƿ������*/
status Checkqipan(struct Qipan qipan[]);
/*ת��ΪCNF�ļ�*/
void SetCNFfile(struct Qipan qipan[]);
#endif