#pragma once

struct Info{
	unsigned short race;
	unsigned short gender;
	unsigned short identity;
	unsigned short nationality;
	unsigned short age;
	unsigned short ideology;
};

struct Info* initialize_info();

struct Personality {
	//The Big Five Personalities
	unsigned short TODO;
};

struct Personality* initialize_personality();

struct FavoriteVideoCategories {
	unsigned short TODO;
};

struct FavoriteVideoCategories* initialize_favorite_video_categories();

struct FavoriteMusicCategories {
	unsigned short TODO;
};

struct FavoriteMusicCategories* initialize_favorite_music_categories();
