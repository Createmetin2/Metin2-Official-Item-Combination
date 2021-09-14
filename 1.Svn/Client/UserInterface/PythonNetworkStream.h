//Find
		bool SendSelectItemPacket(DWORD dwItemPos);

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
		bool SendItemCombinationPacket(const int iMediumIndex, const int iBaseIndex, const int iMaterialIndex);
		bool SendItemCombinationPacketCancel();
#endif