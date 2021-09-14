//Find
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
						|| ch->IsItemComb()
#endif
					)

//Find
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
		|| ch->IsItemComb()
#endif
	)

//Find
void CInputMain::Fishing(LPCHARACTER ch, const char* c_pData)
{
	...
}

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
void CInputMain::ItemCombination(LPCHARACTER ch, const char* c_pData)
{
	const TPacketCGItemCombination* p = reinterpret_cast<const TPacketCGItemCombination*>(c_pData);

	ch->ItemCombination(p->MediumIndex, p->BaseIndex, p->MaterialIndex);
}

void CInputMain::ItemCombinationCancel(LPCHARACTER ch, const char* c_pData)
{
	const TPacketCGItemCombinationCancel* p = reinterpret_cast<const TPacketCGItemCombinationCancel*>(c_pData);

	ch->SetItemCombNpc(NULL);
}
#endif

//Find
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_MOVE_COSTUME_ATTR__)
		|| ch->IsItemComb()
#endif
	)

//Find
		case HEADER_CG_MALL_CHECKOUT:
			SafeboxCheckout(ch, c_pData, true);
			break;

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
		case HEADER_CG_ITEM_COMBINATION:
			ItemCombination(ch, c_pData);
			break;

		case HEADER_CG_ITEM_COMBINATION_CANCEL:
			ItemCombinationCancel(ch, c_pData);
			break;
#endif