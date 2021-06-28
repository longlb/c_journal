#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <regex.h>

// the number of seconds in a day
const int DAY = 86400;
// regex to recognize dates
const char reg_date[] = "^20[0-9][0-9][/-](0[1-9]|1[012])[/-](0[1-9]|[12][0-9]|3[01])$";
// regex to recognize integers
const char reg_int[] = "^[+-][0-9]{1,3}$";

// check if a string is recognized by a given regular expression
int reg_test(char *inp, const char *reg_expr)
{
	regex_t reg;
	regcomp(&reg, reg_expr, REG_EXTENDED);
	return regexec(&reg, inp, 0, NULL, 0) ? 0 : 1;
}

// replace all instances of one char with another
void replace_hyphens(char *buf, char orig, char repl)
{
	for (int i = 0; i < strlen(buf); i++)
	{
		if (buf[i] == orig)
			buf[i] = repl;
	}
}

int main(int argc, char *argv[])
{
	// generating a date for the journal entry path
	char date_str[20];
	// save the input if it matches the specific date regex and replace hyphens with slashes
	if (argc > 1 && reg_test(argv[1], reg_date))
	{
		strncpy(date_str, argv[1], 20);
		replace_hyphens(date_str, '-', '/');
	}
	else // retrieve the current time and adjust it if there is an integer input
	{	 // get today's date in seconds
		time_t rawtime = time(NULL);
		// check for integer input and adjust the time according to it
		if (argc > 1 && reg_test(argv[1], reg_int))
			rawtime += atoi(argv[1]) * DAY;
		// convert ad save the time as a date string
		struct tm today = *localtime(&rawtime);
		strftime(date_str, 20, "%Y/%B/%d\n", &today);
	}

	// compile the file path to the journal entry
	char journal_path[90];
	strncpy(journal_path, getenv("HOME"), 50);
	strncat(journal_path, "/Documents/journal/", 20);
	strncat(journal_path, date_str, 20);

	// compile the command string then execute on it
	char command[100] = "gedit ";
	strncat(command, journal_path, 90);
	system(command);
	// printf("%s\n", command);

	return 0;
}
