#include "xparameters.h"
#include "xgpio.h"
#include "xutil.h"
  

//====================================================

int main (void) 
{

    XGpio led, push;
	int i, psb_check;
	
    xil_printf("-- Start of the Program --\r\n");
 
    XGpio_Initialize(&led, XPAR_LED_4BIT_DEVICE_ID);
	XGpio_SetDataDirection(&led, 1, 0x00000000);
	
	XGpio_Initialize(&push, XPAR_BTN_4BIT_DEVICE_ID);
	XGpio_SetDataDirection(&push, 1, 0xffffffff);
	
	while (1)
	{
	  psb_check = XGpio_DiscreteRead(&push, 1);
	  xil_printf("Push Buttons Status %x\r\n", psb_check);
	  
	  if(psb_check==0)
	  		  XGpio_DiscreteWrite(&led, 1,0);

	  if(psb_check==1)
		  XGpio_DiscreteWrite(&led, 1,1);
	  if(psb_check==2)
	  		  XGpio_DiscreteWrite(&led, 1,2);
	  if(psb_check==4)
	  	  	 XGpio_DiscreteWrite(&led, 1,4);
	  if(psb_check==8)
	  	  	 XGpio_DiscreteWrite(&led, 1,8);


	  for (i=0; i<9999999; i++); 
	}
 
}
 
