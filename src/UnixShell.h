#ifndef UNIXSHELL_H_
#define UNIXSHELL_H_


#include <string>
using namespace std;
class Shell{
public:
	// launch shell
	void runShell();
private:
	// run command in background or not
	bool background{false};
	// convert user input to valid form command
	const char** parseInput(string input);
	// execute command
	void executeCommand(const char **&command);
	// handle interrupt of child process when it terminate
	void static signalHandler(int sign);
	// implement cd built-in command
	void cd(const char *path);
	// clear the log file when the shell created
	void clearLog();
};



#endif /* UNIXSHELL_H_ */
