#ifndef __JUZHEN_H
#define __JUZHEN_H	 
#include "sys.h"
/*****�� PB1-4 ******/
#define H1 PAout(0)
#define H2 PAout(1)
#define H3 PAout(2)
#define H4 PAout(3)

/*****�� PB5-8 ******/
#define L1 PAin(4)
#define L2 PAin(5)
#define L3 PAin(6)
#define L4 PAin(7)


void JUZHEN_Init(void);//IO��ʼ��
u8 JUZHEN_Scan(u8 he);  	//����ɨ�躯��	    
#endif
