#ifndef EI1710_STACK_H
#define EI1710_STACK_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

//���`���X�g�ŃX�^�b�N������

typedef struct stack_cell{
    void *data; //���f�[�^�̈���w��
    struct stack_cell *next; //���Z��
}StackCell;

typedef struct stack {
    StackCell *sp; //�f�[�^�̊i�[�A���o���ʒu

    size_t data_size; //�i�[����f�[�^�̑傫��
    size_t stack_size; //�i�[�f�[�^�̌� (=�X�^�b�N�̑傫��)
} Stack;

//Stack�\���̂̏�����
//Stack�Ɋi�[����f�[�^�^�́Adata_size�ő傫�����w�肵�Č���
//Stack���g���O�ɕK���Ăяo������!
void Stack_init(struct stack *s, size_t data_size);

//Stack�Ƀf�[�^���i�[
//data�͊i�[�f�[�^�ւ̃|�C���^
//�G���[:0 ����I��:����
int Stack_push(struct stack *s, const void *data);

//Stack����f�[�^�����o��
//data�͎��o�����f�[�^�̊i�[�̈�
//data���w���̈�̑傫�����s�\���ȏꍇ����͕s��
//�G���[:0 ����I��:����
int Stack_pop(struct stack *s, void *data);

//Stack�Ɋi�[����Ă���f�[�^����Ԃ�
size_t Stack_size(struct stack *s);

//Stack���N���A����
//Stack���g�������ƕK���Ăяo������!
void Stack_clear(struct stack *s);

#endif
