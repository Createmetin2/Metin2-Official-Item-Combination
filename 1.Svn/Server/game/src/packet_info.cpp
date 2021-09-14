//Find
	Set(HEADER_CG_GUILD, sizeof(TPacketCGGuild), "Guild", true);

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	Set(HEADER_CG_ITEM_COMBINATION, sizeof(TPacketCGItemCombination), "ItemCombination", true);
	Set(HEADER_CG_ITEM_COMBINATION_CANCEL, sizeof(TPacketCGItemCombinationCancel), "ItemCombinationCancel", true);
#endif