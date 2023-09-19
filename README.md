
### Usage

Use an interactive or non-interactive **hsh** call. You need only run the compiled application in interactive mode. Give a command file as an input if you want non-interactive mode.

Examples:
- Interactive mode: `./hsh`
- Non-interactive mode: `./hsh script_file`

### Key Environment Parameters

Key variables and the environment of the parent process are inherited and copied by **hsh**.
'HOME' refers to the user's home directory.
- 'PWD': Present working directory.
'OLDPWD' stands for the previous working directory.
- "PATH": A list of folders to search for executable commands that are separated by commas.

### Execution of Command

A command is tokenized into words using spaces as delimiters by **hsh** after it has been received. The command is denoted by the first word; the command's arguments are denoted by the following words. The following things are done by **hsh**
1. Verifies that the command is an internal.
2. Looks through the directories in PATH for the command.
3. The command is executed together with its arguments.

### Exit Status

When a command is last run, **hsh** gives its exit status. Non-zero implies failure, and zero means success.

### Signals

While in interactive mode, **hsh** ignores Ctrl+C and interprets Ctrl+D as an exit command (end-of-file input).

### Replacement of Variable

The '$' character has the following meaning for variable replacement in **hsh**:
- '$ENV_VARIABLE': The relevant value was replaced.
- "$?": Replaced with the last command's exit status.
- '$$': The current process ID has been substituted with '$$'.

### Comments

Every character on a line following the '#' symbol is ignored by **hsh**.

### Operators

The special operator characters for **hsh** are as follows:
- ';': Executes commands one after the other in a sequential manner.
- "&&": Only executes the second command when the first command is successful.
- "||": Only runs the second command if the first one succeeds.

### Built-in Commands

- `cd`: Modifies the current directory.
- `alias`: Deals with command aliases.
- `exit`: Exits the shell.
- `env`: Shows the current environment..
- `setenv`: Creates or updates an environment variable.
- `unsetenv`: Destroys or clears a variable in the environment.

## Authors

- Emmanuel Oyiti

