#pragma once

typedef struct
{
	size_t size;
	char* allocPtr;
} Alloc;

char* getEntryBeginning(char* string, char initial);

void addEntry(Alloc* content);

void printEntries(Alloc* content);

void findPhoneByName(Alloc* content);

void findNameByPhone(Alloc* content);

void saveContentToFile(Alloc* content);