#include "character.h"
#include <stdio.h>
#include <string.h>

// 全局角色数组
//extern Character characters[20];
// 已建立角色数量
//extern int character_count;

// 创建新角色，成功返回1，失败返回0
int create_character(const char* name) 
{
    if (character_count >= 20) return 0; // 角色数组已满，创建失败
    Character new_character;
    strcpy_s(new_character.name, sizeof(name),name);
    new_character.level = 1;
    new_character.energy = 100;
    new_character.friends = NULL;
    for (int i = 0; i < 5; i++) new_character.skills[i] = 0;
    characters[character_count++] = new_character;
    return 1;
}

// 获取角色信息，返回Character结构体指针
Character* get_character(const char* name) 
{
    for (int i = 0; i < character_count; i++) 
    {
        if (strcmp(characters[i].name, name) == 0) return &characters[i];
    }
    return NULL; // 未找到角色，返回空指针
}

// 角色完成某一类任务后，更新角色的相应技能点数
int update_character_reward(const char* name, int task_type, int reward) 
{
    Character* character = get_character(name);
    if (character == NULL) return 0; // 角色不存在，更新失败
    character->skills[task_type] += reward;
    return 1;
}

// 根据角色的技能点数判断该角色是否能更新状态
int can_level_up(Character* character) 
{
    for (int i = 0; i < 5; i++) 
    {
        if (character->skills[i] >= 10) return 1;
    }
    return 0;
}

// 更新角色状态（等级和能量）
int update_character_status(const char* name) 
{
    Character* character = get_character(name);
    if (character == NULL) return 0; // 角色不存在，更新失败
    if (can_level_up(character)) 
    {
        character->level++;
        character->energy += 10;
        return 1;
    }
    return 0;
}
