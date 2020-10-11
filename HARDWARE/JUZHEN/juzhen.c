#include "juzhen.h"
#include "delay.h"
void JUZHEN_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PB�˿�ʱ��
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����
	
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;	//�� PB5-PB8  		 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3); 	
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;//�� PB9-PB12  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOB
	
}


//����������
//���ذ���ֵ
u8 JUZHEN_Scan(u8 jzmode)
{	 
	u8 hang = 0;
	u8 lie;
	u8 he;
	
/***************����1��*******************/
	hang = 1;
	H1 = 0,H2 = 1,H3 = 1,H4 = 1;
  if( L1==0 || L2==0 || L3==0 || L4==0 ) //�а�������
	{
	  delay_ms(20);
		 if( L1==0 || L2==0 || L3==0 || L4==0 ) //�а�������
		 {
			 
   if( L1==0 && L2==1 && L3==1 && L4==1 )//��1�а�������
	  lie = 1;
	else if( L1==1 && L2==0 && L3==1 && L4==1 )//��2�а�������
		lie = 2;
	else if( L1==1 && L2==1 && L3==0 && L4==1 )//��3�а�������
		lie = 3;
	else if( L1==1 && L2==1 && L3==1 && L4==0 )//��4�а�������
		lie = 4;
	else 
		lie = 0;
			 
			 
			he = hang*10 + lie;
	if(lie == 0)
		he = 0;
		 }
	}
	
/***************����2��*******************/
	hang = 2;
	H1 = 1,H2 = 0,H3 = 1,H4 = 1;
  if( L1==0 || L2==0 || L3==0 || L4==0 ) //�а�������
	{
	  delay_ms(20);
		 if( L1==0 || L2==0 || L3==0 || L4==0 ) //�а�������
		 {
	if( L1==0 && L2==1 && L3==1 && L4==1 )//��1�а�������
	  lie = 1;
	else if( L1==1 && L2==0 && L3==1 && L4==1 )//��2�а�������
		lie = 2;
	else if( L1==1 && L2==1 && L3==0 && L4==1 )//��3�а�������
		lie = 3;
	else if( L1==1 && L2==1 && L3==1 && L4==0 )//��4�а�������
		lie = 4;
	else 
		lie = 0;
			he = hang*10 + lie;
	if(lie == 0)
		he = 0;
		 }
	}
	
/***************����3��*******************/
	hang = 3;
	H1 = 1,H2 = 1,H3 = 0,H4 = 1;
  if( L1==0 || L2==0 || L3==0 || L4==0 ) //�а�������
	{
delay_ms(20);
		 if( L1==0 || L2==0 || L3==0 || L4==0 ) //�а�������
		 {
			 
	if( L1==0 && L2==1 && L3==1 && L4==1 )//��1�а�������
	  lie = 1;
	else if( L1==1 && L2==0 && L3==1 && L4==1 )//��2�а�������
		lie = 2;
	else if( L1==1 && L2==1 && L3==0 && L4==1 )//��3�а�������
		lie = 3;
	else if( L1==1 && L2==1 && L3==1 && L4==0 )//��4�а�������
		lie = 4;
	else 
		lie = 0;
			he = hang*10 + lie;
	if(lie == 0)
		he = 0;
		 }
	}
	
/***************����4��*******************/
	hang = 4;
	H1 = 1,H2 = 1,H3 = 1,H4 = 0;
  if( L1==0 || L2==0 || L3==0 || L4==0 ) //�а�������
	{
	  delay_ms(20);
		 if( L1==0 || L2==0 || L3==0 || L4==0 ) //�а�������
		 {
			 
	if( L1==0 && L2==1 && L3==1 && L4==1 )//��1�а�������
	  lie = 1;
	else if( L1==1 && L2==0 && L3==1 && L4==1 )//��2�а�������
		lie = 2;
	else if( L1==1 && L2==1 && L3==0 && L4==1 )//��3�а�������
		lie = 3;
	else if( L1==1 && L2==1 && L3==1 && L4==0 )//��4�а�������
		lie = 4;
	else 
	lie = 0;
			he = hang*10 + lie;
	if(lie == 0)
		he = 0;
		 }
	}
	

	//���󰴼�0-9	
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

