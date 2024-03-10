# Pipex

### This project will let you discover in detail a UNIX mechanism that you already know by using it in your program.

This project is about handling pipes.

## How to use

clone the repository
```bash
git clone https://github.com/pyven-dr/pipex.git
```
compile
```bash
make
```

The program behave exactly the same as this shell command
```bash
< infile cmd1 | cmd2 > outfile
```
You can use it like this
```bash
./pipex infile cmd1 cmd2 oufile
```

All the errors are handle like the shell command

The program can handle multiple pipe like this command
```bash
< infile cmd1 | cmd2 | ... | cmdn > outfile
```

You can use it like this
```bash
./pipex infile cmd1 cmd2 ... cmdn outfile
```
