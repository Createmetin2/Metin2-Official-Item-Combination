//Find
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
		|| ch->IsItemComb()
#endif
	)