#include "UserHandler.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int currentIndex = 0;
User *users;

void create_user_properties() {
    srand(time(NULL));
	int n = rand();
    users = (User*)malloc(n * sizeof(User*));
    for (size_t i = 0; i < n; i++)
    {
        User *u = malloc(sizeof(User*));
        u->userInfo = initialize_info();
        u->userPersonality = initialize_personality();
        u->favoriteMusicCategories = initialize_favorite_music_categories();
        u->favoriteVideoCategories = initialize_favorite_video_categories();
        users[i] = *u;
        printf("%d\n", users[i].userInfo->age);
    }
};