.PHONY: all clean rebuild

all clean rebuild:
	@for d in */ ;					\
	do						\
		$(MAKE) -C $$d $@ || exit 1 ;		\
	done

