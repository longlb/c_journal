# c_journal

Replacement to the original journal script I had written in Rust before. Function is the same, just made to blend with other Linux commands as a C binary.

## How to Use

It's best to add the journal binary to /usr/local/bin to have it as like a normal Linux command. You do that with a symbolic link using the command

`sudo ln -s path_to_journal /usr/local/bin/`

Command runs as follows:

`journal ['integer' | 'date']`

'integer': any integer from -999 to +999, and will give the entry that many days backward or forward accordingly
'date': enter a specific date and it will be accessed accordingly. CURRENTLY UNAVAILABLE UNTIL DIGIT MONTHS IMPLEMENTED

## TODO:

- ~~convert yesterday and twodaysago inputs to want given integers instead, like -1 and -2~~
- ~~fix specific dates to allow both slashes and hyphens as delimeters~~
- convert digit months to word months for specific date
- create flags for the two above rather than just reading input as is
- make the README look more like a man page
- manually creating directory/files in case of different text editor that doesn't do that like gedit does
