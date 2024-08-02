#pragma once
#include "UserInfo.h";

struct User {
	struct Info userInfo;
	struct Personality userPersonality;
	struct FavoriteVideoCategories favoriteVideoCategories;
	struct FavoriteMusicCategories favoriteMusicCategories;
};

void create_user_properties();