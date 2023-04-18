#include <REGX52.H>

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

#define DS1302_SECOND		0x80			//写秒命令
#define DS1302_MINUTE		0x82			//写分钟
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86
#define DS1302_MONTH		0x88
#define DS1302_DAY			0x8A
#define DS1302_YEAR			0x8c
#define DS1302_WP			0x8E			//写保护


unsigned char DS1302_Time[]={23,4,18,10,8,59};
void DS1302_Init(void)
{
	DS1302_CE=0;//	初始化
	DS1302_SCLK=0;
}
//:
/**
  * @brief  写一个字节
  * @param  参数命令和要写入的数据
  * @retval  返回值无
  */
void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i=0;
	DS1302_CE=1;//将CE置1
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);//数据从地位写
		DS1302_SCLK=1;
		DS1302_SCLK=0;		
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
		DS1302_CE=0;
}
//:
/**
  * @brief  读一个数据
  * @param  参数命令
  * @retval 返回值一个数据
  */
unsigned char DS1302_ReadByte(unsigned char Command)
{
		unsigned char Data=0;
		unsigned char i;
		Command|=0x01;//将命令最后一位置1改为读命令
		DS1302_CE=1;
		for(i=0;i<8;i++)//写入命令
		{
			DS1302_IO=Command&(0x01<<i);
			DS1302_SCLK=0;
			DS1302_SCLK=1;
		
		}
		for(i=0;i<8;i++)//读取数据
		{
			DS1302_SCLK=1;
			DS1302_SCLK=0;
			if(DS1302_IO){Data|=(0x01<<i);}//IO交给从机控制，从低位开始读
	
		}
			DS1302_CE=0;
			DS1302_IO=0;//读完一个数据置0
			return Data;
}
//:
/**
  * @brief  设置时间
  * @param  参数无
  * @retval 返回值无
  */
void SetTime(void)
{
	
//	DS1302_WriteByte(DS1302_WP,0x00);
//	DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);//十进制转BCD码后写入
//	DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
//	DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
//	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
//	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
//	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
//	DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
//	DS1302_WriteByte(DS1302_WP,0x80);
	DS1302_WriteByte(0X8E,0X00);//写入写保护命令
	DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);//将数组中存放的时间复给时间
	DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP,0X00);

}
//:
/**
  * @brief  读取时间
  * @param  无
  * @retval 无
  */
void DS1302_ReadTime()
{
	unsigned char Temp;
	Temp=DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6]=Temp/16*10+Temp%16;

}
//void DS1302_Init(void)
//{
//	DS1302_CE=0;
//	DS1302_SCLK=0;
//}

///**
//  * @brief  DS1302写一个字节
//  * @param  Command 命令字/地址
//  * @param  Data 要写入的数据
//  * @retval 无
//  */
//void DS1302_WriteByte(unsigned char Command,Data)
//{
//	unsigned char i;
//	DS1302_CE=1;
//	for(i=0;i<8;i++)
//	{
//		DS1302_IO=Command&(0x01<<i);
//		DS1302_SCLK=1;
//		DS1302_SCLK=0;
//	}
//	for(i=0;i<8;i++)
//	{
//		DS1302_IO=Data&(0x01<<i);
//		DS1302_SCLK=1;
//		DS1302_SCLK=0;
//	}
//	DS1302_CE=0;
//}

///**
//  * @brief  DS1302读一个字节
//  * @param  Command 命令字/地址
//  * @retval 读出的数据
//  */
//unsigned char DS1302_ReadByte(unsigned char Command)
//{
//	unsigned char i,Data=0x00;
//	Command|=0x01;	//将指令转换为读指令
//	DS1302_CE=1;
//	for(i=0;i<8;i++)
//	{
//		DS1302_IO=Command&(0x01<<i);
//		DS1302_SCLK=0;
//		DS1302_SCLK=1;
//	}
//	for(i=0;i<8;i++)
//	{
//		DS1302_SCLK=1;
//		DS1302_SCLK=0;
//		if(DS1302_IO){Data|=(0x01<<i);}
//	}
//	DS1302_CE=0;
//	DS1302_IO=0;	//读取后将IO设置为0，否则读出的数据会出错
//	return Data;
//}