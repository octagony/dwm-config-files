/* user and group to drop privileges to */
static const char *user  = "octagony";
static const char *group = "octagony";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
	[CAPS] = "red",         /* CapsLock on */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* default message */
static const char * message = "What do you want?";

/* text color */
static const char * text_color = "#ffffff";
/* text size (must be a valid size) */
static const char * font_name = "6x13";
