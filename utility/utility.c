//�������X�g����1byte����cp�ɃR�s�[
void *vmemcpy(void *cp, va_list org, size_t size) 
{
	va_list dat;
	unsigned char byte;

	//org �� dat �R�s�[, org�ւ̕���p�𖳂���
	va_copy(dat, org);

	while(size--) {
		byte = va_arg(dat, unsigned char);
		cp[size] = byte;
	}

	return cp;
}

int finput(FILE *source, const char *format, ...)
{
    va_list arg;
    char buff[1024];
    int result;

    fgets(buff, sizeof(buff) - 1, source);

    va_start(arg, format);
    result = vsscanf(buff, format, arg);
    va_end(arg);

	return result;
}
