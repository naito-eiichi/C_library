#ifndef EI1710_HEAP_H

#include "../vector/vector.h"

//vector��Ȥä���ʬ�ҡ���

typedef struct {
	Vector storage;
	int (*compare)(const void *, const void *);
} Heap;

//Heap��¤�Τν����
void Heap_init(Heap *heap, size_t data_size, int (*compare)(const void *, const void*));

//Heap�˥ǡ������ɲ�
int Heap_add(Heap *heap, void *);

//Heap����ǡ�������Ф�
//���Ф����ǡ����Ϻ�������
int Heap_top(Heap *heap, void *);

//Heap�˳�Ǽ����Ƥ���ǡ������������
size_t Heap_size(Heap *heap);

//Heap�򥯥ꥢ
void Heap_clear(Heap *heap);

#endif
