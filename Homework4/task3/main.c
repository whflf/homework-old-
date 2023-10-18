#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

#define BOOK_FILE_NAME "book.txt"

void programLoop(Alloc* content)
{
	system("cls"); // clear console
	printf("Enter an operation code to continue:\n 0 - Exit\n 1 - Add an entry\n 2 - Print existing entries\n 3 - Find phone number by name\n 4 - Find name by phone number\n 5 - Save everything to database file\n> ");

	switch (getchar())
	{
	case '0':
		return;
	case '1':
		addEntry(content);
		break;
	case '2':
		printEntries(content);
		break;
	case '3':
		findPhoneByName(content);
		break;
	case '4':
		findNameByPhone(content);
		break;
	case '5':
		saveContentToFile(content);
		break;
	}
	getchar();
	programLoop(content);
}

int main()
{
	FILE* file = NULL;
	Alloc* fileContent = malloc(sizeof(Alloc));
	size_t fileSize = 0;
	fopen_s(&file, BOOK_FILE_NAME, "rb");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		fileSize = ftell(file);
		fseek(file, 0, SEEK_SET);
		if (fileContent)
		{
			fileContent->allocPtr = malloc(fileSize + 1);
			if (fileContent->allocPtr)
			{
				fileContent->size = fileSize;
				fread(fileContent->allocPtr, 1, fileSize, file);
				fileContent->allocPtr[fileSize] = 0;
			}
		}
		fclose(file);
	}
	else if (fileContent)
	{
		fileContent->allocPtr = malloc(1);
		if (fileContent->allocPtr) {
			*fileContent->allocPtr = 0;
			fileContent->size = 0;
		}
	}
	else
	{
		return 1;
	}
	programLoop(fileContent);
	return 0;
}
