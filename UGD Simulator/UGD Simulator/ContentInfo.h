#pragma once

typedef struct {
	unsigned long id;
	unsigned long length;
	unsigned long contentCreatorId;
	unsigned short contentType;
	unsigned short* categories;
	float popularity;
	unsigned long views;
	unsigned long likes;
	unsigned long dislikes;
} ContentInfo;

ContentInfo* initialize_content_info();