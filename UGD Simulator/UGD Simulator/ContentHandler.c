#include "ContentHandler.h"
#include "base.h"
#include "UserHandler.h"
#include <time.h>
#include <stdio.h>

#define MIN_CONTENT 100000
#define MAX_CONTENT 500000


int contentAmount = 0;
int contentIndex = 0;

Content* contents;

void create_content_properties() {
	srand(time(NULL));
	contentAmount = (rand() % (MAX_CONTENT - MIN_CONTENT + 1)) + MIN_CONTENT;
	new_array(&contents, sizeof(*contents), contentAmount);
	for (size_t i = 0; i < contentAmount; i++)
	{
		Content c = { 0 };
		c.contentInfo = initialize_content_info();
		contents[i] = c;
	}
}

void interact_with_random_content(User u) {
	Content* choosenContents = NULL;
	new_array(&choosenContents, sizeof(*choosenContents), 6);
	for (size_t i = 0; i < 6; i++)
	{
		contentIndex = rand() % contentAmount;
		choosenContents[i] = contents[contentIndex];
		//printf("%f", contents[contentIndex].contentInfo->popularity);
		logn_a("Content pop: ", (char* []) { to_string(&contents[contentIndex].contentInfo->popularity, FLOAT), NULL });
	}
	contents[contentIndex].contentInfo->views++;
	u.userActionInfo->tictToFinish += contents[contentIndex].contentInfo->length;

	//logn_a("User ", (char* []) { to_string(u.userInfo->id), " started watching content with ID: ", to_string(contents[contentIndex].contentInfo->id), "; Views: ", to_string(contents[contentIndex].contentInfo->views), NULL });
}