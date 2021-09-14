//Find
		void	EndEmotionProcess();

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
		void	SetItemCombinationWindowActivedItemSlot(const BYTE bSlotType, const int iSlotIndex);
		short	GetInvenSlotAttachedToConbWindowSlot(const BYTE bSlotType) const;
#endif

//Find
		DWORD					m_adwEffect[EFFECT_NUM];

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
		short					m_MoveCostumeAttrArr[ECombSlotType::COMB_WND_SLOT_MAX];
#endif