/* See LICENSE file for copyright and license details. */

/* 1. CONFIGURAÇÕES GLOBAIS E MACROS (Devem vir primeiro) */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* CORRIGIDO: 1 mantém a barra do DWM no TOPO */

/* Fontes */
static const char *fonts[]          = { "JetBrains Mono:size=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetBrains Mono:pixelsize=14:antialias=true:autohint=true";

/* Paleta de cores em Hexadecimal */
static const char col_black[]       = "#000000"; 
static const char col_dark_purple[] = "#1a002c"; 
static const char col_purple[]      = "#4a0e7a"; 
static const char col_light_purple[]= "#9d4edf"; 
static const char col_gray[]        = "#bbbbbb"; 

static const char *colors[][3]      = {
	/*               fg                bg               border   */
	[SchemeNorm] = { col_gray,         col_black,       col_dark_purple },
	[SchemeSel]  = { col_light_purple, col_dark_purple, col_purple      },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* forward declarations para o config.h saber que elas existem */
void tile(Monitor *m);

static const Rule rules[] = {
	/* class        instance    title       tags mask     isfloating   monitor */
	{ "Gimp",       NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",    NULL,       NULL,       1 << 8,       0,           -1 },
	{ "scratchpad", NULL,       NULL,       0,            1,           -1 }, 
	{ "ShellFooter",NULL,       NULL,       0,            1,           -1 }, 
};

/* layout(s) */
static const float mfact     = 0.50; 
static const int nmaster     = 0;    
static const int resizehints = 1;    
static const int lockfullscreen = 1; 
static const int refreshrate = 120;  

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    
	{ "><>",      NULL },    
	{ "[M]",      monocle },
};

/* commands */
static char dmenumon[2] = "0"; 
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_gray, "-sb", col_dark_purple, "-sf", col_light_purple, NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *qtermcmd[] = { "qterminal", NULL };
static const char *terminatorcmd[] = { "terminator", NULL };


/* CORRIGIDO: Comando 100% limpo e nativo para o Kitty */
static const char *footercmd[] = { "kitty", "--class", "ShellFooter", "-o", "remember_window_size=no", NULL };




static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} }, 
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} }, 
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },   
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },   
	{ MODKEY,                       XK_b,      togglebar,      {0} },          
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },   
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },   

	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },       
	{ MODKEY|ControlMask,           XK_Return, spawn,          {.v = qtermcmd } },      
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = terminatorcmd } }, 

	/* Atalho Super + F1 para abrir o rodapé */
	{ MODKEY,                       XK_F1,     spawn,          {.v = footercmd } }, 

	{ MODKEY,                       XK_q,      killclient,     {0} },             
	{ MODKEY,                       XK_space,  togglefloating, {0} },             
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[0]} }, 

	{ MODKEY,                       XK_r,      quit,           {1} },             
	{ MODKEY,                       XK_Escape, killclient,     {0} },             

	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },   
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },   
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },   
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },   

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },             
};

/* button definitions */
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
};
