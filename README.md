# c_journal

Replacement to the original journal script I had written in Rust before. Function is the same, just made to blend with other Linux commands as a C binary.

## How to Use

It's best to add the journal binary to /usr/local/bin to have it as like a normal Linux command. You do that with a symbolic link using the command

`sudo ln -s path_to_journal /usr/local/bin/`

Command runs as follows:

`journal [yesterday | twodaysago | 'date']

yesterday: the previous day's entry.\
twodaysago: the entry two days ago.\
'date': enter a specific date and it will be accessed accordingly. CURRENTLY UNAVAILABLE
