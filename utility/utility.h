#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//�������X�gorg�����f�[�^��cp��size�o�C�g���R�s�[
//�����悻 memcpy() �Ɠ���
void *vmemcpy(void *cp, va_list org, size_t size); 

//fscanf()�Ɠ����@�\ �������A�ϊ��Ɏ��s�����������o�b�t�@�Ɏc��Ȃ�
int finput(FILE *source, const char *format, ...);
