# Simple-Shell
a simple shell program that executes some commands of unix-enivornment.
#Introduction
A Unix shell​ is a command-line interpreter or ​ shell​ that provides a command line user
interface for Unix​ -like operating systems. The s ​ hell​ is both an interactive command
language and a scripting language, and is used by the operating system to control the
execution of the system using s ​ hell​ scripts.
Requirements
It is required to implement a Unix shell program. A shell is simply a program that
conveniently allows you to run other programs.
Your shell must support the following:
  1. The internal shell command "exit" which terminates the shell
      ○ Concepts​ : shell commands, exiting the shell.
      ○ System​ calls: exit()
  2. A command with no arguments
      ○ Example​ : ls, cp, rm ...etc
      ○ Details​ : Your shell must block until the command completes and, if
                  the return code is abnormal, print out a message to that effect.
      ○ Concepts​ : Forking a child process, waiting for it to complete and
                  synchronous execution.
      ○ System calls:​ fork(), execvp(), exit(), wait()
   3. A command with arguments
      ○ Example​ : ls –l
      ○ Details​ : Argument 0 is the name of the command.
      ○ Concepts​ : Command-line parameters.
   4. A command, with or without arguments, executed in the background
        using &.
      ○ Example​ : firefox &
      ○Details​ : In this case, your shell must execute the command and
                return immediately, not blocking until the command finishes.
      ○ Concepts​ : Background execution, signals, signal handlers, processes
                  and asynchronous execution.
#Organization of Code
There are three parts of the project :
    1. UnixShell.h : declares class Shell and all its associated functions without
                    implementation, acts like an interface.
    2. UnixShell.cpp : defines the class Shell and all its methods with detailed
                      implementation and commented code.
    3. Main.cpp : creates an object from the Class Shell and execute the Shell
                  program.
