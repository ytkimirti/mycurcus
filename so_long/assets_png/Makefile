
SRC_PNG=$(wildcard *.png)
DST_XPM=$(SRC_PNG:.png=.xpm)

MAGICK_FLAGS=-scale 400% -filter box

listsrc:
	echo $(SRC_PNG)

listdst:
	echo $(DST_XPM)

fclean:
	rm -rf $(DST_XPM)

convert: $(DST_XPM)

%.xpm: %.png
	magick $^ $(MAGICK_FLAGS) ../assets/$@
