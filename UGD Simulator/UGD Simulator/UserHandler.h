#pragma once
#include "UserInfo.h"

typedef struct {
	Info* userInfo;
	Personality* userPersonality;
	FavoriteVideoCategories* favoriteVideoCategories;
	FavoriteMusicCategories* favoriteMusicCategories;
} User;

void create_user_properties();