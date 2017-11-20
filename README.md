# Simple Shell

The following project is an attempt to create a replica of Ken Thompson's Unix
Shell. The goal of this project was to create a shell that would take basic
commands that are often used in Thompson's Unix Shell. Additionally, the current
iteration of my shell handles multiple arguments as well as the PATH allowing
the user to enter commands without specifying the absolute PATH. Finally,
this project handles botht the "env" and "exit" built-in.

Moving forward, I plan to clean up the code to simplify it and add more
functionality to increase the number of builtins.

## Getting Started

To get the shell running on your local machine, please clone the repo and have
everything specified in the prerequisites section.

## Prerequisites

* Ubuntu 14.04 LTS
* gcc 4.8.4(-Wall, -Werror, -Wextra, and -pedantic flags)

## Running the tests

To enter the interactive mode of my Simple Shell, you can run the executable:

```
./hsh
```

Otherwise, you can enter a non-interactive mode by using echo as specified
below:

echo "ls -l" | ./hsh

## Functionality

In the current iteration, there are only certain commands that works and below I
will specify the ones that will successfully work.

1. Builtins
	* exit
	* env
2. $PATH Commands

## Moving Forward

In the near future, I plan to add additional builtins like cd as well as handle
comments, the help builtin, and the history builtin.

## Work on Your Own Shell

You are free to fork this project and add any additionally functionality you
would like.

## Authors

Ramandeep Hundal - Holberton School

## License

The Simple Shell is released under the MIT License.
