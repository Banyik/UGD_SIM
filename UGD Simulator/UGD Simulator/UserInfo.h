#pragma once

typedef struct{
	unsigned short race;
	unsigned short gender;
	unsigned short identity;
	unsigned short nationality;
	unsigned short age;
	unsigned short ideology;
} Info;

Info* initialize_info();

typedef struct{
	//The Big Five Personalities
	unsigned short TODO;
} Personality;

Personality* initialize_personality();

typedef struct{
	unsigned short TODO;
} FavoriteVideoCategories;

FavoriteVideoCategories* initialize_favorite_video_categories();

typedef struct{
	unsigned short TODO;
} FavoriteMusicCategories;

FavoriteMusicCategories* initialize_favorite_music_categories();
