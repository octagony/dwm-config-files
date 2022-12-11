/* See LICENSE file for copyright and license details. */

/* appearance */
#include "/home/octagony/.config/dwm/colorschemes/catppuccin.h"
#include "XF86keysym.h"

static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 2;        /* vertical padding for statusbar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=12" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=12"; 
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "cmd", "www", "dev", "soc", "mail", "gg"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance     title         tags mask     isfloating   monitor */
	{ "firefox",              NULL,       NULL,         1 << 1,       0,           -1 },
	{ "Brave-browser",        NULL,       NULL,         1 << 1,       0,           -1 },
	{ "VSCodium",             NULL,       NULL,         1 << 2,       0,           -1 },
	{ "Emacs",                NULL,       NULL,         1 << 2,       0,           -1 },
	{ "TelegramDesktop",      NULL,       NULL,         1 << 3,       1,           -1 },
	{ "Claws-mail",           NULL,       NULL,         1 << 4,       0,           -1 },
	{ "Steam",                NULL,       NULL,         1 << 5,       1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static const char *dmenucmd[] = { "dmenu_run","-h", "24", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, "-shb", col_gray4,  NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *brupcmd[]  = { "/home/octagony/.config/dwm/scripts/brightnessnotifications.sh", "up", NULL };
static const char *brdowncmd[]  = { "/home/octagony/.config/dwm/scripts/brightnessnotifications.sh", "down", NULL };
static const char *upvol[]  = { "/home/octagony/.config/dwm/scripts/volumenotifications.sh", "up", NULL};
static const char *downvol[]  =  { "/home/octagony/.config/dwm/scripts/volumenotifications.sh", "down", NULL};
static const char *mutevol[]  = { "/home/octagony/.config/dwm/scripts/volumenotifications.sh", "mute", NULL};
static const char *flameshot[]  = { "flameshot", "gui", NULL };
static const char *nnn[]  = { "st", "./.nnn", NULL };
static const char *powermenu[] = { "/home/octagony/.config/dwm/scripts/powermenu.sh", NULL};

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
	{ MOD2KEY,                      XK_s,                        spawn,      		   	{.v = flameshot} },
	{ MOD2KEY|ControlMask,          XK_n,                        spawn,             {.v = nnn} },
	{ MOD2KEY|ControlMask, 		      XK_Delete, 			             spawn, 	          {.v = powermenu} },
	{ MOD2KEY|ControlMask,          XK_f,                        spawn,             SHCMD("firefox")},
	{ MOD2KEY|ControlMask,          XK_d,                        spawn,             SHCMD("doublecmd")},
	{ MOD2KEY|ControlMask,          XK_p,                        spawn,             SHCMD("pcmanfm")},
	{ MOD2KEY|ControlMask,          XK_t,                        spawn,             SHCMD("telegram-desktop")},
	{ MOD2KEY|ControlMask,          XK_b,                        spawn,             SHCMD("brave")},
	{ MOD2KEY|ControlMask,          XK_BackSpace,                spawn,             SHCMD("slock")},
	{ MODKEY|ShiftMask,             XK_j,                        rotatestack,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,                        rotatestack,       {.i = -1 } },
	{ MODKEY,                       XK_j,                        focusstack,        {.i = +1 } },
	{ MODKEY,                       XK_k,                        focusstack,        {.i = -1 } },
	{ MODKEY,                       XK_i,                        incnmaster,        {.i = +1 } },
	{ MODKEY,                       XK_d,                        incnmaster,        {.i = -1 } },
	{ MODKEY,                       XK_h,                        setmfact,          {.f = -0.05} },
	{ MODKEY,                       XK_l,                        setmfact,          {.f = +0.05} },
	{ MODKEY,                       XK_z,                        zoom,              {0} },
	{ MODKEY,                       XK_Tab,                      view,              {0} },
	{ MODKEY,       					      XK_q,                        killclient,        {0} },
	{ MODKEY,                       XK_t,                        setlayout,         {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                        setlayout,         {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                        setlayout,         {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,                    setlayout,         {0} },
	{ MODKEY|ShiftMask,             XK_space,                    togglefloating,    {0} },
	{ MODKEY,                       XK_0,                        view,              {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                        tag,               {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                    focusmon,          {.i = -1 } },
	{ MODKEY,                       XK_period,                   focusmon,          {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                    tagmon,            {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                   tagmon,            {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
  { MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                                           0)
	TAGKEYS(                        XK_2,                                           1)
	TAGKEYS(                        XK_3,                                           2)
	TAGKEYS(                        XK_4,                                           3)
	TAGKEYS(                        XK_5,                                           4)
	TAGKEYS(                        XK_6,                                           5)
	TAGKEYS(                        XK_7,                                           6)
	TAGKEYS(                        XK_8,                                           7)
	TAGKEYS(                        XK_9,                                           8)
	{ MODKEY|ShiftMask,             XK_Escape,                   quit,              {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,                        quit,              {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
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

