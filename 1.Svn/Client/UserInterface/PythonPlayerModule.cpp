///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
PyObject* playerSetItemCombinationWindowActivedItemSlot(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bSlotType;
	if (!PyTuple_GetByte(poArgs, 0, &bSlotType))
		return Py_BadArgument();

	int iSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &iSlotIndex))
		return Py_BadArgument();

	if (bSlotType >= ECombSlotType::COMB_WND_SLOT_MAX)
		return Py_BuildException();

	CPythonPlayer::Instance().SetItemCombinationWindowActivedItemSlot(bSlotType, iSlotIndex);

	return Py_BuildNone();
}

PyObject* playerGetInvenSlotAttachedToConbWindowSlot(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bSlotType;
	if (!PyTuple_GetByte(poArgs, 0, &bSlotType))
		return Py_BadArgument();

	if (bSlotType >= ECombSlotType::COMB_WND_SLOT_MAX)
		return Py_BuildException();

	return Py_BuildValue("i", CPythonPlayer::Instance().GetInvenSlotAttachedToConbWindowSlot(bSlotType));
}

PyObject* playerCanAttachToCombMediumSlot(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bSlotType;
	if (!PyTuple_GetByte(poArgs, 0, &bSlotType))
		return Py_BadArgument();

	TItemPos Cell;
	if (!PyTuple_GetByte(poArgs, 1, &Cell.window_type))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 2, &Cell.cell))
		return Py_BuildException();

	if (bSlotType != ECombSlotType::COMB_WND_SLOT_MEDIUM || Cell.window_type != INVENTORY)
		return Py_BuildValue("b", false);

	const TItemData* pItem = CPythonPlayer::Instance().GetItemData(Cell);
	if (pItem == nullptr)
		return Py_BuildValue("b", false);

	CItemData* pItemData = nullptr;
	if (CItemManager::Instance().GetItemDataPointer(pItem->vnum, &pItemData) == false)
		return Py_BuildValue("b", false);

	const bool bRet = pItemData->GetType() == CItemData::EItemType::ITEM_TYPE_MEDIUM 
		&& pItemData->GetSubType() == CItemData::EMediumSubTypes::MEDIUM_MOVE_COSTUME_ATTR;

	return Py_BuildValue("b", bRet);
}

PyObject* playerCanAttachToCombItemSlot(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bSlotType;
	if (!PyTuple_GetByte(poArgs, 0, &bSlotType))
		return Py_BadArgument();

	TItemPos Cell;
	if (!PyTuple_GetByte(poArgs, 1, &Cell.window_type))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 2, &Cell.cell))
		return Py_BuildException();

	if ((bSlotType != ECombSlotType::COMB_WND_SLOT_BASE && bSlotType != ECombSlotType::COMB_WND_SLOT_MATERIAL) 
		|| Cell.window_type != INVENTORY)
		return Py_BuildValue("b", false);

	const TItemData* pItem = CPythonPlayer::Instance().GetItemData(Cell);
	if (pItem == nullptr)
		return Py_BuildValue("b", false);

	CItemData* pItemData = nullptr;
	if (CItemManager::Instance().GetItemDataPointer(pItem->vnum, &pItemData) == false)
		return Py_BuildValue("b", false);

	bool bHasAttr = false;
	for (BYTE i = 0; i < ITEM_ATTRIBUTE_SLOT_MAX_NUM; i++)
	{
		if (pItem->aAttr[i].bType != 0)
		{
			bHasAttr = true;
			break;
		}
	}

	const bool bRet = pItemData->GetType() == CItemData::EItemType::ITEM_TYPE_COSTUME && bHasAttr;

	return Py_BuildValue("b", bRet);
}

PyObject* playerGetConbWindowSlotByAttachedInvenSlot(PyObject* poSelf, PyObject* poArgs)
{
	int iSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iSlotIndex))
		return Py_BadArgument();

	BYTE bRet = 0;
	while (bRet < ECombSlotType::COMB_WND_SLOT_MAX 
		&& CPythonPlayer::Instance().GetInvenSlotAttachedToConbWindowSlot(bRet) != iSlotIndex)
		bRet++;

	return Py_BuildValue("i", bRet);
}
#endif

//Find
		{ "SendDragonSoulRefine",		playerSendDragonSoulRefine,			METH_VARARGS },

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
		{ "SetItemCombinationWindowActivedItemSlot", playerSetItemCombinationWindowActivedItemSlot, METH_VARARGS },
		{ "GetInvenSlotAttachedToConbWindowSlot", playerGetInvenSlotAttachedToConbWindowSlot, METH_VARARGS },
		{ "CanAttachToCombMediumSlot", playerCanAttachToCombMediumSlot, METH_VARARGS },
		{ "CanAttachToCombItemSlot", playerCanAttachToCombItemSlot, METH_VARARGS },
		{ "GetConbWindowSlotByAttachedInvenSlot", playerGetConbWindowSlotByAttachedInvenSlot, METH_VARARGS },
#endif

//Find
	PyModule_AddIntConstant(poModule, "DS_SUB_HEADER_DO_REFINE",	DS_SUB_HEADER_DO_REFINE);
	
///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_MEDIUM",	ECombSlotType::COMB_WND_SLOT_MEDIUM);
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_BASE",		ECombSlotType::COMB_WND_SLOT_BASE);
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_MATERIAL", ECombSlotType::COMB_WND_SLOT_MATERIAL);
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_RESULT",	ECombSlotType::COMB_WND_SLOT_RESULT);
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_MAX",		ECombSlotType::COMB_WND_SLOT_MAX);
#endif