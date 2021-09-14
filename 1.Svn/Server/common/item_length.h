///Add
#include "service.h"

//Find
	ITEM_BELT,				//34 є§Ж®

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	ITEM_MEDIUM,			//35 (Move Costume Attr)
#endif

//Find
enum EMetinSubTypes
{
	...
};

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
enum EMediumSubTypes
{
	MEDIUM_MOVE_COSTUME_ATTR,
	MEDIUM_MOVE_ACCE_ATTR,
};
#endif

//Find
	USE_PUT_INTO_RING_SOCKET,			// 30

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	USE_RESET_COSTUME_ATTR,				// 31
	USE_CHANGE_COSTUME_ATTR,			// 32
#endif