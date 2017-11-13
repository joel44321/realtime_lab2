#include "MKW41Z4.h"
#include "Net_Config_SLIP.h"
#include "Net_Config_TCP.h"

int main (void)
{
	int sock_num;
	
	SystemCoreClockUpdate();
	LED_Initialize();
	netInitialize();
	
	netSLIP_Listen();
	
	while (!netSLIP_LinkUp()) {}
	sock_num = netTCP_GetSocket (1);
	if (sock_num >= 0) {
		netTCP_Listen (sock_num, 100);
	}
	
	for(;;){}
}