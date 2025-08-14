Changes done in the sdk for the development 

Application files 

bp_uart.c 		-> uart init using uart1
btble.c 		-> bt/ble related apis -> spp data cb, connection/disconnection
spp_serial.c 	-> AT cmd and data processing 

Changed files (Note - wrote "//usr defined" where we had add or done changes)

tlkapp.c 
tlk_config.h  -> only using spp  so others macros are put to 0 
tlkmdi_le_command.c -> changes done in the advertising and scanning data
tlkmdi_lemgrAtt.c  - > changes done for the att table and the spp data function
tlkmmi_btmgr.c 		-> changes done for the switching between pinmode and simple pairing and changed this tlkmmi_btmgr_start to stop auto pairing
btp_config.h		-> changes done to use only spp profile
tlkmdi_le_command.c -> changed the ble to always in advertising mode
tlkmmi_btmgrRec.c   -> channged sacn and paging paramter values(	tlkmdi_btrec_setPageParam(512, 18); // improves connect response
	tlkmdi_btrec_setScanParam(512, 18, true, true); // improves visibility)

website to check data correctness https://www.diffchecker.com/text-compare/
