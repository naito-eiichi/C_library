#ifndef EI1710_UTILITY_H
#define EI1710_UTILITY_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//fscanf()�Ɠ����@�\ �������A�ϊ��Ɏ��s�����������o�b�t�@�Ɏc��Ȃ�
int finput(FILE *source, const char *format, ...);

#endif
