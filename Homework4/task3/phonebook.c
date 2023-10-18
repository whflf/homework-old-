#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

#define BOOK_FILE_NAME "book.txt"

char* getEntryBeginning(char* string, char* initial)
{
	while (*string != '\n' && string != initial)
	{
		string--;
	}
	return string;
}

void addEntry(Alloc* content)
{
	char name[51] = { 0 };
	char phone[21] = { 0 };
	printf("Enter the name (up to 50 characters): ");
	fscanf_s(stdin, "%s", name, 50);
	printf("Enter the phone (up to 20 characters): ");
	fscanf_s(stdin, "%s", phone, 20);
	size_t nameSize = strlen(name);
	size_t phoneSize = strlen(phone);
	size_t newSize = content->size + 2 + nameSize + phoneSize;
	char* newFileContent = realloc(content->allocPtr, newSize + 1);

	if (newFileContent)
	{
		content->allocPtr = newFileContent;
		memcpy(&content->allocPtr[content->size], name, nameSize);
		content->allocPtr[content->size + nameSize] = ':';
		memcpy(&content->allocPtr[content->size + 1 + nameSize], phone, phoneSize);
		content->allocPtr[newSize - 1] = '\n';
		content->allocPtr[newSize] = 0;
		content->size = newSize;
		printf("Entry \"%s\" added with phone number %s\nPress enter to continue...", name, phone);
	}
	else
	{
		printf("Fail. Couldn't reallocate memory.\nPress enter to return...");
	}
	getchar();
}

void printEntries(Alloc* content)
{
	if (content->size)
	{
		printf("Entries:\n%s\nPress enter to continue...", content->allocPtr);
	}
	else
	{
		printf("No entries found.\nPress enter to return...");
	}
	getchar();
}

void findPhoneByName(Alloc* content)
{
	char name[51] = { 0 };
	printf("Enter the name to find phone number (up to 50 characters): ");
	fscanf_s(stdin, "%s", name, 50);

	char* result = strstr(content->allocPtr, name);

	if (result != NULL)
	{
		char* newStr = malloc(strlen(result) + 1);
		if (newStr)
		{
			char* context = NULL;
			strcpy_s(newStr, strlen(result) + 1, result);
			size_t tokenLength = strlen(strtok_s(newStr, ":", &context));
			char* parsedStringPointer = newStr + tokenLength + 1;
			printf("Phone number for \"%s\": %s\nPress enter to continue...", name, strtok_s(parsedStringPointer, "\n", &context));
			free(newStr);
		}
		else
		{
			printf("Fail. Couldn't allocate memory.\nPress enter to return...");
		}
	}
	else
	{
		printf("Nothing was found for \"%s\".\nPress enter to return...", name);
	}
	getchar();
}

void findNameByPhone(Alloc* content)
{
	char phone[21] = { 0 };
	printf("Enter the phone number to find name (up to 20 characters): ");
	fscanf_s(stdin, "%s", phone, 20);

	char* initial = content->allocPtr;
	char* result = strstr(content->allocPtr, phone);

	if (result != NULL)
	{
		char* entryStart = getEntryBeginning(result, initial);
		char* newStr = malloc(strlen(entryStart) + 1);
		if (newStr)
		{
			char* context = NULL;
			strcpy_s(newStr, strlen(entryStart) + 1, entryStart);
			printf("Name for \"%s\": %s\nPress enter to continue...", phone, strtok_s(newStr, ":", &context));
			free(newStr);
		}
		else
		{
			printf("Fail. Couldn't allocate memory.\nPress enter to return...");
		}
	}
	else
	{
		printf("Nothing was found for %s.\nPress enter to return...", phone);
	}
	getchar();
}

void saveContentToFile(Alloc* content)
{
	FILE* file = NULL;
	fopen_s(&file, BOOK_FILE_NAME, "wb");
	if (file != NULL)
	{
		fwrite(content->allocPtr, 1, content->size, file);
		fclose(file);
	}
}