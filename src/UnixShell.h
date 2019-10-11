#ifndef UNIXSHELL_H_
#define UNIXSHELL_H_


#include <string>
using namespace std;
class Shell{
public:
	void runShell();
private:
	bool background{false};

	const char** parseInput(string input);

	void executeCommand(const char **&command);
	void static signalHandler(int sign);
	void cd(const char *path);
};



#endif /* UNIXSHELL_H_ */
