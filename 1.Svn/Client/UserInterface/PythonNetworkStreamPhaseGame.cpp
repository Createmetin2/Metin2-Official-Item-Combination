//Find
bool CPythonNetworkStream::RecvMotionPacket()
{
	...
}

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
bool CPythonNetworkStream::SendItemCombinationPacket(const int iMediumIndex, const int iBaseIndex, const int iMaterialIndex)
{
	TPacketCGItemCombination p;
	p.Header = HEADER_CG_ITEM_COMBINATION;
	p.MediumIndex = iMediumIndex;
	p.BaseIndex = iBaseIndex;
	p.MaterialIndex = iMaterialIndex;

	if (!Send(sizeof(p), &p))
	{
		Tracef("SendItemCombinationPacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::SendItemCombinationPacketCancel()
{
	TPacketCGItemCombinationCancel p;
	p.Header = HEADER_CG_ITEM_COMBINATION_CANCEL;

	if (!Send(sizeof(p), &p))
	{
		Tracef("SendItemCombinationPacketCancel Error\n");
		return false;
	}

	return SendSequence();
}
#endif