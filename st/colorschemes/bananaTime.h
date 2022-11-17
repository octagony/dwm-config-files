static const char *colorname[] = {
	/* 8 normal colors */
	"#000000",
	"#b21818",
	"#18b218",
	"#be5f00",
	"#6d85ba",
	"#b218b2",
	"#18b2b2",
	"#b2b2b2",

	/* 8 bright colors */
	"#686868",
	"#ff5454",
	"#54ff54",
	"#ffff54",
	"#6385ff",
	"#ff54ff",
	"#54ffff",
	"#ffffff",

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	/* (cursor defaults - see below) */
	"#cccccc",
	"#555555",
	"#f9ce74", /* default foreground colour */
	"#1c1c1c", /* default background colour */
};
unsigned int defaultfg = 258;
unsigned int defaultbg = 259;
unsigned int defaultcs = 256;
