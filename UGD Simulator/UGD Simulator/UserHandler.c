#include "UserHandler.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "ContentHandler.h"

#define MIN_USERS 100000
#define MAX_USERS 500000

int userAmount = 0;

Array USER_users;

void create_user_properties() {
    srand(time(NULL));
	userAmount = (rand() % (MAX_USERS - MIN_USERS + 1)) + MIN_USERS;
    new_array(&USER_users, sizeof(User), userAmount);
    for (size_t i = 0; i < USER_users.length; i++)
    {
        User* u = malloc(sizeof(User));
        u->userInfo = initialize_info();
        u->userActionInfo = initialize_action_info();
        u->userPersonality = initialize_personality();
        u->favoriteMusicCategories = initialize_favorite_music_categories();
        u->favoriteVideoCategories = initialize_favorite_video_categories();
        USER_users.Add(&USER_users, u, i);
    }
};

void update_users(unsigned long currentTick) {
    for (size_t i = 0; i < USER_users.length; i++)
    {
        User u = *(User*)USER_users.Get(&USER_users, i);
        if (u.userActionInfo->tickToFinish <= currentTick) {
            u.userActionInfo->tickToFinish = currentTick;
            interact_with_random_content(u);
        }
    }
}

void clean_users() {
    USER_users.Free(&USER_users);
}