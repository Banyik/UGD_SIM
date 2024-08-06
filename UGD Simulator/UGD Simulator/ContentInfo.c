#include "ContentInfo.h"
#include "base.h"

unsigned long c_id = 0;

ContentInfo* initialize_content_info() {
	ContentInfo* contentInfo = malloc(sizeof(ContentInfo));
	if (contentInfo == NULL) {
		errlog("ContentInfo.c : FAILED TO ALLOCATE CONTENT_INFO MEMORY");
	}
	contentInfo->id = c_id++;
	contentInfo->views = 0;
	contentInfo->contentCreatorId = 0;
	contentInfo->contentType = 0;
	contentInfo->dislikes = 0;
	contentInfo->likes = 0;
	contentInfo->length = rand() % 1000;
	contentInfo->popularity = (rand() % 100) * 0.01f;
	contentInfo->categories = (unsigned short*){ NULL };
};