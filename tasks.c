#include "tasks.h"

int complete_task(const char *name, TaskType type,int reward) {
    // 检索角色
    Character *character = retrieve_character(name);
    if (!character) {
        // 角色不存在，返回0表示任务未完成
        printf("error:未找到角色\n");
        return 0;
    }

    // 可以考虑reward的值不能是负数
    /*if (reward < 0) {
        return 2;
    }   */
    // 要和main.c的小组说一下调整一下代码，能printf("课程参加失败，请检查回报是否正确。\n")

    // 根据任务类型更新技能点数
    // 注意：我们假设skills数组的下标与TaskType枚举的顺序一致
    if (type >= 0 && type < 5) {

        character->skills[type] += reward;
        //complete_task(name,type,reward);
        // 还可以考虑添加逻辑来限制技能点数的最大值，例如：
        /*if (character->skills[type] > PROGRESS_THRESHOLD) {
        /    character->skills[type] = PROGRESS_THRESHOLD;
        } */
        // 但这好像不是我们的活

        printf("任务完成成功！角色 %s 获得了提升。\n", name);

        // 任务完成，返回1
        return 1;
    } else {
        // 无效的任务类型，返回0表示任务未完成
        return 0;
    }
}


