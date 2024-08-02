#include <stdlib.h>
#include "UserInfo.h"

struct Info* initialize_info() {
	struct Info* p_userInfo = malloc(sizeof(struct Info));

	return p_userInfo;
};

struct Personality* initialize_personality() {
	struct Personality* p_userPersonality = malloc(sizeof(struct Info));

	return p_userPersonality;
};

struct FavoriteVideoCategories* initialize_favorite_video_categories() {
	struct FavoriteVideoCategories* p_userVideoCategories = malloc(sizeof(struct FavoriteVideoCategories));

	return p_userVideoCategories;
};

struct FavoriteMusicCategories* initialize_favorite_music_categories() {
	struct FavoriteVideoCategories* p_userMusicCategories = malloc(sizeof(struct FavoriteVideoCategories));

	return p_userMusicCategories;
};
