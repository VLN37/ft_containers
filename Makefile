test:	$(OBJDIR) $(OBJ)
	make -s --no-print-directory -C vector performance
	make -s --no-print-directory -C vector accuracy
	make -s --no-print-directory -C stack accuracy
	make -s --no-print-directory -C stack accuracy

clean:
		make -s -C stack clean
		make -s -C vector clean
		rm -rf $(OBJDIR)
		rm -f vector_*
		rm -f set_*
		rm -f stack_*
		rm -f map_*

fclean:	clean

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean test
