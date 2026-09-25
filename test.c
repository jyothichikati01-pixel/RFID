#include"interrupt.h"
#include"admin.h"
#include"rtc.h"
#include"uart1.h"
#include"uart1_function.h"
s32 hour,min,sec,date,month,year,day;
s8 str[11];
s8 DATA_FRAME[30];
u32 UART1_Fired;
extern u32 UART0_Fired;
s8 UART1_BUFFER[15];
u32 UART1_RX_LEN;
int main()
{
	Intilisation();
	InitializeSPI();
	InitLCD();
	RTC_Init();
	InitializeUART0();
	InitializeUART1();
	while(1)
	{
	  GetRTCTimeInfo(&hour,&min,&sec);
	  	CmdLCD(GOTO_LINE1_POS0);
		DisplayRTCTime(hour,min,sec);
		GetRTCDateInfo(&date,&month,&year);
		DisplayRTCDate(date,month,year);
		GetRTCDay(&day);
		DisplayRTCDay(day);
		//Receive_string_UART1(str,10);
	     if(UART1_Fired){

			UART1_Fired = 0;

			ExtractRFID(UART1_BUFFER);

			switch(check_admin(UART1_BUFFER)){

				case 'A' : admin();

						    CmdLCD(CLEAR_LCD);

						     break;

				case 'B' : user();

					       CmdLCD(CLEAR_LCD);

						   break;

				default  : CmdLCD(CLEAR_LCD);

						   StrLCD("  INVALID CARD");

						   delay_ms(1000);

						   break;

			}

		}

		

		//UART Interrupt testing code

		/*if(UART1_Fired){

			UART1_Fired = 0;

			CmdLCD(CLEAR_LCD);

			ExtractRFID(UART1_BUFFER);

			StrLCD(UART1_BUFFER);

			delay_ms(500);	      

			CmdLCD(CLEAR_LCD);

		}*/ 	
	}

}
