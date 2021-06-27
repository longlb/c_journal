#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <regex.h>

// const number of seconds in a day
const int DAY = 86400;

// void get_date(char *buf, char *arg)
// {
// 	regex_t date_regex;
// 	char *pattern = "^20[:number:][-/](0[:number:]|1[012])[-/](0[:number:]|[12][:number:]|3[01])$";
// 	regcomp(&date_regex, pattern, 0);

// 	if strn
// }

int reg_test(char *inp)
{
	regex_t date_regex;
	regcomp(&date_regex, "^20[0-9][0-9][-/](0[1-9]|1[012])[-/](0[1-9]|[12][0-9]|3[01])$", REG_EXTENDED);
	return regexec(&date_regex, inp, 0, NULL, 0) ? 0 : 1;
}

int main(int argc, char *argv[])
{
	char date_str[20];
	if (argc > 1 && reg_test(argv[1]))
		strncpy(date_str, argv[1], 20);
	else
	{
		time_t rawtime = time(NULL);
		if (argc > 1)
		{
			if (strncmp("yesterday", argv[1], 10) == 0)
				rawtime -= DAY;
			else if (strncmp("twodaysago", argv[1], 11) == 0)
				rawtime -= DAY * 2;
		}
		struct tm today = *localtime(&rawtime);
		strftime(date_str, 20, "%Y/%B/%d\n", &today);
	}

	// putting the journal path together
	char journal_path[90];
	strncat(journal_path, getenv("HOME"), 50);
	strncat(journal_path, "/Documents/journal/", 20);
	strncat(journal_path, date_str, 20);

	// for when the file doesn't exist

	// executing the text editor on the journal path
	char command[100] = "gedit ";
	strncat(command, journal_path, 90);
	printf("%s\n", command);
	system(command);

	return 0;
}
