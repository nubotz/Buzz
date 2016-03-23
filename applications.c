#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

#define LED_OFF 0
#define LED_ON  1


void buff_freq_1(){
	int  fd;
	char input;

	fd = open("/dev/pwm_buzzer", O_WRONLY);

	write(fd, &input, 1);	
	finish:	
	close(fd);	
}





void led1_ctl(int i)
{
	int  fd;
	char input;

	fd = open("/dev/pwm_buzzer", O_WRONLY);
	if(fd == -1)
	{
		printf("Fail to open device lab5_1!\n");
		goto finish;	
	}
	if(i == LED_ON)
	{
		input = '1';
	}
	else
	{
		input = '0';
	}
	write(fd, &input, 1);	
finish:	
	close(fd);	
}

void led2_ctl(int i)
{
	int  fd;
	char input;

	fd = open("/dev/lab5_2", O_WRONLY);
	if(fd == -1)
	{
		printf("Fail to open device lab5_2!\n");
		goto finish;	
	}
	if(i == LED_ON)
	{
		input = '1';
	}
	else
	{
		input = '0';
	}
	write(fd, &input, 1);
finish:			
	close(fd);	
}

void led3_ctl(int i)
{
	int  fd;
	char input;

	fd = open("/dev/lab5_3", O_WRONLY);
	if(fd == -1)
	{
		printf("Fail to open device lab5_3!\n");
		goto finish;	
	}
	if(i == LED_ON)
	{
		input = '1';
	}
	else
	{
		input = '0';
	}
	write(fd, &input, 1);	
finish:		
	close(fd);	
}

void led4_ctl(int i)
{
	int  fd;
	char input;

	fd = open("/dev/lab5_4", O_WRONLY);
	if(fd == -1)
	{
		printf("Fail to open device lab5_4!\n");
		goto finish;	
	}
	if(i == LED_ON)
	{
		input = '1';
	}
	else
	{
		input = '0';
	}
	write(fd, &input, 1);
finish:		
	close(fd);	
}

int main(void)
{
	int  key_fd;
	char current_values[1];
	int  ret;
	
	key_fd = open("/dev/lab6", O_RDONLY);
	while(1)
	{
		ret = read(key_fd, current_values, sizeof(current_values) );
		if (ret != sizeof(current_values) ) 
		{
			printf("Read key error:\n");
			goto finish;
		}
		if(current_values[0] == '1')
		{
			//buff_freq_1
		}
		else if(current_values[0] == '2')
		{
			//buff_freq_2
		} 
		else if(current_values[0] == '3')
		{
			//buff_freq_3
		} 
		else if(current_values[0] == '4')
		{
			//buff_off
		} 
	}	
	
finish:		
	close(key_fd);	
	return 0;
}
