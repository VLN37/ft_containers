test:	$(OBJDIR) $(OBJ)
	make -s --no-print-directory -C vector performance
	make -s --no-print-directory -C vector accuracy
	make -s --no-print-directory -C stack accuracy
	make -s --no-print-directory -C stack performance
	make -s --no-print-directory -C map accuracy

clean:
		make -s -C stack clean
		make -s -C vector clean
		make -s -C set clean
		make -s -C map clean
		rm -rf $(OBJDIR)

fclean:	clean
		make -s -C stack fclean
		make -s -C vector fclean
		make -s -C set fclean
		make -s -C map fclean

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean test
