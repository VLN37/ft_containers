TEST		= test


$(TEST):	$(OBJDIR) $(OBJ)
	make -s -C vector performance
	make -s -C vector accuracy

clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -rf accft accstd

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean

-include $(DEPS)
