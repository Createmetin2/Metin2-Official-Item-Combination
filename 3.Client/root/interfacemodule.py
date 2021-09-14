# Add
if app.BL_MOVE_COSTUME_ATTR:
	import uiItemCombination

# Find
		self.bigBoard = None

# Add
		if app.BL_MOVE_COSTUME_ATTR:
			self.wndItemCombination = None

# Find
		wndChatLog.BindInterface(self)

# Add
		if app.BL_MOVE_COSTUME_ATTR:
			wndItemCombination = uiItemCombination.ItemCombinationWindow()
			wndItemCombination.BindInterface(self)
			self.wndItemCombination = wndItemCombination

# Find
		self.wndGuild.SetSkillToolTip(self.tooltipSkill)

# Add
		if app.BL_MOVE_COSTUME_ATTR:
			self.wndItemCombination.SetInven(self.wndInventory)
			self.wndItemCombination.SetItemToolTip(self.tooltipItem)

# Find
    def BULID_ExitGuildArea(self, areaID):
		self.wndGameButton.HideBuildButton()

# Add
	if app.BL_MOVE_COSTUME_ATTR:
		def ItemCombinationDialogOpen(self):
			self.wndItemCombination.Open()
			if False == self.wndInventory.IsShow():
				self.wndInventory.Show()
		
		def MarkUnusableInvenSlotMoveCostumeAttr(self, onTopWnd, index):
			return onTopWnd == player.ON_TOP_WND_ITEM_COMB and self.wndItemCombination and self.wndItemCombination.CantAttachToCombSlot(index)

	def AttachInvenItemToOtherWindowSlot(self, slotIndex):		
		if app.BL_MOVE_COSTUME_ATTR:
			if self.GetOnTopWindow() == player.ON_TOP_WND_ITEM_COMB and self.wndItemCombination and self.wndItemCombination.IsShow():
				self.wndItemCombination.AttachToCombinationSlot(player.INVENTORY, slotIndex)
				return True

		return False