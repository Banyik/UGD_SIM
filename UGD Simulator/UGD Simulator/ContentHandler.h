#pragma once
#include "ContentInfo.h"
#include "UserHandler.h";

typedef struct {
	ContentInfo* contentInfo;
}Content;

void create_content_properties();
void interact_with_random_content(User u);
Content get_best_content();