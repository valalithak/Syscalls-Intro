/* Code to create symlink and verify various permissions */
#include <unistd.h>
#include<stdio.h>
#include <fcntl.h>

int main()
{
   
    int i;
    int fd2 = open("Assignment/output.txt",O_RDWR|O_CREAT|O_TRUNC,0700);
	int fd5 = symlink("Assignment/output.txt", "Assignment/output_link.txt");
    int fd1=open("test.txt",O_RDONLY);
	// checking for directory

	if(access("Assignment",F_OK)!=-1)
	{
		const char msg[] = "Directory created : YES\n";
			write(1, msg, sizeof(msg)-1);

	}
	else
	{
		const char msg[] = "Directory created : NO\n";
			write(1, msg, sizeof(msg)-1);

	}
	if(fd2<0)
	{
		const char msg[] = "Output file created : NO\n";
			write(1, msg, sizeof(msg)-1);

	}
	else
	{
		const char msg[] = "Output file created : YES\n";
			write(1, msg, sizeof(msg)-1);

	}

	// Checking for symlink
	if(fd5 <0)
	{
		const char msg[] = "Symlink created : NO\n";
			write(1, msg, sizeof(msg)-1);

	}
	else
	{
		const char msg[] = "Symlink created : YES\n";
			write(1, msg, sizeof(msg)-1);

	}


	// checking if file contents have been inverted

	int flag = 0;
	char x1, x2;
	while(lseek(fd1,-1L-(i),SEEK_END)!=-1)
	{
		read(fd1,&x1,1);
		read(fd2,&x2,1);
		if (x1>='A' && x1<='Z')
		{
			if(x2 - x1 == 'A'-'a')
				continue;
			else
				flag = 1;
		}
		else if (x1>='a' && x2<='z')
		{
			if(x1 - x2 == 'a'-'A')
				continue;
			else
				flag = 1;
		}
		else
		{
			if(x1==x2)
				continue;
			else
				flag = 1;

		}
		i++;
	}

	if(flag==1)
	{
		const char msg[] = "File contents reversed and inverted : NO\n";
			write(1, msg, sizeof(msg)-1);

	}
	else
	{
		const char msg[] = "File contents reversed and inverted : YES\n";
			write(1, msg, sizeof(msg)-1);

	}


	// checking for permissions on file
	struct stat st;

	if(stat("Assignment/output.txt", &st) == 0){
		mode_t perm = st.st_mode;
	// USER

		if((perm & S_IRUSR) == 0)
		{
			const char msg[] = "File has user read permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has user read permissions :Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

		if((perm & S_IWUSR) == 0)
		{
			const char msg[] = "File has user write permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has user write permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

		if((perm & S_IXUSR) == 0)
		{
			const char msg[] = "File has user execute permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has user execute permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}


		// GROUP

		if((perm & S_IRGRP) == 0)
		{
			const char msg[] = "File has group read permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has group read permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

		if((perm & S_IWGRP) == 0)
		{
			const char msg[] = "File has group write permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has group write permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

		if((perm & S_IXGRP) == 0)
		{
			const char msg[] = "File has group execute permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has group execute permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}


		// OTHERS

		if((perm & S_IROTH) == 0)
		{
			const char msg[] = "File has others read permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has others read permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}


		if((perm & S_IWOTH) == 0)
		{
			const char msg[] = "File has others write permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has others write permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}
		if((perm & S_IXOTH) == 0)
		{
			const char msg[] = "File has others execute permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "File has others execute permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

	}
	// checking for permissions on directory
	struct stat st1;

	if(stat("Assignment", &st1) == 0){
		mode_t perm1 = st1.st_mode;


		// USER

		if((perm1 & S_IRUSR) == 0)
		{
			const char msg[] = "Directory has user read permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has user read permissions :Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

		if((perm1 & S_IWUSR) == 0)
		{
			const char msg[] = "Directory has user write permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has user write permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

		if((perm1 & S_IXUSR) == 0)
		{
			const char msg[] = "Directory has user execute permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has user execute permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}


		// GROUP

		if((perm1 & S_IRGRP) == 0)
		{
			const char msg[] = "Directory has group read permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has group read permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

		if((perm1 & S_IWGRP) == 0)
		{
			const char msg[] = "Directory has group write permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has group write permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}

		if((perm1 & S_IXGRP) == 0)
		{
			const char msg[] = "Directory has group execute permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has group execute permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}


		// OTHERS

		if((perm1 & S_IROTH) == 0)
		{
			const char msg[] = "Directory has others read permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has others read permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}


		if((perm1 & S_IWOTH) == 0)
		{
			const char msg[] = "Directory has others write permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has others write permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}


		if((perm1 & S_IXOTH) == 0)
		{
			const char msg[] = "Directory has others execute permissions : No\n";
			write(1, msg, sizeof(msg)-1);
		}
		else
		{
			const char msg[] = "Directory has others execute permissions : Yes\n";
			write(1, msg, sizeof(msg)-1);
		}


	}
//	close(fd0);
	close(fd1);
	close(fd2);
//	close(fd3);
//	close(fd4);
	close(fd5);

		return 0;
}
