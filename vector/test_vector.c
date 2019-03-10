#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char __Byte; //Byte�^���Ɗ����̌^���Ɣ�邩������Ȃ��̂�

//-------
//1�o�C�g����memcopy(), memmove()�ȂǂŃf�[�^���i�[
//�v�f�ւ̃A�N�Z�X��sizeof(Type) * index �o�C�g����̗v�f�����Ď���
//���炩���ߑ傫�ڂɗ̈������Ă����A�L���p�V�e�B�I�[�o�[������realloc()����
//-------
typedef struct vector {
    __Byte *storage;

    size_t data_size;
    size_t vec_size;
    size_t capacity;

    int  (*push_back)(struct vector *vec, void *data);
    int  (*array)(struct vector *vec, size_t i, void *data);
    void (*clear)(struct vector *vec);
    size_t (*size)(struct vector *vec);
} Vector;

int initVector(struct vector *vec, size_t vec_size, size_t data_size);
int Vec_push_back(struct vector *vec, void *data);
int Vec_array(struct vector *vec, size_t i, void *data);
void Vec_clear(struct vector *vec);
size_t Vec_size(struct vector *vec);

int initVector(struct vector *vec, size_t vec_size, size_t data_size)
{
    vec->data_size = data_size;
    vec->vec_size = 0;
    vec->capacity = vec_size;

    vec->storage = (__Byte*)malloc(data_size * vec_size);
    if (vec->storage == NULL) {
        return -1;
    }

    vec->push_back = Vec_push_back;
    vec->array = Vec_array;
    vec->clear = Vec_clear;
    vec->size = Vec_size;

    return 0;
}

int Vec_push_back(struct vector *vec, void *data)
{
    if (Vec_size(vec) + 1 <= vec->capacity) {
        memcpy(vec->storage + (vec->data_size * Vec_size(vec)), data, vec->data_size); 
        ++(vec->vec_size);

        return 0;
    } else {
        size_t new_capacity = (vec->capacity * 2 > vec->capacity + 1 ? vec->capacity * 2 : vec->capacity + 1);
        void *ptr;

        ptr = realloc(vec->storage, vec->data_size * new_capacity);

        if (ptr == NULL) {
            return -1;
        }

        memcpy(vec->storage + (vec->data_size * Vec_size(vec)), data, vec->data_size); 

        ++(vec->vec_size);
        vec->storage = ptr;
        vec->capacity = new_capacity;

        return 0;
    }
}

int Vec_array(struct vector *vec, size_t i, void *data)
{
    if (i < Vec_size(vec)) {
        memcpy(data, vec->storage + (vec->data_size * i), vec->data_size);
        return 0;
    } else {
        return -1;
    }
}

void Vec_clear(struct vector *vec)
{
    free(vec->storage);

    return;
}

size_t Vec_size(struct vector *vec)
{
    return vec->vec_size;
}
