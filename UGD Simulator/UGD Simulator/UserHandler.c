#include "UserInfo.h"
#include "UserHandler.h"
#include <stdio.h>

void create_user_properties() {
	struct User user;
	user.userInfo = *initialize_info();
};