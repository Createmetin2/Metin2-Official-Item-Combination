//Find
	memset(m_adwEffect, 0, sizeof(m_adwEffect));

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	std::memset(m_MoveCostumeAttrArr, -1, sizeof(m_MoveCostumeAttrArr));
#endif

///Add new funcs
#if defined(__BL_MOVE_COSTUME_ATTR__)
void CPythonPlayer::SetItemCombinationWindowActivedItemSlot(const BYTE bSlotType, const int iSlotIndex)
{
	m_MoveCostumeAttrArr[bSlotType] = iSlotIndex;
}

short CPythonPlayer::GetInvenSlotAttachedToConbWindowSlot(const BYTE bSlotType) const
{
	return m_MoveCostumeAttrArr[bSlotType];
}
#endif