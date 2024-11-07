#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include "tasks.h"
#include "data.h"


/*创建新角色，成功返回1，失败返回0*/
int create_character(const char *name);

//获取角色信息，返回Character结构体指针
Character* get_character(const char *name);

// 角色完成某一类任务后，更新角色的相应技能点数
int update_character_reward(const char *name,int task_type, int reward);

// 根据角色的技能点数判断该角色是否能更新状态
int can_level_up(Character *character);

// 更新角色状态
int update_character_status(const char *name);




#endif // CHARACTER_H_INCLUDED
