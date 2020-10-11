#include "stm32f10x.h"
#include "sys.h"
#include "LED.h"
#include "delay.h"
#include "pwm.h"
#include "OLED_I2C.h"
#include <stdio.h>		 
#include "juzhen.h"


int main(void)
{
	u16 j = 5;
static unsigned char a;
unsigned char str[1];
	static u8 i=4;
u32 PW=1111; //���õ�password ��ʼ����Ϊ111
u32 P_W=1,pw=1; //�����password 
//u8 n=0,j;// 
	
	
extern const unsigned char BMP0[];
extern const unsigned char BMP1[];
 TIM1_PWM_Init(2000-1,720-1);//����Ƶ��PWMƵ��=10k//200=50hz 
	LED_Init();		  	 	//��ʼ����LED���ӵ�Ӳ���ӿ�
	JUZHEN_Init();
	delay_init();
	I2C_Configuration();
  OLED_Init();
	
	
  OLED_CLS();//����
  PW =1111;
	

	
    while(1)
 {
/*
A  ��������
B  �޸�����
C  ����
D  ȷ��
*/ 
/***************��ӭ����****************/
	 

OLED_ShowStr(0,2,"                    ",2);	//����
      for(i=0;i<4;i++)
	  		OLED_ShowCN(32+i*16,2,i);//��ʾ ��ӭ����
	
	
OLED_ShowStr(0,4,"                    ",2);	//����
///////////////////////////////////////////			
	 
	 { ///////////////////////////////////////////////
	while(JUZHEN_Scan(0)=='N');
/***************��������****************/
  if(JUZHEN_Scan(0) == 'A') //���A��,���½�����������ģʽ
	{
		for(i=4;i<9;i++)
	  {
			OLED_ShowCN(24+(i-4)*16,2,i);//��ʾ ����������
		}
		OLED_ShowStr(0,4,"                    ",2);	
		
		pw = 1;
		i = 0;
	  while(JUZHEN_Scan(0) != 'D') //��Dȷ�����룬����ѭ��
	  {
       a = JUZHEN_Scan(0);
			if(a== '0'||a== '1'||a== '2'||a== '3'||a== '4'||a== '5'||a== '6'||a== '7'||a== '8'||a== '9' )
			{ 
				str[0] = a;
			pw = pw*10+(a -'0') ;
				
    	OLED_ShowStr(i,4,str,2);//��ʾ���������	
	  	i = i+8;	
		  }	
			while(JUZHEN_Scan(0)!='N');
			 delay_ms(100);
			
	  }
		
		OLED_ShowStr(0,4,"                    ",2);		//����whileѭ��������

	
	if( pw == PW ) // �������������������
 {
	  OLED_ShowStr(0,2,"                    ",2);
	 for(i=7;i<11;i++)
	  {
			OLED_ShowCN(32+(i-7)*16,2,i);//��ʾ ������ȷ
		}
		
		
		
			TIM_SetCompare3(TIM1,250);	
			
		
		
		   LED = 0; //������ȷ��Ӧ
		for(i=13;i<17;i++)
	  {
			OLED_ShowCN(32+(i-13)*16,4,i);//��ʾ �ɹ�����
		}
		OLED_ShowCN(32+2*16,4,17);//���滻��
	 

	 pw = 1;   //������������
while(JUZHEN_Scan(0)!='C');//����C��������������ѭ��
  }
 else
 {
	 OLED_ShowStr(0,2,"               ",2);
	 OLED_ShowCN(32,2,7);//��
	 OLED_ShowCN(32+16,2,8);//��
	 OLED_ShowCN(32+2*16,2,11);//��
	 OLED_ShowCN(32+3*16,2,12);//��
	 OLED_ShowStr(0,4,"               ",2);
	  delay_ms(1000);
 
 }
} 

 if(JUZHEN_Scan(0) == 'C')//����
  {
	LED = 1;
		
			TIM_SetCompare3(TIM1,50);	
		
   OLED_ShowStr(0,2,"                    ",2);
	 for(i=13;i<17;i++)
	  {
			OLED_ShowCN(32+(i-13)*16,2,i);//��ʾ �ɹ�����
		}
	OLED_ShowStr(0,4,"                    ",2);
		 delay_ms(1000);
		
  }


		
//��������
  if(JUZHEN_Scan(0) == 'B')
	{
		
		for(i=4;i<9;i++)
	  {
			OLED_ShowCN(24+(i-4)*16,2,i);//��ʾ ����������
		}
		OLED_ShowStr(0,4,"                    ",2);	
		
		pw = 1;
		i = 0;
	  while(JUZHEN_Scan(0) != 'D') //��Dȷ�����룬����ѭ��
	  {
       a = JUZHEN_Scan(0);
			if(a== '0'||a== '1'||a== '2'||a== '3'||a== '4'||a== '5'||a== '6'||a== '7'||a== '8'||a== '9' )
			{ 
				str[0] = a;
			pw = pw*10+(a -'0') ;
				
    	OLED_ShowStr(i,4,str,2);//��ʾ���������	
	  	i = i+8;	
		  }	
			while(JUZHEN_Scan(0) == a);
			
				 delay_ms(50);
	  }
		
		OLED_ShowStr(0,4,"                    ",2);		//����whileѭ��������

	   if(pw != PW)
		{
	 OLED_ShowStr(0,2,"               ",2);
	 OLED_ShowCN(32,2,7);//��
	 OLED_ShowCN(32+16,2,8);//��
	 OLED_ShowCN(32+2*16,2,11);//��
	 OLED_ShowCN(32+3*16,2,12);//��
	 OLED_ShowStr(0,4,"               ",2);
	  delay_ms(1000);
 
   }
		
		
/*******************����������ȷ����������*********************/
		if( pw == PW ) // �������������������
 {
	 
	 
	  OLED_ShowStr(0,2,"                    ",2);
	 for(i=7;i<11;i++)
			OLED_ShowCN(32+(i-7)*16,2,i);//��ʾ ������ȷ
		 delay_ms(500);
	
			
		OLED_ShowStr(0,2,"                    ",2);
		
			for(i=4;i<9;i++)
			OLED_ShowCN(24+(i-4)*16,2,i);//��ʾ ����������
		  
		  OLED_ShowCN(24+1*16,2,18);//�衪����
		  OLED_ShowCN(24+2*16,2,19);//��----��
		OLED_ShowStr(0,4,"                    ",2);	
		
		
		P_W = 1;
		i = 0;
	while(JUZHEN_Scan(0) != 'D')
	  {
       a = JUZHEN_Scan(0);
		if(a== '0'||a== '1'||a== '2'||a== '3'||a== '4'||a== '5'||a== '6'||a== '7'||a== '8'||a== '9' )
			{
				str[0] = a;
				P_W = P_W*10+(a-'0');
			
    	  OLED_ShowStr(i,4,str,2);				
	  	  i = i+8;	
		while(JUZHEN_Scan(0) == a);
			}	
			
			 delay_ms(50);
	  }
		
		
      OLED_ShowStr(0,2,"                    ",2);
			for(i=4;i<9;i++)
			OLED_ShowCN(24+(i-4)*16,2,i);//��ʾ ����������
		  OLED_ShowCN(24+1*16,2,20);//ȷ----��
		  OLED_ShowCN(24+2*16,2,21);//��----��
		 OLED_ShowStr(0,4,"                    ",2);	
		
		
		 delay_ms(100);
		//ȷ������
		pw = 1;
		i = 0;
		while(JUZHEN_Scan(0) != 'D')
	  {
       a = JUZHEN_Scan(0);
		if(a== '0'||a== '1'||a== '2'||a== '3'||a== '4'||a== '5'||a== '6'||a== '7'||a== '8'||a== '9' )
			{
				str[0] = a;
				pw = pw*10+(a-'0');
			
    	  OLED_ShowStr(i,4,str,2);				
	  	  i = i+8;	
		while(JUZHEN_Scan(0) == a);
			}	
				 delay_ms(50);
			
	  }
		if(P_W == pw)
		{
  	PW = P_W;
	 OLED_ShowStr(0,2,"               ",2);
	 OLED_ShowStr(0,4,"               ",2);
	 OLED_ShowCN(16,2,7);//��
	 OLED_ShowCN(16+16,2,8);//��
	 OLED_ShowCN(16+2*16,2,18);//��
	 OLED_ShowCN(16+3*16,2,19);//��
	 OLED_ShowCN(16+4*16,2,13);//��
	 OLED_ShowCN(16+5*16,2,14);//��
		 delay_ms(1000);
		}
		else
		{
		   
			OLED_ShowStr(0,2,"                    ",2);
	    OLED_ShowStr(0,4,"                    ",2);
			OLED_ShowCN(24,2,7);//��
	    OLED_ShowCN(24+16,2,8);//��
			for(i=22;i<25;i++)
			OLED_ShowCN(24+(i-20)*16,2,i);//��ʾ ��һ��
		 delay_ms(1000);
			OLED_ShowStr(0,2,"                    ",2);
		}
		
  }
 } //if  B
	
 }

}
}
/*
		for(i=0;i<5;i++)
	  {
			OLED_ShowCN(21+i*16,0,i);//������ʾ����
		}
		for(i=5;i<10;i++)
	  {
			OLED_ShowCN(21+(i-5)*16,2,i);//������ʾ����
		}
		
		for(i=10;i<15;i++)
	  {
			OLED_ShowCN(21+(i-10)*16,4,i);//������ʾ����
		}
		
	
	//	OLED_ShowStr(0,3,"Lv",1);//����6*8�ַ�
	//	OLED_ShowStr(0,4,"Lv",2);				//����8*16�ַ�
	//DelayS(2);
//		OLED_CLS();//����
	//	OLED_OFF();//����OLED����
	//	DelayS(2);
	//	OLED_ON();//����OLED���ߺ���
	

	*/


