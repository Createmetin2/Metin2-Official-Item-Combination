//Find
#ifdef __AUCTION__
	HEADER_CG_AUCTION_CMD							= 205,
#endif

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
	HEADER_CG_ITEM_COMBINATION = 225,
	HEADER_CG_ITEM_COMBINATION_CANCEL = 226,
#endif

//Find
typedef struct packet_shop_update_item
{
	...
} TPacketGCShopUpdateItem;

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__)
typedef struct packet_cg_item_combination
{
	BYTE							Header;
	short							MediumIndex;
	short							BaseIndex;
	short							MaterialIndex;
} TPacketCGItemCombination;

typedef struct packet_cg_item_combination_cancel
{
	BYTE							Header;
} TPacketCGItemCombinationCancel;
#endif