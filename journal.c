#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// const number of seconds in a day
const int DAY = 86400;

int main(int argc, char *argv[])
{
	
	// formatting the date into a string
	time_t rawtime = time(NULL);
	if (argc > 1 && strncmp("yesterday", argv[1], 9) == 0)
		rawtime -= DAY;

	struct tm today = *localtime(&rawtime);
	char date_str[20];
	strftime(date_str, 20, "%Y/%B/%d\n", &today);

	// putting the journal path together
	char journal_path[90];
	strncat(journal_path, getenv("HOME"), 50);
	strncat(journal_path, "/Documents/journal/", 20);
	strncat(journal_path, date_str, 20);
	
	// for when the file doesn't exist
	

	// executing the text editor on the journal path
	char command[100] = "gedit ";
	strncat(command, journal_path, 90);
	system(command);

	return 0;
}
