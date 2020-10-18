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

/* commands */
#define SPAWN(...) spawn((const char*[]){ __VA_ARGS__, NULL })
void do_spawnmenu(int unused) {
	char num[] = "0";

	num[0] += selmon->num;
	SPAWN("dmenu_run", "-b", "-m", num, "-fn", fonts[0],
		"-nf", colors[SchemeNorm][0], "-nb", colors[SchemeNorm][1],
		"-sf", colors[SchemeSel][0], "-sb", colors[SchemeSel][1]);
}
void do_spawnterm(int unused) {
	SPAWN("st");
}

/* key definitions */
#define MODKEY Mod1Mask
#define WSPACEKEYS(KEY, WSPACE) \
	{ MODKEY,                       KEY,       do_viewspace,   WSPACE }, \
	{ MODKEY|ShiftMask,             KEY,       do_movespace,   WSPACE },
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
	{ MODKEY,                       XK_p,      do_spawnmenu,   0 },
	{ MODKEY|ShiftMask,             XK_Return, do_spawnterm,   0 },
	{ MODKEY,                       XK_j,      do_focus,       +1 },
	{ MODKEY,                       XK_k,      do_focus,       -1 },
	{ MODKEY,                       XK_h,      do_focus,       -2 },
	{ MODKEY,                       XK_l,      do_focus,       +2 },
	{ MODKEY,                       XK_i,      do_setnrows,    +1 },
	{ MODKEY,                       XK_d,      do_setnrows,    -1 },
	{ MODKEY,                       XK_h,      do_setcolw,     -1 },
	{ MODKEY,                       XK_l,      do_setcolw,     +1 },
	{ MODKEY,                       XK_Return, do_zoom,        0 },
	{ MODKEY|ShiftMask,             XK_c,      do_close,       0 },
	{ MODKEY,                       XK_Tab,    do_toggletiled, 0 },
	{ MODKEY,                       XK_space,  do_togglefocus, 0 },
	{ MODKEY|ShiftMask,             XK_space,  do_togglefloating, 0 },
	{ MODKEY,                       XK_comma,  do_focusmon,    -1 },
	{ MODKEY,                       XK_period, do_focusmon,    +1 },
	{ MODKEY|ShiftMask,             XK_comma,  do_movemon,     -1 },
	{ MODKEY|ShiftMask,             XK_period, do_movemon,     +1 },
	{ MODKEY|ShiftMask,             XK_q,      do_quit,        0 },
};

/* pointer buttons definitions */
static Button buttons[] = {
	/* event mask     button          function           argument */
	{ MODKEY,         Button1,        do_mousemove,      0 },
	{ MODKEY,         Button2,        do_togglefloating, 0 },
	{ MODKEY,         Button3,        do_mouseresize,    0 },
};

