#define dll_init
// define the exported dll functions here
global.px_init=external_define('pxwrap.dll','pxtone_init',dll_cdecl ,ty_real,6,ty_real,ty_real,ty_real,ty_real,ty_real,ty_real);
global.px_load=external_define('pxwrap.dll','pxtone_load',dll_cdecl ,ty_real,1,ty_string);
global.px_play=external_define('pxwrap.dll','pxtone_play',dll_cdecl ,ty_real,3,ty_real,ty_real,ty_real);
global.px_volume=external_define('pxwrap.dll','pxtone_volume',dll_cdecl ,ty_real,1,ty_real);
global.px_fadeout=external_define('pxwrap.dll','pxtone_fadeout',dll_cdecl ,ty_real,1,ty_real);
global.px_setloop=external_define('pxwrap.dll','pxtone_setloop',dll_cdecl ,ty_real,1,ty_real);
global.px_stop=external_define('pxwrap.dll','pxtone_stop',dll_cdecl ,ty_real,0);
global.px_release=external_define('pxwrap.dll','pxtone_release',dll_cdecl ,ty_real,0);
global.px_shutdown=external_define('pxwrap.dll','pxtone_shutdown',dll_cdecl ,ty_real,0);

#define pxt_init
// calls the exported Messagebox function(mb)

return external_call(global.px_init, argument0,argument1,argument2,argument3,argument4,argument5)
#define pxt_load
// calls the exported Messagebox function(mb)

return external_call(global.px_load, argument0)
#define pxt_play
// calls the exported Messagebox function(mb)

return external_call(global.px_play, argument0,argument1,argument2)
#define pxt_volume
// calls the exported Messagebox function(mb)

return external_call(global.px_volume, argument0)
#define pxt_fadeout
// calls the exported Messagebox function(mb)

return external_call(global.px_fadeout, argument0)
#define pxt_setloop
// calls the exported Messagebox function(mb)

return external_call(global.px_setloop, argument0)
#define pxt_stop
// calls the exported Messagebox function(mb)

return external_call(global.px_stop)
#define pxt_release
// calls the exported Messagebox function(mb)

return external_call(global.px_release)
#define pxt_shutdown
// calls the exported Messagebox function(mb)

return external_call(global.px_shutdown)
