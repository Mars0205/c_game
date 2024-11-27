#ifndef MANAGE_H_INCLUDED
#define MANAGE_H_INCLUDED

#include "data.h"
#include "social.h"
#include "character.h"

//保存当前游戏状态
extern int save_game(const char *filename);

//加载游戏状态
extern int load_game(const char *filename);

//释放动态分配内存
extern void free_memory(void);

#endif // MANAGE_H_INCLUDED
