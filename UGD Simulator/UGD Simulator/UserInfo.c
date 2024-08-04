#include <stdlib.h>
#include "UserInfo.h"
#include "base.h";

Info* initialize_info() {
	Info* userInfo = malloc(sizeof(Info));
	if (userInfo == NULL) {
		errlog("UserInfo.c : FAILED TO ALLOCATE USER_INFO MEMORY");
	}
	userInfo->age = 5;
	userInfo->gender = 0;
	userInfo->identity = 0;
	userInfo->ideology = 0;
	userInfo->nationality = 0;
	userInfo->race = 0;
	return userInfo;
};

Personality* initialize_personality() {
	Personality* userPersonality = malloc(sizeof(Personality));
	if (userPersonality == NULL) {
		errlog("UserInfo.c : FAILED TO ALLOCATE USER_PERSONALITY MEMORY");
	}
	userPersonality->TODO = 0;
	return userPersonality;
};

FavoriteVideoCategories* initialize_favorite_video_categories() {
	FavoriteVideoCategories* userVideoCategories = malloc(sizeof(FavoriteMusicCategories));
	if (userVideoCategories == NULL) {
		errlog("UserInfo.c : FAILED TO ALLOCATE USER_VIDEO_CATEGORIES MEMORY");
	}
	userVideoCategories->TODO = 0;

	return userVideoCategories;
};

FavoriteMusicCategories* initialize_favorite_music_categories() {
	FavoriteMusicCategories* userMusicCategories = malloc(sizeof(FavoriteMusicCategories));
	if (userMusicCategories == NULL) {
		errlog("UserInfo.c : FAILED TO ALLOCATE USER_MUSIC_CATEGORIES MEMORY");
	}
	userMusicCategories->TODO = 0;

	return userMusicCategories;
};
