#include "juzhen.h"
#include "delay.h"
void JUZHEN_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PB端口时钟
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭jtag，使能SWD，可以用SWD模式调试
	
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;	//行 PB5-PB8  		 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3); 	
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;//列 PB9-PB12  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOB
	
}


//按键处理函数
//返回按键值
u8 JUZHEN_Scan(u8 jzmode)
{	 
	u8 hang = 0;
	u8 lie;
	u8 he;
	
/***************检测第1行*******************/
	hang = 1;
	H1 = 0,H2 = 1,H3 = 1,H4 = 1;
  if( L1==0 || L2==0 || L3==0 || L4==0 ) //有按键按下
	{
	  delay_ms(20);
		 if( L1==0 || L2==0 || L3==0 || L4==0 ) //有按键按下
		 {
			 
   if( L1==0 && L2==1 && L3==1 && L4==1 )//第1列按键按下
	  lie = 1;
	else if( L1==1 && L2==0 && L3==1 && L4==1 )//第2列按键按下
		lie = 2;
	else if( L1==1 && L2==1 && L3==0 && L4==1 )//第3列按键按下
		lie = 3;
	else if( L1==1 && L2==1 && L3==1 && L4==0 )//第4列按键按下
		lie = 4;
	else 
		lie = 0;
			 
			 
			he = hang*10 + lie;
	if(lie == 0)
		he = 0;
		 }
	}
	
/***************检测第2行*******************/
	hang = 2;
	H1 = 1,H2 = 0,H3 = 1,H4 = 1;
  if( L1==0 || L2==0 || L3==0 || L4==0 ) //有按键按下
	{
	  delay_ms(20);
		 if( L1==0 || L2==0 || L3==0 || L4==0 ) //有按键按下
		 {
	if( L1==0 && L2==1 && L3==1 && L4==1 )//第1列按键按下
	  lie = 1;
	else if( L1==1 && L2==0 && L3==1 && L4==1 )//第2列按键按下
		lie = 2;
	else if( L1==1 && L2==1 && L3==0 && L4==1 )//第3列按键按下
		lie = 3;
	else if( L1==1 && L2==1 && L3==1 && L4==0 )//第4列按键按下
		lie = 4;
	else 
		lie = 0;
			he = hang*10 + lie;
	if(lie == 0)
		he = 0;
		 }
	}
	
/***************检测第3行*******************/
	hang = 3;
	H1 = 1,H2 = 1,H3 = 0,H4 = 1;
  if( L1==0 || L2==0 || L3==0 || L4==0 ) //有按键按下
	{
delay_ms(20);
		 if( L1==0 || L2==0 || L3==0 || L4==0 ) //有按键按下
		 {
			 
	if( L1==0 && L2==1 && L3==1 && L4==1 )//第1列按键按下
	  lie = 1;
	else if( L1==1 && L2==0 && L3==1 && L4==1 )//第2列按键按下
		lie = 2;
	else if( L1==1 && L2==1 && L3==0 && L4==1 )//第3列按键按下
		lie = 3;
	else if( L1==1 && L2==1 && L3==1 && L4==0 )//第4列按键按下
		lie = 4;
	else 
		lie = 0;
			he = hang*10 + lie;
	if(lie == 0)
		he = 0;
		 }
	}
	
/***************检测第4行*******************/
	hang = 4;
	H1 = 1,H2 = 1,H3 = 1,H4 = 0;
  if( L1==0 || L2==0 || L3==0 || L4==0 ) //有按键按下
	{
	  delay_ms(20);
		 if( L1==0 || L2==0 || L3==0 || L4==0 ) //有按键按下
		 {
			 
	if( L1==0 && L2==1 && L3==1 && L4==1 )//第1列按键按下
	  lie = 1;
	else if( L1==1 && L2==0 && L3==1 && L4==1 )//第2列按键按下
		lie = 2;
	else if( L1==1 && L2==1 && L3==0 && L4==1 )//第3列按键按下
		lie = 3;
	else if( L1==1 && L2==1 && L3==1 && L4==0 )//第4列按键按下
		lie = 4;
	else 
	lie = 0;
			he = hang*10 + lie;
	if(lie == 0)
		he = 0;
		 }
	}
	

	//矩阵按键0-9	
	 switch(he)
	{
		case 0:
		he = 'N';			
		break;
		
		case 11:
		he = '1';			
		break;
		case 12:
		he = '2';		
		break;
		case 13:
		he = '3';		
		break;
		case 14:
		he = 'A';		
		break;
		
		case 21:
		he = '4';		
		break;
		case 22:
		he = '5';			
		break;
		case 23:
		he = '6';			
		break;
		case 24:
		he = 'B';		
		break;
		
		case 31:
	  he = '7';					
		break;
		case 32:
		he = '8';		
		break;
		case 33:
		he = '9';		
		break;
    case 34:
		he = 'C';		
		break;
		
		case 41:
	  he = '*';					
		break;
		case 42:
		he = '0';		
		break;
		case 43:
		he = '#';		
		break;
    case 44:
		he = 'D';		
		break;
		
		default: he = 'N';
	}
	
	
	
	return he;

}

