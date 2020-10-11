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
u32 PW=1111; //设置的password 初始密码为111
u32 P_W=1,pw=1; //输入的password 
//u8 n=0,j;// 
	
	
extern const unsigned char BMP0[];
extern const unsigned char BMP1[];
 TIM1_PWM_Init(2000-1,720-1);//不分频。PWM频率=10k//200=50hz 
	LED_Init();		  	 	//初始化与LED连接的硬件接口
	JUZHEN_Init();
	delay_init();
	I2C_Configuration();
  OLED_Init();
	
	
  OLED_CLS();//清屏
  PW =1111;
	

	
    while(1)
 {
/*
A  输入密码
B  修改密码
C  关锁
D  确认
*/ 
/***************欢迎光临****************/
	 

OLED_ShowStr(0,2,"                    ",2);	//清屏
      for(i=0;i<4;i++)
	  		OLED_ShowCN(32+i*16,2,i);//显示 欢迎光临
	
	
OLED_ShowStr(0,4,"                    ",2);	//清屏
///////////////////////////////////////////			
	 
	 { ///////////////////////////////////////////////
	while(JUZHEN_Scan(0)=='N');
/***************输入密码****************/
  if(JUZHEN_Scan(0) == 'A') //检测A键,按下进入输入密码模式
	{
		for(i=4;i<9;i++)
	  {
			OLED_ShowCN(24+(i-4)*16,2,i);//显示 请输入密码
		}
		OLED_ShowStr(0,4,"                    ",2);	
		
		pw = 1;
		i = 0;
	  while(JUZHEN_Scan(0) != 'D') //按D确认密码，跳出循环
	  {
       a = JUZHEN_Scan(0);
			if(a== '0'||a== '1'||a== '2'||a== '3'||a== '4'||a== '5'||a== '6'||a== '7'||a== '8'||a== '9' )
			{ 
				str[0] = a;
			pw = pw*10+(a -'0') ;
				
    	OLED_ShowStr(i,4,str,2);//显示输入的数字	
	  	i = i+8;	
		  }	
			while(JUZHEN_Scan(0)!='N');
			 delay_ms(100);
			
	  }
		
		OLED_ShowStr(0,4,"                    ",2);		//跳出while循环后清屏

	
	if( pw == PW ) // 输入密码等于设置密码
 {
	  OLED_ShowStr(0,2,"                    ",2);
	 for(i=7;i<11;i++)
	  {
			OLED_ShowCN(32+(i-7)*16,2,i);//显示 密码正确
		}
		
		
		
			TIM_SetCompare3(TIM1,250);	
			
		
		
		   LED = 0; //密码正确响应
		for(i=13;i<17;i++)
	  {
			OLED_ShowCN(32+(i-13)*16,4,i);//显示 成功关锁
		}
		OLED_ShowCN(32+2*16,4,17);//开替换关
	 

	 pw = 1;   //重置输入密码
while(JUZHEN_Scan(0)!='C');//按下C键，关锁，跳出循环
  }
 else
 {
	 OLED_ShowStr(0,2,"               ",2);
	 OLED_ShowCN(32,2,7);//密
	 OLED_ShowCN(32+16,2,8);//码
	 OLED_ShowCN(32+2*16,2,11);//错
	 OLED_ShowCN(32+3*16,2,12);//误
	 OLED_ShowStr(0,4,"               ",2);
	  delay_ms(1000);
 
 }
} 

 if(JUZHEN_Scan(0) == 'C')//关锁
  {
	LED = 1;
		
			TIM_SetCompare3(TIM1,50);	
		
   OLED_ShowStr(0,2,"                    ",2);
	 for(i=13;i<17;i++)
	  {
			OLED_ShowCN(32+(i-13)*16,2,i);//显示 成功关锁
		}
	OLED_ShowStr(0,4,"                    ",2);
		 delay_ms(1000);
		
  }


		
//设置密码
  if(JUZHEN_Scan(0) == 'B')
	{
		
		for(i=4;i<9;i++)
	  {
			OLED_ShowCN(24+(i-4)*16,2,i);//显示 请输入密码
		}
		OLED_ShowStr(0,4,"                    ",2);	
		
		pw = 1;
		i = 0;
	  while(JUZHEN_Scan(0) != 'D') //按D确认密码，跳出循环
	  {
       a = JUZHEN_Scan(0);
			if(a== '0'||a== '1'||a== '2'||a== '3'||a== '4'||a== '5'||a== '6'||a== '7'||a== '8'||a== '9' )
			{ 
				str[0] = a;
			pw = pw*10+(a -'0') ;
				
    	OLED_ShowStr(i,4,str,2);//显示输入的数字	
	  	i = i+8;	
		  }	
			while(JUZHEN_Scan(0) == a);
			
				 delay_ms(50);
	  }
		
		OLED_ShowStr(0,4,"                    ",2);		//跳出while循环后清屏

	   if(pw != PW)
		{
	 OLED_ShowStr(0,2,"               ",2);
	 OLED_ShowCN(32,2,7);//密
	 OLED_ShowCN(32+16,2,8);//码
	 OLED_ShowCN(32+2*16,2,11);//错
	 OLED_ShowCN(32+3*16,2,12);//误
	 OLED_ShowStr(0,4,"               ",2);
	  delay_ms(1000);
 
   }
		
		
/*******************密码输入正确后设置密码*********************/
		if( pw == PW ) // 输入密码等于设置密码
 {
	 
	 
	  OLED_ShowStr(0,2,"                    ",2);
	 for(i=7;i<11;i++)
			OLED_ShowCN(32+(i-7)*16,2,i);//显示 密码正确
		 delay_ms(500);
	
			
		OLED_ShowStr(0,2,"                    ",2);
		
			for(i=4;i<9;i++)
			OLED_ShowCN(24+(i-4)*16,2,i);//显示 请输入密码
		  
		  OLED_ShowCN(24+1*16,2,18);//设——输
		  OLED_ShowCN(24+2*16,2,19);//置----入
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
			OLED_ShowCN(24+(i-4)*16,2,i);//显示 请输入密码
		  OLED_ShowCN(24+1*16,2,20);//确----输
		  OLED_ShowCN(24+2*16,2,21);//认----入
		 OLED_ShowStr(0,4,"                    ",2);	
		
		
		 delay_ms(100);
		//确认密码
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
	 OLED_ShowCN(16,2,7);//密
	 OLED_ShowCN(16+16,2,8);//码
	 OLED_ShowCN(16+2*16,2,18);//设
	 OLED_ShowCN(16+3*16,2,19);//置
	 OLED_ShowCN(16+4*16,2,13);//成
	 OLED_ShowCN(16+5*16,2,14);//功
		 delay_ms(1000);
		}
		else
		{
		   
			OLED_ShowStr(0,2,"                    ",2);
	    OLED_ShowStr(0,4,"                    ",2);
			OLED_ShowCN(24,2,7);//密
	    OLED_ShowCN(24+16,2,8);//码
			for(i=22;i<25;i++)
			OLED_ShowCN(24+(i-20)*16,2,i);//显示 不一致
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
			OLED_ShowCN(21+i*16,0,i);//测试显示中文
		}
		for(i=5;i<10;i++)
	  {
			OLED_ShowCN(21+(i-5)*16,2,i);//测试显示中文
		}
		
		for(i=10;i<15;i++)
	  {
			OLED_ShowCN(21+(i-10)*16,4,i);//测试显示中文
		}
		
	
	//	OLED_ShowStr(0,3,"Lv",1);//测试6*8字符
	//	OLED_ShowStr(0,4,"Lv",2);				//测试8*16字符
	//DelayS(2);
//		OLED_CLS();//清屏
	//	OLED_OFF();//测试OLED休眠
	//	DelayS(2);
	//	OLED_ON();//测试OLED休眠后唤醒
	

	*/


