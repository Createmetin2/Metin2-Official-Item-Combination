# Find
	USE_TYPE_TUPLE = ("USE_CLEAN_SOCKET", "USE_CHANGE_ATTRIBUTE", "USE_ADD_ATTRIBUTE", "USE_ADD_ATTRIBUTE2",
							"USE_ADD_ACCESSORY_SOCKET", "USE_PUT_INTO_ACCESSORY_SOCKET", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET")

# Change
	if app.BL_MOVE_COSTUME_ATTR:
		USE_TYPE_TUPLE = ("USE_CLEAN_SOCKET", "USE_CHANGE_ATTRIBUTE", "USE_CHANGE_ATTRIBUTE2", "USE_ADD_ATTRIBUTE", "USE_ADD_ATTRIBUTE2",
							"USE_ADD_ACCESSORY_SOCKET", "USE_PUT_INTO_ACCESSORY_SOCKET", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET", "USE_CHANGE_COSTUME_ATTR", "USE_RESET_COSTUME_ATTR")
	else:
		USE_TYPE_TUPLE = ("USE_CLEAN_SOCKET", "USE_CHANGE_ATTRIBUTE", "USE_ADD_ATTRIBUTE", "USE_ADD_ATTRIBUTE2",
							"USE_ADD_ACCESSORY_SOCKET", "USE_PUT_INTO_ACCESSORY_SOCKET", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET")

# Find
				elif onTopWnd == player.ON_TOP_WND_SAFEBOX:
					if player.IsAntiFlagBySlot(slotNumber, item.ANTIFLAG_SAFEBOX):
						self.wndItem.SetUnusableSlotOnTopWnd(localIndex)
					else:
						self.wndItem.SetUsableSlotOnTopWnd(localIndex)

# Add
				elif app.BL_MOVE_COSTUME_ATTR and onTopWnd == player.ON_TOP_WND_ITEM_COMB:
					if self.interface.MarkUnusableInvenSlotMoveCostumeAttr(onTopWnd, slotNumber):
						self.wndItem.SetUnusableSlotOnTopWnd(localIndex)
					else:
						self.wndItem.SetUsableSlotOnTopWnd(localIndex)

# Find
				elif onTopWnd == player.ON_TOP_WND_SAFEBOX:
					if player.IsAntiFlagBySlot(slotNumber, item.ANTIFLAG_SAFEBOX):
						self.wndItem.SetUnusableSlotOnTopWnd(i)
					else:
						self.wndItem.SetUsableSlotOnTopWnd(i)

# Add
				elif app.BL_MOVE_COSTUME_ATTR and onTopWnd == player.ON_TOP_WND_ITEM_COMB:
					if self.interface.MarkUnusableInvenSlotMoveCostumeAttr(onTopWnd, slotNumber):
						self.wndItem.SetUnusableSlotOnTopWnd(i)
					else:
						self.wndItem.SetUsableSlotOnTopWnd(i)

# Find
			elif "USE_ADD_ACCESSORY_SOCKET" == useType:
				if self.__CanAddAccessorySocket(dstSlotPos):
					return True

# Add
			elif app.BL_MOVE_COSTUME_ATTR and "USE_CHANGE_COSTUME_ATTR" == useType:
				if self.__CanChangeCostumeAttrList(dstSlotPos):
					return True
			elif app.BL_MOVE_COSTUME_ATTR and "USE_RESET_COSTUME_ATTR" == useType:
				if self.__CanResetCostumeAttr(dstSlotPos):
					return True

# Find
	def ShowToolTip(self, slotIndex):
		if None != self.tooltipItem:
			self.tooltipItem.SetInventoryItem(slotIndex)

# Add
	if app.BL_MOVE_COSTUME_ATTR:
		def __CanChangeCostumeAttrList(self, dstSlotPos):
			dstItemVNum = player.GetItemIndex(dstSlotPos)
			if dstItemVNum == 0:
				return False
			
			item.SelectItem(dstItemVNum)
			
			if item.GetItemType() !=item.ITEM_TYPE_COSTUME:	 
				return False
			
			# if item.GetItemSubType() == item.COSTUME_TYPE_ACCE:
			# 	return False
			
			# if item.GetItemSubType() == item.COSTUME_TYPE_MOUNT:
			# 	return False	  
			
			for i in xrange(player.METIN_SOCKET_MAX_NUM):
				type, value = player.GetItemAttribute(dstSlotPos, i)
				if type != 0:
					return True
			
			return False
		
		def __CanResetCostumeAttr(self, dstSlotPos):
			dstItemVNum = player.GetItemIndex(dstSlotPos)
			if dstItemVNum == 0:
				return False
			
			item.SelectItem(dstItemVNum)
			
			if item.GetItemType() !=item.ITEM_TYPE_COSTUME:	 	  
				return False
			
			# if item.GetItemSubType() == item.COSTUME_TYPE_ACCE:
			# 	return False
			
			# if item.GetItemSubType() == item.COSTUME_TYPE_MOUNT:
			# 	return False
			
			for i in xrange(player.METIN_SOCKET_MAX_NUM):
				type, value = player.GetItemAttribute(dstSlotPos, i)
				if type != 0:
					return True
			
			return False

# Find
	def __UseItem(self, slotIndex):
		ItemVNum = player.GetItemIndex(slotIndex)
		item.SelectItem(ItemVNum)

# Add
		if app.BL_MOVE_COSTUME_ATTR:
			if self.interface.AttachInvenItemToOtherWindowSlot(slotIndex):
				return