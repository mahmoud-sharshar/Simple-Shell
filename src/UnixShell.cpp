/*
 * UnixShell.cpp
 *
 *  Created on: Oct 11, 2019
 *      Author: mahmoud_sharshar
 */

#include "UnixShell.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include<sstream>
#include<vector>
#include <csignal>
#include <fstream>

void Shell::runShell() {
	string input;
	signal(SIGCHLD,signalHandler);
	while (true) {
		cout << "simple shell$ ";
		//wait for user input
		getline(cin, input);
		// parse user input
		const char **command = parseInput(input);
		// Handle empty input
		if (!command[0])
			continue;
		// execute command
		executeCommand(command);
		background = false;
		// free location of command after excution
		delete[] command;
	}
}
// split string input to construct the corresponding command
const char** Shell::parseInput(string input) {
	stringstream ss(input);
	// create vector to hold parts of input
	vector<string> words;
	while (ss) {
		string word;
		ss >> word;
		words.push_back(word);
	}
	// if user want to run process in backgroud
	if (words[words.size() - 2] == "&") {
		background = true;
		words.pop_back();
	}
	// create dynamic array of type char array to hold parts of command
	const char **command = new const char*[words.size()];

	for (int i = 0; i < (int) words.size() - 1; i++) {
		command[i] = words[i].c_str();
	}
	// insert null to the end of command
	command[words.size() - 1] = NULL;
	return command;
}

// execute command using fork and execvp
void Shell::executeCommand(const char **&command) {
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
	} else if (pid > 0 && !background) {
		int status_loc;
		waitpid(pid, &status_loc, WUNTRACED);
	} else if (pid < 0) {
		perror("Fork failed");
		exit(1); // this will terminate the entire program
	}
}
// execute cd command
void Shell::cd(const char *path) {
	if (chdir(path) < 0) {
		perror(path);
	}
}

// signal handler routine
void Shell::signalHandler(int sig) {
	ofstream logFile;
	logFile.open("logfile.txt", std::ios_base::app);
	logFile << "Child process was terminated .\n";
	logFile.close();
}
