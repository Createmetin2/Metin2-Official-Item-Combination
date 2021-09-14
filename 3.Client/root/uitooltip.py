# Find
	def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):
        ...

# Add
    if app.BL_MOVE_COSTUME_ATTR:
		def SetResulItemAttrMove(self, baseSlotIndex, materialSlotIndex, window_type = player.INVENTORY):
			baseItemVnum = player.GetItemIndex(window_type, baseSlotIndex)
			
			if 0 == baseItemVnum:
				return

			materialItemVnum = player.GetItemIndex(window_type, materialSlotIndex)
			
			if 0 == materialItemVnum:
				return
				
			self.ClearToolTip()

			metinSlot = [player.GetItemMetinSocket(window_type, baseSlotIndex, i) for i in xrange(player.METIN_SOCKET_MAX_NUM)]
			attrSlot = [player.GetItemAttribute(window_type, materialSlotIndex, i) for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM)]

			self.AddItemData(baseItemVnum, metinSlot, attrSlot)