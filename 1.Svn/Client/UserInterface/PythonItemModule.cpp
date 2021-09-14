///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
PyObject* itemGetItemNameByVnum(PyObject* poSelf, PyObject* poArgs)
{
	DWORD dwVirtualNumber;
	if (!PyTuple_GetUnsignedLong(poArgs, 0, &dwVirtualNumber))
		return Py_BadArgument();
	
	CItemData* pItemData;
	if (!CItemManager::Instance().GetItemDataPointer(dwVirtualNumber, &pItemData))
		return Py_BuildException();

	return Py_BuildValue("s", pItemData->GetName());
}
#endif

//Find
		{ "Pick",							itemPick,								METH_VARARGS },

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
		{ "GetItemNameByVnum",				itemGetItemNameByVnum,					METH_VARARGS },
#endif

//Find
	PyModule_AddIntConstant(poModule, "ITEM_TYPE_BELT",				CItemData::ITEM_TYPE_BELT);

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	PyModule_AddIntConstant(poModule, "ITEM_TYPE_MEDIUM",			CItemData::EItemType::ITEM_TYPE_MEDIUM);
	PyModule_AddIntConstant(poModule, "MEDIUM_MOVE_COSTUME_ATTR",	CItemData::EMediumSubTypes::MEDIUM_MOVE_COSTUME_ATTR);
	PyModule_AddIntConstant(poModule, "MEDIUM_MOVE_ACCE_ATTR",		CItemData::EMediumSubTypes::MEDIUM_MOVE_ACCE_ATTR);
#endif