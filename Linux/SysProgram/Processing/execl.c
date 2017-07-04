#include <unistd.h>

int main()
{
	execl("/bin/ps", "ps", "-ef", NULL);
    execlp("ps", "ps", "-aux", NULL);
	char* argvs[] = {"ps", "-ef", NULL};
	execv("ps", argvs);

	return 0;
}
