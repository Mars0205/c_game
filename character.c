#include "character.h"
#include <stdio.h>
#include <string.h>


// 在角色数据库中创建新角色，成功返回1，失败返回0（已满）
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

// 角色完成某一类任务后，更新角色的相应技能点数
int update_character_reward(const char* name, int task_type, int reward) 
{
    Character* character = retrieve_character(name);
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
    Character* character = retrieve_character(name);
    if (character == NULL) return 0; // 角色不存在，更新失败
    if (can_level_up(character)) 
    {
        character->level++;
        character->energy += 10;
        return 1;
    }
    return 0;
}
