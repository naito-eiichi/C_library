#ifndef Ei1710_Queue_H
#define Ei1710_Queue_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���`���X�g��Queue����������

//���X�g�̃Z���\����
//data:���f�[�^�ւ̃|�C���^, next:���Z��
typedef struct que_cell{
    void *data; 
    struct que_cell *next; 
} QueCell;

//head:���Ƀf�[�^�����o���ʒu
//last:���Ƀf�[�^���i�[����ʒu (�̈�O)
//data_size:�i�[�f�[�^�̑傫��
//que_length:�i�[�f�[�^�̌� = �L���[�̑傫��
typedef struct queue {
    QueCell *head;
    QueCell *last;

    size_t data_size;
    size_t que_length;
} Queue;

//Queue�\���̂̏��������s��
//q:����������Queue�\���̂ւ̃|�C���^
//data_size:�i�[����f�[�^�̑傫��
//Queue���g���O�ɕK���Ăяo�����ƁI
// ex) int�^���i�[����ꍇ) Queue_init(&que, sizeof(int));
void Queue_init(struct queue *q, const size_t data_size);

//enque
//q:����Ώۂ�Queue�ւ̃|�C���^
//������:�i�[����f�[�^(�l�n��)
//�������i�[�ł���ΐ��� �G���[���N�����Ƃ�0��Ԃ�
int Queue_enque(struct queue *q, ...);

//deque
//q:����Ώۂ�Queue�ւ̃|�C���^
//data:���o�����f�[�^�̊i�[�ꏊ
//�L���[����(�G���[)�̂Ƃ�0, ����Ɏ��o�����Ƃ�������Ԃ�
//data���w���̈悪�f�[�^���i�[����̂ɑ���Ȃ��ꍇ�̓���͕s��ł���
int Queue_deque(struct queue *q, void *data);

//�L���[�Ɋi�[����Ă���f�[�^����Ԃ�
size_t Queue_size(struct queue *q);

//Queue���N���A����
//Queue���g���I�������K���Ăяo�����ƁI
void Queue_clear(struct queue *q);

#endif
