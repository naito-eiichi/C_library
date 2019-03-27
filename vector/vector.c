#include "vector.h"

//vector�̏�����
int Vector_init(Vector *vec, size_t data_size, size_t vec_size)
{
	vec->data_size = data_size;
	vec->capacity = 0;
	vec->array_size = 0;

	if (vec_size > 0) {
		vec->storage = calloc(vec_size, data_size);
		
		if (vec->storage == NULL) {
			return 0;
		} else {
			vec->capacity = vec_size;
			vec->array_size = vec_size;
		}
	} else {
		vec->storage = NULL;
	}

	return 1;
}

//vector�����Ƀf�[�^��ǉ�
int Vector_push_back(Vector *vec, void *data)
{
	size_t indx = vec->array_size;
	size_t new_capacity = max(vec->capacity + 1, vec->capacity * 2);
	Byte *new_storage;


	//�z��̍Ċm��
	if (indx >= vec->capacity) {
		new_storage = realloc(vec->storage,
				new_capacity * vec->data_size);

		if (new_storage == NULL) {
			return 0;
		} else {
			vec->storage = new_storage;
			vec->capacity = new_capacity;
		}

	}

	memcpy(vec->storage + (indx * vec->data_size), 
			data, 
			vec->data_size);

	vec->array_size = vec->array_size + 1;

	return 1;
}

//vector���Ǘ�����f�[�^�ɃA�N�Z�X
void *Vector_array(Vector *vec, size_t i)
{
	if (i >= vec->array_size || i < 0) {
		return NULL;
	} else {
		return (vec->storage + (vec->data_size * i));
	}
}

//vector�����̗v�f���폜
int Vector_pop_back(Vector *vec)
{
	if (vec->array_size == 0) {
		return 0;
	} else {
		vec->array_size--;
	}

	return 1;
}

//vector���N���A
void Vector_clear(Vector *vec)
{
	free(vec->storage);

	Vector_init(vec, vec->data_size, 0);

	return;
}

//vector�Ɋi�[���Ă���f�[�^�̌���Ԃ�
size_t Vector_size(Vector *vec)
{
	return vec->array_size;
}

//�L���p�V�e�B��Ԃ�
size_t Vector_capacity(Vector *vec)
{
	return vec->capacity;
}
