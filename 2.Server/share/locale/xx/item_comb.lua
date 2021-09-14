quest item_comb begin
	state start begin
		when 60003.chat."Transfer Bonuses" begin
			say("You can transfer your bonuses from an item to a")
			say("target item. First activate the window and drag")
			say("the transfer item into it. You can then select")
			say("the source and target items.")
			say("")
			say("The source item will be destroyed during the")
			say("transfer. Do you want to continue?")
			say("")
			local s = select(gameforge.locale.yes, gameforge.locale.no)
			if s == 1 then
				setskin(NOWINDOW)
				game.open_item_comb()
			end
		end
	end
end