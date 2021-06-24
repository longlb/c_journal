#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// const number of seconds in a day
const int DAY = 86400;

int main(int argc, char *argv[])
{
	// getting today in a convertible string
	time_t rawtime = time(NULL);
	rawtime;
	struct tm today = *localtime(&rawtime);
	char date_str[20];
	strftime(date_str, 20, "%Y/%B/%d\n", &today);
	printf("%s\n", asctime(&today));
	printf("%s\n", date_str);

	// putting the command together
	char command[100];
	strncpy(command, "gedit ", 10);
	strncat(command, getenv("HOME"), 50);
	strncat(command, "/Documents/journal/", 20);
	strncat(command, date_str, 20);
	printf("%s\n", command);

	// executing on the final path
	system(command);

	return 0;
}
