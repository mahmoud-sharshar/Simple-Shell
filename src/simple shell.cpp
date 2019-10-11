//============================================================================
// Name        : simple.cpp
// Author      : Mahmoud sharshar
// Version     :
// Copyright   : Your copyright notice
// Description : simple shell involving some commands in unix environment
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include<sstream>
#include<vector>

using namespace std;
const char** parseInput(string input);
void executeCommand(const char **&command);
void cd(const char *path);
int main() {
	string input;
	while (true) {
		cout << "simple shell$ ";
		//wait for user input
		getline(cin, input);
		// parse user input
		const char **command = parseInput(input);
		// execute command
		executeCommand(command);
		// free location of command after excution
		delete[] command;
	}

	return 0;
}

// split string input to construct the corresponding command
const char** parseInput(string input) {
	stringstream ss(input);
	// create vector to hold parts of input
	vector<string> words;
	while (ss) {
		string word;
		ss >> word;
		words.push_back(word);
	}
	// create dynamic array of type char array to hold parts of command
	const char **command = new const char*[words.size()];

	for (int i = 0; i < (int) words.size(); i++) {
		if (i < (int) words.size() - 1)
			command[i] = words[i].c_str();
		else
			command[i] = NULL; // insert null to the end of command
	}
	return command;
}

// execute command using fork and execvp
void executeCommand(const char **&command) {
	// terminate the shell if exit command is entered
	if (strcmp(command[0], "exit") == 0) {
		exit(0);
	}
	// cd command is a built_in command in shell
	if (strcmp(command[0], "cd") == 0) {
		cd(command[1]);
		return;
	}
	// create child process
	pid_t pid = fork();
	if (pid == 0) {
		// if the command fail to execute, execvp will return -1.
		// otherwise, it will never return
		if (execvp(command[0], (char* const*) command) < 0) {
			// show the context of the error in the commands
			perror(command[0]);
			exit(1); // this will terminate the child process only
		}
	} else if (pid > 0) {
		int status_loc;
		waitpid(pid, &status_loc, WUNTRACED);
	} else {
		perror("Fork failed");
		exit(1); // this will terminate the entire program
	}
}
// execute cd command
void cd(const char *path) {
	if (chdir(path) < 0) {
		perror(path);
	}
}
