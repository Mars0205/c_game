#ifndef SOCIAL_H_INCLUDED
#define SOCIAL_H_INCLUDED

#include "character.h"

int send_message(const char *from_name, const char *to_name, char *message);

MessageList* receive_messages(const char *to_name);

int add_friend(const char *name, const char *friend_name);

void display_friends(const char *name);

void free_friends(Character *character);

#endif // SOCIAL_H_INCLUDED
