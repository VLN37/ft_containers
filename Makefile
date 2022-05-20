test:	$(OBJDIR) $(OBJ)
	make -s -C vector performance
	make -s -C vector accuracy
	make -s -C stack accuracy
	make -s -C stack accuracy

clean:
		make -C stack clean
		make -C vector clean
		rm -rf $(OBJDIR)
		rm -f vector_*
		rm -f set_*
		rm -f stack_*
		rm -f map_*

fclean:	clean

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean test
