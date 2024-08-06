#pragma once
#include "UserInfo.h"

typedef struct {
	UserInfo* userInfo;
	ActionInfo* userActionInfo;
	Personality* userPersonality;
	FavoriteVideoCategories* favoriteVideoCategories;
	FavoriteMusicCategories* favoriteMusicCategories;
} User;

void create_user_properties();

void update_users(unsigned long currentTick);

void clean_users();