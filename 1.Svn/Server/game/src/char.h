//Find
	LPCHARACTER		pCubeNpc;

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	LPCHARACTER		pItemCombNpc;
#endif

//Find
	public:
		bool IsSiegeNPC() const;

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	public:
		void ItemCombination(const short MediumIndex, const short BaseIndex, const short MaterialIndex);
		void OpenItemComb();
		bool IsItemComb() const { return m_pointsInstant.pItemCombNpc != NULL; }
		void SetItemCombNpc(const LPCHARACTER npc) { m_pointsInstant.pItemCombNpc = npc; }
#endif