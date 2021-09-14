//Find
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen())

///Change
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
						|| IsItemComb()
#endif
					)

//Find
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen())

///Change
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
						|| pkChrCauser->IsItemComb()
#endif
					)

//Find
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen()))

///Change
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen())
#if defined(__BL_MOVE_COSTUME_ATTR__)
						|| IsItemComb()
#endif
					)

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
			|| IsItemComb()
#endif
		)

//Find
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
			|| IsItemComb()
#endif
		)

//Find
	if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
	if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
		|| IsItemComb()
#endif
	)