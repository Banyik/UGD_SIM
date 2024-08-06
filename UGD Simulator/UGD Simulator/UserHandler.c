#include "UserHandler.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "ContentHandler.h"

#define MIN_USERS 100000
#define MAX_USERS 500000

int userAmount = 0;

User *users;

void create_user_properties() {
    srand(time(NULL));
	userAmount = (rand() % (MAX_USERS - MIN_USERS + 1)) + MIN_USERS;
    new_array(&users, sizeof(*users), userAmount);
    for (size_t i = 0; i < userAmount; i++)
    {
        if (&users[i] == NULL) {
            errlog("UserHandler.c : FAILED TO ALLOCATE USER MEMORY!");
        }
        User u = { 0 };
        u.userInfo = initialize_info();
        u.userActionInfo = initialize_action_info();
        u.userPersonality = initialize_personality();
        u.favoriteMusicCategories = initialize_favorite_music_categories();
        u.favoriteVideoCategories = initialize_favorite_video_categories();
        users[i] = u;
    }
};

void update_users(unsigned long currentTick) {
    for (size_t i = 0; i < userAmount; i++)
    {
        if (users[i].userActionInfo->tictToFinish <= currentTick) {
            users[i].userActionInfo->tictToFinish = currentTick;
            interact_with_random_content(users[i]);
        }
    }
}

void clean_users() {
    free(users);
}