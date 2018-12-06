/* This code takes the test input file in the same folder, reverses the contents of that file and inverts the case of each
English character in the file and stores the result in a new file within a new directory named “Assignment”. The file and directory thus created, can only be read/written
by the user who created it.*/
#include <unistd.h>
#include<stdio.h>
#include <fcntl.h>
int main()
{
	int i, fd0, fd1, fd2, fd3, fd4, fd5;
	i=0;
	fd0 = mkdir("Assignment", 0700);

	fd1=open("test.txt",O_RDONLY);

	char c;
	lseek(fd1,-1L-i,SEEK_END);
	//fd2 = open("test_output.txt",O_RDWR|O_CREAT|O_TRUNC,0700);
	fd2 = open("Assignment/output.txt",O_RDWR|O_CREAT|O_TRUNC,0700);
	while(lseek(fd1,-1L-(i),SEEK_END)!=-1)
	{
		read(fd1,&c,1);
		if (c>='A' && c<='Z')
			c = c + 'a' - 'A';
		else if (c>='a' && c<='z')
			c = c + 'A' - 'a';
		//    printf("%c",c);
		write(fd2, &c, 1);
		i++;
	}

	
	close(fd0);
	close(fd1);
	close(fd2);

	return 0;
}
