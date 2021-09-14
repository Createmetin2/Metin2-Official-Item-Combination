# Find
		self.serverCommander=stringCommander.Analyzer()

#Add Above
		if app.BL_MOVE_COSTUME_ATTR:
			serverCommandList["ShowItemCombinationDialog"] = self.__ItemCombinationDialog

# Add to end
	if app.BL_MOVE_COSTUME_ATTR:
		def __ItemCombinationDialog(self):
			self.interface.ItemCombinationDialogOpen()