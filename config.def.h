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

/* commands */
#define SPAWN(...) spawn((const char*[]){ __VA_ARGS__, NULL })
void spawnmenu(int unused) {
	char num[] = "0";

	num[0] += selmon->num;
	SPAWN("dmenu_run", "-b", "-m", num, "-fn", fonts[0],
		"-nf", colors[SchemeNorm][0], "-nb", colors[SchemeNorm][1],
		"-sf", colors[SchemeSel][0], "-sb", colors[SchemeSel][1]);
}
void spawnterm(int unused) {
	SPAWN("st");
}

/* key definitions */
#define MODKEY Mod1Mask
#define WSPACEKEYS(KEY, WSPACE) \
	{ MODKEY,                       KEY,       view,           WSPACE }, \
	{ MODKEY|ShiftMask,             KEY,       move,           WSPACE },
static Key keys[] = {
	/* modifier                     key        function        argument */
	WSPACEKEYS(                     XK_1,                      1)
	WSPACEKEYS(                     XK_2,                      2)
	WSPACEKEYS(                     XK_3,                      3)
	WSPACEKEYS(                     XK_4,                      4)
	WSPACEKEYS(                     XK_5,                      5)
	WSPACEKEYS(                     XK_6,                      6)
	WSPACEKEYS(                     XK_7,                      7)
	WSPACEKEYS(                     XK_8,                      8)
	WSPACEKEYS(                     XK_9,                      9)
	{ MODKEY,                       XK_p,      spawnmenu,      0 },
	{ MODKEY|ShiftMask,             XK_Return, spawnterm,      0 },
	{ MODKEY,                       XK_j,      focusstack,     +1 },
	{ MODKEY,                       XK_k,      focusstack,     -1 },
	{ MODKEY,                       XK_i,      setnrows,       +1 },
	{ MODKEY,                       XK_d,      setnrows,       -1 },
	{ MODKEY,                       XK_h,      setcolw,        -1 },
	{ MODKEY,                       XK_l,      setcolw,        +1 },
	{ MODKEY,                       XK_Return, zoom,           0 },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     0 },
	{ MODKEY,                       XK_Tab,    toggletiled,    0 },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, 0 },
	{ MODKEY,                       XK_comma,  focusmon,       -1 },
	{ MODKEY,                       XK_period, focusmon,       +1 },
	{ MODKEY|ShiftMask,             XK_comma,  movemon,        -1 },
	{ MODKEY|ShiftMask,             XK_period, movemon,        +1 },
	{ MODKEY|ShiftMask,             XK_q,      quit,           0 },
};

/* pointer buttons definitions */
static Button buttons[] = {
	/* event mask     button          function        argument */
	{ MODKEY,         Button1,        movemouse,      0 },
	{ MODKEY,         Button2,        togglefloating, 0 },
	{ MODKEY,         Button3,        resizemouse,    0 },
};

