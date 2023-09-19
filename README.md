
### Usage

Invoke **hsh** either interactively or non-interactively. For interactive mode, simply execute the compiled program. For non-interactive mode, provide a file containing commands as an argument.

Examples:
- Interactive mode: `./hsh`
- Non-interactive mode: `./hsh script_file`

### Key Environment Variables

**hsh** inherits and copies the parent process's environment, including key variables:
- `HOME`: Home directory of the user.
- `PWD`: Current working directory.
- `OLDPWD`: Previous working directory.
- `PATH`: Colon-separated list of directories to search for executable commands.

### Command Execution

Upon receiving a command, **hsh** tokenizes it into words using spaces as delimiters. The first word represents the command, while subsequent words are treated as its arguments. **hsh** performs the following actions:
1. Checks if the command is a built-in.
2. Searches for the command in the PATH directories.
3. Executes the command with its arguments.

### Exit Status

**hsh** returns the exit status of the last executed command. Zero indicates success, and non-zero indicates failure.

### Signals

In interactive mode, **hsh** disregards Ctrl+C but recognizes the end-of-file input (Ctrl+D) as an exit command.

### Variable Replacement

**hsh** interprets the `$` character for variable replacement:
- `$ENV_VARIABLE`: Substituted with the corresponding value.
- `$?`: Replaced with the exit status of the last command.
- `$$`: Substituted with the current process ID.

### Comments

**hsh** ignores everything after a `#` character on a line.

### Operators

**hsh** interprets special operator characters:
- `;`: Sequentially executes commands separated by a semicolon.
- `&&`: Executes the second command only if the first succeeds.
- `||`: Executes the second command only if the first fails.

### Built-in Commands

- `cd`: Changes the current directory.
- `alias`: Handles command aliases.
- `exit`: Exits the shell.
- `env`: Prints the current environment.
- `setenv`: Initializes or modifies an environment variable.
- `unsetenv`: Removes an environment variable.

## Authors

- Emmanuel Oyiti

