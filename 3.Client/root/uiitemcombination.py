import ui
import player
import mouseModule
import net
import app
import snd
import item
import player
import chat
import grp
import uiScriptLocale
import uiRefine
import uiAttachMetin
import uiPickMoney
import uiCommon
import uiPrivateShopBuilder # ���λ��� ������ ItemMove ����
import localeInfo
import constInfo
import ime
import wndMgr
import uiToolTip

if app.BL_MOVE_COSTUME_ATTR:
	USE_WINDOW_LIMIT_RANGE = 500
	
	class ItemCombinationWindow(ui.ScriptWindow):
		def __init__(self):
			ui.ScriptWindow.__init__(self)
			self.tooltipitem = None
			self.tooltipResult = uiToolTip.ItemToolTip()
			self.wndInventory = None
			self.WindowStartX = 0
			self.WindowStartY = 0
			self.textInitTitleName = "None"
			self.textTitleName = None
			self.inven = None
			self.wndMediumSlot = None
			self.wndCombSlot = None
			self.pop = None
			self.interface = None
			
		def __del__(self):
			ui.ScriptWindow.__del__(self)
			self.tooltipitem = None
			
		def __LoadWindow(self):
			try:
				pyScrLoader = ui.PythonScriptLoader()
				pyScrLoader.LoadScriptFile(self, "UIScript/ItemCombinationWindow.py")
			except:
				import exception
				exception.Abort("ItemCombinationWindow.__LoadWindow.UIScript/ItemCombinationWindow.py")
			try:
				self.wndBgImage = self.GetChild("Item_Comb_Background_Image")
				self.textTitleName = self.GetChild("TitleName")
				self.textInitTitleName = self.textTitleName.GetText()
				wndMediumSlot = self.GetChild("MediumSlot")
				wndCombSlot = self.GetChild("CombSlot")
				self.GetChild("CancelButton").SetEvent(ui.__mem_func__(self.Close))
				self.GetChild("AcceptButton").SetEvent(ui.__mem_func__(self.Accept))
				self.GetChild("TitleBar").SetCloseEvent(ui.__mem_func__(self.Close))
			except:
				import exception
				exception.Abort("ItemCombinationWindow.__LoadWindow")
				
			self.wndBgImage.Hide()
			
			wndCombSlot.SetOverInItemEvent(ui.__mem_func__(self.OverInItem))
			wndCombSlot.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
			wndCombSlot.SetUnselectItemSlotEvent(ui.__mem_func__(self.UseItemSlot))
			wndCombSlot.SetUseSlotEvent(ui.__mem_func__(self.UseItemSlot))						
			wndCombSlot.SetSelectEmptySlotEvent(ui.__mem_func__(self.SelectEmptySlot))
			wndCombSlot.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectItemSlot))
			wndCombSlot.Hide()
			
			wndMediumSlot.SetOverInItemEvent(ui.__mem_func__(self.OverInItem))
			wndMediumSlot.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
			wndMediumSlot.SetUnselectItemSlotEvent(ui.__mem_func__(self.UseItemSlot))
			wndMediumSlot.SetUseSlotEvent(ui.__mem_func__(self.UseItemSlot))						
			wndMediumSlot.SetSelectEmptySlotEvent(ui.__mem_func__(self.SelectEmptySlot))
			wndMediumSlot.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectItemSlot))
			wndMediumSlot.Show()

			self.wndMediumSlot = wndMediumSlot
			self.wndCombSlot = wndCombSlot

		def Open(self):
			self.__LoadWindow()
			self.SetCenterPosition()
			self.SetTop()
			ui.ScriptWindow.Show(self)
			(self.WindowStartX, self.WindowStartY, z) = player.GetMainCharacterPosition()				
		
		def Close(self):
			if self.interface:
				self.interface.SetOnTopWindow(player.ON_TOP_WND_NONE)
				self.RefreshCantMouseEventSlot()
			if self.pop:
				self.pop.Close()
				self.pop = None
				
			net.SendItemCombinationPacketCancel() # New
			self.ClearSlot()
			self.Hide()
		
		def OnPressEscapeKey(self):
			self.Close()
			return True
		
		def Accept(self):
			if not self.IsFilledAllSlots():
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_NOT_ALL_SLOT_APPEND_ITEM)
				return
			
			popup = uiCommon.QuestionDialog2()
			popup.SetText1(localeInfo.COMB_WILL_REMOVE_MATERIAL)
			popup.SetText2(localeInfo.COMB_IS_CONTINUE_PROCESS)
			popup.SetAcceptEvent(self.OnDialogAcceptEvent)
			popup.SetCancelEvent(self.OnDialogCloseEvent)
			popup.Open()
			self.pop = popup
			
		def OnDialogAcceptEvent(self):
			if self.IsFilledAllSlots():
				net.SendItemCombinationPacket(player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_MEDIUM), player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_BASE), player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_MATERIAL))
				self.Close()
			else:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_NOT_ALL_SLOT_APPEND_ITEM)
			
			if self.pop:
				self.pop.Close()
				self.pop = None
				
		def OnDialogCloseEvent(self):
			self.pop.Close()
			self.pop = None

		def BindInterface(self, interface):
			from _weakref import proxy
			self.interface = proxy(interface)
			
		def SetInven(self, inven):
			self.inven = inven
			
		def SetItemToolTip(self, tooltip):
			self.tooltipitem = tooltip
		
		def SetInvenWindow(self, wndInven):
			self.tooltipitem = tooltip
			
		def __ShowToolTip(self, slotIndex):
			if self.tooltipitem:
				self.tooltipitem.SetInventoryItem(slotIndex)
		
		#��� �������� ��ϵǾ� ���� �� �������� SubType�� ���� ��� �������� ������ �����ݴϴ�.		
		def __ShowResultToolTip(self):
				if not self.IsFilledAllSlots():
					return
				
				if self.GetItemSubTypeByCombSlot(player.COMB_WND_SLOT_MEDIUM) == item.MEDIUM_MOVE_COSTUME_ATTR:
					self.tooltipResult.SetResulItemAttrMove(player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_BASE), player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_MATERIAL))
		
		# ������ ���� �����ֱ�
		def OverInItem(self, slotIndex):
			if slotIndex == player.COMB_WND_SLOT_RESULT:
				if self.tooltipResult.IsShow():
					return
				
				self.__ShowResultToolTip()
				return
			
			if self.tooltipitem.IsShow():
				return
			
			InventorySlot = player.GetInvenSlotAttachedToConbWindowSlot(slotIndex)
			if InventorySlot == -1:
				return
				
			self.__ShowToolTip(InventorySlot)
		
		# ������ ���� ���߱�
		def OverOutItem(self):
			self.tooltipitem.HideToolTip()
			self.tooltipResult.HideToolTip()
			
		def AttachItemToSelectSlot(self, selectSlot, slotType, slotIndex):
			if not self.CanAttachSlot(selectSlot, slotType, slotIndex):
				return
			
			ItemVNum = player.GetItemIndex(slotIndex)
			
			if not ItemVNum:
				return
			
			# ��ũ���� �ٲٸ� â�� �̸��� �ٲ۴�. # ����ĭ�� Ȱ��ȭ ��Ų��.
			if selectSlot == player.COMB_WND_SLOT_MEDIUM:
				self.textTitleName.SetText(item.GetItemNameByVnum(ItemVNum))
				self.wndMediumSlot.SetItemSlot(selectSlot, ItemVNum)
				self.ChangeBackgroundImage()
				self.wndBgImage.Show()
				self.wndCombSlot.Show()
			else:
				self.wndCombSlot.SetItemSlot(selectSlot, ItemVNum)

			player.SetItemCombinationWindowActivedItemSlot(selectSlot, slotIndex)
			self.inven.wndItem.SetCantMouseEventSlot(slotIndex)
			
			if self.IsFilledAllSlots():	
				self.SetResultItem()
				
			if self.interface:
				self.interface.RefreshMarkInventoryBag()
				
		
		# �κ� -> ����â
		def SelectEmptySlot(self, selectedSlotPos): # selectedSlotPos : �ش��κ��� slotPos
			if mouseModule.mouseController.isAttached():
				attachedSlotType = mouseModule.mouseController.GetAttachedType() # ���� attach�� �������� �ִ� ������ Ÿ��.
				attachedSlotPos = mouseModule.mouseController.GetAttachedSlotNumber() # ���� attach�� �������� �ִ� ������ ����.
				attachedItemVNum = mouseModule.mouseController.GetAttachedItemIndex()
				
				mouseModule.mouseController.DeattachObject()

				if not self.CanAttachSlot(selectedSlotPos, attachedSlotType, attachedSlotPos):
					return
				
				self.AttachItemToSelectSlot(selectedSlotPos, attachedSlotType, attachedSlotPos)
		
		def AttachToCombinationSlot(self, slotType, slotIndex):
			
			selectSlot = -1
			for i in (player.COMB_WND_SLOT_MEDIUM, player.COMB_WND_SLOT_BASE, player.COMB_WND_SLOT_MATERIAL):
				invenSlot = player.GetInvenSlotAttachedToConbWindowSlot(i)
				if invenSlot == -1:
					selectSlot = i
					break
			
			if selectSlot == -1:
				return
				
			self.AttachItemToSelectSlot(selectSlot, slotType, slotIndex)
				
				
		def ChangeBackgroundImage(self):
			if self.GetItemSubTypeByCombSlot(player.COMB_WND_SLOT_MEDIUM) == item.MEDIUM_MOVE_COSTUME_ATTR:
				self.wndBgImage.LoadImage(uiScriptLocale.LOCALE_UISCRIPT_PATH + "combination/comb1.tga")
				
		def IsFilledAllSlots(self):
			for i in (player.COMB_WND_SLOT_MEDIUM, player.COMB_WND_SLOT_BASE, player.COMB_WND_SLOT_MATERIAL):
				invenSlot = player.GetInvenSlotAttachedToConbWindowSlot(i)
				if invenSlot == -1:
					return False
			return True
			
		def CantAttachToCombSlot(self, slotIndex):
			# if player.GetItemSealDate(player.INVENTORY, slotIndex) != -1: #���ξ����� �ɷ���.
			# 	return True
			if player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_MEDIUM) == -1: # ���� �Ű�ü�� ����� ���� �ʾ��� ��
				return not player.CanAttachToCombMediumSlot(player.COMB_WND_SLOT_MEDIUM, player.INVENTORY, slotIndex)
			elif player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_BASE) == -1: # �⺻ �������� ��� ���� �ʾ��� ��
				return not player.CanAttachToCombItemSlot(player.COMB_WND_SLOT_BASE, player.INVENTORY, slotIndex)
			elif player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_MATERIAL) == -1: # ��ᰡ ��� ���� �ʾ��� ��
				return not player.CanAttachToCombItemSlot(player.COMB_WND_SLOT_MATERIAL, player.INVENTORY, slotIndex)
			return True
		
		def CanAttachSlot(self, selectedSlotPos, attachedSlotType, attachedSlotPos):
			if selectedSlotPos >= player.COMB_WND_SLOT_MAX:
				return False
				
			if selectedSlotPos == player.COMB_WND_SLOT_RESULT:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_CANT_APPEND_ITEM)
				return False
				
			# if app.ENABLE_EXTEND_INVEN_SYSTEM:
			# 	window_type = player.SlotTypeToInvenType(attachedSlotType)
			# 	if window_type != player.INVENTORY:
			# 		chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_NOT_ITEM_IN_INVENTORY)
			# 		return False			
			# else:
			# 	if not player.SLOT_TYPE_INVENTORY == attachedSlotType:
			# 		chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_NOT_ITEM_IN_INVENTORY)
			# 		return
				
			# 	if attachedSlotPos > player.EQUIPMENT_SLOT_START-1: ## �κ�â �ȿ� �ִ� �͸�.
			# 		chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_NOT_ITEM_IN_INVENTORY)
			# 		return False

			if not player.SLOT_TYPE_INVENTORY == attachedSlotType:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_NOT_ITEM_IN_INVENTORY)
				return
			
			if attachedSlotPos > player.EQUIPMENT_SLOT_START-1: ## �κ�â �ȿ� �ִ� �͸�.
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_NOT_ITEM_IN_INVENTORY)
				return False
				
			# if player.GetItemSealDate(player.INVENTORY, attachedSlotPos) != -1:
			# 	chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_CANT_APPEND_SEALED_ITEM)
			# 	return
				
			if selectedSlotPos == player.COMB_WND_SLOT_MEDIUM:
				if not player.CanAttachToCombMediumSlot(selectedSlotPos, attachedSlotType, attachedSlotPos):
					chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_NOT_MEDIUM_ITEM)
					return False
					
			if selectedSlotPos == player.COMB_WND_SLOT_BASE or selectedSlotPos == player.COMB_WND_SLOT_MATERIAL:

				mediumInvenSlot = player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_MEDIUM) # �������� ��� �ȵ� ��� -1�� ���ϵȴ�.
			
				if not selectedSlotPos == player.COMB_WND_SLOT_MEDIUM and mediumInvenSlot == -1:
					chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_PLEASE_APPEND_MEDIUM_FIRST)
					return False

				if not player.CanAttachToCombItemSlot(selectedSlotPos, attachedSlotType, attachedSlotPos):
					chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_CANT_APPEND_ITEM)
					return False
					
			if player.GetConbWindowSlotByAttachedInvenSlot(attachedSlotPos)!=player.COMB_WND_SLOT_MAX:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.COMB_ALREADY_APPEND)
				return False
					
			return True
						
		def SetResultItem(self):
			if self.GetItemSubTypeByCombSlot(player.COMB_WND_SLOT_MEDIUM) == item.MEDIUM_MOVE_COSTUME_ATTR:
				self.wndCombSlot.SetItemSlot(player.COMB_WND_SLOT_RESULT, player.GetItemIndex(player.GetInvenSlotAttachedToConbWindowSlot(player.COMB_WND_SLOT_BASE)))
		
		
		def GetItemSubTypeByCombSlot(self, slotIndex):
			InvenSlot = player.GetInvenSlotAttachedToConbWindowSlot(slotIndex)
			if InvenSlot == -1:
				return -1
			
			ItemVNum = player.GetItemIndex(InvenSlot)
			item.SelectItem(ItemVNum)
			
			return item.GetItemSubType()
			
		def UseItemSlot(self, selectedSlotPos):
			self.RemoveItemSlot(selectedSlotPos)

		def SelectItemSlot(self, selectedSlotPos):
			self.RemoveItemSlot(selectedSlotPos)
			
		def RemoveItemSlot(self, selectedSlotPos):
			if selectedSlotPos == player.COMB_WND_SLOT_MEDIUM:
				self.ClearSlot()				
			elif selectedSlotPos == player.COMB_WND_SLOT_BASE or selectedSlotPos == player.COMB_WND_SLOT_MATERIAL:
				invenSlot = player.GetInvenSlotAttachedToConbWindowSlot(selectedSlotPos)
				if invenSlot != -1:
					if invenSlot >= player.INVENTORY_PAGE_SIZE:
						
						# if app.ENABLE_EXTEND_INVEN_SYSTEM:
						# 	invenPage = self.inven.GetInventoryPageIndex()
						# 	invenSlot -= (invenPage * player.INVENTORY_PAGE_SIZE)
						# else:
						# 	invenSlot -= player.INVENTORY_PAGE_SIZE

						invenPage = self.inven.GetInventoryPageIndex()
						invenSlot -= (invenPage * player.INVENTORY_PAGE_SIZE)
							
					self.inven.wndItem.SetCanMouseEventSlot(invenSlot)
					self.wndCombSlot.SetItemSlot(selectedSlotPos,0)
					player.SetItemCombinationWindowActivedItemSlot(selectedSlotPos, -1)
					self.wndCombSlot.SetItemSlot(player.COMB_WND_SLOT_RESULT, 0)
					
			if self.interface:
				self.interface.RefreshMarkInventoryBag()
			
		def ClearSlot(self):			
			if self.textTitleName == None:
				return
				
			self.textTitleName.SetText(self.textInitTitleName)
			for i in xrange(player.COMB_WND_SLOT_MAX):
				invenSlot = player.GetInvenSlotAttachedToConbWindowSlot(i)
				if invenSlot != -1:					
					if invenSlot >= player.INVENTORY_PAGE_SIZE:
						
						# if app.ENABLE_EXTEND_INVEN_SYSTEM:
						# 	invenPage = self.inven.GetInventoryPageIndex()
						# 	invenSlot -= (invenPage * player.INVENTORY_PAGE_SIZE)
						# else:						
						# 	invenSlot -= player.INVENTORY_PAGE_SIZE
						
						invenPage = self.inven.GetInventoryPageIndex()
						invenSlot -= (invenPage * player.INVENTORY_PAGE_SIZE)
						
					self.inven.wndItem.SetCanMouseEventSlot(invenSlot)
					
				if i == player.COMB_WND_SLOT_MEDIUM:
					self.wndMediumSlot.SetItemSlot(i,0)
				else:
					self.wndCombSlot.SetItemSlot(i,0)
				player.SetItemCombinationWindowActivedItemSlot(i, -1)
			
			self.wndBgImage.Hide()
			self.wndCombSlot.Hide()
			
			if self.interface:
				self.interface.RefreshMarkInventoryBag()
			
		def OnUpdate(self):
			(x, y, z) = player.GetMainCharacterPosition()
			if abs(x - self.WindowStartX) > USE_WINDOW_LIMIT_RANGE or abs(y - self.WindowStartY) > USE_WINDOW_LIMIT_RANGE:
				self.Close()
				
			self.RefreshCantMouseEventSlot()
			
		def RefreshCantMouseEventSlot(self):
			if self.inven == 0:
				return
			
			inven = self.inven
			invenPage = inven.GetInventoryPageIndex() ## 0 or 1
			
			min_range = invenPage * player.INVENTORY_PAGE_SIZE			## 0 or 45
			max_range = (invenPage + 1) * player.INVENTORY_PAGE_SIZE	## 45 or 90
			
			for i in xrange(player.COMB_WND_SLOT_MAX):
				invenSlot = player.GetInvenSlotAttachedToConbWindowSlot(i)
				if invenSlot == -1:
					continue
					
				if min_range <= invenSlot < max_range:
					invenSlot = invenSlot - min_range
					inven.wndItem.SetCantMouseEventSlot(invenSlot)
					
		def Destroy(self):
			self.Close()
			self.tooltipitem = None
			self.tooltipResult = None
			self.wndInventory = None
			self.WindowStartX = 0
			self.WindowStartY = 0
			self.textInitTitleName = None
			self.textTitleName = None
			self.inven = None
			self.wndMediumSlot = None
			self.wndCombSlot = None
			self.pop = None
			
		def OnTop(self):
			if not self.interface:
				return
			
			self.interface.SetOnTopWindow(player.ON_TOP_WND_ITEM_COMB)
			self.interface.RefreshMarkInventoryBag()
			self.RefreshCantMouseEventSlot()
			return