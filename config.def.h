/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const char *fonts[]          = { "monospace:size=10" };
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#bbbbbb", "#222222", "#444444" },
	[SchemeSel]  = { "#eeeeee", "#005577", "#005577" },
};
static const float dcolw = 0.05;  /* increment of first column's width */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       workspace     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       1,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       9,            0,           -1 },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.i = TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      move,           {.i = TAG} }, \

/* commands */
void spawnmenu(const Arg *arg) {
	char num[] = "0";

	num[0] += selmon->num;
	spawn((const char*[]){ "dmenu_run", "-b", "-m", num, "-fn", fonts[0],
		"-nf", colors[SchemeNorm][0], "-nb", colors[SchemeNorm][1],
		"-sf", colors[SchemeSel][0], "-sb", colors[SchemeSel][1], NULL
	});
}
void spawnterm(const Arg *arg) {
	spawn((const char*[]){ "st", NULL });
}

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawnmenu,      {0} },
	{ MODKEY|ShiftMask,             XK_Return, spawnterm,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      setnrows,       {.i = +1 } },
	{ MODKEY,                       XK_d,      setnrows,       {.i = -1 } },
	{ MODKEY,                       XK_h,      setcolw,        {.i = -1 } },
	{ MODKEY,                       XK_l,      setcolw,        {.i = +1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_Tab,    toggletiled,    {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  movemon,        {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, movemon,        {.i = +1 } },
	TAGKEYS(                        XK_1,                      1)
	TAGKEYS(                        XK_2,                      2)
	TAGKEYS(                        XK_3,                      3)
	TAGKEYS(                        XK_4,                      4)
	TAGKEYS(                        XK_5,                      5)
	TAGKEYS(                        XK_6,                      6)
	TAGKEYS(                        XK_7,                      7)
	TAGKEYS(                        XK_8,                      8)
	TAGKEYS(                        XK_9,                      9)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* pointer buttons definitions */
static Button buttons[] = {
	/* event mask     button          function        argument */
	{ MODKEY,         Button1,        movemouse,      {0} },
	{ MODKEY,         Button2,        togglefloating, {0} },
	{ MODKEY,         Button3,        resizemouse,    {0} },
};

