//�� 
#ifndef BLOCK_H
#define BLOCK_H
#include "lib.h"
typedef struct _Block {
	//���� Ÿ�� ex) ��������� ������
	int type;
	//ȸ�� Ƚ��
	int rotate;
	//���� ���� ��ġ
	COORD pos;
}Block;
//�� ������ ��ġ�� map�� ������
void settingBlock(int** map, Block* block);
//�� ��ġ �̵�
void moveBlock(int** map, int key, Block* block);
//�� ����ü ���� �Ҵ�
Block * generateBlock(void);
//������ �� ����
void deleteBlock(Block *block);
#endif //BLOCK_H