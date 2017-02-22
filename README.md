# puget sound shell (psh)
The fourth homework assignment for CSCI 475 Operating Systems. This assignment implements a shell. The goal is to provide an interactive, command-line interface to the OS.

# Usage
Users may use the puget sound shell to run executables. These executables may be located relative to the current relative directory, in which case they should be run by entering their path relative to the current directory prepended with a `/`. Executables may also be located in the user's `PATH`, in which case they should be run by entering their base name without a prepending `/`. Arguments may be supplied after specifying an executable. Providing an `&` as the last argument will cause the process to run in the background. Otherwise, foreground execution will take place; a shell prompt will not appear until the running process is complete. Note that user input is capped at 256 characters.

Additionally, the following commands are implemented by the shell:
* `exit` terminates the shell.
* `pwd` prints the current working directory.
* `cd [path]` changes the current working directory. If `path` is not given, then the shell will change the current working directory to the user's home directory.
* `history` prints the most recent commands executed, up to the 100 most recent commands.

The puget sound shell can be run, after compiling, by entering `./psh` at the command prompt. Unit tests may be run by entering `./runtest` at the command prompt.

# Authorship
Matthew Moreno

Professor David Chiu

# Due
March 3, 2017
