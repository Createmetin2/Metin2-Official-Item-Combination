///Add
#define __BL_MOVE_COSTUME_ATTR__

//Find
		"ITEM_BELT",								//35개 (EItemTypes 값으로 치면 34)
	
///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
		"ITEM_MEDIUM",								//36 (EItemTypes 35) (Move Costume Attr)
#endif

//Find
				"USE_ADD_ATTRIBUTE2", "USE_RECIPE", "USE_CHANGE_ATTRIBUTE2", "USE_BIND", "USE_UNBIND", "USE_TIME_CHARGE_PER", "USE_TIME_CHARGE_FIX", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET");

///Change
				"USE_ADD_ATTRIBUTE2", "USE_RECIPE", "USE_CHANGE_ATTRIBUTE2", "USE_BIND", "USE_UNBIND", "USE_TIME_CHARGE_PER", "USE_TIME_CHARGE_FIX", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET"
#if defined(__BL_MOVE_COSTUME_ATTR__)
				, "USE_RESET_COSTUME_ATTR", "USE_CHANGE_COSTUME_ATTR"
#endif
				};

//Find
	static string arSub31[] = { "EXTRACT_DRAGON_SOUL", "EXTRACT_DRAGON_HEART" };

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	static string arSub35[] = { "MEDIUM_MOVE_COSTUME_ATTR", "MEDIUM_MOVE_ACCE_ATTR" };
#endif

//Find
	static string* arSubType[] = {0,	//0
		...
	};
	static int arNumberOfSubtype[_countof(arSubType)] = {
		...
	};
	
///Change
	static string* arSubType[] = {0,	//0
		arSub1,		//1
		arSub2,	//2
		arSub3,	//3
		arSub4,	//4
		arSub5,	//5
		arSub6,	//6
		arSub7,	//7
		arSub8,	//8
		0,			//9
		arSub10,	//10
		0,			//11
		arSub12,	//12
		0,			//13
		arSub14,	//14
		0,			//15
		arSub16,	//16
		0,			//17
		0,			//18
		0,			//19
		0,			//20
		0,			//21
		0,			//22
		0,			//23
		0,			//24
		0,			//25
		0,			//26
		0,			//27
		arSub28,	//28
		arSub29,		//29
		arSub29,	//30
		arSub31,	//31
		0,			//32
		0,			//33 №ЭБц
		0,			//34 ?§Ж®
#if defined(__BL_MOVE_COSTUME_ATTR__)
		arSub35,    //35 (Move Costume Attr)
#endif
	};
	static int arNumberOfSubtype[_countof(arSubType)] = {
		0,
		sizeof(arSub1)/sizeof(arSub1[0]),
		sizeof(arSub2)/sizeof(arSub2[0]),
		sizeof(arSub3)/sizeof(arSub3[0]),
		sizeof(arSub4)/sizeof(arSub4[0]),
		sizeof(arSub5)/sizeof(arSub5[0]),
		sizeof(arSub6)/sizeof(arSub6[0]),
		sizeof(arSub7)/sizeof(arSub7[0]),
		sizeof(arSub8)/sizeof(arSub8[0]),
		0,
		sizeof(arSub10)/sizeof(arSub10[0]),
		0,
		sizeof(arSub12)/sizeof(arSub12[0]),
		0,
		sizeof(arSub14)/sizeof(arSub14[0]),
		0,
		sizeof(arSub16)/sizeof(arSub16[0]),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(arSub28)/sizeof(arSub28[0]),
		sizeof(arSub29)/sizeof(arSub29[0]),
		sizeof(arSub29)/sizeof(arSub29[0]),
		sizeof(arSub31)/sizeof(arSub31[0]),
		0, // 32
		0, // 33 №ЭБц
		0, // 34 ?§Ж®
#if defined(__BL_MOVE_COSTUME_ATTR__)
		sizeof(arSub35) / sizeof(arSub35[0]),    // 35 (Move Costume Attr)
#endif
	};