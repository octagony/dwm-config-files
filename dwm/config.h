#include "./XF86keysym.h"
#include "./colorschemes/catppuccin.h"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int stairpx   = 20;       /* depth of the stairs layout */
static const int stairdirection     = 1;        /* 0: left-aligned, 1: right-aligned */
static const int stairsamesize      = 1;        /* 1 means shrink all the staired windows to the same size */
#define ICONSIZE 18   /* icon size */
#define ICONSPACING 8 /* space between icon and title */
static const char *fonts[]          = { "JetBrainsMonoNL:weight=bold:size=11:antialias=true:hinting=true" };
static const char dmenufont[]       = "JetBrainsMonoNL:weight=bold:size=11:antialias=true:hinting=true"; 
static const char *colors[][3]      = {
	[SchemeNorm] = { col_gray3, col_gray2, col_gray2 },
	[SchemeSel]  = { col_cyan, col_gray4,  col_cyan },
  [SchemeTitle]  = { col_title, col_gray4, col_gray4 },
};

/* tagging */
static const char *tags[] = { " ", " ", " ", " ",""};

static const Rule rules[] = {
	/*       class                instance     title         tags mask     isfloating   monitor */
       {   "Pcmanfm",              NULL,       NULL,         1 << 0,       1,           -1 },
       {   "firefox",              NULL,       NULL,         1 << 1,       0,           -1 },
       {   "Thorium-browser",      NULL,       NULL,         1 << 1,       0,           -1 },
       {   "Code",                 NULL,       NULL,         1 << 2,       0,           -1 },
       {   "TelegramDesktop",      NULL,       NULL,         1 << 3,       1,           -1 },
       {   "vlc",                  NULL,       NULL,         1 << 0,       1,           -1 },
       {   "discord",              NULL,       NULL,         1 << 4,       1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  
#include "vanitygaps.c"

 static const Layout layouts[] = {
 	/* symbol     arrange function */
  { "| 󰓍 ",      stairs },
  { "| @ ",      spiral },
	{ "| 󰉧 ",      NULL },    
 	{ "| 󰊓 ",      monocle },
 	{ "| [T]",      tile },    
	{ "| [\\]",     dwindle },
	{ "| H[]",      deck },
	{ "| TTT",      bstack },
	{ "| ===",      bstackhoriz },
	{ "| HHH",      grid },
	{ "| ###",      nrowgrid },
	{ "| ---",      horizgrid },
	{ "| :::",      gaplessgrid },
	{ "| |M|",      centeredmaster },
	{ "| >M>",      centeredfloatingmaster },
	{ "| ><>",      NULL },    
	{ NULL,       NULL },
 };

/* key definitions */
#define MODKEY Mod4Mask
#define MOD2KEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run","-l", "6", "-g","1","-h", "32" "-fn", dmenufont, "-shb", "#cba6f7", "-shf","#585b70", "-nhb", "#1e1e2e", "-nhf","#585b70" ,NULL }; 
static const char *termcmd[]  = { "st", NULL };
static const char *brupcmd[]  = { "/home/octagony/.config/suckless/dwm/scripts/brightnessnotifications.sh", "up", NULL };
static const char *brdowncmd[]  = { "/home/octagony/.config/suckless/dwm/scripts/brightnessnotifications.sh", "down", NULL };
static const char *upvol[]  = { "/home/octagony/.config/suckless/dwm/scripts/volumenotifications.sh", "up", NULL};
static const char *downvol[]  =  { "/home/octagony/.config/suckless/dwm/scripts/volumenotifications.sh", "down", NULL};
static const char *mutevol[]  = { "/home/octagony/.config/suckless/dwm/scripts/volumenotifications.sh", "mute", NULL};
static const char *prevtrack[]  = { "playerctl", "previous", NULL};
static const char *nexttrack[]  = { "playerctl", "next", NULL};
static const char *playpausetrack[]  = { "playerctl", "play-pause", NULL};
static const char *flameshot[]  = { "flameshot", "gui", NULL };
static const char *joshuto[]  = { "st","-e", "joshuto", NULL };
static const char *powermenu[] = { "/home/octagony/.config/suckless/dwm/scripts/powermenu.sh", NULL};
static const char *configscript[] = { "/home/octagony/.config/suckless/dwm/scripts/config.sh", NULL};
static const char *browserbookmarksscript[] = { "/home/octagony/.config/suckless/dwm/scripts/browserbookmarks.sh", NULL};

static const Key keys[] = {
	/* modifier                     key                          function           argument */
	{ MODKEY|ShiftMask,             XK_Return,                   spawn,             {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,                   spawn,             {.v = termcmd } },
	{ MODKEY,                       XK_b,                        togglebar,         {0} },
	{ 0, 			                     	XF86XK_MonBrightnessUp, 	   spawn, 	          {.v = brupcmd} },
	{ 0, 			                    	XF86XK_MonBrightnessDown, 	 spawn,           	{.v = brdowncmd} },
	{ 0, 				                    XF86XK_AudioLowerVolume, 	   spawn,           	{.v = downvol} },
	{ 0, 				                    XF86XK_AudioRaiseVolume, 	   spawn,           	{.v = upvol} },
	{ 0, 				                    XF86XK_AudioMute, 		       spawn,           	{.v = mutevol} },
	{ 0, 				                    XF86XK_AudioPrev,						 spawn,           	{.v = prevtrack} },
	{ 0, 				                    XF86XK_AudioNext,						 spawn,           	{.v = nexttrack} },
	{ 0, 				                    XF86XK_AudioPlay,						 spawn,           	{.v = playpausetrack} },
	{ MOD2KEY|ControlMask, 		      XK_c, 			                 spawn, 	          {.v = configscript} },
	{ MOD2KEY|ControlMask, 		      XK_m, 			                 spawn, 	          {.v = browserbookmarksscript} },
	{ MOD2KEY,                      XK_s,                        spawn,      		   	{.v = flameshot} },
	{ MOD2KEY|ControlMask,          XK_j,                        spawn,             {.v = joshuto} },
	{ MOD2KEY|ControlMask, 		      XK_Delete, 			             spawn, 	          {.v = powermenu} },
	{ MOD2KEY|ControlMask,          XK_f,                        spawn,             SHCMD("firefox")},
	{ MOD2KEY|ControlMask,          XK_t,                        spawn,             SHCMD("telegram-desktop")},
	{ MOD2KEY|ControlMask,          XK_b,                        spawn,             SHCMD("thorium-browser")},
	{ MOD2KEY|ControlMask,          XK_p,                				 spawn,             SHCMD("pcmanfm")},
	{ MOD2KEY|ControlMask,          XK_o,                				 spawn,             SHCMD("obsidian")},
	{ MODKEY|ShiftMask,             XK_j,                        rotatestack,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,                        rotatestack,       {.i = -1 } },
	{ MODKEY,                       XK_j,                        focusstack,        {.i = +1 } },
	{ MODKEY,                       XK_k,                        focusstack,        {.i = -1 } },
	{ MODKEY,                       XK_i,                        incnmaster,        {.i = +1 } },
	{ MODKEY,                       XK_d,                        incnmaster,        {.i = -1 } },
	{ MODKEY,                       XK_h,                        setmfact,          {.f = -0.05} },
	{ MODKEY,                       XK_l,                        setmfact,          {.f = +0.05} },
	{ MODKEY,                       XK_z,                        zoom,              {0} },
	{ MODKEY|MOD2KEY,               XK_u,                        incrgaps,          {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_u,                        incrgaps,          {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_i,                        incrigaps,         {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_i,                        incrigaps,         {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_o,                        incrogaps,         {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_o,                        incrogaps,         {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_6,                        incrihgaps,        {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_6,                        incrihgaps,        {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_7,                        incrivgaps,        {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_7,                        incrivgaps,        {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_8,                        incrohgaps,        {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_8,                        incrohgaps,        {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_9,                        incrovgaps,        {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_9,                        incrovgaps,        {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_0,                        togglegaps,        {0} },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_0,                        defaultgaps,       {0} },
	{ MODKEY,                       XK_Tab,                      view,              {0} },
	{ MODKEY,                       XK_q,                        killclient,        {0} },
	{ MODKEY,                       XK_s,                        setlayout,         {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,                        setlayout,         {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,                        setlayout,         {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,                        setlayout,         {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,                    setlayout,         {0} },
	{ MODKEY|ShiftMask,             XK_space,                    togglefloating,    {0} },
	{ MODKEY,                       XK_0,                        view,              {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                        tag,               {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                    focusmon,          {.i = -1 } },
	{ MODKEY,                       XK_period,                   focusmon,          {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                    tagmon,            {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                   tagmon,            {.i = +1 } },
	TAGKEYS(                        XK_1,                                           0)
	TAGKEYS(                        XK_2,                                           1)
	TAGKEYS(                        XK_3,                                           2)
	TAGKEYS(                        XK_4,                                           3)
	TAGKEYS(                        XK_5,                                           4)
	TAGKEYS(                        XK_6,                                           5)
	TAGKEYS(                        XK_7,                                           6)
	TAGKEYS(                        XK_8,                                           7)
	TAGKEYS(                        XK_9,                                           8)
	{ MODKEY|ShiftMask,             XK_Escape, quit,                                {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,                                {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
