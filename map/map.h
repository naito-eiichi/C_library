#ifndef EI1710_MAP_H
#define EI1710_MAP_H


//����������AVL��
//�܂��A�v�f�̏d���͋����Ȃ�(�L�[��������ꍇ�A�l���X�V)

typedef struct map_node {
	void *data;
	int diff;
	struct map_node *left;
	struct map_node *right;
} MapNode;

typedef MapNode *Map;


void Map_init(Map *map, size_t key_size, size_t data_size,
void rotate(MapNode **node, char mode);


#endif
