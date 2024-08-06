#include <stdlib.h>
#include "UserInfo.h"
#include "base.h";

unsigned long u_id = 0;

UserInfo* initialize_info() {
	UserInfo* userInfo = malloc(sizeof(UserInfo));
	if (userInfo == NULL) {
		errlog("UserInfo.c : FAILED TO ALLOCATE USER_INFO MEMORY");
	}
	userInfo->id = u_id++;
	userInfo->age = 5;
	userInfo->gender = 0;
	userInfo->identity = 0;
	userInfo->ideology = 0;
	userInfo->nationality = 0;
	userInfo->race = 0;
	return userInfo;
};

ActionInfo* initialize_action_info() {
	ActionInfo* userActionInfo = malloc(sizeof(ActionInfo));
	if (userActionInfo == NULL) {
		errlog("UserInfo.c : FAILED TO ALLOCATE USER_ACTION_INFO MEMORY");
	}
	userActionInfo->tictToFinish = 0;
	return userActionInfo;
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
