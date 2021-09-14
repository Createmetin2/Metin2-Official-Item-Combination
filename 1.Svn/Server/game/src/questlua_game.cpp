///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	int game_open_item_comb(lua_State* L)
	{
		const LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		if (ch)
			ch->OpenItemComb();

		return 0;
	}
#endif

//Find
			{ "open_web_mall",				game_web_mall					},

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
			{ "open_item_comb",				game_open_item_comb				},
#endif