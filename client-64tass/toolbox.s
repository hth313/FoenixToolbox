;;;
;;; Bindings for the Foenix Toolbox public calls
;;;

sys_proc_exit = $FFE000
sys_chan_read_b = $FFE004
sys_chan_read = $FFE008
sys_chan_readline = $FFE00C
sys_chan_write_b = $FFE010
sys_chan_write = $FFE014
sys_chan_status = $FFE018
sys_chan_flush = $FFE01C
sys_chan_seek = $FFE020
sys_chan_ioctrl = $FFE024
sys_chan_open = $FFE028
sys_chan_close = $FFE02C
sys_chan_swap = $FFE030
sys_chan_device = $FFE034
sys_bdev_register = $FFE038
sys_bdev_read = $FFE03C
sys_bdev_write = $FFE040
sys_bdev_status = $FFE044
sys_bdev_flush = $FFE048
sys_bdev_ioctrl = $FFE04C
sys_fsys_open = $FFE050
sys_fsys_close = $FFE054
sys_fsys_opendir = $FFE058
sys_fsys_closedir = $FFE05C
sys_fsys_readdir = $FFE060
sys_fsys_findfirst = $FFE064
sys_fsys_findnext = $FFE068
sys_fsys_mkdir = $FFE06C
sys_fsys_delete = $FFE070
sys_fsys_rename = $FFE074
sys_fsys_set_cwd = $FFE078
sys_fsys_get_cwd = $FFE07C
sys_fsys_load = $FFE080
sys_fsys_register_loader = $FFE084
sys_fsys_stat = $FFE088
sys_mem_get_ramtop = $FFE08C
sys_mem_reserve = $FFE090
sys_err_message = $FFE094
sys_proc_run = $FFE098
sys_txt_get_capabilities = $FFE09C
sys_txt_set_mode = $FFE0A0
sys_txt_setsizes = $FFE0A4
sys_txt_set_xy = $FFE0A8
sys_txt_get_xy = $FFE0AC
sys_txt_get_region = $FFE0B0
sys_txt_set_region = $FFE0B4
sys_txt_set_color = $FFE0B8
sys_txt_get_color = $FFE0BC
sys_txt_set_cursor_visible = $FFE0C0
sys_txt_set_font = $FFE0C4
sys_txt_get_sizes = $FFE0C8
sys_txt_set_border = $FFE0CC
sys_txt_set_border_color = $FFE0D0
sys_txt_put = $FFE0D4
sys_txt_print = $FFE0D8