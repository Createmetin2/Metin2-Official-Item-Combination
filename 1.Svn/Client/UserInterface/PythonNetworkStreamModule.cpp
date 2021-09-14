//Find
PyObject* netRegisterErrorLog(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
PyObject* netSendItemCombinationPacket(PyObject* poSelf, PyObject* poArgs)
{
	int iMediumIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iMediumIndex))
		return Py_BuildException();

	int iBaseIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &iBaseIndex))
		return Py_BuildException();

	int iMaterialIndex;
	if (!PyTuple_GetInteger(poArgs, 2, &iMaterialIndex))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendItemCombinationPacket(iMediumIndex, iBaseIndex, iMaterialIndex);
	return Py_BuildNone();
}

PyObject* netSendItemCombinationPacketCancel(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream::Instance().SendItemCombinationPacketCancel();
	return Py_BuildNone();
}
#endif

//Find
		{ "SendSelectItemPacket",					netSendSelectItemPacket,					METH_VARARGS },

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
		{ "SendItemCombinationPacket",				netSendItemCombinationPacket,				METH_VARARGS },
		{ "SendItemCombinationPacketCancel",		netSendItemCombinationPacketCancel,			METH_VARARGS },
#endif