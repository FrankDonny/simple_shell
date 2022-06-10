#include "main.h"

/**
 * prompt - this function brings a prompt for the user to enter command
 */

void prompt(void)
{
	static int ft = 1;

	while (ft)
		ft = 0;
	printf("$ ");
}
