#include "stdFnames.h"

// 0x004845b0
char* stdFnames_FindMedName(char* path)
{
    char* pcVar1;
    char* res;

    res = _strrchr(path, '\\');

    if (res != NULL)
    {
        while ((res)[1] == '\\')
        {
            res = res + 1;
        }
        return res;
    }
    return path;
}

// 0x004845e0
char* stdFnames_FindExt(char* path)
{
    char* result = _strrchr(stdFnames_FindMedName(path), '.');
    if (result == NULL)
    {
        return NULL;
    }
    return result + 1;
}

// 0x00484600
int stdFnames_ChangeExt(char* str, char* ext)
{
    char* result = stdFnames_FindExt(str);
    if (result != NULL)
    {
        return NULL;
    }
    _strcat(str, ".");
    _strcat(str, ext);
    return 1;
}

// 0x00484670
char* stsdFnames_StripExtAndDot(char* str)
{
    char* result = stdFnames_FindExt(str);
    if (result != NULL)
    {
        result[-1] = 0;
    }
    return result;
}

// 0x00484690
char* stdFnames_Concat(char* left, char* right, int bufferLen)
{
    int len_;

    int lenPlusOne = _strlen(left) + 1;
    len_ = lenPlusOne - 1;

    if (left[lenPlusOne - 2] != '\\' && len_ < bufferLen - 1 && left[0] != '\0')
    {
        left[len_] = '\\';
        left[lenPlusOne] = '\0';
        len_ = lenPlusOne;
    }

    _strncat(left, right, bufferLen - len_ - 1);
    return left;
}

// 0x004846e0
void stdFnames_MakePath(char* str, int bufferLen, char* str2, char* extension)
{
    _strncpy(str, str2, bufferLen - 1);
    str[bufferLen - 1] = '\0';
    stdFnames_Concat(str, extension, bufferLen);
}
