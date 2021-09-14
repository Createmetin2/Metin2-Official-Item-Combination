///Add
#include "../UserInterface/Locale_inc.h"

//Find
			ITEM_TYPE_BELT,						//34 벨트

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
			ITEM_TYPE_MEDIUM,				// 35 (Move Costume Attr)
#endif

//Find
			USE_PUT_INTO_RING_SOCKET,			// 30 반지 소켓에 사용할 수 있는 아이템 (유니크 반지 말고, 새로 추가된 반지 슬롯)

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
			USE_RESET_COSTUME_ATTR,				// 31
			USE_CHANGE_COSTUME_ATTR,			// 32
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