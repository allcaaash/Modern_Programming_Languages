#pragma once
class CStringHelper
{
public:
	static int strlen(char* str);
	static void strcpy(char* strDestination, const char* strSource);
	static bool strcmp(char* str1, char* str2);
	static void strcat(char*& str1, char* str2);
};

