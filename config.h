/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const int startwithgaps	     = 1;	 /* 1 means gaps are used by default */
static const unsigned int gappx     = 10;       /* default gap between windows in pixels */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
//static const char *fonts[]          = { "monospace:size=10" };
//static const char *fonts[]          = { "monospace:size=10" };
static const char *fonts[]          = { "IBM Plex Mono Medium:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#ebd7a7";
static const char col_sec[]         = "#2c2c2c";
static const char col_gray3[]       = "#83a598";
static const char col_gray4[]       = "#2c2c2c";
static const char col_principal[]   = "#ebd7a7";
static const unsigned int baralpha = 0xd1;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {

	/*               fg         bg         border   */
	[SchemeNorm] = { col_principal, col_sec, col_sec },
	[SchemeSel]  = { col_gray4, col_gray3,  col_gray4  },
};
static const unsigned int alphas[][3]      = {
       /*               fg      bg        border     */
       [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
       [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};
/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九","十" };
static const char *tagsalt[] = { "", "", "", "", "", "", "", "", "","" };

/* launcher commands (They must be NULL terminated) */
//static const char* icecat[]      = { "chromium", "duckduckgo.com", NULL };
//static const char* mail[]      = { "thunderbird", NULL };
static const char* help[]    = { "zathura", "/etc/skel/.intro.pdf", NULL };

static const Launcher launchers[] = {
       /* command       name to display */
//	{ icecat,         "surf" },
//	{ mail,           "mail" },
	{ help,           "help" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",        NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",     NULL,       NULL,    1<<8>>0,      0,           -1 },
	{ "Chromium",    NULL,       NULL,    1<<8>>0,      0,           -1 },
	{ "Thunderbird", NULL,       NULL,    1<<5>>7,      0,           -1 },
	{ "Calamares",   NULL,       NULL,    0,            1,           -1 },
	{ "calamares",   NULL,       NULL,    0,            1,           -1 },
	{ "Audacious",   NULL,       NULL,    1<<7>>9,      0,           -1 },
	{ "Abiword",     NULL,       NULL,    1<<6>>8,      0,           -1 },
	
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray4, "-sb", col_principal, "-sf", col_gray3, NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *browsecmd[] = { "firefox", NULL };
static const char *audioupcmd[] = { "audioup", NULL };
static const char *audiodowncmd[] = { "audiodown", NULL };
//static const char *sscmd[] = { "flameshot", "gui" };
static const char *emacscmd[] = {"emacs", NULL };
static const char *sscmd[] = {"flameshot", "gui", NULL };
static const char *playcmd[] = {"audacious", NULL };
static const char *mailcmd[] = {"thunderbird", NULL, };
static const char *filescmd[] = {"pcmanfm", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
        { MODKEY|ShiftMask,             XK_n,      togglealttag,   {0} },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
        { MODKEY,                       XK_a,      spawn,          {.v = audioupcmd } },
        { MODKEY,                       XK_e,      spawn,          {.v = browsecmd } },
        { MODKEY,                       XK_s,      spawn,          {.v = audiodowncmd } },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          {.v = playcmd } },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = mailcmd } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = sscmd } },
	{ MODKEY,                       XK_n,      spawn,          {.v = filescmd } },
//	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = emacscmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = emacscmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_r,      rotatestack,    {.i = +1 } },
	{ MODKEY,	                XK_g,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_x,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_c,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_k, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_w,      setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_d,      setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_w,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_w,  setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
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

