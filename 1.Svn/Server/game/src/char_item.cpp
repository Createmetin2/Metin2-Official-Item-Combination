//Find
	if (IsCubeOpen() || NULL != DragonSoul_RefineWindow_GetOpener())
		return false;

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	if (IsItemComb())
		return false;
#endif

//Find
					case USE_ADD_ATTRIBUTE2:

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
					case USE_RESET_COSTUME_ATTR:
					case USE_CHANGE_COSTUME_ATTR:
#endif

//Find
							if (ITEM_COSTUME == item2->GetType())
							{
								ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
								return false;
							}

///Change
#if defined(__BL_MOVE_COSTUME_ATTR__)				
							if (ITEM_COSTUME == item2->GetType() 
								&& item->GetSubType() != USE_RESET_COSTUME_ATTR && item->GetSubType() != USE_CHANGE_COSTUME_ATTR)
#else
							if (ITEM_COSTUME == item2->GetType())
#endif
							{
								ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
								return false;
							}

//Find
								case USE_CLEAN_SOCKET:
									{
										...
									}
									break;

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
								case USE_RESET_COSTUME_ATTR:
								{
									if (item2->GetAttributeSetIndex() == -1)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
										return false;
									}

									if (item2->IsEquipped())
										return false;

									if (item2->GetType() != EItemTypes::ITEM_COSTUME)
										return false;

									if (item2->GetAttributeCount() < 1) // (costume+ have at least 1 bonus)
										return false;

									item2->ClearAttribute();

									const int iRandCostume = number(1, 100);
									static BYTE arrCostumeAttrChance[] = { 100, 30, 5 };

									for (BYTE bl = 0; bl < _countof(arrCostumeAttrChance); bl++)
										if (iRandCostume <= arrCostumeAttrChance[bl])
											item2->AddAttribute();

									item->SetCount(item->GetCount() - 1);
									ChatPacket(CHAT_TYPE_INFO, "You have changed the upgrade.");
								}
								break;

								case USE_CHANGE_COSTUME_ATTR:
								{	
									if (item2->GetAttributeSetIndex() == -1)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("속성을 변경할 수 없는 아이템입니다."));
										return false;
									}

									if (item2->IsEquipped())
										return false;

									if (item2->GetType() != EItemTypes::ITEM_COSTUME)
										return false;

									if (item2->GetAttributeCount() < 1) // (costume+ have at least 1 bonus)
										return false;

									item2->ChangeAttribute();

									item->SetCount(item->GetCount() - 1);
									ChatPacket(CHAT_TYPE_INFO, "You have changed the upgrade.");
								}
								break;
#endif

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
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

///Add New Funcs
#if defined(__BL_MOVE_COSTUME_ATTR__)
void CHARACTER::OpenItemComb()
{
	if (IsItemComb())
		return;

	const LPCHARACTER npc = GetQuestNPC();
	if (npc == NULL)
	{
		sys_err("Item Combination NPC is NULL (ch: %s)", GetName());
		return;
	}

	SetItemCombNpc(npc);
	ChatPacket(CHAT_TYPE_COMMAND, "ShowItemCombinationDialog");
}

void CHARACTER::ItemCombination(const short MediumIndex, const short BaseIndex, const short MaterialIndex)
{
	if (IsItemComb() == false)
		return;
	
	const LPITEM MediumItem		= GetItem(TItemPos(INVENTORY, MediumIndex));
	const LPITEM BaseItem		= GetItem(TItemPos(INVENTORY, BaseIndex));
	const LPITEM MaterialItem	= GetItem(TItemPos(INVENTORY, MaterialIndex));

	if (MediumItem == NULL || BaseItem == NULL || MaterialItem == NULL)
		return;

	switch (MediumItem->GetType())
	{
	case EItemTypes::ITEM_MEDIUM:
		switch (MediumItem->GetSubType())
		{
		case EMediumSubTypes::MEDIUM_MOVE_COSTUME_ATTR:
			break;
		/*case EMediumSubTypes::MEDIUM_MOVE_ACCE_ATTR:
			break;*/
		default:
			return;
		}
		break;
	default:
		return;
	}

	if (BaseItem->IsEquipped() || MaterialItem->IsEquipped())
		return;

	if (BaseItem->GetType() != EItemTypes::ITEM_COSTUME || MaterialItem->GetType() != EItemTypes::ITEM_COSTUME)
		return;

	if (BaseItem->GetAttributeCount() < 1 || MaterialItem->GetAttributeCount() < 1)
		return;

	BaseItem->SetAttributes(MaterialItem->GetAttributes());
	BaseItem->UpdatePacket();

	ITEM_MANAGER::instance().RemoveItem(MaterialItem, "REMOVE (Item Combination)");
	MediumItem->SetCount(MediumItem->GetCount() - 1);
}
#endif