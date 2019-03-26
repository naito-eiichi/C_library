#ifndef EI1710_VECTOR_H
#define EI1710_VECTOR_H

#include "../utility/utility.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char Byte;

//vector������@
//memcopy(), memmove()�ŃI�u�W�F�N�g���R�s�[
//�v�f�ւ̃A�N�Z�X��sizeof(Type) * index �o�C�g����̗v�f�����Ď���
//���炩���ߑ傫�ڂɗ̈������Ă����A�L���p�V�e�B�I�[�o�[������realloc()����

typedef struct vector {
    Byte *storage; //�z��̈�

    size_t data_size; //�i�[�f�[�^�^�̃T�C�Y
    size_t array_size; //�i�[�f�[�^�̌�
    size_t capacity; //realloc()�����Ɋi�[�ł���f�[�^��
} Vector;

//vector�̏�����
int Vector_init(struct vector *vec, size_t data_size, size_t vec_size);

//vector�����Ƀf�[�^��ǉ�
int Vector_push_back(struct vector *vec, void *data);

//vector���Ǘ�����f�[�^�ɃA�N�Z�X
void *Vector_array(struct vector *vec, size_t i);

//vector���N���A
void Vector_clear(struct vector *vec);

//vector�Ɋi�[���Ă���f�[�^�̌���Ԃ�
size_t Vector_size(struct vector *vec);

//�L���p�V�e�B��Ԃ�
size_t Vector_capacity(struct vector *vec);


// int
#define int_Vector_init(Vec, Arr_size) \
	Vector_init(Vec, sizeof(int), Arr_size)

#define int_Vector_push_back(Vec, Data) \
	Vector_push_back(Vec, &(int){Data})

#define int_Vector_array(Vec, Indx) \
	*(int *)Vector_array(Vec, Indx)

//long long
#define llong_Vector_init(Vec, Arr_size) \
	Vector_init(Vec, sizeof(long long), Arr_size)

#define llong_Vector_push_back(Vec, Data) \
	Vector_push_back(Vec, &(long long){Data})

#define llong_Vector_Array(Vec, Indx) \
	*(long long *)Vector_array(Vec, Indx)

//double
#define dbl_Vector_init(Vec, Arr_size) \
	Vector_init(Vec, sizeof(double), Arr_size)

#define dbl_Vector_push_back(Vec, Data) \
	Vector_push_back(Vec, &(double){Data})

#define dbl_Vector_array(Vec, Indx) \
	*(double *)Vector_array(Vec, Indx)

#endif
