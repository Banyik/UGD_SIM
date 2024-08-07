#include "ContentHandler.h"
#include "base.h"
#include "UserHandler.h"
#include <time.h>
#include <stdio.h>

#define MIN_CONTENT 100000
#define MAX_CONTENT 500000


int contentAmount = 0;
int contentIndex = 0;

Array CONTENT_contents;
Array CONTENT_choosenContents;

void create_content_properties() {
	srand(time(NULL));
	contentAmount = (rand() % (MAX_CONTENT - MIN_CONTENT + 1)) + MIN_CONTENT;
	new_array(&CONTENT_contents, sizeof(Content), contentAmount);

	for (size_t i = 0; i < CONTENT_contents.length; i++)
	{
		Content* c = malloc(sizeof(Content));
		c->contentInfo = initialize_content_info();
		CONTENT_contents.Add(&CONTENT_contents, c, i);
	}
}

void interact_with_random_content(User u) {
	CONTENT_choosenContents = (Array){ 0 };
	new_array(&CONTENT_choosenContents, sizeof(Content), 6);
	for (size_t i = 0; i < CONTENT_choosenContents.length; i++)
	{
		contentIndex = rand() % contentAmount;
		CONTENT_choosenContents.Add(&CONTENT_choosenContents, CONTENT_contents.Get(&CONTENT_contents, contentIndex), i);
	}
	Content choosenContent = get_best_content();
	ContentInfo choosenContentInfo = *choosenContent.contentInfo;
	float pop = get_item_percentage(choosenContentInfo);
	choosenContent.contentInfo->views++;
	u.userActionInfo->tickToFinish += choosenContent.contentInfo->length;

	logn_a("User ", (char* []) { to_string(&u.userInfo->id, INT), 
								" started watching content with ID: ", 
								to_string(&choosenContent.contentInfo->id, INT), 
								"; Views: ", to_string(&choosenContent.contentInfo->views, INT), 
								"; POP: ", 
								to_string(&pop, FLOAT),
								NULL });
	CONTENT_choosenContents.Free(&CONTENT_choosenContents);
	CONTENT_choosenContents = (Array){ 0 };
}

Content get_best_content() {
	int index = 0;
	float minPercentage = 0;
	for (size_t i = 0; i < CONTENT_choosenContents.length; i++)
	{
		Content c = *(Content*)CONTENT_choosenContents.Get(&CONTENT_choosenContents, i);
		ContentInfo cInfo = *c.contentInfo;
		float percentage = get_item_percentage(cInfo);
		if (percentage > minPercentage) {
			index = i;
		}
	}
	Content c = *(Content*)CONTENT_choosenContents.Get(&CONTENT_choosenContents, index);
	return c;
}