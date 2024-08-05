#include "UserHandler.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

int userAmount = 0;

User *users;

void create_user_properties() {
    srand(time(NULL));
	userAmount = rand() % 50;
    users = new_array(&users, userAmount);
    for (size_t i = 0; i < userAmount; i++)
    {
        User u = { 0 };
        u.userInfo = initialize_info();
        u.userPersonality = initialize_personality();
        u.favoriteMusicCategories = initialize_favorite_music_categories();
        u.favoriteVideoCategories = initialize_favorite_video_categories();
        users[i] = u;
    }
};

void update_users() {
    for (size_t i = 0; i < userAmount; i++)
    {
        //printf("User ");
        //printf("%d", users[i].userInfo->id);
        //printf(" is updated\n");
    }
}

void clean_users() {
    free(users);
}