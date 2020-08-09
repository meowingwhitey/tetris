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
//���� ���ӿ��� ���� �̵����θ� üũ�ؾߵ�
//��ȯ�� 1 -> ���̵�O
//��ȯ�� 0 -> ���̵�X
int moveBlock(int** map, int key, Block* block);

//�� ȸ��
//��ȸ�� - z, ctrl
//��ȸ�� - x, ��
int rotateBlock(int** map, int key, Block* block);

//�� ����ü ���� �Ҵ�
Block * generateBlock(void);

//������ �� ����
void deleteBlock(Block *block);

//�� �̵��ÿ� �浹 Ž��
int isBlockCollision(int ** map, Block *block, COORD diff);

//���� �ʿ� �Է½�Ŵ
int fixBlock(int ** map, Block *block);

//���� �̵� �������� ���� üũ
int isBlockMovable(int ** map, Block *block);

//���� �ٴ����� ���� üũ
int isBlockBottom(int ** map, Block * block);

#endif //BLOCK_H