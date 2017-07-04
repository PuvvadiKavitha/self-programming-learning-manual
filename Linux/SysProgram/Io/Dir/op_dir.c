#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


int main()
{
	DIR* dp = NULL;
	struct dirent* ep = NULL;

	dp = opendir(".//");
	if (dp != NULL)
	{
		while (ep = readdir(dp))
		{
			puts(ep->d_name);
		}
		closedir(dp);
	
	}
	else
	{
		perror("opendir failed\n");


	}
	close(dp);

	return 0;
}
