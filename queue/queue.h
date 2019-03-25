#ifndef EI1710_Queue_H
#define EI1710_Queue_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���`���X�g��Queue����������
//���X�g�̐擪����f�[�^�����o���A
//���X�g�̖����Ƀf�[�^��ǉ����Ă���

typedef struct que_cell{
    void *data;  //���f�[�^�ւ̃|�C���^
    struct que_cell *next;  //���Z��
} QueCell;

typedef struct queue {
    QueCell *head; //�L���[�̐擪(�f�[�^�̎��o���ʒu)
    QueCell *last; //�L���[�̖���(�f�[�^�̊i�[�ʒu)

    size_t data_size; //�i�[�f�[�^�̑傫��
    size_t que_length; //�i�[�f�[�^�̌� = �L���[�̑傫��
} Queue;

//Queue�\���̂̏��������s��
//q:����������Queue�\���̂ւ̃|�C���^
//data_size:�i�[����f�[�^�̑傫��
//Queue���g���O�ɕK���Ăяo�����ƁI
// ex) int�^���i�[����ꍇ) Queue_init(&que, sizeof(int));
void Queue_init(struct queue *q, const size_t data_size);

//enque
//q:����Ώۂ�Queue�ւ̃|�C���^
//data:�i�[�f�[�^�ւ̃|�C���^
//�������i�[�ł���ΐ��� �G���[���N�����Ƃ�0��Ԃ�
int Queue_enque(struct queue *q, void *data);

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
